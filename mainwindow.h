#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "equipes.h"
#include "dialog.h"
#include <QRegularExpressionValidator>
#include <QSqlQuery>
#include <QDebug>
#include <QMenu>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots for text input formatting
    void on_lineEdit_Nom_textChanged(const QString &text);
    void on_lineEdit_Origin_textChanged(const QString &text);

    // Slots for button clicks
    void on_buttonEnregistrer_clicked();
    void on_pushButton_modifier_clicked();

    // Slot for handling cell changes in the table
    void on_tableWidget_cellChanged(int row, int column);

    // Slot for context menu
    void showContextMenu(const QPoint &pos);  // Added for context menu

private:
    Ui::MainWindow *ui;
    Equipes Etmp;

    // Function to populate the table widget
    void populateTableWidget();

    // Function to delete a row
    void deleteRow(int row);  // Added for deleting rows

    // Function to validate input fields
    bool validateInput();
};

#endif // MAINWINDOW_H
