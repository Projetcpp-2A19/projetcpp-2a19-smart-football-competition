#include "connection.h"
#include <QSqlError>
#include <QDebug>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnection() {
    db.setDatabaseName("SFC"); // Your database name
    db.setUserName("rayen");   // Your username
    db.setPassword("rayen");   // Your password

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }
    return true;
}

void Connection::closeConnection() {
    db.close();
}
