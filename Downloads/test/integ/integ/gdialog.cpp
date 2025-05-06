#include "gdialog.h"
#include "ui_gdialog.h"
#include "dialog.h"
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsLayout>
#include <QLayout>
#include <QGraphicsDropShadowEffect>
#include <qprogressdialog.h>
#include <QStandardPaths>
#include <QFileDialog>
#include <QPrinter>
#include <QDesktopServices>
#include <QTextTableCell>
#include <QBarSet>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <qapplication.h>
#include <QChartView>
#include "arduino.h"
#include <QThread>
gdialog::gdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gdialog),
    chartView(nullptr),
    arduino(new Arduino())
{
    ui->setupUi(this);
    on_display_clicked();
    if(arduino->connect_arduino() == 0) {
        qDebug() << "Arduino connected successfully";
    } else {
        qDebug() << "Arduino connection failed";
    }


    QTimer::singleShot(100, this, &gdialog::updateStatistics);
    connect(ui->tableView, &QTableView::clicked, this, &gdialog::on_tableView_clicked);
}


gdialog::~gdialog()
{

    if(arduino) {
        arduino->close_arduino();
        delete arduino;
    }
    if (chartView)
    {
       delete chartView;
    }
    delete ui;
}

// arduino setup code
/*void gdialog::setupArduino() {
    int connectionStatus = arduino->connect_arduino();
    if(connectionStatus != 0) {
        QMessageBox::warning(this, "Arduino Error",
                             "Failed to connect to Arduino!\n"
                             "1. Check USB cable connection\n"
                             "2. Verify Arduino is powered on\n"
                             "3. Check port configuration");
    }
}*/

void gdialog::on_tableView_clicked(const QModelIndex &index) {
    int row = index.row();
    QAbstractItemModel *model = ui->tableView->model();

    ui->id->setText(model->index(row, 0).data().toString());                 // ID
    ui->nom_stade->setText(model->index(row, 1).data().toString());         // Établissement
    ui->zone->setText(model->index(row, 2).data().toString());              // Zone
    ui->prix_billet->setText(model->index(row, 3).data().toString());       // Prix
    ui->Date->setDateTime(model->index(row, 4).data().toDateTime());        // Date/Heure
    ui->num_place->setText(model->index(row, 5).data().toString());         // Num Place
}

void gdialog::on_add_clicked()
{
    // Verify all fields are filled
    if (ui->num_place->text().isEmpty() ||
        ui->zone->text().isEmpty() ||
        ui->nom_stade->text().isEmpty() ||
        ui->prix_billet->text().isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs!");
        return;
    }

    // Validate seat number
    bool ok;
    int nb = ui->num_place->text().toInt(&ok);
    if (!ok || nb <= 0 || nb > 10000)
    {
        QMessageBox::warning(this, "Numéro invalide",
                             "Le numéro de place doit:\n"
                             "- Être un nombre entier\n"
                             "- Entre 1 et 10000");
        ui->num_place->setFocus();
        return;
    }

    // Validate price
    float prix = ui->prix_billet->text().toFloat(&ok);
    if (!ok || prix < 0.01f || prix > 1000.0f)
    {
        QMessageBox::warning(this, "Prix invalide",
                             "Le prix doit:\n"
                             "- Être un nombre décimal\n"
                             "- Entre 0.01€ et 1000.00€");
        ui->prix_billet->setFocus();
        return;
    }

    // Get and validate text fields
    QDateTime date = ui->Date->dateTime();
    QString zone = ui->zone->text().trimmed();
    QString stade = ui->nom_stade->text().trimmed();

    // Validate zone (text only)
    QRegularExpression zoneRegex("^[\\p{L}\\s\\-'’]{2,20}$", QRegularExpression::UseUnicodePropertiesOption);
    if (!zoneRegex.match(zone).hasMatch())
    {
        QMessageBox::warning(this, "Zone invalide",
                             "La zone doit contenir:\n"
                             "- 2 à 20 caractères\n"
                             "- Lettres seulement (pas de chiffres)\n"
                             "- Espaces, tirets (-) et apostrophes (’) autorisés");
        ui->zone->setFocus();
        return;
    }

    // Validate stadium name (text only)
    QRegularExpression stadeRegex("^[\\p{L}\\s\\-'’]{3,30}$", QRegularExpression::UseUnicodePropertiesOption);
    if (!stadeRegex.match(stade).hasMatch())
    {
        QMessageBox::warning(this, "Stade invalide",
                             "Le nom du stade doit contenir:\n"
                             "- 3 à 30 caractères\n"
                             "- Lettres seulement (pas de chiffres)\n"
                             "- Espaces, tirets (-) et apostrophes (’) autorisés");
        ui->nom_stade->setFocus();
        return;
    }

    // Validate date
    if (date < QDateTime::currentDateTime())
    {
        QMessageBox::warning(this, "Date erronée",
                             "La date de l'événement ne peut pas être dans le passé!");
        ui->Date->setFocus();
        return;
    }

    // Create and add ticket
    Billet b(stade, zone, prix, date, nb);

    if (b.ajouter_billet())
    {
        QMessageBox::information(this, "Succès", "Billet ajouté avec succès!");

        // Clear inputs
        ui->num_place->clear();
        ui->prix_billet->clear();
        ui->zone->clear();
        ui->nom_stade->clear();
        ui->Date->setDateTime(QDateTime::currentDateTime());

        // Refresh display
        on_display_clicked();
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du billet!");
    }
}


