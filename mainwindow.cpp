#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "match.h"
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QRegularExpressionValidator>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQuery>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), match(new Match())
{
    ui->setupUi(this);


    ui->id_match->setValidator(new QIntValidator(1, 99999, this));
    QRegularExpressionValidator *heureValidator = new QRegularExpressionValidator(
        QRegularExpression("^(0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$"), this);
    ui->heure_match->setValidator(heureValidator);
    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(
        QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ ]{2,20}$"), this);
    ui->nom_equipe1->setValidator(nameValidator);
    ui->nom_equipe2->setValidator(nameValidator);
    QRegularExpressionValidator *scoreValidator = new QRegularExpressionValidator(
        QRegularExpression("^\\d{1,2}-\\d{1,2}$"), this);
    ui->score->setValidator(scoreValidator);

    QStringList stadiums = {"Veuillez sélectionner un stade.","Stade de France", "Camp Nou", "Wembley", "San Siro", "Old Trafford"};
    ui->stade->addItems(stadiums);
    connect(ui->search_button, &QPushButton::clicked, this, &MainWindow::searchMatch);

    connect(ui->pb_afficher, &QPushButton::clicked, this, &MainWindow::displayTable);
    connect(ui->pb_tri, &QPushButton::clicked, this, &MainWindow::on_pb_tri_clicked);
    connect(ui->pb_export_pdf, &QPushButton::clicked, this, &MainWindow::exportToPDF);

      // Initialize the table view
      displayTable();  // This will populate the table when the window is created
  }

MainWindow::~MainWindow()
{
    delete ui;
    delete match;
}

// Slot to add a match
void MainWindow::on_pb_ajouter_clicked()
{
    int id_match = ui->id_match->text().toInt();
    QDate date_match = ui->date_match->date();
    QString heure_match = ui->heure_match->text().trimmed();
    QString stade = ui->stade->currentText();
    QString score = ui->score->text().trimmed();
    QString nom_equipe1 = ui->nom_equipe1->text().trimmed();
    QString nom_equipe2 = ui->nom_equipe2->text().trimmed();

    // Validate ID Match (Must be a number)
    if (ui->id_match->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID du match est requis.");
        return;
    }

    // Validate Date Match (Must be 2015 or later)
    if (date_match.year() < 2015) {
        QMessageBox::warning(this, "Erreur", "La date du match doit être en 2015 ou plus.");
        return;
    }

    // Validate Heure Match (Must be in HH:MM format)
    if (!ui->heure_match->hasAcceptableInput()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une heure valide au format HH:MM (ex: 09:30, 15:45).");
        return;
    }

    // Validate Stade (Cannot be empty selection)
    if (ui->stade->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un stade.");
        return;
    }

    // Validate Score (Can be empty, but must be in number:number format if provided)
    if (!score.isEmpty() && !score.contains(QRegularExpression("^\\d{1,2}-\\d{1,2}$"))) {
        QMessageBox::warning(this, "Erreur", "Le score doit être au format Nombre:Nombre (ex: 2-1, 10-5) ou vide.");
        return;
    }

    // Validate Nom d'équipe 1 & 2 (Min 2, Max 20, Only Letters & Spaces)
    QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ ]{2,20}$");
    if (!nom_equipe1.contains(nameRegex)) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'équipe 1 doit contenir entre 2 et 20 lettres uniquement.");
        return;
    }
    if (!nom_equipe2.contains(nameRegex)) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'équipe 2 doit contenir entre 2 et 20 lettres uniquement.");
        return;
    }

    // Create a Match object and add it to the database
    Match newMatch(id_match, date_match, heure_match, stade, score, nom_equipe1, nom_equipe2);
    bool test = newMatch.ajouter();

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Match ajouté avec succès."), QMessageBox::Ok);
        displayTable();  // Refresh the table
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de l'ajout du match."), QMessageBox::Ok);
    }
}


// Slot to delete a match
void MainWindow::on_pb_supprimer_clicked()
{
    int id_match = ui->id_match->text().toInt();

    // Check if the match exists
    if (!match->checkIfMatchExists(id_match)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Match non trouvé."), QMessageBox::Ok);
        return;
    }

    // Delete the match
    bool test = match->supprimer(id_match);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Match supprimé avec succès."), QMessageBox::Ok);
        displayTable();  // Refresh the table
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la suppression du match."), QMessageBox::Ok);
    }
}

