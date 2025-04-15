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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gdialog
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_2;
    QPushButton *pushButton_11;
    QTableView *tableView;
    QLabel *label_3;
    QLabel *stat;
    QPushButton *pushButton_5;
    QLabel *set;
    QPushButton *pushButton_8;
    QLabel *logoo;
    QLabel *label_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *date;
    QLineEdit *nom_stade;
    QLabel *nom_stade_3;
    QLabel *label_;
    QPushButton *modif;
    QDateTimeEdit *Date;
    QLineEdit *zone;
    QLineEdit *prix_billet;
    QPushButton *add;
    QLabel *zone_3;
    QLabel *num_place_3;
    QLineEdit *num_place;
    QPushButton *ref;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *id;
    QPushButton *delete_2;
    QPushButton *export_2;
    QPushButton *sort;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *recherche;
    QPushButton *search;
    QPushButton *tirageButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_12;
    QPushButton *quit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gdialog)
    {
        if (gdialog->objectName().isEmpty())
            gdialog->setObjectName("gdialog");
        gdialog->resize(1202, 587);
        centralwidget = new QWidget(gdialog);
        centralwidget->setObjectName("centralwidget");
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(110, 260, 141, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(92, 498, 61, 31));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(620, 100, 401, 221));
        tableView->setStyleSheet(QString::fromUtf8(""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 100, 201, 421));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        stat = new QLabel(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(570, 370, 501, 151));
        stat->setStyleSheet(QString::fromUtf8("QLabel {\n"
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
        pushButton_5->setGeometry(QRect(110, 440, 141, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        set = new QLabel(centralwidget);
        set->setObjectName("set");
        set->setGeometry(QRect(200, 500, 31, 31));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(110, 320, 141, 41));
        pushButton_8->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        logoo = new QLabel(centralwidget);
        logoo->setObjectName("logoo");
        logoo->setGeometry(QRect(100, 30, 161, 141));
        logoo->setPixmap(QPixmap(QString::fromUtf8("../../Downloads/New folder (15)/473998708_9421539317910106_7515820646283734691_n (1).png")));
        logoo->setScaledContents(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 40, 201, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Haettenschweiler")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        label_4->setFont(font);
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
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(110, 380, 141, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(110, 200, 141, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 281, 601));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        date = new QLabel(centralwidget);
        date->setObjectName("date");
        date->setGeometry(QRect(310, 280, 101, 31));
        date->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        nom_stade = new QLineEdit(centralwidget);
        nom_stade->setObjectName("nom_stade");
        nom_stade->setGeometry(QRect(310, 130, 141, 31));
        nom_stade->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        nom_stade_3 = new QLabel(centralwidget);
        nom_stade_3->setObjectName("nom_stade_3");
        nom_stade_3->setGeometry(QRect(310, 100, 101, 31));
        nom_stade_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        label_ = new QLabel(centralwidget);
        label_->setObjectName("label_");
        label_->setGeometry(QRect(310, 220, 91, 31));
        label_->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        modif = new QPushButton(centralwidget);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(320, 470, 141, 41));
        modif->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        Date = new QDateTimeEdit(centralwidget);
        Date->setObjectName("Date");
        Date->setGeometry(QRect(310, 310, 141, 31));
        zone = new QLineEdit(centralwidget);
        zone->setObjectName("zone");
        zone->setGeometry(QRect(310, 190, 141, 31));
        zone->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        prix_billet = new QLineEdit(centralwidget);
        prix_billet->setObjectName("prix_billet");
        prix_billet->setGeometry(QRect(310, 250, 141, 31));
        prix_billet->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(320, 420, 141, 41));
        add->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        zone_3 = new QLabel(centralwidget);
        zone_3->setObjectName("zone_3");
        zone_3->setGeometry(QRect(310, 160, 101, 31));
        zone_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        num_place_3 = new QLabel(centralwidget);
        num_place_3->setObjectName("num_place_3");
        num_place_3->setGeometry(QRect(310, 340, 111, 31));
        num_place_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";"));
        num_place = new QLineEdit(centralwidget);
        num_place->setObjectName("num_place");
        num_place->setGeometry(QRect(310, 370, 141, 31));
        num_place->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        ref = new QPushButton(centralwidget);
        ref->setObjectName("ref");
        ref->setGeometry(QRect(1020, 100, 21, 21));
        ref->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SystemReboot));
        ref->setIcon(icon);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(580, 330, 481, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        id = new QLineEdit(layoutWidget);
        id->setObjectName("id");
        id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(id);

        delete_2 = new QPushButton(layoutWidget);
        delete_2->setObjectName("delete_2");
        delete_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));

        horizontalLayout->addWidget(delete_2);

        export_2 = new QPushButton(layoutWidget);
        export_2->setObjectName("export_2");
        export_2->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));

        horizontalLayout->addWidget(export_2);

        sort = new QPushButton(layoutWidget);
        sort->setObjectName("sort");
        sort->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));

        horizontalLayout->addWidget(sort);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(500, 40, 651, 38));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        recherche = new QLineEdit(layoutWidget1);
        recherche->setObjectName("recherche");
        recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        horizontalLayout_2->addWidget(recherche);

        search = new QPushButton(layoutWidget1);
        search->setObjectName("search");
        search->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));

        horizontalLayout_2->addWidget(search);

        tirageButton = new QPushButton(layoutWidget1);
        tirageButton->setObjectName("tirageButton");
        tirageButton->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 76);\n"
