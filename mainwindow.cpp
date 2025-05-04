#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QMenu>
#include<QPageLayout>
#include <QPageSize>
#include<QFile>
#include<QDateTime>
#include<QDir>
#include<QTextStream>
#include<QMap>
#include <QAbstractItemModel>
#include "statwindow.h"
#include "smsservice.h"



QStringList MainWindow::getTeamNamesFromDatabase() {
    QStringList teams;
    QSqlQuery query;

    // Use the correct table and column names (EQUIPE.NOM_EQUIPE)
    if (query.exec("SELECT NOM_EQUIPE FROM EQUIPE ORDER BY NOM_EQUIPE")) {
        while (query.next()) {
            teams << query.value(0).toString();
        }
    } else {
        qDebug() << "Database error:" << query.lastError().text();
        // Fallback to default values if query fails
        teams = {"barcelona", "real madrid", "dortmund"};
    }

    return teams;
}
void MainWindow::initializeComboBox() {
    QStringList teams = getTeamNamesFromDatabase();
    ui->comboBox->addItems(teams);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr)
    , selectedId(-1)
    , smsService(new SmsService(this))
{
    ui->setupUi(this);

    // Initialize UI elements
    ui->comboBox_2->addItems({"VIP", "Regular", "Premium"});
    //ui->comboBox->addItems({"barcelone", "real madrid", "dortmund"});
    initializeComboBox();
    ui->dateEdit->setDate(QDate::currentDate());

    // Set up the table
    setupTable();

    // Connect navigation buttons
    connect(ui->supporter, &QPushButton::clicked, this, &MainWindow::on_supporter_clicked);
    connect(ui->equipe, &QPushButton::clicked, this, &MainWindow::on_equipe_clicked);
    connect(ui->joueur, &QPushButton::clicked, this, &MainWindow::on_joueur_clicked);
    connect(ui->match, &QPushButton::clicked, this, &MainWindow::on_match_clicked);
    connect(ui->billets, &QPushButton::clicked, this, &MainWindow::on_billets_clicked);
}

void MainWindow::setupTable()
{
    model = new QSqlTableModel(this);
    model->setTable("SUPPORTER");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // Set headers
    model->setHeaderData(1, Qt::Horizontal, tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, tr("Telephone"));
    model->setHeaderData(4, Qt::Horizontal, tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, tr("Points"));
    model->setHeaderData(7, Qt::Horizontal, tr("Date Naissance"));
    model->setHeaderData(8, Qt::Horizontal, tr("Equipe"));

    if(!model->select()) {
        QMessageBox::critical(this, "Error", "Failed to load data: " + model->lastError().text());
    }

    ui->tableView->setModel(model);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->hideColumn(0); // Hide ID column
}

void MainWindow::refreshTable()
{
    model->select();
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::clearForm()
{
    ui->lineEdit_Nom->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_Nom_4->clear();
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox_2->setCurrentIndex(0);
    ui->comboBox->setCurrentIndex(0);
    selectedId = -1;
}

bool MainWindow::validateForm()
{
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString prenom = ui->lineEdit_prenom->text().trimmed();
    QRegularExpression nameRegex("^[a-zA-ZÀ-ÿ\\-]+(\\s[a-zA-ZÀ-ÿ\\-]+)*$");
    // Check empty fields
    if(ui->lineEdit_Nom->text().isEmpty() ||  ui->lineEdit_Nom->text().length() < 2 || !nameRegex.match(nom).hasMatch() || !nameRegex.match(prenom).hasMatch() || prenom.contains("--") || prenom.contains("''") || prenom.contains("  ")) {
        QMessageBox::warning(this, "Warning", "Please enter last name!");
        ui->lineEdit_Nom->setFocus();
        return false;
    }

    if(ui->lineEdit_prenom->text().isEmpty() || ui->lineEdit_Nom->text().length() < 2||!nameRegex.match(prenom).hasMatch() || prenom.contains("--") || prenom.contains("''") || prenom.contains("  ")) {
        QMessageBox::warning(this, "Warning", "Please enter first name!");
        ui->lineEdit_prenom->setFocus();
        return false;
    }

    if(ui->lineEdit_mail->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter email address!");
        ui->lineEdit_mail->setFocus();
        return false;
    }

    if(ui->lineEdit_Nom_4->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter phone number!");
        ui->lineEdit_Nom_4->setFocus();
        return false;
    }

    // Validate email format
    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if(!emailRegex.match(ui->lineEdit_mail->text()).hasMatch()) {
        QMessageBox::warning(this, "Warning", "Please enter a valid email address!");
        ui->lineEdit_mail->setFocus();
        ui->lineEdit_mail->selectAll();
        return false;
    }

    // Validate phone number format (international format)
    QString phone = ui->lineEdit_Nom_4->text().trimmed();
    QRegularExpression phoneRegex("^\\+\\d{10,15}$");
    if(!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Warning",
                             "Phone number must be in international format:\n"
                             "Examples: +212612345678 or +33612345678\n"
                             "Start with '+' followed by 10-15 digits");
        ui->lineEdit_Nom_4->setFocus();
        ui->lineEdit_Nom_4->selectAll();
        return false;
    }

    // Validate name fields (minimum 2 characters)
    if(ui->lineEdit_Nom->text().length() < 2) {
        QMessageBox::warning(this, "Warning", "Last name must be at least 2 characters!");
        ui->lineEdit_Nom->setFocus();
        ui->lineEdit_Nom->selectAll();
        return false;
    }

    if(ui->lineEdit_prenom->text().length() < 2) {
        QMessageBox::warning(this, "Warning", "First name must be at least 2 characters!");
        ui->lineEdit_prenom->setFocus();
        ui->lineEdit_prenom->selectAll();
        return false;
    }

    return true;
}

