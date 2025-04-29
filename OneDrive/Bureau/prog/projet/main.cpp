#include "mainwindow.h"
#include "dialog.h"
#include "aimodel.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Initialize SQL module
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    // Create database connection
    Connection c;
    bool test = c.createConnection();

    // Create all UI windows
    MainWindow *mainWindow = new MainWindow();
    Dialog *dialogWindow = new Dialog();
    aimodel *aiModelWindow = new aimodel();  // AI model window from .ui

    if (test) {
        // Set window titles
        mainWindow->setWindowTitle("Main Window");
        dialogWindow->setWindowTitle("Dialog");
        aiModelWindow->setWindowTitle("AI Model");

        // Show all windows
        mainWindow->show();
        dialogWindow->show();
        aiModelWindow->show();

        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Connection successful.\n"), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"), QMessageBox::Cancel);
    }

    return a.exec();
}
