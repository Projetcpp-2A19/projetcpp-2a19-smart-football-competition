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
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QSqlRecord>
#include <QVBoxLayout>
#include <QLayout>
#include <QLayoutItem>
#include <QInputDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), match(new Match())
{
    ui->setupUi(this);

    // Load team names and set up validation
    loadTeamNames();
    setupTeamComboValidation();

    // Validators
    ui->id_match->setValidator(new QIntValidator(1, 99999, this));

    QRegularExpressionValidator *heureValidator = new QRegularExpressionValidator(
        QRegularExpression("^(0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]$"), this);
    ui->heure_match->setValidator(heureValidator);

    QRegularExpressionValidator *scoreValidator = new QRegularExpressionValidator(
        QRegularExpression("^\\d{1,2}-\\d{1,2}$"), this);
    ui->score->setValidator(scoreValidator);

    // Populate stadium choices
    QStringList stadiums = {
        "Veuillez sélectionner un stade.",
        "Stade de France", "Camp Nou", "Wembley", "San Siro", "Old Trafford"
    };
    ui->stade->addItems(stadiums);

    // Button connections
    connect(ui->pb_afficher, &QPushButton::clicked, this, &MainWindow::displayTable);
    connect(ui->chatbot_button, &QPushButton::clicked, this, &MainWindow::goToChatbotPage);
    connect(ui->pb_export_pdf, &QPushButton::clicked, this, &MainWindow::exportToHTML);
    connect(ui->comboBox_tri, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->chat_send_button, &QPushButton::clicked, this, &MainWindow::handleChatMessage);
    connect(ui->chat_return_button, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);  // Back to main page
    });
    connect(ui->search_lineedit, &QLineEdit::textChanged, this, [this](const QString &text) {
        QString currentField = ui->comboBox_chercher->currentText();
        if (currentField != "-- Chercher par --") {
            searchMatchesBy(currentField, text.trimmed());
        }
    });

    // Initialize the table view
    displayTable();

    ui->tab_matches->verticalHeader()->setVisible(false);
    ui->tab_matches->horizontalHeader()->sectionResizeMode(QHeaderView::Stretch);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete match;
}
void MainWindow::goToChatbotPage() {
    ui->stackedWidget->setCurrentIndex(2);  // Page 3 = index 3
}

