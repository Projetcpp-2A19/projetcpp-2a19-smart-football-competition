#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , proxyModel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);
    proxyModel->setSourceModel(Jtmp.afficher());
    ui->tableView->setModel(proxyModel);
    ui->tableView->setSortingEnabled(true);


    ui->lineEditRecherche->setFocus();
    connect(ui->pushButton_retour, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Retour à l'accueil
    });
    connect(ui->lineEditRecherche, &QLineEdit::returnPressed, this, &MainWindow::rechercherJoueur);

    remplirComboBoxEquipe();

    ui->tableView->resizeColumnsToContents();  // Automatically resize columns based on their content
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
    ui->tableView->verticalHeader()->setVisible(false);

    // Valider que le nom ne contient que des lettres et des espaces
    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEdit_nom->setValidator(validator);
    ui->lineEdit_prenom->setValidator(validator);

    // Limiter la longueur du texte
    ui->lineEdit_nom->setMaxLength(20);
    ui->lineEdit_prenom->setMaxLength(20);

    // Connecter le signal textChanged à un slot pour mettre la première lettre en majuscule
    connect(ui->lineEdit_nom, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_nom_textChanged);
    connect(ui->lineEdit_prenom, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_prenom_textChanged);

    QIntValidator *validatorBut = new QIntValidator(this);
    QIntValidator *validatorPasse = new QIntValidator(this);
    QIntValidator *validatorCartonJ = new QIntValidator(this);
    QIntValidator *validatorCartonR = new QIntValidator(this);

    ui->lineEdit_but->setValidator(validatorBut);
    ui->lineEdit_passe->setValidator(validatorPasse);
    ui->lineEdit_cartonJ->setValidator(validatorCartonJ);
    ui->lineEdit_cartonR->setValidator(validatorCartonR);

    validatorBut->setRange(0, 999);
    validatorPasse->setRange(0, 999);
    validatorCartonJ->setRange(0, 99);
    validatorCartonR->setRange(0, 99);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getNextId() {
    QSqlQuery query;
    query.prepare("SELECT MAX(id_joueur) FROM joueur"); // Récupère le maximum des id_joueur existants

    if (query.exec() && query.next()) {
        int maxId = query.value(0).toInt(); // Récupère la valeur maximale
        return maxId + 1; // Retourne l'id suivant
    } else {
        qDebug() << "Erreur lors de la récupération du prochain ID :" << query.lastError().text();
        return 1; // Retourne 1 si la table est vide ou en cas d'erreur
    }
}

//controle de saisie
void MainWindow::on_lineEdit_nom_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        // Met la première lettre en majuscule
        QString formattedText = text;
        formattedText[0] = formattedText[0].toUpper();

        // Si le texte a changé (pour éviter une boucle infinie)
        if (formattedText != text) {
            ui->lineEdit_nom->setText(formattedText);
        }
    }
}
void MainWindow::on_lineEdit_prenom_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        // Met la première lettre en majuscule
        QString formattedText = text;
        formattedText[0] = formattedText[0].toUpper();

        // Si le texte a changé (pour éviter une boucle infinie)
        if (formattedText != text) {
            ui->lineEdit_prenom->setText(formattedText);
        }
    }
}

void MainWindow::remplirComboBoxEquipe() {
    QSqlQueryModel *model = new QSqlQueryModel(this); // Créer un modèle

    model->setQuery("SELECT nom_equipe FROM equipe"); // Exécuter la requête

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << model->lastError().text();
        return;
    }

    ui->comboBox_equipe->setModel(model); // Associer le modèle au QComboBox
    ui->comboBox_equipe->setModelColumn(0); // Afficher la première colonne (nom)
}