void gdialog::on_display_clicked()
{
    QSqlQueryModel *model = Billet::afficher_billets();

    if (model == nullptr) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les billets!");

    }
    else {
        qDebug() << "Model data fetched successfully.";
        // Ensure all columns are visible
        for (int i = 0; i < model->columnCount(); ++i) {
            ui->tableView->setColumnHidden(i, false);
        }

    }
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
    ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model->setParent(ui->tableView);
}



void gdialog::on_delete_2_clicked() {
    QString idText = ui->id->text().trimmed();

    // Input validation (keep your existing checks)
    if(idText.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un ID à supprimer!");
        ui->id->setFocus();
        return;
    }

    bool ok;
    int id = idText.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre positif!");
        ui->id->setFocus();
        return;
    }

    if(Billet::supprimer_billet(id, this)) {
        // Activate buzzer if Arduino is connected
        if(arduino && arduino->getserial()->isOpen()) {
            // Turn on buzzer
            arduino->write_to_arduino("1");

            // Turn off buzzer after 1 second
            QTimer::singleShot(1000, [this]() {
                arduino->write_to_arduino("0");
            });
        }

        QMessageBox::information(this, "Succès", "Billet #" + QString::number(id) + " supprimé!");
        ui->id->clear();
        on_display_clicked();
    }
}


void gdialog::on_modif_clicked()
{
    // Get and validate ID input
    QString idText = ui->id->text().trimmed();
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un ID à modifier!");
        ui->id->setFocus();
        return;
    }

    bool ok;
    int id = idText.toInt(&ok);
    if (!ok || id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre positif!");
        ui->id->setFocus();
        return;
    }

    // Validate other inputs
    if (ui->nom_stade->text().isEmpty() ||
        ui->zone->text().isEmpty() ||
        ui->prix_billet->text().isEmpty() ||
        ui->num_place->text().isEmpty())
    {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir tous les champs!");
        return;
    }

    // Convert numeric inputs
    float prix = ui->prix_billet->text().toFloat(&ok);
    if (!ok || prix <= 0) {
        QMessageBox::warning(this, "Prix invalide", "Le prix doit être un nombre positif!");
        ui->prix_billet->setFocus();
        return;
    }

    int numPlace = ui->num_place->text().toInt(&ok);
    if (!ok || numPlace <= 0) {
        QMessageBox::warning(this, "Numéro de place invalide", "Le numéro de place doit être un entier positif!");
        ui->num_place->setFocus();
        return;
    }

    // Get other values
    QDateTime date = ui->Date->dateTime();
    QString zone = ui->zone->text().trimmed();
    QString stade = ui->nom_stade->text().trimmed();

    // Call the modification function
    if (Billet::modifier_billet(id, stade, zone, prix, date, numPlace, this)) {
        QMessageBox::information(this, "Succès", "Billet #" + QString::number(id) + " modifié avec succès!");
        ui->id->clear();
        on_display_clicked();  // Refresh the display
    }
}