// Slot to add a match
void MainWindow::on_pb_ajouter_clicked()
{

    int id_match = ui->id_match->text().toInt();
    QDate date_match = ui->date_match->date();
    QString heure_match = ui->heure_match->text().trimmed();
    QString stade = ui->stade->currentText();
    QString score = ui->score->text().trimmed();
    QString nom_equipe1 = ui->nom_equipe1_combo->currentText().trimmed();
    QString nom_equipe2 = ui->nom_equipe2_combo->currentText().trimmed();
    if (ui->nom_equipe1_combo->currentIndex() == 0 || ui->nom_equipe2_combo->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner tous les équipes.");
        return;
    }
    if (nom_equipe1 == nom_equipe2) {
        QMessageBox::warning(this, "Erreur", "Les deux équipes doivent être différentes.");
        return;
    }

    if (ui->id_match->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID du match est requis.");
        return;
    }

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
QString generateCommentary(const QString &teamName, const QString &score, const QString &opponent) {
    if (score.isEmpty()) return "Le score n'a pas été défini pour ce match.";

    QStringList parts = score.split("-");
    if (parts.size() != 2) return "Score invalide.";

    int score1 = parts[0].toInt();
    int score2 = parts[1].toInt();

    QString outcome;
    bool isTeam1 = false;

    // Just in case, determine if the team is likely team1 or team2
    if (teamName == opponent) {
        outcome = "Match miroir 😄.";
    } else if (teamName == "NOM_EQUIPE1") {
        isTeam1 = true;
    }

    // Actual logic
    int myScore = isTeam1 ? score1 : score2;
    int theirScore = isTeam1 ? score2 : score1;

    if (myScore > theirScore) {
        if (myScore - theirScore >= 3)
            outcome = "Victoire écrasante pour " + teamName + " 💪!";
        else
            outcome = "Belle victoire de " + teamName + " 👏.";
    } else if (myScore < theirScore) {
        if (theirScore - myScore >= 3)
            outcome = "Défaite lourde pour " + teamName + " 😓.";
        else
            outcome = "Défaite serrée, " + teamName + " peut faire mieux la prochaine fois.";
    } else {
        outcome = "Match nul entre " + teamName + " et " + opponent + " 🤝.";
    }

    return outcome;
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
    QString nom_equipe1 = ui->nom_equipe1_combo->currentText().trimmed();
    QString nom_equipe2 = ui->nom_equipe2_combo->currentText().trimmed();


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
    if (ui->nom_equipe1_combo->currentIndex() == 0 || ui->nom_equipe2_combo->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner tous les équipes.");
        return;
    }
    if (nom_equipe1 == nom_equipe2) {
        QMessageBox::warning(this, "Erreur", "Les deux équipes doivent être différentes.");
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
    ui->nom_equipe1_combo->setCurrentText(ui->tab_matches->model()->index(row, 5).data().toString());
    ui->nom_equipe2_combo->setCurrentText(ui->tab_matches->model()->index(row, 6).data().toString());
}

// Slot to refresh the table view
void MainWindow::handleChatMessage() {
    QString teamName = ui->chat_input->text().trimmed();
    if (teamName.isEmpty()) {
        ui->chat_history->append("<p style='color:red'><b>🤖 Bot:</b> Veuillez entrer un nom d'équipe.</p>");
        return;
    }

    ui->chat_history->append("<p style='color:blue;'><b>Vous:</b> " + teamName + "</p>");

    QSqlQuery query;
    query.prepare(R"(
        SELECT ID_MATCH, DATE_MATCH, HEURE_MATCH, STADE, SCORE, NOM_EQUIPE1, NOM_EQUIPE2
        FROM MATCHES
        WHERE LOWER(NOM_EQUIPE1) LIKE :team OR LOWER(NOM_EQUIPE2) LIKE :team
        ORDER BY DATE_MATCH DESC
    )");
    query.bindValue(":team", "%" + teamName.toLower() + "%");

    if (!query.exec()) {
        ui->chat_history->append("<p style='color:red'><b>🤖 Bot:</b> Erreur lors de la recherche.</p>");
        return;
    }

    int count = 0;
    QStringList messages;

    while (query.next()) {
        count++;
        QString date = query.value("DATE_MATCH").toDate().toString("dd/MM/yyyy");
        QString stade = query.value("STADE").toString();
        QString score = query.value("SCORE").toString();
        QString team1 = query.value("NOM_EQUIPE1").toString();
        QString team2 = query.value("NOM_EQUIPE2").toString();

        QString vs = (teamName.compare(team1, Qt::CaseInsensitive) == 0) ? team2 : team1;
        QString analysis = generateCommentary(teamName, score, vs);

        QString commentary = QString("<p style='background:#e6ffe6; padding:8px; border-radius:10px;'>"
                                     "⚽ <b>Match contre %1</b> au %2, le %3.<br>"
                                     "📊 <b>Score :</b> %4.<br>"
                                     "🗣️ <i>%5</i></p>")
                                 .arg(vs, stade, date,
                                      score.isEmpty() ? "non défini" : score,
                                      analysis);

        messages << commentary;
    }

    if (count > 0) {
        ui->chat_history->append(QString("<p style='color:green'><b>🤖 Bot:</b> %1 match(s) trouvé(s)</p>").arg(count));
        for (const QString& msg : messages) {
            ui->chat_history->append(msg);
        }
    } else {
        ui->chat_history->append("<p style='color:orange'><b>🤖 Bot:</b> Aucun match trouvé.</p>");

        // Suggest closest team name
        QSqlQuery teamQuery("SELECT nom_equipe FROM EQUIPE");
        QStringList allTeams;
        while (teamQuery.next()) {
            allTeams << teamQuery.value(0).toString();
        }

        QString bestMatch;
        int minDistance = INT_MAX;
        QString input = teamName.toLower();

        for (const QString &team : allTeams) {
            int distance = levenshteinDistance(input, team.toLower());
            if (distance < minDistance) {
                minDistance = distance;
                bestMatch = team;
            }
        }

        if (minDistance <= 3 && bestMatch.compare(teamName, Qt::CaseInsensitive) != 0) {
            ui->chat_history->append(QString("<p style='color:gray'>🤖 Voulez-vous dire <b>%1</b> ?</p>").arg(bestMatch));
        }
    }

    ui->chat_input->clear();
}




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
void MainWindow::on_stat_clicked()
{
    QSqlQuery query;
    query.prepare(R"(
        SELECT nom_equipe, COUNT(*) AS total_matches
        FROM (
            SELECT nom_equipe1 AS nom_equipe FROM MATCHES
            UNION ALL
            SELECT nom_equipe2 AS nom_equipe FROM MATCHES
        )
        GROUP BY nom_equipe
    )");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de récupération des données de statistiques.");
        return;
    }

    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString team = query.value("nom_equipe").toString();
        int count = query.value("total_matches").toInt();
        series->append(team, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de matchs joués par chaque équipe");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QWidget *page2 = ui->stackedWidget->widget(1);
    QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(page2->layout());
    if (!layout) {
        layout = new QVBoxLayout(page2);
        page2->setLayout(layout);
    }

    // Clear only chart views from the layout, keep the Back button
    QList<QWidget*> widgetsToRemove;
    for (int i = 0; i < layout->count(); ++i) {
        QWidget *w = layout->itemAt(i)->widget();
        if (w && qobject_cast<QChartView *>(w)) {
            widgetsToRemove.append(w);
        }
    }

    for (QWidget *w : widgetsToRemove) {
        layout->removeWidget(w);
        delete w;
    }

    // Add the chart view *below* any existing widgets (like the back button)
    layout->addWidget(chartView);

    // Check if the retour button already exists
    QPushButton *backButton = nullptr;
    for (int i = 0; i < layout->count(); ++i) {
        QWidget *widget = layout->itemAt(i)->widget();
        if (widget && widget->objectName() == "retourButton") {
            backButton = qobject_cast<QPushButton *>(widget);
            break;
        }
    }

    // If the retour button does not exist, create it
    if (!backButton) {
        backButton = new QPushButton("Retour à la page principale", page2);
        backButton->setObjectName("retourButton");  // Set an object name to identify it
        layout->addWidget(backButton);
    }

    // Connect the back button's clicked signal to switch to Page 1
    connect(backButton, &QPushButton::clicked, this, [=]() {
        ui->stackedWidget->setCurrentIndex(0);  // Switch to Page 1 (index 0)
    });

    // Switch to Page 2
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::sortMatchesBy(const QString &criteria)
{
    QString orderBy;
    if (criteria == "ID") {
        orderBy = "ID_MATCH";
    } else if (criteria == "Date") {
        orderBy = "DATE_MATCH";
    } else if (criteria == "Stade") {
        orderBy = "STADE";
    } else {
        QMessageBox::warning(this, "Erreur", "Critère de tri inconnu.");
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT ID_MATCH, TO_CHAR(DATE_MATCH, 'YYYY-MM-DD') AS DATE_MATCH, HEURE_MATCH, STADE, SCORE, NOM_EQUIPE1, NOM_EQUIPE2 "
                          "FROM MATCHES ORDER BY %1 ASC").arg(orderBy));

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec du tri des matchs.");
        return;
    }

    model->setQuery(query);
    ui->tab_matches->setModel(model);
}
void MainWindow::on_comboBox_tri_currentIndexChanged(const QString &text)
{
    if (text == "-- Trier par --")
        return;

    sortMatchesBy(text);
}

