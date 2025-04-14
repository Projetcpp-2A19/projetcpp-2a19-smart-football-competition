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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "radarwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_acceuil;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_cartonJ;
    QPushButton *pushButton;
    QLineEdit *lineEdit_passe;
    QLabel *filtre;
    QPushButton *pushButton_modifier;
    QComboBox *comboBox_equipe;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_but;
    QLabel *back;
    QPushButton *pushButton_ajouter;
    QLabel *next;
    QLineEdit *lineEditRecherche;
    QLabel *label_6;
    QLabel *logo;
    QLineEdit *lineEdit_prenom;
    QLabel *label_9;
    QLineEdit *lineEdit_nom;
    QLabel *label_13;
    QLineEdit *lineEdit_cartonR;
    QLabel *label_7;
    QComboBox *comboBox_poste;
    QLineEdit *lineEdit_supp;
    QLabel *label_14;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QPushButton *pushButton_supp;
    QLabel *label_11;
    QTableView *tableView;
    QPushButton *pushButton_pdf;
    QComboBox *comboBox_trie;
    QWidget *page_profil;
    QLabel *label_12;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *logo_2;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QPushButton *pushButton_photo;
    QLabel *label_prenom;
    QLabel *label_poste;
    QLabel *label_nom;
    QLabel *label_cartonJ;
    QLabel *label_passe;
    QLabel *label_but;
    QLabel *label_cartonR;
    QPushButton *pushButton_retour;
    RadarWidget *radarWidget;
    QLineEdit *lineEdit_11;
    QLabel *label_photo;
    QTableWidget *tableNotesJoueurs;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(894, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-10, 0, 891, 581));
        page_acceuil = new QWidget();
        page_acceuil->setObjectName("page_acceuil");
        pushButton_2 = new QPushButton(page_acceuil);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(35, 239, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_5 = new QPushButton(page_acceuil);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(35, 419, 141, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        lineEdit_cartonJ = new QLineEdit(page_acceuil);
        lineEdit_cartonJ->setObjectName("lineEdit_cartonJ");
        lineEdit_cartonJ->setGeometry(QRect(335, 389, 51, 31));
        lineEdit_cartonJ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(page_acceuil);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(35, 179, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        lineEdit_passe = new QLineEdit(page_acceuil);
        lineEdit_passe->setObjectName("lineEdit_passe");
        lineEdit_passe->setGeometry(QRect(335, 329, 51, 31));
        lineEdit_passe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        filtre = new QLabel(page_acceuil);
        filtre->setObjectName("filtre");
        filtre->setGeometry(QRect(680, 0, 51, 51));
        filtre->setStyleSheet(QString::fromUtf8("image: url(:/pic/filtre.jpeg);"));
        filtre->setPixmap(QPixmap(QString::fromUtf8("filtre.jpeg")));
        filtre->setScaledContents(true);
        pushButton_modifier = new QPushButton(page_acceuil);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(235, 479, 151, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        comboBox_equipe = new QComboBox(page_acceuil);
        comboBox_equipe->setObjectName("comboBox_equipe");
        comboBox_equipe->setGeometry(QRect(235, 269, 141, 31));
        comboBox_equipe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        pushButton_4 = new QPushButton(page_acceuil);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(35, 359, 141, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label = new QLabel(page_acceuil);
        label->setObjectName("label");
        label->setGeometry(QRect(5, -1, 201, 601));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_8 = new QLabel(page_acceuil);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(225, 299, 161, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_2 = new QLabel(page_acceuil);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(205, -1, 661, 591));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        label_5 = new QLabel(page_acceuil);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(235, 119, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_but = new QLineEdit(page_acceuil);
        lineEdit_but->setObjectName("lineEdit_but");
        lineEdit_but->setGeometry(QRect(235, 329, 51, 31));
        lineEdit_but->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        back = new QLabel(page_acceuil);
        back->setObjectName("back");
        back->setGeometry(QRect(755, 9, 31, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/pic/back.jpeg);"));
        back->setPixmap(QPixmap(QString::fromUtf8(":/pic/back.jpeg")));
        back->setScaledContents(true);
        pushButton_ajouter = new QPushButton(page_acceuil);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(235, 429, 151, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        next = new QLabel(page_acceuil);
        next->setObjectName("next");
        next->setGeometry(QRect(805, 9, 31, 31));
        next->setStyleSheet(QString::fromUtf8("image: url(:/pic/next.jpeg);"));
        next->setPixmap(QPixmap(QString::fromUtf8(":/pic/next.jpeg")));
        next->setScaledContents(true);
        lineEditRecherche = new QLineEdit(page_acceuil);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(425, 0, 321, 51));
        lineEditRecherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(page_acceuil);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(235, 179, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        logo = new QLabel(page_acceuil);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(25, 19, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logo->setScaledContents(true);
        lineEdit_prenom = new QLineEdit(page_acceuil);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(235, 89, 141, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"color: rgb(46, 52, 76);"));
        label_9 = new QLabel(page_acceuil);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(415, 369, 441, 151));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(page_acceuil);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(235, 149, 141, 31));
        label_13 = new QLabel(page_acceuil);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(425, 369, 301, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));
        lineEdit_cartonR = new QLineEdit(page_acceuil);
        lineEdit_cartonR->setObjectName("lineEdit_cartonR");
        lineEdit_cartonR->setGeometry(QRect(235, 389, 51, 31));
        lineEdit_cartonR->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(page_acceuil);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(235, 239, 101, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        comboBox_poste = new QComboBox(page_acceuil);
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->addItem(QString());
        comboBox_poste->setObjectName("comboBox_poste");
        comboBox_poste->setGeometry(QRect(235, 209, 141, 31));
        comboBox_poste->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        lineEdit_supp = new QLineEdit(page_acceuil);
        lineEdit_supp->setObjectName("lineEdit_supp");
        lineEdit_supp->setGeometry(QRect(425, 459, 113, 22));
        label_14 = new QLabel(page_acceuil);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(425, 439, 81, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
"\n"
""));
        label_3 = new QLabel(page_acceuil);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(215, 59, 191, 471));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_4 = new QLabel(page_acceuil);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(215, -1, 191, 51));
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
        pushButton_3 = new QPushButton(page_acceuil);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(35, 299, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label_10 = new QLabel(page_acceuil);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(235, 69, 49, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        pushButton_supp = new QPushButton(page_acceuil);
        pushButton_supp->setObjectName("pushButton_supp");
        pushButton_supp->setGeometry(QRect(749, 449, 91, 31));
        pushButton_supp->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        label_11 = new QLabel(page_acceuil);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(225, 359, 181, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        tableView = new QTableView(page_acceuil);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(410, 80, 441, 281));
        tableView->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
");\n"
""));
        pushButton_pdf = new QPushButton(page_acceuil);
        pushButton_pdf->setObjectName("pushButton_pdf");
        pushButton_pdf->setGeometry(QRect(760, 330, 91, 31));
        pushButton_pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        comboBox_trie = new QComboBox(page_acceuil);
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->setObjectName("comboBox_trie");
        comboBox_trie->setGeometry(QRect(690, 0, 61, 51));
        comboBox_trie->setStyleSheet(QString::fromUtf8("QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 25px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: #2E344C;\n"
"    border-left-style: solid;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FDF6D0;\n"
"    color: #2E344C;\n"
"    selection-background-color: #2E344C;\n"
"    selection-color: #FDF6D0;\n"
"    border: 2px solid #2E344C;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QComboBox:on { /* Style lorsque le menu d\303\251roulant est ouvert */\n"
"    border: 2px solid #4C566A;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 12px;\n"
"    height: 12px;\n"
"    /* Pas d'image, on utilise la fl\303\250che native mais on change sa couleur */\n"
"}\n"
"\n"
"QComboBox::down-arrow:on {\n"
"    image: none; /* D\303\251sactive toute ic\303\264ne personnalis\303\251e */\n"
"    color: #2E344C; /* Couleur"
                        " de la fl\303\250che (bleu fonc\303\251) */\n"
"}"));
        stackedWidget->addWidget(page_acceuil);
        label_2->raise();
        lineEditRecherche->raise();
        label_3->raise();
        label->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        lineEdit_cartonJ->raise();
        pushButton->raise();
        lineEdit_passe->raise();
        pushButton_modifier->raise();
        comboBox_equipe->raise();
        pushButton_4->raise();
        label_8->raise();
        label_5->raise();
        lineEdit_but->raise();
        back->raise();
        pushButton_ajouter->raise();
        next->raise();
        label_6->raise();
        logo->raise();
        lineEdit_prenom->raise();
        label_9->raise();
        lineEdit_nom->raise();
        label_13->raise();
        lineEdit_cartonR->raise();
        label_7->raise();
        comboBox_poste->raise();
        lineEdit_supp->raise();
        label_14->raise();
        label_4->raise();
        pushButton_3->raise();
        label_10->raise();
        pushButton_supp->raise();
        label_11->raise();
        tableView->raise();
        pushButton_pdf->raise();
        comboBox_trie->raise();
        filtre->raise();
        page_profil = new QWidget();
        page_profil->setObjectName("page_profil");
        label_12 = new QLabel(page_profil);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 0, 201, 601));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        pushButton_6 = new QPushButton(page_profil);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(40, 200, 141, 41));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_7 = new QPushButton(page_profil);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(40, 440, 141, 41));
        pushButton_7->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_8 = new QPushButton(page_profil);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(40, 380, 141, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_9 = new QPushButton(page_profil);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(40, 260, 141, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_10 = new QPushButton(page_profil);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(40, 320, 141, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        logo_2 = new QLabel(page_profil);
        logo_2->setObjectName("logo_2");
        logo_2->setGeometry(QRect(30, 20, 161, 141));
        logo_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo_2->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logo_2->setScaledContents(true);
        label_15 = new QLabel(page_profil);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(210, 0, 661, 591));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        label_16 = new QLabel(page_profil);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(360, 10, 331, 61));
        label_16->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px;\n"
"    background-color: rgb(253, 246, 208);\n"
"    font: 16pt \"Haettenschweiler\";  /* Augment\303\251 de 14pt \303\240 16pt */\n"
"    color: rgb(46, 52, 76);\n"
"    border: 2px solid #2E344C;\n"
"    padding: 5px;\n"
"    qproperty-alignment: AlignCenter;  /* Centre le texte horizontalement et verticalement */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_17 = new QLabel(page_profil);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(530, 80, 331, 481));
        label_17->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_18 = new QLabel(page_profil);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(220, 80, 291, 241));
        label_18->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_19 = new QLabel(page_profil);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(220, 330, 291, 231));
        label_19->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        lineEdit_9 = new QLineEdit(page_profil);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(530, 80, 331, 51));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;        /* White background */\n"
