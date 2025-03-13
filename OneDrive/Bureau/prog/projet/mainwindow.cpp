#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QIntValidator>
#include <QPixmap>
#include <QTableWidgetItem>
#include <QMenu>  // Added for context menu
#include <QAction>  // Added for context menu

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up the table widget
    populateTableWidget();

    // Automatically resize columns based on their content
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Set up input validation for the team name and origin
    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEdit_Nom->setValidator(validator);
    ui->lineEdit_Origin->setValidator(validator);

    // Set maximum length for input fields
    ui->lineEdit_Nom->setMaxLength(50);
    ui->lineEdit_Origin->setMaxLength(50);

    // Connect textChanged signals to slots for formatting
    connect(ui->lineEdit_Nom, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Nom_textChanged);
    connect(ui->lineEdit_Origin, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Origin_textChanged);

    // Set up integer validators for score components (W, L, D)
    QIntValidator *validatorW = new QIntValidator(this);
    QIntValidator *validatorL = new QIntValidator(this);
    QIntValidator *validatorD = new QIntValidator(this);

    ui->lineEdit_W->setValidator(validatorW);
    ui->lineEdit_L->setValidator(validatorL);
    ui->lineEdit_D->setValidator(validatorD);

    // Set ranges for score components
    validatorW->setRange(0, 999);
    validatorL->setRange(0, 999);
    validatorD->setRange(0, 999);

    // Load images from your computer
    QPixmap logo("C:\\Users\\rayen\\Downloads\\Screenshot_2025-01-26_014639-removebg-preview.png");
    ui->logoo->setPixmap(logo);
    ui->logoo->setScaledContents(true);

    QPixmap home("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021115-removebg-preview.png");
    ui->home->setPixmap(home);
    ui->home->setScaledContents(true);

    QPixmap set("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021120-removebg-preview.png");
    ui->set->setPixmap(set);
    ui->set->setScaledContents(true);

    QPixmap filter("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212956-removebg-preview.png");
    ui->filter->setPixmap(filter);
    ui->filter->setScaledContents(true);

    QPixmap pattern("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212952-removebg-preview.png");
    ui->pattern->setPixmap(pattern);
    ui->pattern->setScaledContents(true);

    QPixmap chart("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_215513-removebg-preview.png");
    ui->chart->setPixmap(chart);
    ui->chart->setScaledContents(true);

    QPixmap first("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_220804-removebg-preview.png");
    ui->first->setPixmap(first);
    ui->first->setScaledContents(true);

    QPixmap ysar("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223231-removebg-preview.png");
    ui->ysar->setPixmap(ysar);
    ui->ysar->setScaledContents(true);

    QPixmap ymin("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223234-removebg-preview.png");
    ui->ymin->setPixmap(ymin);
    ui->ymin->setScaledContents(true);

    // Connect the cellChanged signal to the slot
    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);

    // Enable custom context menu for the table widget
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);

    // Connect the customContextMenuRequested signal to the slot
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateTableWidget()
{
    // Fetch data from the database
    QSqlQueryModel* model = Etmp.read();

    // Set the number of rows and columns in the table widget
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount() - 1); // Exclude the ID column

    // Set headers (skip the first column, which is the ID)
    QStringList headers;
    for (int col = 1; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the table widget with data (skip the first column, which is the ID)
    for (int row = 0; row < model->rowCount(); ++row) {
        // Store the ID in the first column as hidden data
        int id = model->data(model->index(row, 0)).toInt();
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(id));
        idItem->setData(Qt::UserRole, id); // Store the ID in the item's user data
        ui->tableWidget->setVerticalHeaderItem(row, idItem); // Store ID in the vertical header

        // Populate the visible columns
        for (int col = 1; col < model->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget->setItem(row, col - 1, item); // Adjust column index to skip ID
        }
    }
}

void MainWindow::on_lineEdit_Nom_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        QString formattedText = text;
        formattedText[0] = formattedText[0].toUpper();
        if (formattedText != text) {
            ui->lineEdit_Nom->setText(formattedText);
        }
    }
}

