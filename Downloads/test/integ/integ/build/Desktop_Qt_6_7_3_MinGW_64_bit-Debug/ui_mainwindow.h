/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *stackedWidgetPage1;
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
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *score;
    QLineEdit *heure_match;
    QDateEdit *date_match;
    QLabel *label_4;
    QComboBox *stade;
    QPushButton *pb_export_pdf;
    QLineEdit *search_lineedit;
    QPushButton *stat;
    QComboBox *comboBox_tri;
    QComboBox *comboBox_chercher;
    QComboBox *nom_equipe1_combo;
    QComboBox *nom_equipe2_combo;
    QPushButton *chatbot_button;
    QLabel *label_7;
    QWidget *page_2;
    QWidget *page;
    QTextBrowser *chat_history;
    QLineEdit *chat_input;
    QPushButton *chat_send_button;
    QPushButton *chat_return_button;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *logo;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1500, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(240, 0, 1161, 651));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        stackedWidgetPage1 = new QWidget();
        stackedWidgetPage1->setObjectName("stackedWidgetPage1");
        tab_matches = new QTableView(stackedWidgetPage1);
        tab_matches->setObjectName("tab_matches");
        tab_matches->setGeometry(QRect(510, 130, 601, 431));
        tab_matches->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        tab_matches->horizontalHeader()->setVisible(false);
        pb_ajouter = new QPushButton(stackedWidgetPage1);
        pb_ajouter->setObjectName("pb_ajouter");
        pb_ajouter->setGeometry(QRect(50, 560, 141, 41));
        pb_ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        pb_modifier = new QPushButton(stackedWidgetPage1);
        pb_modifier->setObjectName("pb_modifier");
        pb_modifier->setGeometry(QRect(230, 560, 131, 41));
        pb_modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        pb_supprimer = new QPushButton(stackedWidgetPage1);
        pb_supprimer->setObjectName("pb_supprimer");
        pb_supprimer->setGeometry(QRect(640, 580, 161, 61));
        pb_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_2 = new QLabel(stackedWidgetPage1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 70, 101, 41));
        label_2->setMinimumSize(QSize(101, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
"\n"
""));
        label_5 = new QLabel(stackedWidgetPage1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 210, 141, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;"));
        label_6 = new QLabel(stackedWidgetPage1);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 140, 161, 41));
        label_6->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;"));
        id_match = new QLineEdit(stackedWidgetPage1);
        id_match->setObjectName("id_match");
        id_match->setGeometry(QRect(50, 110, 351, 31));
        id_match->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_11 = new QLabel(stackedWidgetPage1);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(50, 270, 101, 31));
        label_11->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
""));
        pb_afficher = new QPushButton(stackedWidgetPage1);
        pb_afficher->setObjectName("pb_afficher");
        pb_afficher->setGeometry(QRect(910, 580, 151, 61));
        pb_afficher->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_12 = new QLabel(stackedWidgetPage1);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 390, 191, 31));
        label_12->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
""));
        label_13 = new QLabel(stackedWidgetPage1);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(50, 330, 101, 31));
        label_13->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
""));
        label_14 = new QLabel(stackedWidgetPage1);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(50, 450, 201, 31));
        label_14->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
""));
        score = new QLineEdit(stackedWidgetPage1);
        score->setObjectName("score");
        score->setGeometry(QRect(50, 360, 351, 31));
        score->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        heure_match = new QLineEdit(stackedWidgetPage1);
        heure_match->setObjectName("heure_match");
        heure_match->setGeometry(QRect(50, 240, 351, 31));
        heure_match->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        date_match = new QDateEdit(stackedWidgetPage1);
        date_match->setObjectName("date_match");
        date_match->setGeometry(QRect(50, 180, 351, 31));
        date_match->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 5px;\n"
"    padding: 2px 5px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    width: 20px;\n"
"    border-left: 1px solid #3498db;\n"
"}"));
        date_match->setDate(QDate(2025, 3, 13));
        label_4 = new QLabel(stackedWidgetPage1);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 70, 431, 561));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}"));
        stade = new QComboBox(stackedWidgetPage1);
        stade->setObjectName("stade");
        stade->setGeometry(QRect(50, 300, 351, 31));
        stade->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #3498db;\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    background-color: white;\n"
