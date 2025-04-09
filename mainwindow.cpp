#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QMessageBox>
#include <QRegularExpression>
#include <QIntValidator>
#include <QPixmap>
#include <QTableWidgetItem>
#include <QMenu>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    populateTableWidget();

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->lineEdit_Nom->setMaxLength(20);
    ui->lineEdit_Origin->setMaxLength(20);

    connect(ui->lineEdit_Nom, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Nom_textChanged);
    connect(ui->lineEdit_Origin, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Origin_textChanged);

    QIntValidator *validatorW = new QIntValidator(this);
    QIntValidator *validatorL = new QIntValidator(this);
    QIntValidator *validatorD = new QIntValidator(this);

    ui->lineEdit_W->setValidator(validatorW);
    ui->lineEdit_L->setValidator(validatorL);
    ui->lineEdit_D->setValidator(validatorD);

    validatorW->setRange(0, 999);
    validatorL->setRange(0, 999);
    validatorD->setRange(0, 999);

    // Load images
    QPixmap logo("C:/Users/rayen/Downloads/Screenshot_2025-01-26_014639-removebg-preview.png");
    ui->logoo->setPixmap(logo);
    ui->logoo->setScaledContents(true);

    QPixmap home("C:/Users/rayen/Downloads/Screenshot_2025-02-13_021115-removebg-preview.png");
    ui->home->setPixmap(home);
    ui->home->setScaledContents(true);

    QPixmap set("C:/Users/rayen/Downloads/Screenshot_2025-02-13_021120-removebg-preview.png");
    ui->set->setPixmap(set);
    ui->set->setScaledContents(true);

    QPixmap filter("C:/Users/rayen/Downloads/Screenshot_2025-02-12_212956-removebg-preview.png");
    ui->filter->setPixmap(filter);
    ui->filter->setScaledContents(true);

    QPixmap pattern("C:/Users/rayen/Downloads/Screenshot_2025-02-12_212952-removebg-preview.png");
    ui->pattern->setPixmap(pattern);
    ui->pattern->setScaledContents(true);

    QPixmap chart("C:/Users/rayen/Downloads/Screenshot_2025-02-12_215513-removebg-preview.png");
    ui->chart->setPixmap(chart);
    ui->chart->setScaledContents(true);

    QPixmap first("C:/Users/rayen/Downloads/Screenshot_2025-02-12_220804-removebg-preview.png");
    ui->first->setPixmap(first);
    ui->first->setScaledContents(true);

    QPixmap ysar("C:/Users/rayen/Downloads/Screenshot_2025-02-12_223231-removebg-preview.png");
    ui->ysar->setPixmap(ysar);
    ui->ysar->setScaledContents(true);

    QPixmap ymin("C:/Users/rayen/Downloads/Screenshot_2025-02-12_223234-removebg-preview.png");
    ui->ymin->setPixmap(ymin);
    ui->ymin->setScaledContents(true);

    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);

    // Connect the page button to open the dialog
    connect(ui->page, &QPushButton::clicked, this, [this]() {
        dialog = new Dialog(this);
        dialog->exec();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateTableWidget()
{
    QSqlQueryModel* model = Etmp.read();
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount() - 1);

    QStringList headers;
    for (int col = 1; col < model->columnCount(); ++col) {
        headers << model->headerData(col, Qt::Horizontal).toString();
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < model->rowCount(); ++row) {
        int id = model->data(model->index(row, 0)).toInt();
        QTableWidgetItem* idItem = new QTableWidgetItem(QString::number(id));
        idItem->setData(Qt::UserRole, id);
        ui->tableWidget->setVerticalHeaderItem(row, idItem);

        for (int col = 1; col < model->columnCount(); ++col) {
            QTableWidgetItem* item = new QTableWidgetItem(model->data(model->index(row, col)).toString());
            ui->tableWidget->setItem(row, col - 1, item);
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

bool MainWindow::validateInput()
{
    QString nom = ui->lineEdit_Nom->text();
    QRegularExpression nomRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Nom d'équipe should only contain letters and spaces.");
        return false;
    }

    QString origin = ui->lineEdit_Origin->text();
    QRegularExpression originRegex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s]+$");
    if (!originRegex.match(origin).hasMatch()) {
        QMessageBox::warning(this, "Invalid Input", "Origine should only contain letters and spaces.");
        return false;
    }

    bool isRangValid;
    int rang = ui->lineEdit_Rang->text().toInt(&isRangValid);
    if (!isRangValid || rang <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Rang should be a positive number.");
        return false;
    }

    bool isWValid, isLValid, isDValid;
    int wins = ui->lineEdit_W->text().toInt(&isWValid);
    int losses = ui->lineEdit_L->text().toInt(&isLValid);
    int draws = ui->lineEdit_D->text().toInt(&isDValid);

    if (!isWValid || !isLValid || !isDValid || wins < 0 || losses < 0 || draws < 0) {
        QMessageBox::warning(this, "Invalid Input", "W, L, D should be positive numbers.");
        return false;
    }

    if (nom.length() > 20 || origin.length() > 20) {
        QMessageBox::warning(this, "Invalid Input", "Nom d'équipe and Origine should be less than 20 characters.");
        return false;
    }

    return true;
}

void MainWindow::on_buttonEnregistrer_clicked()
{
    if (!validateInput()) {
        return;
    }

    QString nom = ui->lineEdit_Nom->text();
    QString origin = ui->lineEdit_Origin->text();
    int rang = ui->lineEdit_Rang->text().toInt();
    int wins = ui->lineEdit_W->text().toInt();
    int losses = ui->lineEdit_L->text().toInt();
    int draws = ui->lineEdit_D->text().toInt();

    int score = Equipes::calculateScore(wins, losses, draws);
    Equipes equipe(0, nom, score, origin, rang);

    if (equipe.create()) {
        populateTableWidget();
        ui->lineEdit_Nom->clear();
        ui->lineEdit_Origin->clear();
        ui->lineEdit_Rang->clear();
        ui->lineEdit_W->clear();
        ui->lineEdit_L->clear();
        ui->lineEdit_D->clear();
        QMessageBox::information(this, "Success", "Team added successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to add team: " + equipe.getLastError());
    }
}

void MainWindow::on_pushButton_modifier_clicked()
{
    if (!validateInput()) {
        return;
    }

    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Warning", "Please select a team to modify.");
        return;
    }

    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();
    QString nom = ui->lineEdit_Nom->text();
    QString origin = ui->lineEdit_Origin->text();
    int rang = ui->lineEdit_Rang->text().toInt();
    int wins = ui->lineEdit_W->text().toInt();
    int losses = ui->lineEdit_L->text().toInt();
    int draws = ui->lineEdit_D->text().toInt();

    int score = Equipes::calculateScore(wins, losses, draws);
    Equipes equipe(id, nom, score, origin, rang);

    if (equipe.update(id)) {
        populateTableWidget();
        QMessageBox::information(this, "Success", "Team updated successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update team.");
    }
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();
    QString newValue = ui->tableWidget->item(row, column)->text();

    QString field;
    switch (column) {
    case 0: field = "NOM_EQUIPE"; break;
    case 1: field = "SCORE"; break;
    case 2: field = "ORIGINE"; break;
    case 3: field = "RANG"; break;
    default: return;
    }

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
    QTableWidgetItem *item = ui->tableWidget->itemAt(pos);
    if (!item) return;

    int row = ui->tableWidget->row(item);
    QMenu menu(this);
    QAction *deleteAction = menu.addAction("Delete");

    connect(deleteAction, &QAction::triggered, this, [this, row]() {
        deleteRow(row);
    });

    menu.exec(ui->tableWidget->viewport()->mapToGlobal(pos));
}

void MainWindow::deleteRow(int row)
{
    int id = ui->tableWidget->verticalHeaderItem(row)->data(Qt::UserRole).toInt();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Delete", "Are you sure you want to delete this team?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    Equipes equipe;
    if (equipe.delet(id)) {
        ui->tableWidget->removeRow(row);
        QMessageBox::information(this, "Success", "Team deleted successfully.");
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete team.");
    }
}