void MainWindow::on_pb_modifier_clicked()
{
    int id_match = ui->id_match->text().toInt();
    QDate date_match = ui->date_match->date();
    QString heure_match = ui->heure_match->text().trimmed();
    QString stade = ui->stade->currentText();
    QString score = ui->score->text().trimmed();
    QString nom_equipe1 = ui->nom_equipe1->text().trimmed();
    QString nom_equipe2 = ui->nom_equipe2->text().trimmed();

    // Check if the match exists
    if (!match->checkIfMatchExists(id_match)) {
        QMessageBox::critical(this, "Erreur", "Match non trouvé.");
        return;
    }

    // Validate ID Match
    if (ui->id_match->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID du match est requis.");
        return;
    }

    // Validate Date Match (Must be 2015 or later)
    if (date_match.year() < 2015) {
        QMessageBox::warning(this, "Erreur", "La date du match doit être en 2015 ou plus.");
        return;
    }

    // Validate Heure Match (Must be in HH:MM format)
    if (!ui->heure_match->hasAcceptableInput()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une heure valide au format HH:MM (ex: 09:30, 15:45).");
        return;
    }

    // Validate Stade (Cannot be empty selection)
    if (ui->stade->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un stade.");
        return;
    }

    // Validate Score (Can be empty, but must be in number:number format if provided)
    if (!score.isEmpty() && !score.contains(QRegularExpression("^\\d{1,2}-\\d{1,2}$"))) {
        QMessageBox::warning(this, "Erreur", "Le score doit être au format Nombre:Nombre (ex: 2-1, 10-5) ou vide.");
        return;
    }

    // Validate Nom d'équipe 1 & 2 (Min 2, Max 20, Only Letters & Spaces)
    QRegularExpression nameRegex("^[A-Za-zÀ-ÖØ-öø-ÿ ]{2,20}$");
    if (!nom_equipe1.contains(nameRegex)) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'équipe 1 doit contenir entre 2 et 20 lettres uniquement.");
        return;
    }
    if (!nom_equipe2.contains(nameRegex)) {
        QMessageBox::warning(this, "Erreur", "Le nom de l'équipe 2 doit contenir entre 2 et 20 lettres uniquement.");
        return;
    }

    // Update the match object
    match->setIdMatch(id_match);
    match->setDateMatch(date_match);
    match->setHeureMatch(heure_match);
    match->setStade(stade);
    match->setScore(score);
    match->setNomEquipe1(nom_equipe1);
    match->setNomEquipe2(nom_equipe2);

    bool test = match->modifierE(id_match);

    if (test) {
        QMessageBox::information(this, tr("Succès"), tr("Match modifié avec succès."), QMessageBox::Ok);
        displayTable();  // Refresh the table
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Échec de la modification du match."), QMessageBox::Ok);
    }
}

// Slot to display selected match in input fields
void MainWindow::on_tab_matches_clicked(const QModelIndex &index)
{
    int row = index.row();
    ui->id_match->setText(ui->tab_matches->model()->index(row, 0).data().toString());
    ui->date_match->setDate(ui->tab_matches->model()->index(row, 1).data().toDate());
    ui->heure_match->setText(ui->tab_matches->model()->index(row, 2).data().toString());
    ui->stade->setCurrentText(ui->tab_matches->model()->index(row, 3).data().toString());
    ui->score->setText(ui->tab_matches->model()->index(row, 4).data().toString());
    ui->nom_equipe1->setText(ui->tab_matches->model()->index(row, 5).data().toString());
    ui->nom_equipe2->setText(ui->tab_matches->model()->index(row, 6).data().toString());
}

// Slot to refresh the table view
void MainWindow::displayTable()
{
    qDebug() << "Displaying table...";  // Debug message
    QSqlQueryModel *model = match->afficher();
    if (model == nullptr) {
        qDebug() << "Failed to get model data!";
    } else {
        qDebug() << "Model data fetched successfully.";
    }
    ui->tab_matches->setModel(model);
}
void MainWindow::on_pb_tri_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Query to fetch matches sorted by date
    query.prepare("SELECT * FROM MATCHES ORDER BY DATE_MATCH DESC");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec du tri des matchs.");
        return;
    }

    model->setQuery(query);
    ui->tab_matches->setModel(model); // Update the table with sorted results
}
void MainWindow::exportToPDF()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty())
        return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);

    QPainter painter(&printer);

    int rowHeight = 30;
    int y = 100;
    int x = 50;

    // Get data from the table
    QSqlQueryModel *model = match->afficher();

    if (!model) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données.");
        return;
    }

    // Set font for header
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(x, y, "ID");
    painter.drawText(x + 50, y, "Date");
    painter.drawText(x + 150, y, "Heure");
    painter.drawText(x + 250, y, "Stade");
    painter.drawText(x + 400, y, "Score");
    painter.drawText(x + 500, y, "Equipe 1");
    painter.drawText(x + 650, y, "Equipe 2");

    y += rowHeight;

    painter.setFont(QFont("Arial", 9));

    for (int i = 0; i < model->rowCount(); ++i) {
        painter.drawText(x, y, model->index(i, 0).data().toString());
        painter.drawText(x + 50, y, model->index(i, 1).data().toString());
        painter.drawText(x + 150, y, model->index(i, 2).data().toString());
        painter.drawText(x + 250, y, model->index(i, 3).data().toString());
        painter.drawText(x + 400, y, model->index(i, 4).data().toString());
        painter.drawText(x + 500, y, model->index(i, 5).data().toString());
        painter.drawText(x + 650, y, model->index(i, 6).data().toString());
        y += rowHeight;
    }

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès.");
}
void MainWindow::searchMatch()
{
    QString searchText = ui->search_lineedit->text().trimmed();  // Get the text from QLineEdit

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom d'équipe.");
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // SQL query to search for matches where the team name matches
    query.prepare("SELECT * FROM MATCHES WHERE NOM_EQUIPE1 LIKE :search OR NOM_EQUIPE2 LIKE :search");
    query.bindValue(":search", "%" + searchText + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche.");
        return;
    }

    model->setQuery(query);
    ui->tab_matches->setModel(model);  // Update the table view with search results

    qDebug() << "Search completed for:" << searchText;
}



// Slot to search for matches

// Manually connect the signal and slot in MainWindow constructor
