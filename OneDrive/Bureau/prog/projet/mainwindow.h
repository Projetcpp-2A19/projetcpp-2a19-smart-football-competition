#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "equipes.h"
#include <QRegularExpressionValidator>
#include <QSqlQuery>
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_Nom_textChanged(const QString &text);
    void on_lineEdit_Origin_textChanged(const QString &text);
    void on_possessioninput_textChanged(const QString &text);
    void on_buttonEnregistrer_clicked();
    void on_pushButton_modifier_clicked();
    void on_tableWidget_cellChanged(int row, int column);
    void showContextMenu(const QPoint &pos);

private:
    Ui::MainWindow *ui;
    Equipes Etmp;
    Dialog *dialog;

    void populateTableWidget();
    void deleteRow(int row);
    bool validateInput();
};

#endif // MAINWINDOW_H
