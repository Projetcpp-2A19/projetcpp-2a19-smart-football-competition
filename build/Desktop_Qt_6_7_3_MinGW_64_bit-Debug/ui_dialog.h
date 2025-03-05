/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_supp;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 461, 301));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 351, 221));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        lineEdit_supp = new QLineEdit(Dialog);
        lineEdit_supp->setObjectName("lineEdit_supp");
        lineEdit_supp->setGeometry(QRect(20, 130, 113, 22));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 100, 81, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
"\n"
""));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 20, 301, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(210, 253, 75, 31));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(300, 253, 75, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"font: 14pt \"Haettenschweiler\";\n"
""));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "TextLabel", nullptr));
        label_3->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog", "Identifiant :", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Veuillez saisir l'identifiant du joueur \303\240 supprimer :", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "Supprimer", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
