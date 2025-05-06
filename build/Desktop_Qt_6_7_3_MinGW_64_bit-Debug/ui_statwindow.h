/********************************************************************************
** Form generated from reading UI file 'statwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATWINDOW_H
#define UI_STATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_StatWindow
{
public:
    QTextEdit *textEdit;

    void setupUi(QDialog *StatWindow)
    {
        if (StatWindow->objectName().isEmpty())
            StatWindow->setObjectName("StatWindow");
        StatWindow->resize(956, 584);
        textEdit = new QTextEdit(StatWindow);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 0, 961, 591));

        retranslateUi(StatWindow);

        QMetaObject::connectSlotsByName(StatWindow);
    } // setupUi

    void retranslateUi(QDialog *StatWindow)
    {
        StatWindow->setWindowTitle(QCoreApplication::translate("StatWindow", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatWindow: public Ui_StatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATWINDOW_H