void MainWindow::on_lineEdit_Origin_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        QString formattedText = text;
        formattedText[0] = formattedText[0].toUpper();
        if (formattedText != text) {
            ui->lineEdit_Origin->setText(formattedText);
        }
    }
}

void MainWindow::on_buttonEnregistrer_clicked()
{
    QString nom = ui->lineEdit_Nom->text();
    QString origin = ui->lineEdit_Origin->text();
    int rang = ui->lineEdit_Rang->text().toInt();
    int wins = ui->lineEdit_W->text().toInt();
    int losses = ui->lineEdit_L->text().toInt();
    int draws = ui->lineEdit_D->text().toInt();

    if (nom.isEmpty() || origin.isEmpty() || ui->lineEdit_Rang->text().isEmpty() ||
        ui->lineEdit_W->text().isEmpty() || ui->lineEdit_L->text().isEmpty() || ui->lineEdit_D->text().isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please fill in all fields.");
        return;
    }

    int score = Equipes::calculateScore(wins, losses, draws);

    Equipes equipe(0, nom, score, origin, rang);

    bool test = equipe.create();
    if (test) {
        populateTableWidget();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Origin->clear();
        ui->lineEdit_Rang->clear();
        ui->lineEdit_W->clear();
        ui->lineEdit_L->clear();
        ui->lineEdit_D->clear();
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Team added successfully.\n"), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to add team.\nError: %1").arg(equipe.getLastError()), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Warning", "Please select a team to modify.");
        return;
    }

    // Retrieve the ID from the hidden vertical header
    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();

    QString nom = ui->lineEdit_Nom->text();
    QString origin = ui->lineEdit_Origin->text();
    int rang = ui->lineEdit_Rang->text().toInt();
    int wins = ui->lineEdit_W->text().toInt();
    int losses = ui->lineEdit_L->text().toInt();
    int draws = ui->lineEdit_D->text().toInt();

    int score = Equipes::calculateScore(wins, losses, draws);

    Equipes equipe(id, nom, score, origin, rang);

    bool test = equipe.update(id);
    if (test) {
        populateTableWidget();
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Team updated successfully.\n"), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to update team.\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    // Retrieve the ID from the hidden vertical header
    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();

    // Get the new value from the cell
    QString newValue = ui->tableWidget->item(row, column)->text();

    // Determine which field was changed based on the column
    QString field;
    switch (column) {
    case 0: field = "NOM_EQUIPE"; break; // First column in the table is "NOM_EQUIPE"
    case 1: field = "SCORE"; break;      // Second column in the table is "SCORE"
    case 2: field = "ORIGINE"; break;    // Third column in the table is "ORIGINE"
    case 3: field = "RANG"; break;       // Fourth column in the table is "RANG"
    default: return; // Ignore other columns
    }

    // Update the database
    QSqlQuery query;
    query.prepare(QString("UPDATE EQUIPE SET %1 = :value WHERE ID_EQUIPE = :id").arg(field));
    query.bindValue(":value", newValue);
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", "Failed to update the database.");
    }
}

void MainWindow::showContextMenu(const QPoint &pos)
{
    // Get the row at the clicked position
    QTableWidgetItem *item = ui->tableWidget->itemAt(pos);
    if (!item) {
        return;  // No item clicked, do nothing
    }

    // Get the row index
    int row = ui->tableWidget->row(item);

    // Create a context menu
    QMenu menu(this);
    QAction *deleteAction = menu.addAction("Delete");

    // Connect the delete action to a slot
    connect(deleteAction, &QAction::triggered, this, [this, row]() {
        deleteRow(row);
    });

    // Show the context menu at the clicked position
    menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::deleteRow(int row)
{
    // Retrieve the ID from the hidden vertical header
    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();

    // Confirm deletion with the user
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this team?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Delete the team from the database
    Equipes equipe;
    bool test = equipe.delet(id);
    if (test) {
        // Remove the row from the table
        ui->tableWidget->removeRow(row);
        QMessageBox::information(nullptr, QObject::tr("Success"),
                                 QObject::tr("Team deleted successfully.\n"), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to delete team.\n"), QMessageBox::Cancel);
    }
}
