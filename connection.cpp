#include "connection.h"

connection::connection() {}

bool connection::set_connection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SFC");
    db.setUserName("yasminef");
    db.setPassword("esprit19");
    return db.open();
}

QSqlDatabase connection::get_connection() {
    return QSqlDatabase::database();
}
