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
    void sortMatchesBy(const QString &criteria);
    void on_pb_ajouter_clicked();  // Add a match
    void on_pb_supprimer_clicked();  // Delete a match
    void on_pb_modifier_clicked();  // Update a match
    void on_tab_matches_clicked(const QModelIndex &index);  // Display selected match in input fields
    void displayTable();  // Refresh the table view
    void exportToHTML();
    void on_stat_clicked();
    void on_comboBox_tri_currentIndexChanged(const QString &text);
    void on_comboBox_chercher_currentIndexChanged(const QString &text);
    void loadTeamNames();
    void setupTeamComboValidation();
    void handleChatMessage();
    void goToChatbotPage();


private:
    void searchMatchesBy(const QString &field, const QString &value);
    Ui::MainWindow *ui;
    Match *match;  // Pointer to the Match class
};
int levenshteinDistance(const QString &s1, const QString &s2);

QString generateCommentary(const QString &teamName, const QString &score, const QString &opponent);

#endif // MAINWINDOW_H
