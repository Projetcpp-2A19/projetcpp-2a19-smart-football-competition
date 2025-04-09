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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_prenom;
    QLabel *label_5;
    QLabel *back;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *logo;
    QLineEdit *lineEdit_cartonR;
    QPushButton *pushButton_ajouter;
    QLabel *filtre;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLineEdit *lineEdit_7;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_but;
    QLabel *label_7;
    QLineEdit *lineEdit_passe;
    QLineEdit *lineEdit_cartonJ;
    QLineEdit *lineEdit_nom;
    QLabel *label_10;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_supp;
    QPushButton *pushButton_supp;
    QTableView *tableView;
    QLabel *next;
    QPushButton *pushButton_modifier;
    QComboBox *comboBox_poste;
    QComboBox *comboBox_equipe;
    QLabel *label_11;
    QPushButton *TrieButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(894, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit_prenom = new QLineEdit(centralwidget);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(230, 90, 141, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"color: rgb(46, 52, 76);"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 120, 111, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        back = new QLabel(centralwidget);
        back->setObjectName("back");
        back->setGeometry(QRect(750, 10, 31, 31));
        back->setStyleSheet(QString::fromUtf8("image: url(:/pic/back.jpeg);"));
        back->setPixmap(QPixmap(QString::fromUtf8(":/pic/back.jpeg")));
        back->setScaledContents(true);
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
        label_4->setGeometry(QRect(210, 0, 191, 51));
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
        label_8->setGeometry(QRect(220, 300, 161, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(20, 20, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("logo.png")));
        logo->setScaledContents(true);
        lineEdit_cartonR = new QLineEdit(centralwidget);
        lineEdit_cartonR->setObjectName("lineEdit_cartonR");
        lineEdit_cartonR->setGeometry(QRect(230, 390, 51, 31));
        lineEdit_cartonR->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(230, 430, 151, 41));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        filtre = new QLabel(centralwidget);
        filtre->setObjectName("filtre");
        filtre->setGeometry(QRect(700, 10, 31, 31));
        filtre->setStyleSheet(QString::fromUtf8("image: url(:/pic/filtre.jpeg);"));
        filtre->setPixmap(QPixmap(QString::fromUtf8("filtre.jpeg")));
        filtre->setScaledContents(true);
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
        label_6->setGeometry(QRect(230, 180, 101, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(420, 0, 321, 51));
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
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 60, 191, 471));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
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
        label_2->setGeometry(QRect(190, 0, 661, 561));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 242);"));
        lineEdit_but = new QLineEdit(centralwidget);
        lineEdit_but->setObjectName("lineEdit_but");
        lineEdit_but->setGeometry(QRect(230, 330, 51, 31));
        lineEdit_but->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(230, 240, 101, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_passe = new QLineEdit(centralwidget);
        lineEdit_passe->setObjectName("lineEdit_passe");
        lineEdit_passe->setGeometry(QRect(330, 330, 51, 31));
        lineEdit_passe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_cartonJ = new QLineEdit(centralwidget);
        lineEdit_cartonJ->setObjectName("lineEdit_cartonJ");
        lineEdit_cartonJ->setGeometry(QRect(330, 390, 51, 31));
        lineEdit_cartonJ->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_nom = new QLineEdit(centralwidget);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(230, 150, 141, 31));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(230, 70, 49, 16));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(410, 370, 441, 151));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(420, 370, 301, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(420, 440, 81, 16));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
"\n"
""));
        lineEdit_supp = new QLineEdit(centralwidget);
        lineEdit_supp->setObjectName("lineEdit_supp");
        lineEdit_supp->setGeometry(QRect(420, 460, 113, 22));
        pushButton_supp = new QPushButton(centralwidget);
        pushButton_supp->setObjectName("pushButton_supp");
        pushButton_supp->setGeometry(QRect(744, 450, 91, 31));
        pushButton_supp->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(410, 70, 431, 281));
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
");"));
        next = new QLabel(centralwidget);
        next->setObjectName("next");
        next->setGeometry(QRect(800, 10, 31, 31));
        next->setStyleSheet(QString::fromUtf8("image: url(:/pic/next.jpeg);"));
        next->setPixmap(QPixmap(QString::fromUtf8(":/pic/next.jpeg")));
        next->setScaledContents(true);
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(230, 480, 151, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        comboBox_poste = new QComboBox(centralwidget);
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
        comboBox_poste->setGeometry(QRect(230, 210, 141, 31));
        comboBox_poste->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        comboBox_equipe = new QComboBox(centralwidget);
        comboBox_equipe->setObjectName("comboBox_equipe");
        comboBox_equipe->setGeometry(QRect(230, 270, 141, 31));
        comboBox_equipe->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 76);"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(220, 360, 181, 31));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        TrieButton = new QPushButton(centralwidget);
        TrieButton->setObjectName("TrieButton");
        TrieButton->setGeometry(QRect(690, 0, 51, 51));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label_3->raise();
        label->raise();
        lineEdit_prenom->raise();
        label_5->raise();
        pushButton->raise();
        pushButton_4->raise();
        label_4->raise();
        label_8->raise();
        logo->raise();
        lineEdit_cartonR->raise();
        pushButton_ajouter->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        label_6->raise();
        lineEdit_7->raise();
        pushButton_5->raise();
        lineEdit_but->raise();
        label_7->raise();
        lineEdit_passe->raise();
        lineEdit_cartonJ->raise();
        lineEdit_nom->raise();
        label_10->raise();
        label_9->raise();
        label_13->raise();
        label_14->raise();
        lineEdit_supp->raise();
        pushButton_supp->raise();
        tableView->raise();
        back->raise();
        next->raise();
        pushButton_modifier->raise();
        comboBox_poste->raise();
        comboBox_equipe->raise();
        label_11->raise();
        TrieButton->raise();
        filtre->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        back->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Joueus", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "           Ajouter un joueur", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "     Goal                         Assist                ", nullptr));
        logo->setText(QString());
        lineEdit_cartonR->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        filtre->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        label_3->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QString());
        lineEdit_but->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Equipe", nullptr));
        lineEdit_passe->setText(QString());
        lineEdit_cartonJ->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        label_9->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "Veuillez saisir l'identifiant du joueur \303\240 supprimer :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Identifiant :", nullptr));
        pushButton_supp->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        next->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
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

        label_11->setText(QCoreApplication::translate("MainWindow", "Carton jaune       Carton rouge", nullptr));
        TrieButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
