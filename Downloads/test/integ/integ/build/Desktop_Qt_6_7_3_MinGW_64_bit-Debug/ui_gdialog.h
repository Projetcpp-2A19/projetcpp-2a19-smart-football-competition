/********************************************************************************
** Form generated from reading UI file 'gdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GDIALOG_H
#define UI_GDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gdialog
{
public:
    QLineEdit *num_place;
    QPushButton *modif;
    QLabel *zone_3;
    QPushButton *pushButton_11;
    QPushButton *add;
    QLineEdit *nom_stade;
    QLabel *date;
    QLabel *nom_stade_3;
    QLabel *label_;
    QLabel *num_place_3;
    QLabel *set;
    QTableView *tableView;
    QLineEdit *zone;
    QDateTimeEdit *Date;
    QPushButton *ref;
    QLineEdit *prix_billet;
    QPushButton *pushButton_3;
    QLabel *label;
    QPushButton *pushButton_5;
    QLabel *logo;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *nom_stade_4;
    QLabel *label_5;
    QPushButton *delete_2;
    QPushButton *sort;
    QPushButton *export_2;
    QLineEdit *recherche;
    QPushButton *search;
    QPushButton *tirageButton;
    QLineEdit *id;
    QWidget *stat;
    QPushButton *test;

    void setupUi(QDialog *gdialog)
    {
        if (gdialog->objectName().isEmpty())
            gdialog->setObjectName("gdialog");
        gdialog->resize(1500, 700);
        num_place = new QLineEdit(gdialog);
        num_place->setObjectName("num_place");
        num_place->setGeometry(QRect(330, 550, 341, 31));
        num_place->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        modif = new QPushButton(gdialog);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(520, 610, 161, 41));
        modif->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        zone_3 = new QLabel(gdialog);
        zone_3->setObjectName("zone_3");
        zone_3->setGeometry(QRect(330, 240, 101, 31));
        zone_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        pushButton_11 = new QPushButton(gdialog);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(82, 508, 61, 31));
        add = new QPushButton(gdialog);
        add->setObjectName("add");
        add->setGeometry(QRect(320, 610, 181, 41));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        nom_stade = new QLineEdit(gdialog);
        nom_stade->setObjectName("nom_stade");
        nom_stade->setGeometry(QRect(330, 200, 341, 31));
        nom_stade->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        date = new QLabel(gdialog);
        date->setObjectName("date");
        date->setGeometry(QRect(330, 400, 101, 31));
        date->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        nom_stade_3 = new QLabel(gdialog);
        nom_stade_3->setObjectName("nom_stade_3");
        nom_stade_3->setGeometry(QRect(330, 170, 101, 31));
        nom_stade_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_ = new QLabel(gdialog);
        label_->setObjectName("label_");
        label_->setGeometry(QRect(330, 320, 111, 31));
        label_->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        num_place_3 = new QLabel(gdialog);
        num_place_3->setObjectName("num_place_3");
        num_place_3->setGeometry(QRect(330, 500, 111, 31));
        num_place_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        set = new QLabel(gdialog);
        set->setObjectName("set");
        set->setGeometry(QRect(190, 510, 31, 31));
        tableView = new QTableView(gdialog);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(730, 120, 731, 341));
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
        zone = new QLineEdit(gdialog);
        zone->setObjectName("zone");
        zone->setGeometry(QRect(330, 280, 341, 31));
        zone->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        Date = new QDateTimeEdit(gdialog);
        Date->setObjectName("Date");
        Date->setGeometry(QRect(330, 450, 341, 31));
        Date->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        ref = new QPushButton(gdialog);
        ref->setObjectName("ref");
        ref->setGeometry(QRect(1460, 120, 21, 21));
        ref->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        QIcon icon;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::SystemReboot)) {
            icon = QIcon::fromTheme(QIcon::ThemeIcon::SystemReboot);
        } else {
            icon.addFile(QString::fromUtf8("../billets"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        ref->setIcon(icon);
        prix_billet = new QLineEdit(gdialog);
        prix_billet->setObjectName("prix_billet");
        prix_billet->setGeometry(QRect(330, 360, 341, 31));
        prix_billet->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        pushButton_3 = new QPushButton(gdialog);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(60, 300, 141, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label = new QLabel(gdialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 241, 691));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        pushButton_5 = new QPushButton(gdialog);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(60, 420, 141, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        logo = new QLabel(gdialog);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(50, 20, 161, 141));
        logo->setStyleSheet(QString::fromUtf8("\n"
"image: url(:/pic/logo.png);"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../joueur/logo.png")));
        logo->setScaledContents(true);
        pushButton_4 = new QPushButton(gdialog);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(60, 360, 141, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton = new QPushButton(gdialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 180, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_2 = new QPushButton(gdialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(60, 240, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label_4 = new QLabel(gdialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 70, 431, 601));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}"));
        nom_stade_4 = new QLabel(gdialog);
        nom_stade_4->setObjectName("nom_stade_4");
        nom_stade_4->setGeometry(QRect(330, 80, 101, 31));
        nom_stade_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_5 = new QLabel(gdialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 10, 301, 51));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        delete_2 = new QPushButton(gdialog);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(960, 630, 191, 51));
        delete_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        sort = new QPushButton(gdialog);
        sort->setObjectName("sort");
        sort->setGeometry(QRect(1010, 70, 201, 41));
        sort->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        export_2 = new QPushButton(gdialog);
        export_2->setObjectName("export_2");
        export_2->setGeometry(QRect(1250, 70, 181, 41));
        export_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        recherche = new QLineEdit(gdialog);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(790, 10, 341, 41));
        recherche->setStyleSheet(QString::fromUtf8("border: 2px solid #2e344c;\n"
"border-radius: 15px;\n"
"background:rgb(254, 246, 209);"));
        search = new QPushButton(gdialog);
        search->setObjectName("search");
        search->setGeometry(QRect(1150, 10, 251, 41));
        search->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        tirageButton = new QPushButton(gdialog);
        tirageButton->setObjectName("tirageButton");
        tirageButton->setGeometry(QRect(810, 70, 161, 41));
        tirageButton->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        id = new QLineEdit(gdialog);
        id->setObjectName("id");
        id->setGeometry(QRect(330, 130, 341, 31));
        id->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"border: none;\n"
"background-color: rgb(255, 255, 255);\n"
"border-color: rgb(46, 52, 68);\n"
"\n"
""));
        stat = new QWidget(gdialog);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(760, 470, 681, 141));
        stat->setStyleSheet(QString::fromUtf8(""));
        test = new QPushButton(gdialog);
        test->setObjectName("test");
        test->setGeometry(QRect(730, 70, 41, 41));
        test->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);\n"
" border-radius: 10px;\n"
"    border: none;\n"
"font-weight: bold;"));
        delete_2->raise();
        sort->raise();
        export_2->raise();
        recherche->raise();
        search->raise();
        tirageButton->raise();
        set->raise();
        pushButton_11->raise();
        label_4->raise();
        label->raise();
        pushButton_2->raise();
        pushButton_5->raise();
        pushButton_4->raise();
        logo->raise();
        pushButton->raise();
        pushButton_3->raise();
        num_place->raise();
        modif->raise();
        zone_3->raise();
        add->raise();
        nom_stade->raise();
        date->raise();
        nom_stade_3->raise();
        label_->raise();
        num_place_3->raise();
        tableView->raise();
        zone->raise();
        Date->raise();
        ref->raise();
        prix_billet->raise();
        nom_stade_4->raise();
        label_5->raise();
        id->raise();
        stat->raise();
        test->raise();

        retranslateUi(gdialog);

        QMetaObject::connectSlotsByName(gdialog);
    } // setupUi

    void retranslateUi(QDialog *gdialog)
    {
        gdialog->setWindowTitle(QCoreApplication::translate("gdialog", "Dialog", nullptr));
        modif->setText(QCoreApplication::translate("gdialog", "Modifier", nullptr));
        zone_3->setText(QCoreApplication::translate("gdialog", "zone", nullptr));
        pushButton_11->setText(QCoreApplication::translate("gdialog", "PushButton", nullptr));
        add->setText(QCoreApplication::translate("gdialog", "Ajouter", nullptr));
        date->setText(QCoreApplication::translate("gdialog", "Date", nullptr));
        nom_stade_3->setText(QCoreApplication::translate("gdialog", "nom_stade", nullptr));
        label_->setText(QCoreApplication::translate("gdialog", "prix_billet", nullptr));
        num_place_3->setText(QCoreApplication::translate("gdialog", "num_place", nullptr));
        set->setText(QCoreApplication::translate("gdialog", "TextLabel", nullptr));
        ref->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("gdialog", "Billets", nullptr));
        label->setText(QCoreApplication::translate("gdialog", "TextLabel", nullptr));
        pushButton_5->setText(QCoreApplication::translate("gdialog", "Supporter", nullptr));
        logo->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("gdialog", "Joueus", nullptr));
        pushButton->setText(QCoreApplication::translate("gdialog", "Equipes", nullptr));
        pushButton_2->setText(QCoreApplication::translate("gdialog", "Matchs", nullptr));
        label_4->setText(QString());
        nom_stade_4->setText(QCoreApplication::translate("gdialog", "ID", nullptr));
        label_5->setText(QCoreApplication::translate("gdialog", "           Ajouter un Billets", nullptr));
        delete_2->setText(QCoreApplication::translate("gdialog", "Supprimer", nullptr));
        sort->setText(QCoreApplication::translate("gdialog", "Trier par nombre de places", nullptr));
        export_2->setText(QCoreApplication::translate("gdialog", "Exporter un PDF", nullptr));
        recherche->setText(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("gdialog", "Recherche par nombre de place", nullptr));
        search->setText(QCoreApplication::translate("gdialog", "Recherche par nombre de place", nullptr));
        tirageButton->setText(QCoreApplication::translate("gdialog", "Tirage au Sort", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("gdialog", "ID", nullptr));
        test->setText(QCoreApplication::translate("gdialog", "A", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gdialog: public Ui_gdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDIALOG_H