"    border: 2px solid #2E344C;      /* Border color */\n"
"    border-radius: 10px;            /* Rounded corners */\n"
"    padding: 5px;                   /* Padding inside the line edit */\n"
"    color: #2E344C;                 /* Text color */\n"
"font: 14pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2E344C;      /* Keep border color when focused */\n"
"}\n"
""));
        lineEdit_10 = new QLineEdit(page_profil);
        lineEdit_10->setObjectName("lineEdit_10");
        lineEdit_10->setGeometry(QRect(220, 80, 121, 41));
        lineEdit_10->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;        /* White background */\n"
"    border: 2px solid #2E344C;      /* Border color */\n"
"    border-radius: 10px;            /* Rounded corners */\n"
"    padding: 5px;                   /* Padding inside the line edit */\n"
"    color: #2E344C;                 /* Text color */\n"
"font: 14pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2E344C;      /* Keep border color when focused */\n"
"}\n"
""));
        label_20 = new QLabel(page_profil);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(230, 340, 49, 16));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_21 = new QLabel(page_profil);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(400, 340, 49, 16));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_22 = new QLabel(page_profil);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(230, 420, 49, 16));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_23 = new QLabel(page_profil);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(400, 420, 49, 16));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_24 = new QLabel(page_profil);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(230, 490, 49, 16));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_25 = new QLabel(page_profil);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(400, 490, 71, 16));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        pushButton_photo = new QPushButton(page_profil);
        pushButton_photo->setObjectName("pushButton_photo");
        pushButton_photo->setGeometry(QRect(410, 260, 101, 51));
        pushButton_photo->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        label_prenom = new QLabel(page_profil);
        label_prenom->setObjectName("label_prenom");
        label_prenom->setGeometry(QRect(230, 360, 101, 41));
        label_prenom->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_poste = new QLabel(page_profil);
        label_poste->setObjectName("label_poste");
        label_poste->setGeometry(QRect(230, 440, 101, 41));
        label_poste->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_nom = new QLabel(page_profil);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(390, 360, 101, 41));
        label_nom->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_cartonJ = new QLabel(page_profil);
        label_cartonJ->setObjectName("label_cartonJ");
        label_cartonJ->setGeometry(QRect(390, 510, 41, 41));
        label_cartonJ->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_passe = new QLabel(page_profil);
        label_passe->setObjectName("label_passe");
        label_passe->setGeometry(QRect(230, 510, 101, 41));
        label_passe->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_but = new QLabel(page_profil);
        label_but->setObjectName("label_but");
        label_but->setGeometry(QRect(390, 440, 101, 41));
        label_but->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        label_cartonR = new QLabel(page_profil);
        label_cartonR->setObjectName("label_cartonR");
        label_cartonR->setGeometry(QRect(460, 510, 41, 41));
        label_cartonR->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    /* Style du texte */\n"
