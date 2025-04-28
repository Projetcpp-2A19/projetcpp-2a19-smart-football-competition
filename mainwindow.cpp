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

    m_joueurId = -1;
    afficherPhotoJoueur(m_joueurId, ui->label_photo);

    remplirComboBoxEquipe();

    ui->tableView->resizeColumnsToContents();  // Automatically resize columns based on their content
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
    ui->tableView->verticalHeader()->setVisible(false);
    int lastColumn = ui->tableView->model()->columnCount() - 1;
    ui->tableView->setColumnHidden(lastColumn, true);
    ui->tableNotesJoueurs->verticalHeader()->setVisible(false);

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

    /*int ret = A.connect_arduino();
    switch(ret){
    case(0):
        qDebug() << "Arduino is available and connected to :" << A.getarduino_port_name();
        break;
    case(1):
        qDebug() << "Arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case(-1):
        qDebug() << "Arduino is not available";
    }
    QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));
*/
    // Configurer le port série (à adapter selon votre configuration)
    serial = new QSerialPort(this);
    serial->setPortName("COM4"); // Remplacer par le bon port
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->open(QIODevice::ReadOnly);

    // Connecter le signal readyRead() à la fonction readSerial()
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readSerial);

    // Dans le constructeur de MainWindow
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, [this](int index) {
        rfidScanEnabled = (index == 2);  // 1 = index de page_2
        qDebug() << "RFID état:" << rfidScanEnabled;
    });

    connect(ui->pushButton_retour_2, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Retour à l'accueil
    });

    connect(ui->pushButton_retour_3, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Retour à l'accueil
    });

    connect(ui->pushButton_retour_4, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0); // Retour à l'accueil
    });
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

void MainWindow::trierLignes(int colonne, bool croissant)
{
    if (proxyModel) {
        proxyModel->sort(colonne, croissant ? Qt::AscendingOrder : Qt::DescendingOrder);
    }
}

void MainWindow::on_comboBox_trie_currentIndexChanged(int index)
{
    switch(index) {
    case 0: // "Nom"
        trierLignes(1, true);
        break;
    case 1: // "Prénom"
        trierLignes(2, true);
        break;
    case 2: // "Poste"
        trierLignes(3, false);
        break;
    case 3: // "But"
        trierLignes(4, false);
        break;
    case 4: // "Passe"
        trierLignes(5, false);
        break;
    case 5: // "Carton Jaune"
        trierLignes(6, false);
        break;
    case 6: // "Carton Rouge"
        trierLignes(7, false);
        break;
    default:
        break;
    }
}



