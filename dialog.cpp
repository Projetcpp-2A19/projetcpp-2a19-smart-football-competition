#include "dialog.h"
#include "ui_dialog.h"
#include "Billet.h"
#include "QSqlQuery"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    {

        QPixmap image("C:\\Users\\rayen\\Downloads\\Screenshot_2025-01-26_014639-removebg-preview.png");


        ui->logoo->setPixmap(image);


        ui->logoo->setScaledContents(true);

       /* QTableWidget *tableWidget = new QTableWidget(3, 4);
        tableWidget->setHorizontalHeaderLabels({"", "Rang", "Score", "Pays d’origine"});*/



        /*QPixmap filter("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212956-removebg-preview.png");


        ui->filter->setPixmap(filter);


        ui->filter->setScaledContents(true);*/

       /* QPixmap pattern("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212952-removebg-preview.png");


        ui->pattern->setPixmap(pattern);


        ui->pattern->setScaledContents(true);*/



        QPixmap chart("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_215513-removebg-preview.png");


        ui->chart->setPixmap(chart);


        ui->chart->setScaledContents(true);

        QPixmap home("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021115-removebg-preview.png");


        ui->home->setPixmap(home);


        ui->home->setScaledContents(true);
        QPixmap set("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021120-removebg-preview.png");


        ui->set->setPixmap(set);
        QPixmap ysar("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223231-removebg-preview.png");


  //      ui->ysar->setPixmap(ysar);




//        ui->ysar->setScaledContents(true);

        ui->set->setScaledContents(true);

        QPixmap pattern("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212952-removebg-preview.png");


    //    ui->pattern->setPixmap(pattern);


      //  ui->pattern->setScaledContents(true);

        QPixmap chart2("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_215051-removebg-preview.png");


       // ui->chart2->setPixmap(chart2);


        //ui->chart2->setScaledContents(true);

        QPixmap ymin("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223234-removebg-preview.png");


       // ui->ymin->setPixmap(ymin);


        // ui->ymin->setScaledContents(true);

       /* QPixmap first("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_220804-removebg-preview.png");


        ui->first->setPixmap(first);


        ui->first->setScaledContents(true);*/

        /*QPixmap ysar("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223231-removebg-preview.png");


        ui->ysar->setPixmap(ysar);


        ui->ysar->setScaledContents(true);*/


     /*   QPixmap ymin("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223234-removebg-preview.png");


        ui->ymin->setPixmap(ymin);


        ui->ymin->setScaledContents(true);*/

      /*  QPixmap kra1("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_222920-removebg-preview.png");


        ui->kra1->setPixmap(kra1);


        ui->kra1->setScaledContents(true);*/



        // ui->tableWidget->resizeColumnsToContents();  // Automatically resize columns based on their content
        // ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
        // ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // Stretch rows to fill space

        ui->tableView->setModel( ba.afficher());

}
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_6_clicked()
{
    int nb=ui->num_place->text().toInt();
    QDateTime date=ui->Date->dateTime();
    QString zone=ui->zone->text();
    QString stade=ui->nom_stade->text();
    float prix=ui->prix_billet->text().toFloat();
    Billet b(date,prix,stade,zone,nb);
    bool test=b.ajouter();
    if (test)
    {
        ui->tableView->setModel( ba.afficher());
    }
}




void Dialog::on_pushButton_10_clicked()
{
    QModelIndex index=ui->tableView->currentIndex();
    int i=index.row();
    QModelIndex in=index.sibling(i,0);
    int val=ui->tableView->model()->data(in).toInt();
    bool test=ba.supprimer(val);
    if (test)
    {
       ui->tableView->setModel( ba.afficher());

    }
}


void Dialog::on_tableView_clicked(const QModelIndex &index)
{
    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("SELECT * FROM billet where ID_BILLET='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->Date->setDateTime(qry.value(1).toDateTime());
            ui->prix_billet->setText(qry.value(5).toString());
            ui->nom_stade->setText(qry.value(2).toString());
            ui->zone->setText(qry.value(3).toString());
            ui->num_place->setText(qry.value(4).toString());

        }
    }
}


void Dialog::on_pushButton_7_clicked()
{
    QModelIndex index=ui->tableView->currentIndex();

    int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    int val=ui->tableView->model()->data(in).toInt();
    int nb=ui->num_place->text().toInt();
    QDateTime date=ui->Date->dateTime();
    QString zone=ui->zone->text();
    QString stade=ui->nom_stade->text();
    float prix=ui->prix_billet->text().toFloat();
    Billet b(date,prix,stade,zone,nb);
    bool test=b.modifier(val);
    if(test){
        ui->tableView->setModel( ba.afficher());

    }
}

