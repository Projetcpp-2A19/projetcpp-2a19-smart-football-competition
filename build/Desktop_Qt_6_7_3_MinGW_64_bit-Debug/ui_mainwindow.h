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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tab_matches;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *id_match;
    QLabel *label_11;
    QPushButton *pb_afficher;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *nom_equipe2;
    QLineEdit *nom_equipe1;
    QLineEdit *score;
    QLineEdit *stade;
    QLineEdit *heure_match;
    QDateEdit *date_match;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1401, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(230, -20, 1831, 911));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        tab_matches = new QTableView(tab);
        tab_matches->setObjectName("tab_matches");
        tab_matches->setGeometry(QRect(490, 90, 481, 431));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(480, 570, 161, 41));
        pb_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;"));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName("pb_modifier");
        pb_modifier->setGeometry(QRect(670, 570, 121, 41));
        pb_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;"));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName("pb_supprimer");
        pb_supprimer->setGeometry(QRect(820, 570, 141, 41));
        pb_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;"));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 101, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 220, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 150, 161, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        id_match = new QLineEdit(tab);
        id_match->setObjectName("id_match");
        id_match->setGeometry(QRect(200, 90, 241, 31));
        label_11 = new QLabel(tab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(60, 280, 101, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        pb_afficher = new QPushButton(tab);
        pb_afficher->setObjectName("pb_afficher");
        pb_afficher->setGeometry(QRect(680, 40, 101, 28));
        pb_afficher->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;"));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(-10, -60, 1541, 1031));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/img/img/1.jpg);"));
        label_12 = new QLabel(tab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 410, 121, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        label_13 = new QLabel(tab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(60, 340, 101, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        label_14 = new QLabel(tab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(50, 480, 121, 31));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
""));
        nom_equipe2 = new QLineEdit(tab);
        nom_equipe2->setObjectName("nom_equipe2");
        nom_equipe2->setGeometry(QRect(190, 490, 241, 31));
        nom_equipe1 = new QLineEdit(tab);
        nom_equipe1->setObjectName("nom_equipe1");
        nom_equipe1->setGeometry(QRect(190, 420, 241, 31));
        score = new QLineEdit(tab);
        score->setObjectName("score");
        score->setGeometry(QRect(190, 340, 241, 31));
        stade = new QLineEdit(tab);
        stade->setObjectName("stade");
        stade->setGeometry(QRect(190, 280, 241, 31));
        heure_match = new QLineEdit(tab);
        heure_match->setObjectName("heure_match");
        heure_match->setGeometry(QRect(190, 220, 251, 31));
        date_match = new QDateEdit(tab);
        date_match->setObjectName("date_match");
        date_match->setGeometry(QRect(210, 160, 221, 22));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 431, 571));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(253, 246, 208);\n"
"border-radius: 15px;"));
        tabWidget->addTab(tab, QString());
        label_4->raise();
        label_3->raise();
        tab_matches->raise();
        pb_ajouter->raise();
        pb_supprimer->raise();
        label_2->raise();
        label_5->raise();
        label_6->raise();
        id_match->raise();
        label_11->raise();
        pb_afficher->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        nom_equipe2->raise();
        nom_equipe1->raise();
        score->raise();
        stade->raise();
        heure_match->raise();
        date_match->raise();
        pb_modifier->raise();
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(true);
        pushButton_2->setGeometry(QRect(30, 180, 171, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"font: 12pt \"Haettenschweiler\";\n"
" border-radius: 10px;\n"
"    border: none;\n"
"}\n"
""));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 10, 181, 151));
        label_7->setAcceptDrops(true);
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../Desktop/wetransfer_gmatches_2025-03-05_1214/Gmatches/logo.png")));
        label_7->setScaledContents(true);
        label_7->setOpenExternalLinks(true);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 320, 171, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"font: 12pt \"Haettenschweiler\";\n"
" border-radius: 10px;\n"
"    border: none;\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 460, 171, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"font: 12pt \"Haettenschweiler\";\n"
" border-radius: 10px;\n"
"    border: none;\n"
"}"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(30, 250, 171, 41));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"font: 12pt \"Haettenschweiler\";\n"
" border-radius: 10px;\n"
"    border: none;\n"
"}\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 231, 621));
        label->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(46, 52, 76);"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(30, 390, 171, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"font: 12pt \"Haettenschweiler\";\n"
" border-radius: 10px;\n"
"    border: none;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        tabWidget->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        pushButton->raise();
        pushButton_4->raise();
        label_7->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1401, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        pushButton_4->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pb_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "id_match ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "heure_match ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "date_match ", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "stade ", nullptr));
        pb_afficher->setText(QCoreApplication::translate("MainWindow", "show table", nullptr));
        label_3->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "nom_equipe1 ", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "score ", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "nom_equipe2", nullptr));
        label_4->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "main page", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        label_7->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        label->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "joueurs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
