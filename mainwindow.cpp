#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
connect(ui->page, &QPushButton::clicked, this, &MainWindow::openDialog);

    QPixmap image("C:\\Users\\rayen\\Downloads\\Screenshot_2025-01-26_014639-removebg-preview.png");


 ui->logoo->setPixmap(image);


    ui->logoo->setScaledContents(true);

 QTableWidget *tableWidget = new QTableWidget(3, 4);
 tableWidget->setHorizontalHeaderLabels({"", "Rang", "Score", "Pays d’origine"});
 QPixmap home("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021115-removebg-preview.png");


 ui->home->setPixmap(home);


 ui->home->setScaledContents(true);
 QPixmap set("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-13_021120-removebg-preview.png");


 ui->set->setPixmap(set);


 ui->set->setScaledContents(true);


 QPixmap filter("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212956-removebg-preview.png");


 ui->filter->setPixmap(filter);


 ui->filter->setScaledContents(true);

 QPixmap pattern("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_212952-removebg-preview.png");


 ui->pattern->setPixmap(pattern);


 ui->pattern->setScaledContents(true);



 QPixmap chart("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_215513-removebg-preview.png");


 ui->chart->setPixmap(chart);


 ui->chart->setScaledContents(true);



 QPixmap first("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_220804-removebg-preview.png");


 ui->first->setPixmap(first);


 ui->first->setScaledContents(true);

 QPixmap ysar("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223231-removebg-preview.png");


 ui->ysar->setPixmap(ysar);


 ui->ysar->setScaledContents(true);


 QPixmap ymin("C:\\Users\\rayen\\Downloads\\Screenshot_2025-02-12_223234-removebg-preview.png");


 ui->ymin->setPixmap(ymin);


 ui->ymin->setScaledContents(true);





    // Set manual column widths
    /*tab->setColumnWidth(0, 100);  // First column width = 100px
    tab->setColumnWidth(1, 50);   // Second column width = 50px

    // Automatically resize columns to their contents (removes extra space)
    tab->resizeColumnsToContents();*/


 ui->tableWidget->resizeColumnsToContents();  // Automatically resize columns based on their content
 ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);  // Stretch columns to fill space
 ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // Stretch rows to fill space



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDialog()
{
    Dialog dialog(this);  // This assumes Dialog is already instantiated elsewhere
    dialog.exec(); // Show the Dialog in a modal way
}

