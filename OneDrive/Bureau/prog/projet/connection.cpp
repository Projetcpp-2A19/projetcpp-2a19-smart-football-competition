#include "connection.h"
#include <QSqlError>
#include <QSqlQuery>

Connection::Connection() {
    db = QSqlDatabase::addDatabase("QODBC");
}

bool Connection::createConnection() {
    db.setDatabaseName("SFC");
    db.setUserName("rayen");
    db.setPassword("rayen");

    if (!db.open()) {
        return false;
    }
    return true;
}

void Connection::closeConnection() {
    db.close();
}
