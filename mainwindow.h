#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDate>
#include "match.h"  // Include the new Match class

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();  // Add a match
    void on_pb_supprimer_clicked();  // Delete a match
    void on_pb_modifier_clicked();  // Update a match
    void on_tab_matches_clicked(const QModelIndex &index);  // Display selected match in input fields
    void displayTable();  // Refresh the table view
    void on_lineEdit_search_textChanged(const QString &text);  // Search functionality

private:
    Ui::MainWindow *ui;
    Match *match;  // Pointer to the Match class
};

#endif // MAINWINDOW_H
