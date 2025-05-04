#include "connection.h"
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnection() {
    db.setDatabaseName("SFC");
    db.setUserName("malek");
    db.setPassword("malek2003");

    if (!db.open()) {
        QSqlError error = db.lastError();
        qDebug() << "Database error:" << error.text();
        qDebug() << "Database driver:" << db.driverName();
        qDebug() << "Database name:" << db.databaseName();
        qDebug() << "Available drivers:" << QSqlDatabase::drivers();

        // Show a detailed error message box
        QMessageBox::critical(nullptr, "Database Connection Error",
                              QString("Failed to connect to database.\n\n"
                                      "Error: %1\n"
                                      "Driver: %2\n"
                                      "Database: %3\n\n"
                                      "Available drivers: %4")
                                  .arg(error.text())
                                  .arg(db.driverName())
                                  .arg(db.databaseName())
                                  .arg(QSqlDatabase::drivers().join(", ")));

        return false;
    }
    return true;
}

void Connection::closeConnection() {
    db.close();
}
