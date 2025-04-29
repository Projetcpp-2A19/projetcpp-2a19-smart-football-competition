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
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include "equipes.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup Arduino serial connection
    arduino = new QSerialPort(this);
    arduino->setPortName("COM7"); // Ensure this is correct for your setup
    arduino->setBaudRate(QSerialPort::Baud9600);
    arduino->setDataBits(QSerialPort::Data8);
    arduino->setParity(QSerialPort::NoParity);
    arduino->setStopBits(QSerialPort::OneStop);
    arduino->setFlowControl(QSerialPort::NoFlowControl);

    if (arduino->open(QIODevice::ReadWrite)) {
        connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readArduinoData);
    } else {
        QMessageBox::critical(this, "Error", "Failed to open Arduino connection.");
    }

    // Populate the table with team data
    populateTableWidget();

    // Resize table columns to fit content
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setVisible(false);

    // Set maximum length for input fields
    ui->lineEdit_Nom->setMaxLength(20);
    ui->lineEdit_Origin->setMaxLength(20);

    // Connect UI elements to validation functions
    connect(ui->lineEdit_Nom, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Nom_textChanged);
    connect(ui->lineEdit_Origin, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_Origin_textChanged);
    connect(ui->possessioninput, &QLineEdit::textChanged, this, [this](const QString &text) {
        if (!text.isEmpty() && !text.endsWith('%')) {
            ui->possessioninput->setText(text + "%");
        }
    });

    // Set validators for input fields
    QIntValidator *validatorW = new QIntValidator(0, 999, this);
    QIntValidator *validatorL = new QIntValidator(0, 999, this);
    QIntValidator *validatorD = new QIntValidator(0, 999, this);
    QRegularExpressionValidator *possessionValidator = new QRegularExpressionValidator(QRegularExpression("^\\d{1,3}%?$"), this);

    ui->lineEdit_W->setValidator(validatorW);
    ui->lineEdit_L->setValidator(validatorL);
    ui->lineEdit_D->setValidator(validatorD);
    ui->possessioninput->setValidator(possessionValidator);

    // Set images for buttons/icons
    QPixmap logo(":/images/logo.png");
    ui->logoo->setPixmap(logo); ui->logoo->setScaledContents(true);

    QPixmap home(":/images/home.png");
    ui->home->setPixmap(home); ui->home->setScaledContents(true);

    QPixmap set(":/images/settings.png");
    ui->set->setPixmap(set); ui->set->setScaledContents(true);

    QPixmap filter(":/images/filter.png");
    ui->filter->setPixmap(filter); ui->filter->setScaledContents(true);

    QPixmap pattern(":/images/pattern.png");
    ui->pattern->setPixmap(pattern); ui->pattern->setScaledContents(true);

    QPixmap chart(":/images/chart.png");
    ui->chart->setPixmap(chart); ui->chart->setScaledContents(true);

    QPixmap first(":/images/first.png");
    ui->first->setPixmap(first); ui->first->setScaledContents(true);

    QPixmap ysar(":/images/ysar.png");
    ui->ysar->setPixmap(ysar); ui->ysar->setScaledContents(true);

    QPixmap ymin(":/images/ymin.png");
    ui->ymin->setPixmap(ymin); ui->ymin->setScaledContents(true);

    connect(ui->tableWidget, &QTableWidget::cellChanged, this, &MainWindow::on_tableWidget_cellChanged);
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested, this, &MainWindow::showContextMenu);
}

MainWindow::~MainWindow()
{
    if (arduino->isOpen()) arduino->close();
    delete ui;
}

void MainWindow::readArduinoData()
{
    QByteArray data = arduino->readAll();
    QString dataStr = QString::fromStdString(data.toStdString()).trimmed();

    qDebug() << "Received from Arduino:" << dataStr;

    // Check the received data and update the corresponding team's score
    if (dataStr == "GOAL_TEAM1") {
        // Update score for FCB (team name: 'FCB')
        QSqlQuery query;
        query.prepare("UPDATE EQUIPE SET SCORE = SCORE + 1 WHERE NOM_EQUIPE = 'FCB'");

        if (!query.exec()) {
            qDebug() << "Failed to update FCB score:" << query.lastError().text();
        } else {
            qDebug() << "FCB score updated.";
        }
    } else if (dataStr == "GOAL_TEAM2") {
        // Update score for RLM (team name: 'RLM')
        QSqlQuery query;
        query.prepare("UPDATE EQUIPE SET SCORE = SCORE + 1 WHERE NOM_EQUIPE = 'RLM'");

        if (!query.exec()) {
            qDebug() << "Failed to update RLM score:" << query.lastError().text();
        } else {
            qDebug() << "RLM score updated.";
        }
    }

    // Re-fetch and refresh the table after updating the score
    populateTableWidget();
}


void MainWindow::populateTableWidget()
{
    Equipes Etmp;
    QSqlQueryModel* model = Etmp.read();  // Assuming this method fetches all team data from the database

    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount() - 1);

    QStringList headers;
    for (int col = 1; col < model->columnCount(); ++col)
        headers << model->headerData(col, Qt::Horizontal).toString();

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

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    qDebug() << "Cell changed at row:" << row << "column:" << column;
}

void MainWindow::on_lineEdit_Nom_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        QString formatted = text;
        formatted[0] = formatted[0].toUpper();
        if (formatted != text) ui->lineEdit_Nom->setText(formatted);
    }
}

void MainWindow::on_lineEdit_Origin_textChanged(const QString &text)
{
    if (!text.isEmpty()) {
        QString formatted = text;
        formatted[0] = formatted[0].toUpper();
        if (formatted != text) ui->lineEdit_Origin->setText(formatted);
    }
}

bool MainWindow::validateInput()
{
    // Input validation logic
    // You can implement the validate logic to make sure inputs are correct
    return true;
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
    reply = QMessageBox::question(this, "Confirm Deletion", "Delete this row?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        Equipes Etmp;  // Declare the Equipe object
        /*if (Etmp.deleteItem(id)) {
            qDebug() << "Item deleted successfully!";
            populateTableWidget();
        } else {
            qDebug() << "Failed to delete item.";*/
        }
    }

