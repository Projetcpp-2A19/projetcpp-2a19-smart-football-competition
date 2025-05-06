/********************************************************************************
** Form generated from reading UI file 'pagejoueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEJOUEUR_H
#define UI_PAGEJOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "radarwidget.h"

QT_BEGIN_NAMESPACE

class Ui_pagejoueur
{
public:
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
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_cartonR;
    QLabel *label_7;
    QComboBox *comboBox_poste;
    QLineEdit *lineEdit_supp;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QPushButton *pushButton_supp;
    QLabel *label_11;
    QTableView *tableView;
    QPushButton *pushButton_pdf;
    QComboBox *comboBox_trie;
    QLabel *label_29;
    QLabel *label_13;
    QLabel *label_30;
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
    QPushButton *pushButton_lock;
    QWidget *page_controle;
    QLabel *label_26;
    QLabel *logo_3;
    QLabel *label_53;
    QLabel *label_55;
    QLabel *label_54;
    QPushButton *pushButton_retour_2;
    QWidget *page_3;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *logo_7;
    QLabel *label_59;
    QPushButton *pushButton_retour_3;
    QLabel *label_entree;
    QLabel *label_60;
    QLabel *label_27;
    QWidget *page_4;
    QLabel *label_93;
    QLabel *label_94;
    QLabel *logo_12;
    QLabel *label_95;
    QLabel *label_96;
    QLabel *label_97;
    QPushButton *pushButton_retour_4;
    QLabel *label_28;

    void setupUi(QDialog *pagejoueur)
    {
        if (pagejoueur->objectName().isEmpty())
            pagejoueur->setObjectName("pagejoueur");
        pagejoueur->setEnabled(true);
        pagejoueur->resize(1500, 700);
        stackedWidget = new QStackedWidget(pagejoueur);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 10, 1491, 691));
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
        lineEdit_cartonJ->setGeometry(QRect(440, 560, 141, 31));
        lineEdit_cartonJ->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
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
        lineEdit_passe->setGeometry(QRect(440, 471, 141, 31));
        lineEdit_passe->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        filtre = new QLabel(page_acceuil);
        filtre->setObjectName("filtre");
        filtre->setGeometry(QRect(1270, 10, 51, 51));
        filtre->setStyleSheet(QString::fromUtf8("image: url(:/pic/filtre.jpeg);"));
        filtre->setPixmap(QPixmap(QString::fromUtf8("../joueur/filtre.jpeg")));
        filtre->setScaledContents(true);
        pushButton_modifier = new QPushButton(page_acceuil);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(980, 590, 231, 61));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        comboBox_equipe = new QComboBox(page_acceuil);
        comboBox_equipe->setObjectName("comboBox_equipe");
        comboBox_equipe->setGeometry(QRect(280, 390, 301, 31));
        comboBox_equipe->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
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
        label->setGeometry(QRect(5, -1, 201, 691));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_8 = new QLabel(page_acceuil);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(260, 430, 101, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_2 = new QLabel(page_acceuil);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, -10, 1301, 691));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        label_5 = new QLabel(page_acceuil);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 170, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_but = new QLineEdit(page_acceuil);
        lineEdit_but->setObjectName("lineEdit_but");
        lineEdit_but->setGeometry(QRect(280, 470, 121, 31));
        lineEdit_but->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        back = new QLabel(page_acceuil);
        back->setObjectName("back");
        back->setGeometry(QRect(755, 9, 31, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/pic/back.jpeg);"));
        back->setPixmap(QPixmap(QString::fromUtf8(":/pic/back.jpeg")));
        back->setScaledContents(true);
        pushButton_ajouter = new QPushButton(page_acceuil);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(720, 590, 211, 61));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        next = new QLabel(page_acceuil);
        next->setObjectName("next");
        next->setGeometry(QRect(805, 9, 31, 31));
        next->setStyleSheet(QString::fromUtf8("image: url(:/pic/next.jpeg);"));
        next->setPixmap(QPixmap(QString::fromUtf8(":/pic/next.jpeg")));
        next->setScaledContents(true);
        lineEditRecherche = new QLineEdit(page_acceuil);
        lineEditRecherche->setObjectName("lineEditRecherche");
        lineEditRecherche->setGeometry(QRect(710, 10, 671, 51));
        lineEditRecherche->setStyleSheet(QString::fromUtf8("border: 2px solid #2e344c;\n"
"border-radius: 15px;\n"
"background:rgb(254, 246, 209);"));
        label_6 = new QLabel(page_acceuil);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(280, 260, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        logo = new QLabel(page_acceuil);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(25, 19, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo->setScaledContents(true);
        lineEdit_prenom = new QLineEdit(page_acceuil);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(280, 130, 301, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        lineEdit_nom = new QLineEdit(page_acceuil);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(280, 220, 301, 31));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        lineEdit_cartonR = new QLineEdit(page_acceuil);
        lineEdit_cartonR->setObjectName("lineEdit_cartonR");
        lineEdit_cartonR->setGeometry(QRect(280, 560, 121, 31));
        lineEdit_cartonR->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_7 = new QLabel(page_acceuil);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(280, 340, 101, 31));
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
        comboBox_poste->setGeometry(QRect(280, 300, 301, 31));
        comboBox_poste->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        lineEdit_supp = new QLineEdit(page_acceuil);
        lineEdit_supp->setObjectName("lineEdit_supp");
        lineEdit_supp->setGeometry(QRect(20, 630, 301, 31));
        lineEdit_supp->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_4 = new QLabel(page_acceuil);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(260, 10, 301, 51));
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
        label_10->setGeometry(QRect(280, 100, 81, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        pushButton_supp = new QPushButton(page_acceuil);
        pushButton_supp->setObjectName("pushButton_supp");
        pushButton_supp->setGeometry(QRect(1250, 590, 191, 61));
        pushButton_supp->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_11 = new QLabel(page_acceuil);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(280, 520, 131, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        tableView = new QTableView(page_acceuil);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(680, 80, 781, 491));
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
        pushButton_pdf->setGeometry(QRect(1390, 20, 91, 41));
        pushButton_pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        comboBox_trie = new QComboBox(page_acceuil);
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->addItem(QString());
        comboBox_trie->setObjectName("comboBox_trie");
        comboBox_trie->setGeometry(QRect(1320, 10, 61, 51));
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
        label_29 = new QLabel(page_acceuil);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(220, 70, 431, 591));
        label_29->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}"));
        label_13 = new QLabel(page_acceuil);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(440, 430, 131, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_30 = new QLabel(page_acceuil);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(450, 520, 141, 31));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        stackedWidget->addWidget(page_acceuil);
        lineEdit_supp->raise();
        label_2->raise();
        label_29->raise();
        lineEditRecherche->raise();
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
        lineEdit_nom->raise();
        lineEdit_cartonR->raise();
        label_7->raise();
        comboBox_poste->raise();
        label_4->raise();
        pushButton_3->raise();
        label_10->raise();
        pushButton_supp->raise();
        label_11->raise();
        tableView->raise();
        pushButton_pdf->raise();
        comboBox_trie->raise();
        filtre->raise();
        label_13->raise();
        label_30->raise();
        page_profil = new QWidget();
        page_profil->setObjectName("page_profil");
        label_12 = new QLabel(page_profil);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 0, 201, 691));
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
        logo_2->setGeometry(QRect(30, 20, 161, 140));
        logo_2->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo_2->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo_2->setScaledContents(true);
        label_15 = new QLabel(page_profil);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(210, 0, 1491, 691));
        label_15->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        label_16 = new QLabel(page_profil);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(560, 10, 331, 61));
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
        label_17->setGeometry(QRect(810, 80, 431, 601));
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
        label_18->setGeometry(QRect(320, 80, 401, 281));
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
        label_19->setGeometry(QRect(320, 370, 411, 311));
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
        lineEdit_9->setGeometry(QRect(860, 100, 331, 51));
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
        lineEdit_10->setGeometry(QRect(330, 80, 191, 41));
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
        label_20->setGeometry(QRect(330, 390, 91, 16));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_21 = new QLabel(page_profil);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(580, 390, 49, 16));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_22 = new QLabel(page_profil);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(330, 480, 81, 21));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_23 = new QLabel(page_profil);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(570, 480, 61, 21));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_24 = new QLabel(page_profil);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(340, 580, 91, 21));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_25 = new QLabel(page_profil);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(570, 570, 121, 21));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        pushButton_photo = new QPushButton(page_profil);
        pushButton_photo->setObjectName("pushButton_photo");
        pushButton_photo->setGeometry(QRect(530, 320, 181, 31));
        pushButton_photo->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        label_prenom = new QLabel(page_profil);
        label_prenom->setObjectName("label_prenom");
        label_prenom->setGeometry(QRect(330, 420, 131, 51));
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
        label_poste->setGeometry(QRect(330, 510, 131, 51));
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
        label_nom->setGeometry(QRect(570, 420, 141, 51));
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
        label_cartonJ->setGeometry(QRect(570, 620, 61, 51));
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
        label_passe->setGeometry(QRect(330, 610, 151, 51));
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
        label_but->setGeometry(QRect(570, 510, 131, 51));
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
        label_cartonR->setGeometry(QRect(660, 620, 61, 51));
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
        radarWidget->setGeometry(QRect(880, 160, 291, 181));
        lineEdit_11 = new QLineEdit(page_profil);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(860, 360, 331, 51));
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
        label_photo->setGeometry(QRect(340, 150, 201, 161));
        tableNotesJoueurs = new QTableWidget(page_profil);
        tableNotesJoueurs->setObjectName("tableNotesJoueurs");
        tableNotesJoueurs->setGeometry(QRect(840, 420, 391, 251));
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
        pushButton_lock = new QPushButton(page_profil);
        pushButton_lock->setObjectName("pushButton_lock");
        pushButton_lock->setGeometry(QRect(90, 510, 41, 41));
        pushButton_lock->setStyleSheet(QString::fromUtf8("image: url(:/pic/unlock.png);"));
        stackedWidget->addWidget(page_profil);
        page_controle = new QWidget();
        page_controle->setObjectName("page_controle");
        label_26 = new QLabel(page_controle);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(40, 20, 1231, 641));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        logo_3 = new QLabel(page_controle);
        logo_3->setObjectName("logo_3");
        logo_3->setGeometry(QRect(590, 80, 191, 161));
        logo_3->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo_3->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo_3->setScaledContents(true);
        label_53 = new QLabel(page_controle);
        label_53->setObjectName("label_53");
        label_53->setGeometry(QRect(10, 0, 1301, 691));
        label_53->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        label_55 = new QLabel(page_controle);
        label_55->setObjectName("label_55");
        label_55->setGeometry(QRect(480, 330, 411, 131));
        label_55->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"\n"
""));
        label_54 = new QLabel(page_controle);
        label_54->setObjectName("label_54");
        label_54->setGeometry(QRect(560, 370, 281, 51));
        label_54->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 20pt \"Haettenschweiler\";"));
        pushButton_retour_2 = new QPushButton(page_controle);
        pushButton_retour_2->setObjectName("pushButton_retour_2");
        pushButton_retour_2->setGeometry(QRect(50, 30, 101, 41));
        pushButton_retour_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        stackedWidget->addWidget(page_controle);
        label_53->raise();
        label_26->raise();
        logo_3->raise();
        label_55->raise();
        label_54->raise();
        pushButton_retour_2->raise();
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_56 = new QLabel(page_3);
        label_56->setObjectName("label_56");
        label_56->setGeometry(QRect(20, 10, 1261, 651));
        label_56->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_57 = new QLabel(page_3);
        label_57->setObjectName("label_57");
        label_57->setGeometry(QRect(250, 180, 661, 461));
        label_57->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"\n"
""));
        label_58 = new QLabel(page_3);
        label_58->setObjectName("label_58");
        label_58->setGeometry(QRect(10, 0, 1301, 691));
        label_58->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        logo_7 = new QLabel(page_3);
        logo_7->setObjectName("logo_7");
        logo_7->setGeometry(QRect(490, 20, 191, 161));
        logo_7->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo_7->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo_7->setScaledContents(true);
        label_59 = new QLabel(page_3);
        label_59->setObjectName("label_59");
        label_59->setGeometry(QRect(270, 200, 251, 51));
        label_59->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 20pt \"Haettenschweiler\";"));
        pushButton_retour_3 = new QPushButton(page_3);
        pushButton_retour_3->setObjectName("pushButton_retour_3");
        pushButton_retour_3->setGeometry(QRect(30, 20, 101, 41));
        pushButton_retour_3->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        label_entree = new QLabel(page_3);
        label_entree->setObjectName("label_entree");
        label_entree->setGeometry(QRect(550, 570, 111, 41));
        label_entree->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        label_60 = new QLabel(page_3);
        label_60->setObjectName("label_60");
        label_60->setGeometry(QRect(270, 560, 241, 51));
        label_60->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 16pt \"Haettenschweiler\";"));
        label_27 = new QLabel(page_3);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(370, 280, 171, 141));
        label_27->setStyleSheet(QString::fromUtf8("image: url(:/pic/correct.png);"));
        stackedWidget->addWidget(page_3);
        label_58->raise();
        label_56->raise();
        label_57->raise();
        logo_7->raise();
        label_59->raise();
        pushButton_retour_3->raise();
        label_entree->raise();
        label_60->raise();
        label_27->raise();
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_93 = new QLabel(page_4);
        label_93->setObjectName("label_93");
        label_93->setGeometry(QRect(30, 30, 1251, 641));
        label_93->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_94 = new QLabel(page_4);
        label_94->setObjectName("label_94");
        label_94->setGeometry(QRect(10, 0, 1301, 691));
        label_94->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        logo_12 = new QLabel(page_4);
        logo_12->setObjectName("logo_12");
        logo_12->setGeometry(QRect(490, 50, 191, 161));
        logo_12->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo_12->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo_12->setScaledContents(true);
        label_95 = new QLabel(page_4);
        label_95->setObjectName("label_95");
        label_95->setGeometry(QRect(370, 440, 151, 51));
        label_95->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 20pt \"Haettenschweiler\";"));
        label_96 = new QLabel(page_4);
        label_96->setObjectName("label_96");
        label_96->setGeometry(QRect(270, 230, 641, 421));
        label_96->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
"\n"
""));
        label_97 = new QLabel(page_4);
        label_97->setObjectName("label_97");
        label_97->setGeometry(QRect(290, 250, 191, 51));
        label_97->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 20pt \"Haettenschweiler\";"));
        pushButton_retour_4 = new QPushButton(page_4);
        pushButton_retour_4->setObjectName("pushButton_retour_4");
        pushButton_retour_4->setGeometry(QRect(40, 50, 101, 41));
        pushButton_retour_4->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        label_28 = new QLabel(page_4);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(480, 330, 211, 171));
        label_28->setStyleSheet(QString::fromUtf8("image: url(:/pic/delete.png);"));
        stackedWidget->addWidget(page_4);
        label_94->raise();
        label_93->raise();
        logo_12->raise();
        label_95->raise();
        label_96->raise();
        label_97->raise();
        pushButton_retour_4->raise();
        label_28->raise();

        retranslateUi(pagejoueur);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pagejoueur);
    } // setupUi

    void retranslateUi(QDialog *pagejoueur)
    {
        pagejoueur->setWindowTitle(QCoreApplication::translate("pagejoueur", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pagejoueur", "Matchs", nullptr));
        pushButton_5->setText(QCoreApplication::translate("pagejoueur", "Supporter", nullptr));
        lineEdit_cartonJ->setText(QString());
        pushButton->setText(QCoreApplication::translate("pagejoueur", "Equipes", nullptr));
        lineEdit_passe->setText(QString());
        filtre->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("pagejoueur", "Modifier", nullptr));
        pushButton_4->setText(QCoreApplication::translate("pagejoueur", "Joueus", nullptr));
        label->setText(QCoreApplication::translate("pagejoueur", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("pagejoueur", "     Goal    ", nullptr));
        label_2->setText(QString());
        label_5->setText(QCoreApplication::translate("pagejoueur", "Nom", nullptr));
        lineEdit_but->setText(QString());
        back->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("pagejoueur", "Ajouter", nullptr));
        next->setText(QString());
        label_6->setText(QCoreApplication::translate("pagejoueur", "Poste", nullptr));
        logo->setText(QString());
        lineEdit_cartonR->setText(QString());
        label_7->setText(QCoreApplication::translate("pagejoueur", "Equipe", nullptr));
        comboBox_poste->setItemText(0, QCoreApplication::translate("pagejoueur", "BU", nullptr));
        comboBox_poste->setItemText(1, QCoreApplication::translate("pagejoueur", "AD", nullptr));
        comboBox_poste->setItemText(2, QCoreApplication::translate("pagejoueur", "AG", nullptr));
        comboBox_poste->setItemText(3, QCoreApplication::translate("pagejoueur", "MC", nullptr));
        comboBox_poste->setItemText(4, QCoreApplication::translate("pagejoueur", "MOC", nullptr));
        comboBox_poste->setItemText(5, QCoreApplication::translate("pagejoueur", "MDC", nullptr));
        comboBox_poste->setItemText(6, QCoreApplication::translate("pagejoueur", "DC", nullptr));
        comboBox_poste->setItemText(7, QCoreApplication::translate("pagejoueur", "DG", nullptr));
        comboBox_poste->setItemText(8, QCoreApplication::translate("pagejoueur", "DD", nullptr));
        comboBox_poste->setItemText(9, QCoreApplication::translate("pagejoueur", "G", nullptr));

        label_4->setText(QCoreApplication::translate("pagejoueur", "           Ajouter un joueur", nullptr));
        pushButton_3->setText(QCoreApplication::translate("pagejoueur", "Billets", nullptr));
        label_10->setText(QCoreApplication::translate("pagejoueur", "Prenom", nullptr));
        pushButton_supp->setText(QCoreApplication::translate("pagejoueur", "Supprimer", nullptr));
        label_11->setText(QCoreApplication::translate("pagejoueur", "Carton jaune", nullptr));
        pushButton_pdf->setText(QCoreApplication::translate("pagejoueur", "PDF", nullptr));
        comboBox_trie->setItemText(0, QCoreApplication::translate("pagejoueur", "Nom", nullptr));
        comboBox_trie->setItemText(1, QCoreApplication::translate("pagejoueur", "Pr\303\251nom", nullptr));
        comboBox_trie->setItemText(2, QCoreApplication::translate("pagejoueur", "Poste", nullptr));
        comboBox_trie->setItemText(3, QCoreApplication::translate("pagejoueur", "But", nullptr));
        comboBox_trie->setItemText(4, QCoreApplication::translate("pagejoueur", "Passe", nullptr));
        comboBox_trie->setItemText(5, QCoreApplication::translate("pagejoueur", "Jaune", nullptr));
        comboBox_trie->setItemText(6, QCoreApplication::translate("pagejoueur", "Rouge", nullptr));

        label_29->setText(QString());
        label_13->setText(QCoreApplication::translate("pagejoueur", "assist", nullptr));
        label_30->setText(QCoreApplication::translate("pagejoueur", "Carton Rouge", nullptr));
        label_12->setText(QCoreApplication::translate("pagejoueur", "TextLabel", nullptr));
        pushButton_6->setText(QCoreApplication::translate("pagejoueur", "Equipes", nullptr));
        pushButton_7->setText(QCoreApplication::translate("pagejoueur", "Supporter", nullptr));
        pushButton_8->setText(QCoreApplication::translate("pagejoueur", "Joueus", nullptr));
        pushButton_9->setText(QCoreApplication::translate("pagejoueur", "Matchs", nullptr));
        pushButton_10->setText(QCoreApplication::translate("pagejoueur", "Billets", nullptr));
        logo_2->setText(QString());
        label_15->setText(QString());
        label_16->setText(QCoreApplication::translate("pagejoueur", "Profil du joueur ", nullptr));
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        lineEdit_9->setText(QCoreApplication::translate("pagejoueur", "Statistique :", nullptr));
        lineEdit_10->setText(QCoreApplication::translate("pagejoueur", "Photo de profil :", nullptr));
        label_20->setText(QCoreApplication::translate("pagejoueur", "Prenom", nullptr));
        label_21->setText(QCoreApplication::translate("pagejoueur", "Nom", nullptr));
        label_22->setText(QCoreApplication::translate("pagejoueur", "Poste", nullptr));
        label_23->setText(QCoreApplication::translate("pagejoueur", "Buts", nullptr));
        label_24->setText(QCoreApplication::translate("pagejoueur", "Passes", nullptr));
        label_25->setText(QCoreApplication::translate("pagejoueur", "Carton R/J", nullptr));
        pushButton_photo->setText(QCoreApplication::translate("pagejoueur", "Ajouter une photo", nullptr));
        label_prenom->setText(QString());
        label_poste->setText(QString());
        label_nom->setText(QString());
        label_cartonJ->setText(QString());
        label_passe->setText(QString());
        label_but->setText(QString());
        label_cartonR->setText(QString());
        pushButton_retour->setText(QCoreApplication::translate("pagejoueur", "Retour", nullptr));
        lineEdit_11->setText(QCoreApplication::translate("pagejoueur", "Derni\303\251re performances : ", nullptr));
        label_photo->setText(QString());
        pushButton_lock->setText(QString());
        label_26->setText(QCoreApplication::translate("pagejoueur", "TextLabel", nullptr));
        logo_3->setText(QString());
        label_53->setText(QString());
        label_55->setText(QString());
        label_54->setText(QCoreApplication::translate("pagejoueur", "Contr\303\264le d'acc\303\250s", nullptr));
        pushButton_retour_2->setText(QCoreApplication::translate("pagejoueur", "Retour", nullptr));
        label_56->setText(QCoreApplication::translate("pagejoueur", "TextLabel", nullptr));
        label_57->setText(QString());
        label_58->setText(QString());
        logo_7->setText(QString());
        label_59->setText(QCoreApplication::translate("pagejoueur", " Acc\303\250s autoris\303\251 ", nullptr));
        pushButton_retour_3->setText(QCoreApplication::translate("pagejoueur", "Retour", nullptr));
        label_entree->setText(QString());
        label_60->setText(QCoreApplication::translate("pagejoueur", "Nombre d'entr\303\251e :", nullptr));
        label_27->setText(QString());
        label_93->setText(QCoreApplication::translate("pagejoueur", "TextLabel", nullptr));
        label_94->setText(QString());
        logo_12->setText(QString());
        label_95->setText(QCoreApplication::translate("pagejoueur", "autoris\303\251", nullptr));
        label_96->setText(QString());
        label_97->setText(QCoreApplication::translate("pagejoueur", "Acc\303\250s refus\303\251", nullptr));
        pushButton_retour_4->setText(QCoreApplication::translate("pagejoueur", "Retour", nullptr));
        label_28->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pagejoueur: public Ui_pagejoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEJOUEUR_H