/*void MainWindow::on_ajouter_clicked()
{
    if(!validateForm()) return;

    supp.setNom(ui->lineEdit_Nom->text());
    supp.setPrenom(ui->lineEdit_prenom->text());
    supp.setEmail(ui->lineEdit_mail->text());
    supp.setTel(ui->lineEdit_Nom_4->text());
    supp.setTypesupp(ui->comboBox_2->currentText());
    //supp.setequipe(ui->comboBox->currentText());
    supp.setDob(ui->dateEdit->date());
    supp.setPointFidelite(0); // Default points

    if(supp.ajouter()) {
        QMessageBox::information(this, "Success", "Supporter added successfully!");
        refreshTable();
        clearForm();
    } else {
        QMessageBox::critical(this, "Error", "Failed to add supporter!");
    }
}*/
void MainWindow::on_ajouter_clicked()
{
    if(!validateForm()) return;

    // Set supporter data from UI
    supp.setNom(ui->lineEdit_Nom->text());
    supp.setPrenom(ui->lineEdit_prenom->text());
    supp.setEmail(ui->lineEdit_mail->text());
    supp.setTel(ui->lineEdit_Nom_4->text());  // Assuming this is the phone number field
    supp.setTypesupp(ui->comboBox_2->currentText());
    supp.setDob(ui->dateEdit->date());
    supp.setPointFidelite(0); // Default points

    if(supp.ajouter()) {
        QMessageBox::information(this, "Success", "Supporter added successfully!");
        refreshTable();
        clearForm();

        // SMS Notification
        QString phone = ui->lineEdit_Nom_4->text().trimmed(); // Get phone from the form
        QString message = tr("Dear %1 %2, thank you for registering as a supporter!").arg(supp.getPrenom()).arg(supp.getNom());

        if (!phone.isEmpty()) {
            if (smsService->sendSms(phone, message)) {
                statusBar()->showMessage(tr("SMS notification sent to %1").arg(phone), 3000);
            } else {
                statusBar()->showMessage(tr("Failed to send SMS to %1").arg(phone), 3000);
            }
        } else {
            statusBar()->showMessage("Supporter added but no phone number for SMS", 3000);
        }
    } else {
        QMessageBox::critical(this, "Error", "Failed to add supporter!");
    }
}
void MainWindow::on_annuler_clicked()
{
    clearForm();
}

void MainWindow::on_brecherche_clicked()
{
    QString searchText = ui->recherche->toPlainText().trimmed();

    if(!searchText.isEmpty()) {
        QString filter = QString("nom LIKE '%%1%' OR prenom LIKE '%%1%' OR e_mail LIKE '%%1%'")
        .arg(searchText.replace("'", "''"));
        model->setFilter(filter);
    } else {
        model->setFilter("");
    }

    if(!model->select()) {
        QMessageBox::warning(this, "Warning", "Search failed: " + model->lastError().text());
    }
}

void MainWindow::on_tri_clicked()
{
    QMenu menu(this);
    QAction *sortName = menu.addAction("Sort by Name");
    QAction *sortPrenom = menu.addAction("Sort by First Name");
    QAction *sortDob = menu.addAction("Sort by Birth Date");
    QAction *sortPoints = menu.addAction("Sort by Points");

    QPoint pos = ui->tri->mapToGlobal(QPoint(0, ui->tri->height()));
    QAction *selected = menu.exec(pos);

    if(selected == sortName) {
        model->setSort(1, Qt::AscendingOrder);
    } else if(selected == sortPrenom) {
        model->setSort(2, Qt::AscendingOrder);
    } else if(selected == sortDob) {
        model->setSort(7, Qt::AscendingOrder);
    } else if(selected == sortPoints) {
        model->setSort(6, Qt::DescendingOrder);
    }

    model->select();
}

