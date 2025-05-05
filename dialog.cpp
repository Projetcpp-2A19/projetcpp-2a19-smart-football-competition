#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    int id = ui->lineEdit_supp->text().toInt();
    bool test = Jtmp.supprimer(id);

    if(test){
        if(test){
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Le joueur à été supprimé \n"), QMessageBox::Cancel);
        }
        else{
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Le joueur n'as pas été supprimé \n"), QMessageBox::Cancel);
        }
    }
}

