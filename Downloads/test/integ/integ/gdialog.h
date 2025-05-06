#ifndef GDIALOG_H
#define GDIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class gdialog;
}
QT_END_NAMESPACE

class gdialog : public QDialog
{
    Q_OBJECT

public:
    gdialog(QWidget *parent = nullptr);
    ~gdialog();
public slots:
    void on_display_clicked();
    void updateStatistics();
    void on_tableView_clicked(const QModelIndex &index);
private slots:
    void on_add_clicked();
    void on_delete_2_clicked();

    void on_modif_clicked();

    void on_export_2_clicked();

    void on_search_clicked();

    void on_ref_clicked();

    void on_sort_clicked();


    void on_tirageButton_clicked();

    void on_quit_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_test_clicked();

private:
    Ui::gdialog *ui;
    QChartView* createZoneStatChart();
    QChartView *chartView;
    Arduino *arduino;
    void setupArduino();
};
#endif // GDIALOG_H