void gdialog::on_export_2_clicked()
{
    // Set default file path
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString defaultFileName = QString("/billets_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss"));

    // Get save file name
    QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter en PDF",
        desktopPath + defaultFileName,
        "Fichiers PDF (*.pdf)");

    if (fileName.isEmpty()) {
        return; // User cancelled
    }

    // Ensure PDF extension
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) {
        fileName += ".pdf";
    }

    // Create printer
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Landscape);

    // Create text document
    QTextDocument doc;
    QTextCursor cursor(&doc);

    // Add title
    QTextCharFormat titleFormat;
    titleFormat.setFont(QFont("Arial", 16, QFont::Bold));
    cursor.insertText("Liste des Billets\n", titleFormat);

    // Add date
    cursor.insertText(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "\n\n");

    // Create table
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setCellPadding(4);
    tableFormat.setCellSpacing(0);
    tableFormat.setBorder(1);
    tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
    tableFormat.setHeaderRowCount(1);

    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter!");
        return;
    }

    int rows = model->rowCount();
    int cols = model->columnCount();

    QTextTable *table = cursor.insertTable(rows + 1, cols, tableFormat);

    // Add headers
    QTextCharFormat headerFormat;
    headerFormat.setFont(QFont("Arial", 10, QFont::Bold));
    headerFormat.setBackground(Qt::lightGray);

    for (int col = 0; col < cols; ++col) {
        QTextTableCell cell = table->cellAt(0, col);
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(model->headerData(col, Qt::Horizontal).toString(), headerFormat);
    }

    // Add data
    QTextCharFormat dataFormat;
    dataFormat.setFont(QFont("Arial", 9));

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            QModelIndex index = model->index(row, col);
            QTextTableCell cell = table->cellAt(row + 1, col);
            QTextCursor cellCursor = cell.firstCursorPosition();
            cellCursor.insertText(model->data(index).toString(), dataFormat);
        }
    }

    // Print to PDF
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    // Show success message
    QMessageBox::information(this, "Export réussi",
                             QString("Le tableau a été exporté avec succès vers:\n%1").arg(fileName));

    // Open the containing folder
    QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(fileName).path()));
}


void gdialog::on_search_clicked()
{
    // Get the place number from UI
    QString numPlaceText = ui->recherche->text().trimmed(); // Assuming you have a QLineEdit named searchLineEdit

    if (numPlaceText.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un numéro de place à rechercher!");
        ui->recherche->setFocus();
        return;
    }

    bool ok;
    int numPlace = numPlaceText.toInt(&ok);
    if (!ok || numPlace <= 0) {
        QMessageBox::warning(this, "Numéro invalide", "Le numéro de place doit être un entier positif!");
        ui->recherche->setFocus();
        return;
    }

    // Perform the search
    QSqlQueryModel *searchModel = Billet::searchByNumPlace(numPlace);

    if (!searchModel) {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la recherche!");
        return;
    }

    if (searchModel->rowCount() == 0) {
        QMessageBox::information(this, "Résultat", "Aucun billet trouvé pour le numéro de place " + QString::number(numPlace));
        delete searchModel;
        return;
    }

    // Display results in the table view
    ui->tableView->setModel(searchModel);

    // Optional: Adjust column widths
    ui->tableView->resizeColumnsToContents();

    // Connect model deletion to table view destruction
    searchModel->setParent(ui->tableView);

    // Show result count in status bar or label if you have one
    //ui->statusLabel->setText(QString("%1 résultats trouvés").arg(searchModel->rowCount()));
    ui->recherche->clear();
}


