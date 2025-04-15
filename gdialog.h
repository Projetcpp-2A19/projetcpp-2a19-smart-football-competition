#ifndef GDIALOG_H
#define GDIALOG_H

#include <QMainWindow>
#include <QtCharts/QChartView>
QT_BEGIN_NAMESPACE
namespace Ui {
class gdialog;
}
QT_END_NAMESPACE

class gdialog : public QMainWindow
{
    Q_OBJECT

public:
    gdialog(QWidget *parent = nullptr);
    ~gdialog();
public slots:
    void on_display_clicked();
    void updateStatistics();
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

private:
    Ui::gdialog *ui;
    QChartView* createZoneStatChart();
    QChartView *chartView;
};
#endif // GDIALOG_H
