#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "match.h"
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), match(new Match())
{
    ui->setupUi(this);

    connect(ui->pb_afficher, &QPushButton::clicked, this, &MainWindow::displayTable);

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
    QString heure_match = ui->heure_match->text();
    QString stade = ui->stade->text();
    int score = ui->score->text().toInt();
    QString nom_equipe1 = ui->nom_equipe1->text();
    QString nom_equipe2 = ui->nom_equipe2->text();

    // Validate input fields
    if (ui->id_match->text().isEmpty() || ui->date_match->text().isEmpty() || ui->heure_match->text().isEmpty()
        || ui->stade->text().isEmpty() || ui->score->text().isEmpty() || ui->nom_equipe1->text().isEmpty()
        || ui->nom_equipe2->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"), tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
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

void MainWindow::on_pb_modifier_clicked() {
    int id_match = ui->id_match->text().toInt();
    QDate date_match = ui->date_match->date();
    QString heure_match = ui->heure_match->text();
    QString stade = ui->stade->text();
    int score = ui->score->text().toInt();
    QString nom_equipe1 = ui->nom_equipe1->text();
    QString nom_equipe2 = ui->nom_equipe2->text();

    // Validate input fields
    if (ui->id_match->text().isEmpty() || ui->date_match->text().isEmpty() || ui->heure_match->text().isEmpty()
        || ui->stade->text().isEmpty() || ui->score->text().isEmpty() || ui->nom_equipe1->text().isEmpty()
        || ui->nom_equipe2->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"), tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    // Check if the match exists
    if (!match->checkIfMatchExists(id_match)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Match non trouvé."), QMessageBox::Ok);
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
    ui->stade->setText(ui->tab_matches->model()->index(row, 3).data().toString());
    ui->score->setText(ui->tab_matches->model()->index(row, 4).data().toString());
    ui->nom_equipe1->setText(ui->tab_matches->model()->index(row, 5).data().toString());
    ui->nom_equipe2->setText(ui->tab_matches->model()->index(row, 6).data().toString());
}

// Slot to refresh the table view
void MainWindow::displayTable()
{
    QSqlQueryModel *model = match->afficher();
    ui->tab_matches->setModel(model);
}

// Slot to search for matches
void MainWindow::on_lineEdit_search_textChanged(const QString &text)
{
    QSqlQueryModel *model = match->afficher();
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterKeyColumn(3);  // Filter by "STADE" column
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxyModel->setFilterFixedString(text);
    ui->tab_matches->setModel(proxyModel);
}
