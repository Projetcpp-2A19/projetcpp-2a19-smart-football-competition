#include "connection.h"
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::addDatabase("QODBC", "qt_sql_default_connection");
    }

    db.setDatabaseName("sfc");  // Check if "sfc" is correctly configured in ODBC
    db.setUserName("yasminef");    // Ensure correct username
    db.setPassword("esprit19");// Ensure correct password

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected successfully!";
    return true;
}
