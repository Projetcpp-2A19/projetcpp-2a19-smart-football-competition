#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQueryModel>
#include <QSqlQuery>
#include <QTableWidget>
#include <QPushButton>
#include <QSerialPort>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void populateTableWidget();
    void onDeleteButtonClicked();  // Slot for delete button click
    void readArduinoData();        // Slot to read from Arduino
    void on_tableWidget_cellChanged(int row, int column);
    void on_buttonEnregistrer_clicked();
    void on_lineEdit_Nom_textChanged(const QString &text);
    void on_lineEdit_Origin_textChanged(const QString &text);
    void showContextMenu(const QPoint &pos);
    void deleteRow(int row);

private:
    bool validateInput();
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QTableWidget *tableWidget;
    QPushButton *deleteButton;
    QSerialPort *arduino;
};

#endif // MAINWINDOW_H
