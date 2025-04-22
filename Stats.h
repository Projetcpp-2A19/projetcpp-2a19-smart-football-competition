/*#ifndef STATS_H  // Rename the header guard to match the new class name
#define STATS_H

#include <QDialog>
#include <QtCharts>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class Stats;  // Change class name to Stats
}

class Stats : public QDialog
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr);
    ~Stats();

private:
    Ui::Stats *ui;

    void setup_charts();
    void load_stats();
    void show_team_scores();
    void show_possession_stats();
    void show_origin_distribution();
    void show_rank_distribution();

private slots:
    void on_comboBox_currentIndexChanged(int index);
};

#endif // STATS_H
*/
