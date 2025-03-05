/********************************************************************************
** Form generated from reading UI file 'dialog2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG2_H
#define UI_DIALOG2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Dialog2
{
public:
    QLabel *label;
    QLabel *label_3;
    QTableView *tableView;

    void setupUi(QDialog *Dialog2)
    {
        if (Dialog2->objectName().isEmpty())
            Dialog2->setObjectName("Dialog2");
        Dialog2->resize(400, 300);
        label = new QLabel(Dialog2);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, 0, 461, 301));
        label->setStyleSheet(QString::fromUtf8("color: rgb(46, 52, 76);\n"
"background-color: rgb(46, 52, 76);"));
        label_3 = new QLabel(Dialog2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 20, 351, 261));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    border-radius: 10px; /* Adjust the value for roundness */\n"
"   background-color: rgb(253, 246, 208); /* Optional background color */\n"
"}\n"
"QLabel {\n"
"    border: 2px solid #2E344C;  /* Border color */\n"
"    padding: 5px;               /* Optional: Adds space inside the label */\n"
"}\n"
""));
        tableView = new QTableView(Dialog2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(60, 50, 256, 192));

        retranslateUi(Dialog2);

        QMetaObject::connectSlotsByName(Dialog2);
    } // setupUi

    void retranslateUi(QDialog *Dialog2)
    {
        Dialog2->setWindowTitle(QCoreApplication::translate("Dialog2", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog2", "TextLabel", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog2: public Ui_Dialog2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG2_H