void MainWindow::on_supprimer_clicked()
{
    QModelIndexList selected = ui->tableView->selectionModel()->selectedRows();
    if(selected.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please select a supporter to delete!");
        return;
    }

    int row = selected.first().row();
    int id = model->data(model->index(row, 0)).toInt();

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirm Delete", "Are you sure you want to delete this supporter?",
        QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes) {
        if(supp.supprimer(id)) {
            QMessageBox::information(this, "Success", "Supporter deleted successfully!");
            refreshTable();
            clearForm();
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete supporter!");
        }
    }
}

void MainWindow::on_modifier_clicked()
{
    if(selectedId == -1) {
        QMessageBox::warning(this, "Warning", "Please select a supporter to modify!");
        return;
    }

    if(!validateForm()) return;

    if(supp.modifier(selectedId,
                      ui->lineEdit_Nom->text(),
                      ui->lineEdit_prenom->text(),
                      ui->lineEdit_Nom_4->text(),
                      ui->lineEdit_mail->text(),
                      ui->comboBox_2->currentText(),
                      0, // Points not editable in form
                      ui->dateEdit->date(),
                      ui->comboBox->currentText())) {
        QMessageBox::information(this, "Success", "Supporter updated successfully!");
        refreshTable();
        clearForm();
    } else {
        QMessageBox::critical(this, "Error", "Failed to update supporter!");
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(!index.isValid()) return;

    int row = index.row();
    selectedId = model->data(model->index(row, 0)).toInt();

    ui->lineEdit_Nom->setText(model->data(model->index(row, 1)).toString());
    ui->lineEdit_prenom->setText(model->data(model->index(row, 2)).toString());
    ui->lineEdit_mail->setText(model->data(model->index(row, 4)).toString());
    ui->lineEdit_Nom_4->setText(model->data(model->index(row, 3)).toString());
    ui->comboBox_2->setCurrentText(model->data(model->index(row, 5)).toString());
    ui->dateEdit->setDate(model->data(model->index(row, 7)).toDate());
    ui->comboBox->setCurrentText(model->data(model->index(row, 8)).toString());
}

void MainWindow::on_generatePdf_clicked()
{
    // Set default filename with current date/time
    QString defaultFileName = QString("Report_%1.pdf")
                                  .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));

    // Get save file path with better dialog options
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Save PDF Document"),
        QDir::homePath() + "/" + defaultFileName,
        tr("PDF Files (*.pdf);;All Files (*)"));

    if(filePath.isEmpty()) {
        return;
    }

    // Ensure the file has the .pdf extension
    if(!filePath.endsWith(".pdf", Qt::CaseInsensitive)) {
        filePath += ".pdf";
    }

    // Initialize printer with better settings
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageOrientation(QPageLayout::Portrait);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setFullPage(true);

    // Create painter with error handling
    QPainter painter;
    if(!painter.begin(&printer)) {
        QMessageBox::critical(this, tr("Error"), tr("Could not create PDF document!"));
        return;
    }

    try {
        // Get page rectangle as QRectF (floating-point)
        QRectF pageRect = printer.pageRect(QPrinter::DevicePixel);

        // Calculate scaling factors
        double xscale = pageRect.width() / ui->tableView->width();
        double yscale = pageRect.height() / ui->tableView->height();
        double scale = qMin(xscale, yscale);

        painter.translate(pageRect.center());
        painter.scale(scale, scale);
        painter.translate(-ui->tableView->width()/2, -ui->tableView->height()/2);

        ui->tableView->render(&painter);
        painter.end();

        QMessageBox::information(
            this,
            tr("Success"),
            tr("PDF generated successfully!\nSaved to: %1").arg(filePath));
    }
    catch (...) {
        painter.end();
        QFile::remove(filePath);
        QMessageBox::critical(this, tr("Error"), tr("Failed to generate PDF!"));
    }
}



void MainWindow::on_statButton_clicked()
{
    // Get the model from your tableView
    QAbstractItemModel *model = ui->tableView->model();

    // Create and show the statistics window
    StatWindow *statWindow = new StatWindow(this, model);
    statWindow->setAttribute(Qt::WA_DeleteOnClose);
    statWindow->exec();
}



// Navigation functions
void MainWindow::on_supporter_clicked() { ui->stackedWidget->setCurrentIndex(0); }
void MainWindow::on_equipe_clicked() { ui->stackedWidget->setCurrentIndex(1); }
void MainWindow::on_joueur_clicked() { ui->stackedWidget->setCurrentIndex(2); }
void MainWindow::on_match_clicked() { ui->stackedWidget->setCurrentIndex(3); }
void MainWindow::on_billets_clicked() { ui->stackedWidget->setCurrentIndex(4); }

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}