void MainWindow::exportToHTML()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty())
        return;

    QSqlQueryModel *model = match->afficher();

    if (!model) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données.");
        return;
    }

    QString html;
    html += "<!DOCTYPE html><html><head><meta charset='utf-8'><style>";
    html += "table { border-collapse: collapse; width: 100%; font-family: Arial; }";
    html += "th, td { border: 1px solid #000; padding: 8px; text-align: left; }";
    html += "th { background-color: #f2f2f2; }";
    html += "</style></head><body>";
    html += "<h2>Liste des Matchs</h2>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Date</th><th>Heure</th><th>Stade</th><th>Score</th><th>Equipe 1</th><th>Equipe 2</th></tr>";

    for (int i = 0; i < model->rowCount(); ++i) {
        html += "<tr>";
        for (int j = 0; j < model->columnCount(); ++j) {
            html += "<td>" + model->index(i, j).data().toString() + "</td>";
        }
        html += "</tr>";
    }

    html += "</table></body></html>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès.");
}

void MainWindow::searchMatchesBy(const QString &field, const QString &value)
{

    QString sqlField;
    if (field == "ID") {
        sqlField = "ID_MATCH";
    } else if (field == "Nom Équipe") {
        sqlField = "NOM_EQUIPE1 || ' ' || NOM_EQUIPE2";  // Check both teams
    } else if (field == "Stade") {
        sqlField = "STADE";
    } else {
        QMessageBox::warning(this, "Erreur", "Critère de recherche inconnu.");
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString = QString("SELECT ID_MATCH, TO_CHAR(DATE_MATCH, 'YYYY-MM-DD') AS DATE_MATCH, HEURE_MATCH, STADE, SCORE, NOM_EQUIPE1, NOM_EQUIPE2 FROM MATCHES WHERE %1 LIKE :val").arg(sqlField);
    query.prepare(queryString);
    query.bindValue(":val", "%" + value + "%");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche.");
        return;
    }

    model->setQuery(query);
    ui->tab_matches->setModel(model);
}
void MainWindow::on_comboBox_chercher_currentIndexChanged(const QString &text)
{
    if (text == "-- Chercher par --")
        return;

    QString value = ui->search_lineedit->text().trimmed();
    searchMatchesBy(text, value);
}
void MainWindow::loadTeamNames() {
    // Clear in case it's being reloaded
    ui->nom_equipe1_combo->clear();
    ui->nom_equipe2_combo->clear();

    // Add default option
    QString defaultText = "Veuillez sélectionner l'équipe";
    ui->nom_equipe1_combo->addItem(defaultText);
    ui->nom_equipe2_combo->addItem(defaultText);

    // Load actual team names from the database
    QSqlQuery query("SELECT nom_equipe FROM EQUIPE");
    while (query.next()) {
        QString teamName = query.value(0).toString();
        ui->nom_equipe1_combo->addItem(teamName);
        ui->nom_equipe2_combo->addItem(teamName);
    }

    // Set default selected index
    ui->nom_equipe1_combo->setCurrentIndex(0);
    ui->nom_equipe2_combo->setCurrentIndex(0);
}
void MainWindow::setupTeamComboValidation() {
    connect(ui->nom_equipe1_combo, &QComboBox::currentTextChanged, this, [=]() {
        if (ui->nom_equipe1_combo->currentText() == ui->nom_equipe2_combo->currentText()) {
            QMessageBox::warning(this, "Erreur", "Les deux équipes ne peuvent pas être identiques.");
            ui->nom_equipe2_combo->setCurrentIndex(-1); // Deselect
        }
    });

    connect(ui->nom_equipe2_combo, &QComboBox::currentTextChanged, this, [=]() {
        if (ui->nom_equipe1_combo->currentText() == ui->nom_equipe2_combo->currentText()) {
            QMessageBox::warning(this, "Erreur", "Les deux équipes ne peuvent pas être identiques.");
            ui->nom_equipe1_combo->setCurrentIndex(-1); // Deselect
        }
    });
}
int levenshteinDistance(const QString &s1, const QString &s2) {
    const int len1 = s1.length();
    const int len2 = s2.length();
    QVector<QVector<int>> d(len1 + 1, QVector<int>(len2 + 1));

    for (int i = 0; i <= len1; ++i)
        d[i][0] = i;
    for (int j = 0; j <= len2; ++j)
        d[0][j] = j;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = std::min({
                d[i - 1][j] + 1,
                d[i][j - 1] + 1,
                d[i - 1][j - 1] + cost
            });
        }
    }
    return d[len1][len2];
}
