/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *ymin;
    QLineEdit *lineEdit_prenom;
    QLabel *label_5;
    QLabel *filter;
    QLabel *pattern;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *logoo;
    QLineEdit *lineEdit_cartonR;
    QPushButton *pushButton_ajouter;
    QLabel *ysar;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QLabel *chart;
    QLineEdit *lineEdit_equipe;
    QPushButton *pushButton_5;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_poste;
    QLabel *first;
    QPushButton *pushButton_7;
    QLineEdit *lineEdit_but;
    QLabel *label_7;
    QLabel *label_9;
    QLineEdit *lineEdit_passe;
    QLineEdit *lineEdit_cartonJ;
    QLineEdit *lineEdit_nom;
    QLabel *label_10;
    QLineEdit *lineEdit_id;
    QLabel *label_11;
    QPushButton *pushButton_8;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(894, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ymin = new QLabel(centralwidget);
        ymin->setObjectName("ymin");
        ymin->setGeometry(QRect(800, 20, 31, 31));
        lineEdit_prenom = new QLineEdit(centralwidget);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(250, 210, 141, 21));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"color: rgb(46, 52, 76);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 130, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        filter = new QLabel(centralwidget);
        filter->setObjectName("filter");
        filter->setGeometry(QRect(710, 20, 31, 31));
        pattern = new QLabel(centralwidget);
        pattern->setObjectName("pattern");
        pattern->setGeometry(QRect(670, 20, 31, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 180, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 360, 141, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(220, 10, 201, 51));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"font: 14pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(250, 330, 161, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        logoo = new QLabel(centralwidget);
        logoo->setObjectName("logoo");
        logoo->setGeometry(QRect(20, 20, 161, 141));
        lineEdit_cartonR = new QLineEdit(centralwidget);
        lineEdit_cartonR->setObjectName("lineEdit_cartonR");
        lineEdit_cartonR->setGeometry(QRect(330, 360, 31, 31));
        lineEdit_cartonR->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(250, 400, 141, 31));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        ysar = new QLabel(centralwidget);
        ysar->setObjectName("ysar");
        ysar->setGeometry(QRect(760, 20, 31, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 300, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 240, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 230, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(430, 10, 321, 51));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;        /* White background */\n"
"    border: 2px solid #2E344C;      /* Border color */\n"
"    border-radius: 10px;            /* Rounded corners */\n"
"    padding: 5px;                   /* Padding inside the line edit */\n"
"    color: #2E344C;                 /* Text color */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2E344C;      /* Keep border color when focused */\n"
"}\n"
""));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 4, __qtablewidgetitem28);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(430, 70, 411, 221));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #FDF6D0;\n"
"    color: #2E344C;\n"
"    gridline-color: #2E344C;\n"
"    border: 2px solid #2E344C;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2E344C;\n"
"    color: #FDF6D0;\n"
"    padding: 5px;\n"
"    border: 1px solid #2E344C;\n"
"}\n"
"\n"
"QTableWidget QTableCornerButton::section {\n"
"    background-color: #2E344C;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"    border: 1px solid #2E344C;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #2E344C;\n"
"    color: #FDF6D0;\n"
"}\n"
"ui->tab->setStyleSheet(\n"
"    \"QTableWidget {\"\n"
"    \"   width: 600px;\"   // Set the width of the table\n"
"    \"   height: 300px;\"  // Set the height of the table\n"
"    \"}\"\n"
");"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 70, 201, 451));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        chart = new QLabel(centralwidget);
        chart->setObjectName("chart");
        chart->setGeometry(QRect(450, 320, 231, 151));
        chart->setStyleSheet(QString::fromUtf8(""));
        lineEdit_equipe = new QLineEdit(centralwidget);
        lineEdit_equipe->setObjectName("lineEdit_equipe");
        lineEdit_equipe->setGeometry(QRect(250, 310, 141, 21));
        lineEdit_equipe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 420, 141, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 201, 601));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 0, 661, 551));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        lineEdit_poste = new QLineEdit(centralwidget);
        lineEdit_poste->setObjectName("lineEdit_poste");
        lineEdit_poste->setGeometry(QRect(250, 260, 141, 21));
        lineEdit_poste->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        first = new QLabel(centralwidget);
        first->setObjectName("first");
        first->setGeometry(QRect(690, 320, 131, 151));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(250, 440, 141, 31));
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        lineEdit_but = new QLineEdit(centralwidget);
        lineEdit_but->setObjectName("lineEdit_but");
        lineEdit_but->setGeometry(QRect(250, 360, 31, 31));
        lineEdit_but->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 280, 101, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(430, 300, 411, 191));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"	background-color: rgb(46, 52, 76);\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        lineEdit_passe = new QLineEdit(centralwidget);
        lineEdit_passe->setObjectName("lineEdit_passe");
        lineEdit_passe->setGeometry(QRect(290, 360, 31, 31));
        lineEdit_passe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_cartonJ = new QLineEdit(centralwidget);
        lineEdit_cartonJ->setObjectName("lineEdit_cartonJ");
        lineEdit_cartonJ->setGeometry(QRect(370, 360, 31, 31));
        lineEdit_cartonJ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_nom = new QLineEdit(centralwidget);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(250, 160, 141, 22));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(250, 190, 49, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_id = new QLineEdit(centralwidget);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(250, 110, 141, 22));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(250, 90, 101, 16));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(250, 480, 141, 31));
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label_3->raise();
        label->raise();
        ymin->raise();
        lineEdit_prenom->raise();
        label_5->raise();
        filter->raise();
        pattern->raise();
        pushButton->raise();
        pushButton_4->raise();
        label_4->raise();
        label_8->raise();
        logoo->raise();
        lineEdit_cartonR->raise();
        pushButton_ajouter->raise();
        ysar->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        label_6->raise();
        lineEdit_7->raise();
        tableWidget->raise();
        lineEdit_equipe->raise();
        pushButton_5->raise();
        lineEdit_poste->raise();
        pushButton_7->raise();
        lineEdit_but->raise();
        label_7->raise();
        label_9->raise();
        first->raise();
        chart->raise();
        lineEdit_passe->raise();
        lineEdit_cartonJ->raise();
        lineEdit_nom->raise();
        label_10->raise();
        lineEdit_id->raise();
        label_11->raise();
        pushButton_8->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ymin->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        filter->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pattern->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Joueus", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "           Ajouter un joueur", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Goal    Assist      R          J", nullptr));
        logoo->setText(QCoreApplication::translate("MainWindow", "logo", nullptr));
        lineEdit_cartonR->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        ysar->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Equipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Goal", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Assist", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Carton J/R", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Messi", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Ronaldo", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Neymar", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Vinicious", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Barcelone", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(0, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Attaque", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->item(0, 2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "14", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "2/0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Real Madrid", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Attaque", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(1, 2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "3/0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(2, 0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Barcelone", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(2, 1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Attaque", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "18", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "1/2", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(3, 0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Real Madrid", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Attaque", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "17", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "2/4", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_3->setText(QString());
        chart->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QString());
        first->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Supprimer un joueur", nullptr));
        lineEdit_but->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Equipe", nullptr));
        label_9->setText(QString());
        lineEdit_passe->setText(QString());
        lineEdit_cartonJ->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Identifiant", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Afficher les joueurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
