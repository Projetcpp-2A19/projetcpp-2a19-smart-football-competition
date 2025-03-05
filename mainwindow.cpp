#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include "ui_dialog2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap first(":/images/logo.png");
    ui->first->setPixmap(first);
    ui->first->setScaledContents(true);


    QPixmap logoo(":/logo.png");


    ui->logoo->setPixmap(logoo);


    ui->logoo->setScaledContents(true);



    ui->first->setScaledContents(true);

    QPixmap chart(":/logo.png");


    ui->chart->setPixmap(chart);


    ui->chart->setScaledContents(true);


    ui->tableWidget->resizeColumnsToContents();  // Automatically resize columns based on their content
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // Stretch rows to fill space


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString poste = ui->lineEdit_poste->text();
    int nbr_but = ui->lineEdit_but->text().toInt();
    int nbr_passe = ui->lineEdit_passe->text().toInt();
    int carton_j = ui->lineEdit_cartonJ->text().toInt();
    int carton_r = ui->lineEdit_cartonR->text().toInt();

    Joueur J(id,nom,prenom,poste,nbr_but,nbr_passe,carton_j,carton_r);

    bool test = J.ajouter();
    if(test){
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n"), QMessageBox::Cancel);
    }
    else{
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué \n"), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    Dialog *dialog = new Dialog(this);
    dialog->setWindowTitle("Supprimer un joueur");
    dialog->exec();
}


void MainWindow::on_pushButton_8_clicked()
{
    Dialog2 *dialog = new Dialog2(this);
    dialog->setWindowTitle("Afficher les joueurs");
    dialog->exec();
}

