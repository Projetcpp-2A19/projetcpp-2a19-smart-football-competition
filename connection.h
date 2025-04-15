#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class connection {
public:
    connection();
    bool set_connection();  // Changed to return bool for success/failure
    QSqlDatabase get_connection(); // method return the current database
};

#endif // CONNECTION_H
