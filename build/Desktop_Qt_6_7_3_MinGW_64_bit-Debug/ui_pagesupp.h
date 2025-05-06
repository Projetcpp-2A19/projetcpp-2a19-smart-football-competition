/********************************************************************************
** Form generated from reading UI file 'pagesupp.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGESUPP_H
#define UI_PAGESUPP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pagesupp
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *billets;
    QPushButton *equipe;
    QPushButton *supporter;
    QPushButton *joueur;
    QPushButton *match;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_Nom;
    QLabel *label_6;
    QLineEdit *lineEdit_prenom;
    QLabel *label_7;
    QLineEdit *lineEdit_mail;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBox;
    QDateEdit *dateEdit;
    QLabel *label_10;
    QLineEdit *lineEdit_Nom_4;
    QLabel *label_11;
    QComboBox *comboBox_2;
    QPushButton *ajouter;
    QPushButton *annuler;
    QPlainTextEdit *recherche;
    QToolButton *brecherche;
    QToolButton *tri;
    QTableView *tableView;
    QPushButton *modifier;
    QPushButton *generatePdf;
    QPushButton *statButton;
    QPushButton *supprimer;
    QLabel *logo;
    QWidget *page_2;

    void setupUi(QDialog *pagesupp)
    {
        if (pagesupp->objectName().isEmpty())
            pagesupp->setObjectName("pagesupp");
        pagesupp->resize(1500, 700);
        stackedWidget = new QStackedWidget(pagesupp);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(10, 0, 1491, 711));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 201, 691));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        billets = new QPushButton(page);
        billets->setObjectName("billets");
        billets->setGeometry(QRect(30, 330, 141, 41));
        billets->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        equipe = new QPushButton(page);
        equipe->setObjectName("equipe");
        equipe->setGeometry(QRect(30, 190, 141, 40));
        equipe->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        supporter = new QPushButton(page);
        supporter->setObjectName("supporter");
        supporter->setGeometry(QRect(30, 470, 141, 41));
        supporter->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        joueur = new QPushButton(page);
        joueur->setObjectName("joueur");
        joueur->setGeometry(QRect(30, 400, 141, 41));
        joueur->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        match = new QPushButton(page);
        match->setObjectName("match");
        match->setGeometry(QRect(30, 260, 141, 41));
        match->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 60, 441, 561));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        label_4 = new QLabel(page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 0, 271, 51));
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
        label_5 = new QLabel(page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(250, 90, 91, 30));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_Nom = new QLineEdit(page);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(244, 120, 351, 31));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_6 = new QLabel(page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(250, 160, 91, 30));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_prenom = new QLineEdit(page);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(243, 190, 351, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_7 = new QLabel(page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(250, 220, 91, 30));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_mail = new QLineEdit(page);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(240, 250, 351, 31));
        lineEdit_mail->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_8 = new QLabel(page);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(250, 280, 91, 30));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_9 = new QLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(246, 350, 191, 30));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        comboBox = new QComboBox(page);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(240, 310, 351, 41));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        dateEdit = new QDateEdit(page);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(240, 380, 351, 41));
        dateEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        label_10 = new QLabel(page);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(247, 420, 120, 30));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        lineEdit_Nom_4 = new QLineEdit(page);
        lineEdit_Nom_4->setObjectName("lineEdit_Nom_4");
        lineEdit_Nom_4->setGeometry(QRect(240, 450, 351, 31));
        lineEdit_Nom_4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        label_11 = new QLabel(page);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(247, 480, 181, 30));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        comboBox_2 = new QComboBox(page);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(240, 510, 351, 41));
        comboBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        ajouter = new QPushButton(page);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(750, 610, 171, 61));
        ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        annuler = new QPushButton(page);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(410, 560, 80, 30));
        QFont font;
        font.setUnderline(true);
        annuler->setFont(font);
        annuler->setStyleSheet(QString::fromUtf8("border:none;\n"
"qproperty-alignment: 'AlignCenter';"));
        recherche = new QPlainTextEdit(page);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(690, 20, 640, 40));
        recherche->setStyleSheet(QString::fromUtf8("border: 2px solid #2e344c;\n"
"border-radius: 15px;\n"
"background:rgb(254, 246, 209);"));
        brecherche = new QToolButton(page);
        brecherche->setObjectName("brecherche");
        brecherche->setGeometry(QRect(1270, 20, 41, 30));
        brecherche->setAutoFillBackground(false);
        brecherche->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 253, 240);\n"
"border-radius: 20px;"));
        QIcon icon;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::EditFind)) {
            icon = QIcon::fromTheme(QIcon::ThemeIcon::EditFind);
        } else {
            icon.addFile(QString::fromUtf8("../SUP"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        brecherche->setIcon(icon);
        brecherche->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        tri = new QToolButton(page);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1144, 70, 40, 30));
        tri->setAutoFillBackground(false);
        tri->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(255, 253, 240);\n"
"border-radius: 20px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../Downloads/sort-icon-2048x1641-gd2ymg6b.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tri->setIcon(icon1);
        tri->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        tableView = new QTableView(page);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(673, 120, 761, 461));
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
        modifier = new QPushButton(page);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(970, 610, 191, 61));
        modifier->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        generatePdf = new QPushButton(page);
        generatePdf->setObjectName("generatePdf");
        generatePdf->setGeometry(QRect(780, 70, 191, 41));
        generatePdf->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        statButton = new QPushButton(page);
        statButton->setObjectName("statButton");
        statButton->setGeometry(QRect(1110, 70, 211, 41));
        statButton->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        supprimer = new QPushButton(page);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(1200, 610, 181, 61));
        supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        logo = new QLabel(page);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(30, 20, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo->setScaledContents(true);
        stackedWidget->addWidget(page);
        label->raise();
        billets->raise();
        supporter->raise();
        joueur->raise();
        match->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        lineEdit_Nom->raise();
        label_6->raise();
        lineEdit_prenom->raise();
        label_7->raise();
        lineEdit_mail->raise();
        label_8->raise();
        label_9->raise();
        comboBox->raise();
        dateEdit->raise();
        label_10->raise();
        lineEdit_Nom_4->raise();
        label_11->raise();
        comboBox_2->raise();
        ajouter->raise();
        annuler->raise();
        recherche->raise();
        brecherche->raise();
        tri->raise();
        tableView->raise();
        modifier->raise();
        generatePdf->raise();
        statButton->raise();
        supprimer->raise();
        equipe->raise();
        logo->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        retranslateUi(pagesupp);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pagesupp);
    } // setupUi

    void retranslateUi(QDialog *pagesupp)
    {
        pagesupp->setWindowTitle(QCoreApplication::translate("pagesupp", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pagesupp", "TextLabel", nullptr));
        billets->setText(QCoreApplication::translate("pagesupp", "Billets", nullptr));
        equipe->setText(QCoreApplication::translate("pagesupp", "Equipes", nullptr));
        supporter->setText(QCoreApplication::translate("pagesupp", "Supporter", nullptr));
        joueur->setText(QCoreApplication::translate("pagesupp", "Joueus", nullptr));
        match->setText(QCoreApplication::translate("pagesupp", "Matchs", nullptr));
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("pagesupp", "    Ajouter un Supporter", nullptr));
        label_5->setText(QCoreApplication::translate("pagesupp", "Nom ", nullptr));
        label_6->setText(QCoreApplication::translate("pagesupp", "Prenom", nullptr));
        label_7->setText(QCoreApplication::translate("pagesupp", "E_mail", nullptr));
        label_8->setText(QCoreApplication::translate("pagesupp", "Equipe", nullptr));
        label_9->setText(QCoreApplication::translate("pagesupp", "Date de naissance", nullptr));
        label_10->setText(QCoreApplication::translate("pagesupp", "telephone", nullptr));
        label_11->setText(QCoreApplication::translate("pagesupp", "type de Suppoter", nullptr));
        ajouter->setText(QCoreApplication::translate("pagesupp", "Ajouter", nullptr));
        annuler->setText(QCoreApplication::translate("pagesupp", "Annuler", nullptr));
        recherche->setPlainText(QString());
        brecherche->setText(QCoreApplication::translate("pagesupp", "...", nullptr));
        tri->setText(QCoreApplication::translate("pagesupp", "...", nullptr));
        modifier->setText(QCoreApplication::translate("pagesupp", "Modifier", nullptr));
        generatePdf->setText(QCoreApplication::translate("pagesupp", "PDF", nullptr));
        statButton->setText(QCoreApplication::translate("pagesupp", "statistique", nullptr));
        supprimer->setText(QCoreApplication::translate("pagesupp", "Supprimer ", nullptr));
        logo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pagesupp: public Ui_pagesupp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGESUPP_H