"    color: black;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"\n"
""));
        pb_export_pdf = new QPushButton(stackedWidgetPage1);
        pb_export_pdf->setObjectName("pb_export_pdf");
        pb_export_pdf->setGeometry(QRect(670, 80, 181, 41));
        pb_export_pdf->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        search_lineedit = new QLineEdit(stackedWidgetPage1);
        search_lineedit->setObjectName("search_lineedit");
        search_lineedit->setGeometry(QRect(480, 20, 451, 51));
        search_lineedit->setStyleSheet(QString::fromUtf8("border: 2px solid #2e344c;\n"
"border-radius: 15px;\n"
"background:rgb(254, 246, 209);"));
        stat = new QPushButton(stackedWidgetPage1);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(860, 80, 141, 41));
        stat->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        comboBox_tri = new QComboBox(stackedWidgetPage1);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(490, 80, 171, 41));
        comboBox_tri->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        comboBox_chercher = new QComboBox(stackedWidgetPage1);
        comboBox_chercher->addItem(QString());
        comboBox_chercher->addItem(QString());
        comboBox_chercher->addItem(QString());
        comboBox_chercher->addItem(QString());
        comboBox_chercher->setObjectName("comboBox_chercher");
        comboBox_chercher->setGeometry(QRect(940, 30, 201, 41));
        comboBox_chercher->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        nom_equipe1_combo = new QComboBox(stackedWidgetPage1);
        nom_equipe1_combo->setObjectName("nom_equipe1_combo");
        nom_equipe1_combo->setGeometry(QRect(50, 420, 351, 26));
        nom_equipe1_combo->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        nom_equipe2_combo = new QComboBox(stackedWidgetPage1);
        nom_equipe2_combo->setObjectName("nom_equipe2_combo");
        nom_equipe2_combo->setGeometry(QRect(50, 480, 351, 26));
        nom_equipe2_combo->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        chatbot_button = new QPushButton(stackedWidgetPage1);
        chatbot_button->setObjectName("chatbot_button");
        chatbot_button->setGeometry(QRect(1010, 80, 131, 41));
        chatbot_button->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_7 = new QLabel(stackedWidgetPage1);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 10, 341, 51));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        stackedWidget->addWidget(stackedWidgetPage1);
        label_4->raise();
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
        score->raise();
        heure_match->raise();
        date_match->raise();
        pb_modifier->raise();
        stade->raise();
        pb_export_pdf->raise();
        search_lineedit->raise();
        stat->raise();
        comboBox_tri->raise();
        comboBox_chercher->raise();
        nom_equipe1_combo->raise();
        nom_equipe2_combo->raise();
        chatbot_button->raise();
        label_7->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName("page");
        chat_history = new QTextBrowser(page);
        chat_history->setObjectName("chat_history");
        chat_history->setGeometry(QRect(180, 70, 641, 461));
        chat_history->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
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
        chat_input = new QLineEdit(page);
        chat_input->setObjectName("chat_input");
        chat_input->setGeometry(QRect(180, 540, 471, 41));
        chat_input->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        chat_send_button = new QPushButton(page);
        chat_send_button->setObjectName("chat_send_button");
        chat_send_button->setGeometry(QRect(670, 540, 161, 41));
        chat_send_button->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        chat_return_button = new QPushButton(page);
        chat_return_button->setObjectName("chat_return_button");
        chat_return_button->setGeometry(QRect(1000, 570, 131, 41));
        chat_return_button->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(340, 30, 361, 20));
        label_8->setStyleSheet(QString::fromUtf8("font: 12pt \"Haettenschweiler\";\n"
"color: rgb(46, 52, 76);\n"
"font-weight: bold;\n"
"\n"
""));
        stackedWidget->addWidget(page);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 370, 1541, 1191));
        label_3->setStyleSheet(QString::fromUtf8("border-image: url(:/img/img/1.jpg);"));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 50, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo->setScaledContents(true);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(40, 450, 141, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 390, 141, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 270, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 330, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 201, 691));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 210, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        label_3->raise();
        stackedWidget->raise();
        logo->raise();
        pushButton_5->raise();
        pushButton_4->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1500, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pb_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Heure", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Stade ", nullptr));
        pb_afficher->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\303\251quipe \303\240 domicile", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\303\251quipe \303\240 l'ext\303\251rieur", nullptr));
        label_4->setText(QString());
        pb_export_pdf->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        stat->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "-- Trier par --", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "Date", nullptr));
        comboBox_tri->setItemText(3, QCoreApplication::translate("MainWindow", "Stade", nullptr));

        comboBox_chercher->setItemText(0, QCoreApplication::translate("MainWindow", "-- Chercher par --", nullptr));
        comboBox_chercher->setItemText(1, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox_chercher->setItemText(2, QCoreApplication::translate("MainWindow", "Nom \303\211quipe", nullptr));
        comboBox_chercher->setItemText(3, QCoreApplication::translate("MainWindow", "Stade", nullptr));

        chatbot_button->setText(QCoreApplication::translate("MainWindow", "ChatBot", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "           Ajouter un match", nullptr));
        chat_send_button->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        chat_return_button->setText(QCoreApplication::translate("MainWindow", "Retour", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Historique des matchs de l'\303\251quipe", nullptr));
        label_3->setText(QString());
        logo->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Supporter", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Joueus", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Matchs", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Billets", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Equipes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
