#include "gdialog.h"
#include "connection.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gdialog w;
    connection c;

    if(c.set_connection()){
    w.on_display_clicked();
    w.updateStatistics();
    w.show();
    qDebug()<<"database connected";
    }else{
        qDebug()<<"probleme";
    }
    return a.exec();
}