void MainWindow::afficherProfil(int id) {
    m_joueurId = id;

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
        QString nom = query.value(0).toString();        // nom
        QString prenom = query.value(1).toString();     // prenom
        QString poste = query.value(2).toString();      // poste
        int buts = query.value(3).toInt();              // nbr_but
        int passes = query.value(4).toInt();            // nbr_passe
        int cartonsJ = query.value(5).toInt();          // carton_j
        int cartonsR = query.value(6).toInt();          // carton_r

        ui->label_nom->setText(nom);
        ui->label_prenom->setText(prenom);
        ui->label_poste->setText(poste);
        ui->label_but->setText(QString::number(buts));
        ui->label_passe->setText(QString::number(passes));
        ui->label_cartonJ->setText(QString::number(cartonsJ));
        ui->label_cartonR->setText(QString::number(cartonsR));

        ui->stackedWidget->setCurrentWidget(ui->page_profil);
        ui->radarWidget->setStats(buts, passes, cartonsJ, cartonsR);

        afficherPhotoJoueur(m_joueurId, ui->label_photo);
        afficherNotesDansTable(m_joueurId);
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

    // Chemin vers le logo - à adapter
    QString logoPath = "C:\\Users\\emnag\\OneDrive\\Bureau\\Ali\\Projet_Qt\\logo.png";

    // Chargement et redimensionnement du logo
    QPixmap logo(logoPath);
    if(!logo.isNull()) {
        logo = logo.scaled(45, 45, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    }

    // Sauvegarde temporaire du logo redimensionné
    QString tempLogoPath;
    if(!logo.isNull()) {
        tempLogoPath = QDir::tempPath() + "/temp_logo.png";
        if(!logo.save(tempLogoPath)) {
            tempLogoPath.clear();
        }
    }

    // Construction du HTML avec le style original du tableau
    QString html = "<html>"
                   "<head>"
                   "<style>"
                   "body { font-family: Arial, sans-serif; font-size: 8pt; }"
                   "h1 { color: #333333; text-align: center; font-size: 12pt; margin-bottom: 5px; }"
                   "table { width: 100%; border-collapse: collapse; margin-top: 10px; }"
                   "th { background-color: #f2f2f2; color: #333333; padding: 4px; text-align: left; font-size: 4pt; border: 1px solid #ddd; }"
                   "td { padding: 4px; border: 1px solid #ddd; font-size: 3pt; }"
                   ".header { display: flex; justify-content: center; align-items: center; margin-bottom: 10px; }"
                   ".title-container { text-align: center; }"
                   "</style>"
                   "</head>"
                   "<body>"
                   "<div class='header'>";

    if(!tempLogoPath.isEmpty()) {
        html += "<img class='logo' src='" + tempLogoPath + "' />";
    }

    html += "<div class='title-container'>"
            "<h1>Liste des Joueurs</h1>"
            "<div style='font-size: 7pt; color: #666;'>Généré le " + QDate::currentDate().toString("dd/MM/yyyy") + "</div>"
                                                            "</div>"
                                                            "</div>"
                                                            "<table>"
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
    html += "</table></body></html>";

    QTextDocument doc;
    doc.setHtml(html);

    QString fichier = QFileDialog::getSaveFileName(
        this,
        "Enregistrer le PDF",
        QDir::homePath() + "/liste_joueurs.pdf",
        "Fichiers PDF (*.pdf)");

    if (fichier.isEmpty()) {
        // Nettoyer le fichier temporaire si l'utilisateur annule
        if(!tempLogoPath.isEmpty()) QFile::remove(tempLogoPath);
        return;
    }

    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fichier);

    // Marges réduites pour gagner de l'espace
    QMargins margins(10, 10, 10, 10);
    QPageLayout pageLayout;
    pageLayout.setMargins(margins);
    pageLayout.setMode(QPageLayout::StandardMode);
    printer.setPageLayout(pageLayout);

    // Ajustement de la taille du document
    doc.setPageSize(printer.pageRect(QPrinter::Millimeter).size());

    // Impression du document
    doc.print(&printer);

    // Nettoyer le fichier temporaire
    if(!tempLogoPath.isEmpty()) QFile::remove(tempLogoPath);

    QMessageBox::information(this, "Succès", "PDF généré avec succès !");
}

void MainWindow::on_pushButton_photo_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,
                                                    tr("Sélectionner une image"),
                                                    QDir::homePath(),
                                                    tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));

    if (!filePath.isEmpty()) {
        loadImageToDatabase(filePath);

        // Optionnel: afficher l'image dans un QLabel
        QPixmap pixmap(filePath);
        ui->label_photo->setPixmap(pixmap.scaled(100, 100, Qt::KeepAspectRatio));
    }
}

