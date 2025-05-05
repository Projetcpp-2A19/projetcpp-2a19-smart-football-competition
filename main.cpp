#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <dialog2.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test){
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"), QMessageBox::Cancel);

    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"), QMessageBox::Cancel);
    }

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Port Name:" << serialPortInfo.portName();
        qDebug() << "Description:" << serialPortInfo.description();
        qDebug() << "Vendor ID:" << serialPortInfo.vendorIdentifier();
        qDebug() << "Product ID:" << serialPortInfo.productIdentifier();
        qDebug() << "--------------------------------";
    }

    return a.exec();
}
