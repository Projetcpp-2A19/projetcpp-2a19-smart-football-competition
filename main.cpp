#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Connection c;
    bool test = c.createConnection();


    MainWindow w;

    // Check if the database connection was successful
    if (test) {
        w.show(); // Show the main window
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                     QObject::tr("Connection successful.\n"), QMessageBox::Cancel);
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed.\n"), QMessageBox::Cancel);
    }

    return a.exec(); // Start the application event loop
}
