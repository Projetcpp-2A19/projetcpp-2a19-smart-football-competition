#include "dialog.h"
#include "ui_dialog.h"

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


        ui->ysar->setPixmap(ysar);


        ui->ysar->setScaledContents(true);

        ui->set->setScaledContents(true);

        QPixmap pattern("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212952-removebg-preview.png");


        ui->pattern->setPixmap(pattern);


        ui->pattern->setScaledContents(true);

        QPixmap chart2("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_215051-removebg-preview.png");


        ui->chart2->setPixmap(chart2);


        ui->chart2->setScaledContents(true);

        QPixmap ymin("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223234-removebg-preview.png");


        ui->ymin->setPixmap(ymin);


        ui->ymin->setScaledContents(true);

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



        ui->tableWidget->resizeColumnsToContents();  // Automatically resize columns based on their content
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
        ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // Stretch rows to fill space



}
}

Dialog::~Dialog()
{
    delete ui;
}
