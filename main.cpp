#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        qDebug() << "Database connection failed!";
        QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                              QObject::tr("Connection failed. Click OK to exit."), QMessageBox::Ok);
        return -1;  // Exit the program if the connection fails
    }

    qDebug() << "Database connection successful!";

    MainWindow w;
    w.show();

    return a.exec();
}