void MainWindow::loadImageToDatabase(const QString &filePath)
{
    // [1] Vérification dans la base
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM joueur WHERE id_joueur = ?");
    checkQuery.addBindValue(m_joueurId);

    if (!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::warning(this, "Erreur", "Échec de vérification de l'ID");
        return;
    }

    int count = checkQuery.value(0).toInt();
    qDebug() << "Nombre de joueurs trouvés avec cet ID :" << count;

    if (count == 0) {
        QMessageBox::warning(this, "Erreur",
                             QString("Aucun joueur avec l'ID %1").arg(m_joueurId));
        return;
    }

    // [2] Exécution de la mise à jour
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir l'image");
        return;
    }

    QByteArray imageData = file.readAll();
    file.close();

    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE joueur SET photo = ? WHERE id_joueur = ?");
    updateQuery.addBindValue(imageData);
    updateQuery.addBindValue(m_joueurId);

    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Erreur SQL", updateQuery.lastError().text());
        return;
    }

    // [3] Vérification des lignes affectées
    int rowsAffected = updateQuery.numRowsAffected();
    qDebug() << "Lignes modifiées :" << rowsAffected;

    if (rowsAffected > 0) {
        QMessageBox::information(this, "Succès", "Photo mise à jour");
    } else {
        QMessageBox::warning(this, "Avertissement",
                             "La photo n'a pas été mise à jour (l'ID existe mais aucune modification)");
    }
}

