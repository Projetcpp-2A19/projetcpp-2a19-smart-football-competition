/*#include "Stats.h"  // Change to match the new header file name
#include "ui_Stats.h"
#include <QSqlQuery>
#include <QDebug>
#include <QtCharts>

Stats::Stats(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Stats)  // Change to Stats
    ui->setupUi(this);

    // Set up combo box options
    ui->comboBox->addItem("Team Scores");
    ui->comboBox->addItem("Possession Stats");
    ui->comboBox->addItem("Origin Distribution");
    ui->comboBox->addItem("Rank Distribution");

    setup_charts(); // Call the setup_charts() function
    load_stats();
}

Stat::~Stat()
{
    delete ui;
}

void stat::setup_charts()
{
    // Initialize chart views
    QChartView *chartView1 = new QChartView(ui->mainChartWidget);
    chartView1->setRenderHint(QPainter::Antialiasing);
    ui->mainChartWidget->layout()->addWidget(chartView1);

    QChartView *chartView2 = new QChartView(ui->secondaryChartWidget);
    chartView2->setRenderHint(QPainter::Antialiasing);
    ui->secondaryChartWidget->layout()->addWidget(chartView2);
}

void stat::load_stats()
{
    int currentIndex = ui->comboBox->currentIndex();

    switch(currentIndex) {
    case 0: show_team_scores(); break;
    case 1: show_possession_stats(); break;
    case 2: show_origin_distribution(); break;
    case 3: show_rank_distribution(); break;
    }
}

void stat::on_comboBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    load_stats();
}

void stat::show_team_scores()
{
    QSqlQuery query;
    query.exec("SELECT NOM_EQUIPE, SCORE FROM EQUIPE ORDER BY SCORE DESC LIMIT 10");

    QBarSeries *series = new QBarSeries();
    QStringList categories;

    while (query.next()) {
        QString teamName = query.value(0).toString();
        int score = query.value(1).toInt();

        QBarSet *set = new QBarSet(teamName);
        *set << score;
        series->append(set);
        categories << teamName;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Top 10 Teams by Score");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = qobject_cast<QChartView*>(ui->mainChartWidget->layout()->itemAt(0)->widget());
    chartView->setChart(chart);
}

void stat::show_possession_stats()
{
    QSqlQuery query;
    query.exec("SELECT POSSESSION, COUNT(*) FROM EQUIPE GROUP BY POSSESSION");

    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        QString possession = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(possession + " (" + QString::number(count) + ")", count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Possession Distribution");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = qobject_cast<QChartView*>(ui->mainChartWidget->layout()->itemAt(0)->widget());
    chartView->setChart(chart);
}

void stat::show_origin_distribution()
{
    QSqlQuery query;
    query.exec("SELECT ORIGINE, COUNT(*) FROM EQUIPE GROUP BY ORIGINE");

    QBarSeries *series = new QBarSeries();
    QStringList categories;

    while (query.next()) {
        QString origin = query.value(0).toString();
        int count = query.value(1).toInt();

        QBarSet *set = new QBarSet(origin);
        *set << count;
        series->append(set);
        categories << origin;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Teams by Origin");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = qobject_cast<QChartView*>(ui->mainChartWidget->layout()->itemAt(0)->widget());
    chartView->setChart(chart);
}

void stat::show_rank_distribution()
{
    QSqlQuery query;
    query.exec("SELECT RANG, COUNT(*) FROM EQUIPE GROUP BY RANG ORDER BY RANG");

    QLineSeries *series = new QLineSeries();

    while (query.next()) {
        int rank = query.value(0).toInt();
        int count = query.value(1).toInt();
        series->append(rank, count);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Rank Distribution");
    chart->createDefaultAxes();
    chart->legend()->setVisible(false);

    QChartView *chartView = qobject_cast<QChartView*>(ui->mainChartWidget->layout()->itemAt(0)->widget());
    chartView->setChart(chart);
}
*/
