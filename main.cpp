#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Test database connection
    Connection c;
    bool test = c.createConnection();
    qDebug() << "Database connection test:" << test;

    MainWindow w;

    if (test) {
        w.show();
        qDebug() << "Main window shown";
    } else {
        QMessageBox::critical(nullptr, "Database Error",
                              "Failed to connect to database.\nCheck your connection settings.");
        return 1; // Exit with error code
    }

    return a.exec();
}