void gdialog::on_ref_clicked()
{
    QSqlQueryModel *model = Billet::afficher_billets();

    if (model == nullptr) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les billets!");
        return;
    }
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSortingEnabled(true);
    model->setParent(ui->tableView);
}


void gdialog::on_sort_clicked()
{
    static bool ascending = true; // Toggle state

    QSqlQueryModel *sortedModel = nullptr;

    if (ascending) {
        sortedModel = Billet::sortByNumPlaceAsc();
        ui->sort->setText("Trier ▼"); // Down arrow for descending
    } else {
        sortedModel = Billet::sortByNumPlaceDesc();
        ui->sort->setText("Trier ▲"); // Up arrow for ascending
    }

    ascending = !ascending; // Toggle state

    if (sortedModel) {
        ui->tableView->setModel(sortedModel);
        ui->tableView->resizeColumnsToContents();
        sortedModel->setParent(ui->tableView);
    }
}

void gdialog::updateStatistics()
{
    // Clear previous chart if exists
    if (chartView) {
        ui->stat->layout()->removeWidget(chartView);
        delete chartView;
        chartView = nullptr;
    }

    // Create new chart by zone
    chartView = createZoneStatChart();
    /*if (!chartView) {
        ui->stat->setText("Aucune donnée disponible par zone");
        ui->stat->setStyleSheet("color: red; font-weight: bold;");
        return;
    }*/

    // Configure layout
    if (!ui->stat->layout()) {
        QVBoxLayout *layout = new QVBoxLayout(ui->stat);
        layout->setContentsMargins(0, 0, 0, 0);
        ui->stat->setLayout(layout);
    }
    ui->stat->layout()->addWidget(chartView);
}

QChartView* gdialog::createZoneStatChart()
{
    // Get data from database
    QMap<QString, int> zoneCounts;
    QSqlQuery query;

    if (!query.exec("SELECT zone, COUNT(*) FROM billets GROUP BY zone")) {
        qDebug() << "Query error:" << query.lastError().text();
        return nullptr;
    }

    while (query.next()) {
        QString zone = query.value(0).toString();
        int count = query.value(1).toInt();
        zoneCounts[zone] = count;
    }

    if (zoneCounts.isEmpty()) {
        return nullptr;
    }

    // Prepare data vectors
    QStringList zones = zoneCounts.keys();
    QVector<int> counts;
    for (const QString &zone : zones) {
        counts.append(zoneCounts.value(zone));
    }

    // Create chart with professional styling
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Billets par zone");

    // Color palette
    QVector<QColor> colors = {
        QColor("#4285F4"), // Blue
        QColor("#34A853"), // Green
        QColor("#FBBC05"), // Yellow
        QColor("#EA4335"), // Red
        QColor("#673AB7")  // Purple
    };

    for (int i = 0; i < counts.size(); i++) {
        *set << counts[i];
        set->setColor(colors[i % colors.size()]);
    }
    series->append(set);

    // Configure chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des billets par zone");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // This assumes ui->stat is a QWidget or QFrame with no layout yet
    QVBoxLayout *layout = new QVBoxLayout(ui->stat);
    layout->addWidget(chartView);
    // X-axis configuration
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(zones);
    axisX->setTitleText("Zone");
    axisX->setLabelsFont(QFont("Arial", 9));
    axisX->setLabelsColor(QColor("#333333"));

    // Y-axis configuration
    int maxCount = *std::max_element(counts.begin(), counts.end());
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxCount * 1.1); // 10% padding
    axisY->setTitleText("Nombre de billets");
    axisY->setLabelFormat("%d");
    axisY->setLabelsFont(QFont("Arial", 8));

    // Add axes and labels
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Value labels on bars
    for (int i = 0; i < counts.size(); i++) {
        QGraphicsSimpleTextItem *label = new QGraphicsSimpleTextItem(QString::number(counts[i]), chart);
        label->setPos(i + 0.3, counts[i] - 15);
        label->setFont(QFont("Arial", 8, QFont::Bold));
        label->setBrush(QBrush(Qt::black));
    }

    // Create and style chart view
    chartView->setRenderHint(QPainter::Antialiasing);

    // Shadow effect
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect();
    effect->setBlurRadius(8);
    effect->setOffset(2, 2);
    chartView->setGraphicsEffect(effect);

    return chartView;
}