"    font: 16pt \"Haettenschweiler\";\n"
"    color: rgb(46, 52, 76);  /* Couleur de texte bleu fonc\303\251 */\n"
"    qproperty-alignment: AlignCenter;  /* Texte centr\303\251 */\n"
"    \n"
"    /* Arri\303\250re-plan */\n"
"    background-color: white;  /* Fond blanc */\n"
"    \n"
"    /* Bordures */\n"
"    border: 1.5px solid #2E344C;  /* Bordure bleu fonc\303\251 \303\251paissie (3px au lieu de 2px) */\n"
"    border-radius: 10px;  /* Coins arrondis */\n"
"    \n"
"    /* Espacements */\n"
"    padding: 8px 12px;  /* Plus d'espace \303\240 l'int\303\251rieur (8px haut/bas, 12px gauche/droite) */\n"
"    margin: 2px;  /* Marge ext\303\251rieure l\303\251g\303\250re */\n"
"}"));
        pushButton_retour = new QPushButton(page_profil);
        pushButton_retour->setObjectName("pushButton_retour");
        pushButton_retour->setGeometry(QRect(220, 20, 101, 41));
        pushButton_retour->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        radarWidget = new RadarWidget(page_profil);
        radarWidget->setObjectName("radarWidget");
        radarWidget->setGeometry(QRect(550, 130, 291, 161));
        lineEdit_11 = new QLineEdit(page_profil);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(530, 310, 331, 51));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;        /* White background */\n"