void MainWindow::on_pushButton_ajouter_clicked() {
    // Récupération des données saisies
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString poste = ui->comboBox_poste->currentText();
    int nbr_but = ui->lineEdit_but->text().toInt();
    int nbr_passe = ui->lineEdit_passe->text().toInt();
    int carton_j = ui->lineEdit_cartonJ->text().toInt();
    int carton_r = ui->lineEdit_cartonR->text().toInt();

    // Récupération de l'id_equipe
    QString nomEquipe = ui->comboBox_equipe->currentText();
    QSqlQuery query;
    query.prepare("SELECT id_equipe FROM equipe WHERE nom_equipe = :nom");
    query.bindValue(":nom", nomEquipe);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur lors de la récupération de l'équipe.\n"), QMessageBox::Cancel);
        return;
    }

    int id_equipe = -1; // Valeur par défaut en cas d'échec
    if (query.next()) {
        id_equipe = query.value(0).toInt();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Aucune équipe trouvée avec ce nom.\n"), QMessageBox::Cancel);
        return;
    }

    // Création de l'objet Joueur (l'id est généré automatiquement dans ajouter())
    Joueur J(0, nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r, id_equipe);

    // Ajout du joueur
    bool test = J.ajouter();
    if (test) {
        // Mise à jour de la table
        proxyModel->setSourceModel(Jtmp.afficher());

        // Réinitialisation des champs
        ui->lineEdit_nom->clear();          // Efface le champ nom
        ui->lineEdit_prenom->clear();       // Efface le champ prénom
        ui->comboBox_poste->setCurrentIndex(0); // Réinitialise le comboBox poste
        ui->lineEdit_but->clear();          // Efface le champ buts
        ui->lineEdit_passe->clear();        // Efface le champ passes
        ui->lineEdit_cartonJ->clear();      // Efface le champ cartons jaunes
        ui->lineEdit_cartonR->clear();      // Efface le champ cartons rouges
        ui->comboBox_equipe->setCurrentIndex(0); // Réinitialise le comboBox équipe

        // Message de succès
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n"), QMessageBox::Cancel);
    } else {
        // Message d'erreur
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué \n"), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_supp_clicked()
{
    int id = ui->lineEdit_supp->text().toInt();
    bool test = Jtmp.supprimer(id);

    if(test){
        if(test){
            proxyModel->setSourceModel(Jtmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Le joueur à été supprimé \n"), QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Le joueur n'as pas été supprimé \n"), QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_pushButton_modifier_clicked() {
    // Récupération de l'ID du joueur à partir de la ligne sélectionnée dans le tableView
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un joueur à modifier.");
        return;
    }

    int row = selectedIndexes.first().row(); // Récupère la ligne sélectionnée
    int id = ui->tableView->model()->index(row, 0).data().toInt(); // Supposons que l'ID est dans la colonne 0

    // Récupération des autres données saisies
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString poste = ui->comboBox_poste->currentText();
    int nbr_but = ui->lineEdit_but->text().toInt();
    int nbr_passe = ui->lineEdit_passe->text().toInt();
    int carton_j = ui->lineEdit_cartonJ->text().toInt();
    int carton_r = ui->lineEdit_cartonR->text().toInt();

    // Récupération de l'id_equipe
    QString nomEquipe = ui->comboBox_equipe->currentText();
    QSqlQuery query;
    query.prepare("SELECT id_equipe FROM equipe WHERE nom_equipe = :nom");
    query.bindValue(":nom", nomEquipe);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Erreur lors de la récupération de l'équipe.\n"), QMessageBox::Cancel);
        return;
    }

    int id_equipe = -1; // Valeur par défaut en cas d'échec
    if (query.next()) {
        id_equipe = query.value(0).toInt();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Aucune équipe trouvée avec ce nom.\n"), QMessageBox::Cancel);
        return;
    }

    // Création de l'objet Joueur
    Joueur J(id, nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r, id_equipe);

    // Appel de la méthode modifier()
    bool test = J.modifier();
    if (test) {
        proxyModel->setSourceModel(Jtmp.afficher()); // Mise à jour de la table
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée \n"), QMessageBox::Cancel);
        // Mise à jour de la table
        proxyModel->setSourceModel(Jtmp.afficher());

        // Réinitialisation des champs
        ui->lineEdit_nom->clear();          // Efface le champ nom
        ui->lineEdit_prenom->clear();       // Efface le champ prénom
        ui->comboBox_poste->setCurrentIndex(0); // Réinitialise le comboBox poste
        ui->lineEdit_but->clear();          // Efface le champ buts
        ui->lineEdit_passe->clear();        // Efface le champ passes
        ui->lineEdit_cartonJ->clear();      // Efface le champ cartons jaunes
        ui->lineEdit_cartonR->clear();      // Efface le champ cartons rouges
        ui->comboBox_equipe->setCurrentIndex(0); // Réinitialise le comboBox équipe
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectuée \n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    int row = index.row();

    // Récupération des données du joueur
    ui->lineEdit_nom->setText(ui->tableView->model()->index(row, 1).data().toString());
    ui->lineEdit_prenom->setText(ui->tableView->model()->index(row, 2).data().toString());
    QString poste = ui->tableView->model()->index(row, 3).data().toString();
    int comboIndex = ui->comboBox_poste->findText(poste);
    if (comboIndex != -1) {
        ui->comboBox_poste->setCurrentIndex(comboIndex);
    } else {
        qDebug() << "La valeur" << poste << "n'a pas été trouvée dans le QComboBox.";
    }
    ui->lineEdit_but->setText(ui->tableView->model()->index(row, 4).data().toString());
    ui->lineEdit_passe->setText(ui->tableView->model()->index(row, 5).data().toString());
    ui->lineEdit_cartonJ->setText(ui->tableView->model()->index(row, 6).data().toString());
    ui->lineEdit_cartonR->setText(ui->tableView->model()->index(row, 7).data().toString());

    // Récupération de l'id_equipe du joueur
    int id_equipe = ui->tableView->model()->index(row, 8).data().toInt(); // Supposons que l'id_equipe est dans la colonne 8

    // Requête SQL pour récupérer le nom de l'équipe correspondante
    QSqlQuery query;
    query.prepare("SELECT nom_equipe FROM equipe WHERE id_equipe = :id_equipe");
    query.bindValue(":id_equipe", id_equipe);

    if (query.exec() && query.next()) {
        QString nomEquipe = query.value(0).toString(); // Récupère le nom de l'équipe
        ui->comboBox_equipe->setCurrentText(nomEquipe); // Affiche le nom de l'équipe dans le QComboBox
    } else {
        qDebug() << "Erreur lors de la récupération de l'équipe :" << query.lastError().text();
        ui->comboBox_equipe->setCurrentIndex(-1); // Efface la sélection si l'équipe n'est pas trouvée
    }
}

void MainWindow::on_TrieButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Options de tri");
    msgBox.setText("Trier par :");

    QPushButton *nomBtn = msgBox.addButton("Nom", QMessageBox::ActionRole);
    QPushButton *prenomBtn = msgBox.addButton("Prénom", QMessageBox::ActionRole);
    QPushButton *posteBtn = msgBox.addButton("Poste", QMessageBox::ActionRole);
    QPushButton *butBtn = msgBox.addButton("But", QMessageBox::ActionRole);
    QPushButton *passeBtn = msgBox.addButton("Passe", QMessageBox::ActionRole);
    QPushButton *cartonJBtn = msgBox.addButton("Carton Jaune", QMessageBox::ActionRole);
    QPushButton *cartonRBtn = msgBox.addButton("Carton Rouge", QMessageBox::ActionRole);
    msgBox.addButton("Annuler", QMessageBox::RejectRole);

    msgBox.exec();

    if (msgBox.clickedButton() == nomBtn) {
        trierLignes(1,true);
    } else if (msgBox.clickedButton() == prenomBtn) {
        trierLignes(2,true);
    } else if (msgBox.clickedButton() == posteBtn) {
        trierLignes(3,false);
    } else if (msgBox.clickedButton() == butBtn) {
        trierLignes(4,false);
    } else if (msgBox.clickedButton() == passeBtn) {
        trierLignes(5,false);
    } else if (msgBox.clickedButton() == cartonJBtn) {
        trierLignes(6,false);
    }else if (msgBox.clickedButton() == cartonRBtn) {
        trierLignes(7,false);
    }
}

void MainWindow::trierLignes(int colonne, bool croissant)
{
    if (proxyModel) {
        proxyModel->sort(colonne, croissant ? Qt::AscendingOrder : Qt::DescendingOrder);
    }
}

void MainWindow::afficherProfil(int id) {
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r FROM joueur WHERE id_joueur = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        // Affiche l'erreur SQL précise
        qDebug() << "Erreur SQL:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Problème de base de données: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        // Les indices commencent à 0 pour la première colonne sélectionnée
        QString nom = query.value(0).toString();        // nom (1ère colonne)
        QString prenom = query.value(1).toString();     // prenom (2e colonne)
        QString poste = query.value(2).toString();      // poste (3e colonne)
        int buts = query.value(3).toInt();              // nbr_but (4e)
        int passes = query.value(4).toInt();            // nbr_passe (5e)
        int cartonsJ = query.value(5).toInt();          // carton_j (6e)
        int cartonsR = query.value(6).toInt();          // carton_r (7e)

        ui->label_nom->setText(nom);
        ui->label_prenom->setText(prenom);
        ui->label_poste->setText(poste);
        ui->label_but->setText(QString::number(buts));
        ui->label_passe->setText(QString::number(passes));
        ui->label_cartonJ->setText(QString::number(cartonsJ));
        ui->label_cartonR->setText(QString::number(cartonsR));

        ui->stackedWidget->setCurrentWidget(ui->page_profil);
        ui->radarWidget->setStats(buts, passes, cartonsJ, cartonsR);
    } else {
        qDebug() << "Aucun joueur trouvé avec ID:" << id;
        QMessageBox::information(this, "Non trouvé", "Aucun joueur avec cet ID");
    }
}

void MainWindow:: rechercherJoueur(){
    QString recherche = ui->lineEditRecherche->text();
    QSqlQuery query;
    query.prepare("SELECT id_joueur FROM joueur WHERE LOWER(nom) LIKE LOWER(?) OR LOWER(prenom) LIKE LOWER(?)");
    query.addBindValue("%" + recherche + "%");
    query.addBindValue("%" + recherche + "%");

    if (query.exec() && query.next()) {
        int idJoueur = query.value(0).toInt();
        afficherProfil(idJoueur);  // Bascule vers le profil
    } else {
        QMessageBox::warning(this, "Erreur", "Joueur non trouvé.");
    }
    if (recherche.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom");
        return;
    }
}

void MainWindow::genererPDF(){
    QSqlQuery query;
    query.prepare("SELECT nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r FROM joueur ORDER BY nom");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la requête SQL");
        return;
    }

    QString html;
    html += "<h1>Liste des Joueurs</h1>";
    html += "<table border='1'><tr><th>ID</th><th>Nom</th><th>Prénom</th><th>Poste</th></tr>";

    while (query.next()) {
        html += QString("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td></tr>")
        .arg(query.value(0).toString())
            .arg(query.value(1).toString())
            .arg(query.value(2).toString())
            .arg(query.value(3).toString());
    }
    html += "</table>";

    // Préparer le document
    QTextDocument document;
    document.setHtml(html);

    // Configurer l'impression PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer PDF", QDir::homePath(), "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Générer le PDF
    document.print(&printer);
    QMessageBox::information(this, "Succès", "PDF généré avec succès !");

}