void gdialog::on_tirageButton_clicked()
{

    Billet billet;

    bool success = billet.tirageAuSort(this);

    if (!success) {
        qDebug() << "Tirage au sort failed";
    }
    on_display_clicked();
}


void gdialog::on_quit_clicked()
{
    QApplication::quit();
}

#include "mainwindow.h"
void gdialog::on_pushButton_2_clicked()
{
    hide();
    MainWindow *Mainw;
        Mainw = new MainWindow (this);
        Mainw->show();
}
#include "pagejoueur.h"
void gdialog::on_pushButton_4_clicked()
{
    hide();
    pagejoueur *Pagejoueur;
        Pagejoueur = new pagejoueur (this);
        Pagejoueur->show();
}
#include "pagesupp.h"
void gdialog::on_pushButton_5_clicked()
{
    hide();
    pagesupp *Pagesup;
        Pagesup = new pagesupp (this);
        Pagesup->show();
}

void gdialog::on_test_clicked()
{
    // Input validation
    QString idText = ui->id->text().trimmed();
    if(idText.isEmpty()) {
        QMessageBox::warning(this, "Champ vide", "Veuillez entrer un ID à supprimer!");
        ui->id->setFocus();
        return;
    }

    // ID format validation
    bool ok;
    int id = idText.toInt(&ok);
    if(!ok || id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre positif!");
        ui->id->setFocus();
        return;
    }

    // Verify ID existence
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM BILLETS WHERE ID = :id");
    checkQuery.bindValue(":id", id);

    if(!checkQuery.exec() || !checkQuery.next()) {
        QMessageBox::critical(this, "Erreur", "Échec de la vérification ID: " + checkQuery.lastError().text());
        return;
    }

    if(checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "ID introuvable", "Aucun billet trouvé avec cet ID!");
        ui->id->setFocus();
        return;
    }

    // Update status in database
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE BILLETS SET STATUS = 'annulé' WHERE ID = :id");
    updateQuery.bindValue(":id", id);

    if(!updateQuery.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour: " + updateQuery.lastError().text());
        return;
    }

    // Check if any rows were affected
    if(updateQuery.numRowsAffected() > 0) {
        // Activate buzzer if Arduino is connected
        if(arduino && arduino->getserial()->isOpen()) {
            // Send activation command with newline terminator
            arduino->write_to_arduino("A");

            // Ensure data is fully written
            arduino->getserial()->flush();
            if(arduino->getserial()->waitForBytesWritten(1000)) {
                qDebug() << "Buzzer activation signal sent successfully";

                // Optional: Verify Arduino response
                if(arduino->getserial()->waitForReadyRead(500)) {
                    QByteArray response = arduino->read_from_arduino();
                    qDebug() << "Arduino response:" << response;
                }
            }
            else {
                qDebug() << "Failed to write to Arduino!";
                QMessageBox::warning(this, "Avertissement",
                                     "Le statut a été mis à jour mais le buzzer n'a pas pu être activé!");
            }
        }
        else {
            qDebug() << "Arduino not connected!";
            QMessageBox::information(this, "Succès",
                                     "Statut mis à jour (buzzer non activé - Arduino déconnecté)");
        }

        // Update UI
        QMessageBox::information(this, "Succès", "Statut mis à jour avec succès!");
        on_display_clicked();
        ui->id->clear();
    }
    else {
        QMessageBox::warning(this, "Avertissement",
                             "Aucun changement effectué - le statut était déjà 'annulé'!");
    }
}