"font: 12pt \"Haettenschweiler\";\n"
"color: rgb(255, 254, 242);"));

        horizontalLayout_2->addWidget(tirageButton);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(40, 60, 191, 441));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(layoutWidget2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(layoutWidget2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_3);

        pushButton_13 = new QPushButton(layoutWidget2);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_13);

        pushButton_14 = new QPushButton(layoutWidget2);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_14);

        pushButton_12 = new QPushButton(layoutWidget2);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(253, 246, 208);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(pushButton_12);

        quit = new QPushButton(layoutWidget2);
        quit->setObjectName("quit");
        quit->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(255, 0, 0);\n"
"\n"
"font: 12pt \"Haettenschweiler\";\n"
"\n"
""));

        verticalLayout->addWidget(quit);

        gdialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gdialog);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1202, 26));
        gdialog->setMenuBar(menubar);
        statusbar = new QStatusBar(gdialog);
        statusbar->setObjectName("statusbar");
        gdialog->setStatusBar(statusbar);

        retranslateUi(gdialog);

        QMetaObject::connectSlotsByName(gdialog);
    } // setupUi

    void retranslateUi(QMainWindow *gdialog)
    {
        gdialog->setWindowTitle(QCoreApplication::translate("gdialog", "gdialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("gdialog", "Matchs", nullptr));
        pushButton_11->setText(QCoreApplication::translate("gdialog", "PushButton", nullptr));
        label_3->setText(QString());
        stat->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("gdialog", "Supporter", nullptr));
        set->setText(QCoreApplication::translate("gdialog", "TextLabel", nullptr));
        pushButton_8->setText(QCoreApplication::translate("gdialog", "Billets", nullptr));
        logoo->setText(QString());
        label_4->setText(QCoreApplication::translate("gdialog", "           Ajouter un Billet", nullptr));
        pushButton_9->setText(QCoreApplication::translate("gdialog", "Joueurs", nullptr));
        pushButton->setText(QCoreApplication::translate("gdialog", "Equipes", nullptr));
        label->setText(QCoreApplication::translate("gdialog", "TextLabel", nullptr));
        date->setText(QCoreApplication::translate("gdialog", "Date", nullptr));
        nom_stade_3->setText(QCoreApplication::translate("gdialog", "nom_stade", nullptr));
        label_->setText(QCoreApplication::translate("gdialog", "prix_billet", nullptr));
        modif->setText(QCoreApplication::translate("gdialog", "Modifier", nullptr));
        add->setText(QCoreApplication::translate("gdialog", "Enregistrer", nullptr));
        zone_3->setText(QCoreApplication::translate("gdialog", "zone", nullptr));
        num_place_3->setText(QCoreApplication::translate("gdialog", "num_place", nullptr));
        ref->setText(QString());
        id->setPlaceholderText(QCoreApplication::translate("gdialog", "ID", nullptr));
        delete_2->setText(QCoreApplication::translate("gdialog", "Supprimer", nullptr));
        export_2->setText(QCoreApplication::translate("gdialog", "Exporter un PDF", nullptr));
        sort->setText(QCoreApplication::translate("gdialog", "Trier par nombre de places", nullptr));
        recherche->setText(QString());
        recherche->setPlaceholderText(QCoreApplication::translate("gdialog", "Recherche par nombre de place", nullptr));
        search->setText(QCoreApplication::translate("gdialog", "Recherche par nombre de place", nullptr));
        tirageButton->setText(QCoreApplication::translate("gdialog", "Tirage au Sort", nullptr));
        pushButton_4->setText(QCoreApplication::translate("gdialog", "Equipes", nullptr));
        pushButton_3->setText(QCoreApplication::translate("gdialog", "Matchs", nullptr));
        pushButton_13->setText(QCoreApplication::translate("gdialog", "Billets", nullptr));
        pushButton_14->setText(QCoreApplication::translate("gdialog", "Joueurs", nullptr));
        pushButton_12->setText(QCoreApplication::translate("gdialog", "Supporter", nullptr));
        quit->setText(QCoreApplication::translate("gdialog", "D\303\251connexion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gdialog: public Ui_gdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDIALOG_H