void MainWindow::on_pushButton_pdf_clicked()
{
    QSqlQuery query;
    if(!query.exec("SELECT nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r FROM joueur")) {
        QMessageBox::critical(this, "Erreur", "Échec de la requête SQL: " + query.lastError().text());
        return;
    }

    QString html = "<h1>Liste des Joueurs</h1>"
                   "<table border='1' style='width:100%; border-collapse:collapse;'>"
                   "<tr>"
                   "<th>Nom</th>"
                   "<th>Prénom</th>"
                   "<th>Poste</th>"
                   "<th>Buts</th>"
                   "<th>Passes</th>"
                   "<th>Cartons J</th>"
                   "<th>Cartons R</th>"
                   "</tr>";

    while (query.next()) {
        html += QString("<tr>"
                        "<td>%1</td>"
                        "<td>%2</td>"
                        "<td>%3</td>"
                        "<td>%4</td>"
                        "<td>%5</td>"
                        "<td>%6</td>"
                        "<td>%7</td>"
                        "</tr>")
                    .arg(query.value(0).toString())
                    .arg(query.value(1).toString())
                    .arg(query.value(2).toString())
                    .arg(query.value(3).toString())
                    .arg(query.value(4).toString())
                    .arg(query.value(5).toString())
                    .arg(query.value(6).toString());
    }
    html += "</table>";

    QTextDocument doc;
    doc.setHtml(html);

    QString fichier = QFileDialog::getSaveFileName(
        this,
        "Enregistrer le PDF",
        QDir::homePath() + "/liste_joueurs.pdf",
        "Fichiers PDF (*.pdf)");

    if (fichier.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fichier);

    // Ajout des marges
    QMargins margins(20, 20, 20, 20); // left, top, right, bottom
    QPageLayout pageLayout;
    pageLayout.setMargins(margins);
    pageLayout.setMode(QPageLayout::StandardMode);
    printer.setPageLayout(pageLayout);

    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}