"    border: 2px solid #2E344C;      /* Border color */\n"
"    border-radius: 10px;            /* Rounded corners */\n"
"    padding: 5px;                   /* Padding inside the line edit */\n"
"    color: #2E344C;                 /* Text color */\n"
"font: 14pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"qproperty-alignment: AlignCenter;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2E344C;      /* Keep border color when focused */\n"
"}\n"
""));
        label_photo = new QLabel(page_profil);
        label_photo->setObjectName("label_photo");
        label_photo->setGeometry(QRect(240, 140, 161, 151));
        tableNotesJoueurs = new QTableWidget(page_profil);
        tableNotesJoueurs->setObjectName("tableNotesJoueurs");
        tableNotesJoueurs->setGeometry(QRect(535, 360, 321, 192));
        tableNotesJoueurs->setStyleSheet(QString::fromUtf8("/* Style minimaliste pour QTableWidget */\n"
"QTableWidget {\n"
"    background-color: white;\n"
"    border: 1px solid #ccc;\n"
"    gridline-color: #ddd;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2E344C;\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 3px;\n"
"    border: none;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #2E344C;\n"
"    color: white;\n"
"}"));
        stackedWidget->addWidget(page_profil);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        lineEdit_cartonJ->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        lineEdit_passe->setText(QString());
        filtre->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Joueus", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "     Goal                         Assist                ", nullptr));
        label_2->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        lineEdit_but->setText(QString());
        back->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        next->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        logo->setText(QString());
        label_9->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Veuillez saisir l'identifiant du joueur \303\240 supprimer :", nullptr));
        lineEdit_cartonR->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Equipe", nullptr));
        comboBox_poste->setItemText(0, QCoreApplication::translate("MainWindow", "BU", nullptr));
        comboBox_poste->setItemText(1, QCoreApplication::translate("MainWindow", "AD", nullptr));
        comboBox_poste->setItemText(2, QCoreApplication::translate("MainWindow", "AG", nullptr));
        comboBox_poste->setItemText(3, QCoreApplication::translate("MainWindow", "MC", nullptr));
        comboBox_poste->setItemText(4, QCoreApplication::translate("MainWindow", "MOC", nullptr));
        comboBox_poste->setItemText(5, QCoreApplication::translate("MainWindow", "MDC", nullptr));
        comboBox_poste->setItemText(6, QCoreApplication::translate("MainWindow", "DC", nullptr));
        comboBox_poste->setItemText(7, QCoreApplication::translate("MainWindow", "DG", nullptr));
        comboBox_poste->setItemText(8, QCoreApplication::translate("MainWindow", "DD", nullptr));
        comboBox_poste->setItemText(9, QCoreApplication::translate("MainWindow", "G", nullptr));

        label_14->setText(QCoreApplication::translate("MainWindow", "Identifiant :", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "           Ajouter un joueur", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        pushButton_supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Carton jaune       Carton rouge", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        comboBox_trie->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_trie->setItemText(1, QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        comboBox_trie->setItemText(2, QCoreApplication::translate("MainWindow", "Poste", nullptr));
        comboBox_trie->setItemText(3, QCoreApplication::translate("MainWindow", "But", nullptr));
        comboBox_trie->setItemText(4, QCoreApplication::translate("MainWindow", "Passe", nullptr));
        comboBox_trie->setItemText(5, QCoreApplication::translate("MainWindow", "Jaune", nullptr));
        comboBox_trie->setItemText(6, QCoreApplication::translate("MainWindow", "Rouge", nullptr));

        label_12->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Joueus", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        logo_2->setText(QString());
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "Profil du joueur ", nullptr));
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        lineEdit_9->setText(QCoreApplication::translate("MainWindow", "Statistique :", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("MainWindow", "Photo de profil :", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Buts", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Passes", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Carton R/J", nullptr));
        pushButton_photo->setText(QCoreApplication::translate("MainWindow", "Ajouter une photo", nullptr));
        label_prenom->setText(QString());
        label_poste->setText(QString());
        label_nom->setText(QString());
        label_cartonJ->setText(QString());
        label_passe->setText(QString());
        label_but->setText(QString());
        label_cartonR->setText(QString());
        pushButton_retour->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("MainWindow", "Derni\303\251re performances : ", nullptr));
        label_photo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