void MainWindow::afficherPhotoJoueur(int idJoueur, QLabel* labelPhoto) {
    QSqlQuery query;
    query.prepare("SELECT photo FROM joueur WHERE id_joueur = :id");
    query.bindValue(":id", idJoueur);

    if (!query.exec() || !query.next() || query.isNull("photo")) {
        labelPhoto->setPixmap(QPixmap(":/pic/default.jpg").scaled(labelPhoto->size(), Qt::KeepAspectRatio));

        return;
    }

    QByteArray imageData = query.value("photo").toByteArray();
    QImage image;
    if (image.loadFromData(imageData)) {
        labelPhoto->setPixmap(QPixmap::fromImage(image).scaled(labelPhoto->size(), Qt::KeepAspectRatio));
    } else {
        labelPhoto->setPixmap(QPixmap(":/pic/default.jpg").scaled(labelPhoto->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::afficherNotesDansTable(int idJoueur)
{
    // 1. Préparation de la table
    ui->tableNotesJoueurs->clear();
    ui->tableNotesJoueurs->setColumnCount(3);
    ui->tableNotesJoueurs->setHorizontalHeaderLabels({"Date", "Adversaire", "Note"});
    ui->tableNotesJoueurs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableNotesJoueurs->setRowCount(0);

    // 2. Récupération de l'équipe du joueur
    QSqlQuery queryEquipe;
    queryEquipe.prepare("SELECT ID_EQUIPE FROM JOUEUR WHERE ID_JOUEUR = ?");
    queryEquipe.addBindValue(idJoueur);

    if (!queryEquipe.exec()) {
        ui->tableNotesJoueurs->setRowCount(1);
        ui->tableNotesJoueurs->setItem(0, 0, new QTableWidgetItem("Erreur de base de données"));
        return;
    }

    if (!queryEquipe.next()) {
        ui->tableNotesJoueurs->setRowCount(1);
        ui->tableNotesJoueurs->setItem(0, 0, new QTableWidgetItem("Joueur non trouvé"));
        return;
    }

    int idEquipeJoueur = queryEquipe.value(0).toInt();

    // 3. Récupération du nom de l'équipe
    QSqlQuery queryNomEquipe;
    queryNomEquipe.prepare("SELECT NOM_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = ?");
    queryNomEquipe.addBindValue(idEquipeJoueur);

    if (!queryNomEquipe.exec() || !queryNomEquipe.next()) {
        ui->tableNotesJoueurs->setRowCount(1);
        ui->tableNotesJoueurs->setItem(0, 0, new QTableWidgetItem("Erreur de base de données"));
        return;
    }

    QString nomEquipeJoueur = queryNomEquipe.value(0).toString();

    // 4. Récupération des matchs
    QSqlQuery queryMatch;
    queryMatch.prepare(
        "SELECT m.ID_MATCH, m.DATE_MATCH, m.SCORE, "
        "m.NOM_EQUIPE1, m.NOM_EQUIPE2 "
        "FROM MATCHES m "
        "WHERE m.NOM_EQUIPE1 = ? OR m.NOM_EQUIPE2 = ? "
        "ORDER BY m.DATE_MATCH DESC"
        );
    queryMatch.addBindValue(nomEquipeJoueur);
    queryMatch.addBindValue(nomEquipeJoueur);

    if (!queryMatch.exec()) {
        ui->tableNotesJoueurs->setRowCount(1);
        ui->tableNotesJoueurs->setItem(0, 0, new QTableWidgetItem("Erreur de base de données"));
        return;
    }

    // 5. Traitement des résultats
    int matchCount = 0;
    while (queryMatch.next()) {
        matchCount++;
        int matchId = queryMatch.value(0).toInt();
        QDate date = queryMatch.value(1).toDate();
        QString score = queryMatch.value(2).toString();
        QString equipe1 = queryMatch.value(3).toString();
        QString equipe2 = queryMatch.value(4).toString();

        // Calcul de la note
        double note = calculerNoteParMatch(idJoueur, matchId);

        // Ajout dans la table
        int row = ui->tableNotesJoueurs->rowCount();
        ui->tableNotesJoueurs->insertRow(row);

        ui->tableNotesJoueurs->setItem(row, 0, new QTableWidgetItem(date.toString("dd/MM/yyyy")));

        QString adversaire = (nomEquipeJoueur == equipe1) ? equipe2 : equipe1;
        adversaire += " / " + score;
        ui->tableNotesJoueurs->setItem(row, 1, new QTableWidgetItem(adversaire));

        QTableWidgetItem* noteItem = new QTableWidgetItem(QString::number(note, 'f', 1));
        noteItem->setTextAlignment(Qt::AlignCenter);

        if (note >= 7.5) noteItem->setBackground(QColor(220, 255, 220));
        else if (note <= 4.0) noteItem->setBackground(QColor(255, 220, 220));

        ui->tableNotesJoueurs->setItem(row, 2, noteItem);
    }

    // 6. Gestion du cas vide
    if (matchCount == 0) {
        ui->tableNotesJoueurs->setRowCount(1);
        ui->tableNotesJoueurs->setItem(0, 0, new QTableWidgetItem("Aucun match trouvé"));
        ui->tableNotesJoueurs->setSpan(0, 0, 1, 3);
    }
}
double MainWindow::calculerNoteParMatch(int idJoueur, int matchId)
{
    // 1. Récupération de l'équipe du joueur
    QSqlQuery queryEquipe;
    queryEquipe.prepare("SELECT ID_EQUIPE FROM JOUEUR WHERE ID_JOUEUR = ?");
    queryEquipe.addBindValue(idJoueur);

    if (!queryEquipe.exec() || !queryEquipe.next()) {
        return 0.0;
    }

    int idEquipe = queryEquipe.value(0).toInt();

    // 2. Récupération du nom de l'équipe
    QSqlQuery queryNomEquipe;
    queryNomEquipe.prepare("SELECT NOM_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = ?");
    queryNomEquipe.addBindValue(idEquipe);

    if (!queryNomEquipe.exec() || !queryNomEquipe.next()) {
        return 0.0;
    }

    QString nomEquipe = queryNomEquipe.value(0).toString();

    // 3. Récupération des infos du match
    QSqlQuery queryMatch;
    queryMatch.prepare(
        "SELECT SCORE, NOM_EQUIPE1, NOM_EQUIPE2 "
        "FROM MATCHES "
        "WHERE ID_MATCH = ?"
        );
    queryMatch.addBindValue(matchId);

    if (!queryMatch.exec() || !queryMatch.next()) {
        return 0.0;
    }

    QString score = queryMatch.value(0).toString();
    QString equipe1 = queryMatch.value(1).toString();
    QString equipe2 = queryMatch.value(2).toString();

    // 4. Parsing du score
    QStringList scores = score.split("-");
    if (scores.size() != 2) {
        return 0.0;
    }

    int score1 = scores[0].toInt();
    int score2 = scores[1].toInt();

    // 5. Récupération des stats individuelles du joueur
    QSqlQuery queryStats;
    queryStats.prepare(
        "SELECT BUTS, PASSES, CARTON_J, CARTON_R "
        "FROM JOUEUR "
        "WHERE ID_JOUEUR = ? AND ID_MATCH = ?"
        );
    queryStats.addBindValue(idJoueur);
    queryStats.addBindValue(matchId);

    int buts = 0, passes = 0, cartonJaune = 0, cartonRouge = 0;
    if (queryStats.exec() && queryStats.next()) {
        buts = queryStats.value(0).toInt();
        passes = queryStats.value(1).toInt();
        cartonJaune = queryStats.value(2).toInt();
        cartonRouge = queryStats.value(3).toInt();
    }

    // 6. Détermination du résultat
    bool isVictoire;
    int scoreEquipeJoueur;

    if (nomEquipe == equipe1) {
        isVictoire = (score1 > score2);
        scoreEquipeJoueur = score1;
    } else {
        isVictoire = (score2 > score1);
        scoreEquipeJoueur = score2;
    }

    // 7. Calcul de la note de base
    double note = 5.0; // Note moyenne de base

    // Bonus/malus selon le résultat
    note += isVictoire ? 0.5 : -0.5;

    // Bonus selon les buts marqués par l'équipe
    note += qMin(scoreEquipeJoueur * 0.2, 2.0);

    // Bonus individuels
    note += buts + 0.8;
    note += passes + 0.6;

    // Malus pour les cartons
    note -= cartonJaune - 0.3;
    note -= cartonRouge - 0.6;

    // 8. Variation aléatoire
    uint hash = qHash(QString("%1-%2").arg(idJoueur).arg(matchId));
    double variation = (hash % 20) * 0.1 - 1.0; // Variation entre -1.0 et +1.0
    note += variation;

    // 9. Normalisation
    note = qBound(0.0, note, 10.0);
    return qRound(note * 10) / 10.0;
}

void MainWindow::on_pushButton_lock_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_controle);
}

void MainWindow::on_page_controle_entered() {  // À connecter via un signal
    rfidScanEnabled = true;
    qDebug() << "RFID activé";
}

void MainWindow::on_page_controle_left() {  // À connecter via un signal
    rfidScanEnabled = false;
    qDebug() << "RFID désactivé";
}

void MainWindow::readSerial() {
    if (!rfidScanEnabled) return;

    while (serial->canReadLine()) {
        QString message = QString(serial->readLine()).trimmed();

        if (message == "ACCES_AUTORISE") {
            incrementerEntrees(m_joueurId);
            afficher_entree(); // Met à jour l'affichage après incrémentation
            ui->stackedWidget->setCurrentWidget(ui->page_3);
        } else if (message == "ACCES_REFUSE") {
            ui->stackedWidget->setCurrentWidget(ui->page_4);
        }
    }
}

void MainWindow::incrementerEntrees(int joueurId) {
    QSqlQuery query;
    query.prepare("UPDATE joueur SET nbr_entrees = nbr_entrees + 1 WHERE id_joueur = ?");
    query.addBindValue(joueurId);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'incrémentation :" << query.lastError();
    } else {
        qDebug() << "Entrée +1 pour le joueur ID" << joueurId;
    }
}

void MainWindow::afficher_entree() {
    QSqlQuery query;
    query.prepare("SELECT nbr_entrees FROM joueur WHERE id_joueur = ?");
    query.addBindValue(m_joueurId); // Utilise l'ID du joueur actuel

    if (query.exec() && query.next()) {
        int nbr_entrees = query.value(0).toInt(); // Index 0 car on ne sélectionne qu'une colonne
        ui->label_entree->setText(QString::number(nbr_entrees));
    } else {
        qDebug() << "Erreur lors de la récupération des entrées :" << query.lastError();
        ui->label_entree->setText("Erreur");
    }
}
