#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnection() {
    db.setDatabaseName("SFC");
    db.setUserName("rayen");
    db.setPassword("rayen");

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }
    return true;
}

void Connection::closeConnection() {
    db.close();
}
