#ifndef PAGESUPP_H
#define PAGESUPP_H

#include <QDialog>
#include <QSqlTableModel>
#include "supporter.h"
#include "smsservice.h"


QT_BEGIN_NAMESPACE
namespace Ui { class pagesupp; }
QT_END_NAMESPACE

class pagesupp : public QDialog
{
    Q_OBJECT

public:
    pagesupp(QWidget *parent = nullptr);
    ~pagesupp();

private slots:
    void on_ajouter_clicked();
    void on_annuler_clicked();
    void on_brecherche_clicked();
    void on_tri_clicked();
    void on_generatePdf_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_statButton_clicked();
    void on_joueur_clicked();
    void on_match_clicked();
    QStringList getTeamNamesFromDatabase();
    void initializeComboBox();

    void on_billets_clicked();

private:
    Ui::pagesupp *ui;
    supporter supp;
    QSqlTableModel *model;
    int selectedId;
    QStringList teams;
    QSqlQuery query;
    SmsService *smsService;

    void setupTable();
    void refreshTable();
    void clearForm();
    bool validateForm();
    //STATE
    QMap<QString, int> collectSupporterStats() const;
    QMap<QString, int> collectTeamStats() const;
    void showStatisticsReport(const QMap<QString, int>& supporterStats,
                              const QMap<QString, int>& teamStats,
                              int totalSupporters) const;

};

#endif // pagesupp_H
