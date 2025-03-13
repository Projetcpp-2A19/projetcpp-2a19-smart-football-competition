#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
#include "Connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    connection c;

    bool test=c.createconnection();

    if(test)
    w.show();
    return a.exec();
}
