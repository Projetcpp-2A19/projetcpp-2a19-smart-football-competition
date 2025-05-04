#include "statwindow.h"
#include "ui_statwindow.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QChartView>
#include <QPieSeries>

StatWindow::StatWindow(QWidget *parent, QAbstractItemModel *dataModel) :
    QDialog(parent),
    ui(new Ui::StatWindow),
    model(dataModel)
{
    ui->setupUi(this);
    setWindowTitle("Statistics");
    setLayout(new QVBoxLayout());
    showStatistics();
}

StatWindow::~StatWindow() {
    delete ui;
}

QMap<QString, int> StatWindow::collectStats(int column) const {
    QMap<QString, int> stats;
    if (!model || column < 0 || column >= model->columnCount()) return stats;

    for (int row = 0; row < model->rowCount(); ++row) {
        QString value = model->index(row, column).data().toString();
        if (!value.isEmpty()) stats[value]++;
    }
    return stats;
}

void StatWindow::showStatistics() {
    if (!model || model->columnCount() <= 8) {
        QMessageBox::warning(this, "Error", "Invalid data model!");
        return;
    }

    // Clear existing widgets
    QLayout *layout = this->layout();
    while (QLayoutItem *item = layout->takeAt(0)) {
        if (item->widget() && item->widget() != ui->textEdit) {
            item->widget()->deleteLater();
        }
        delete item;
    }

    QMap<QString, int> supporterStats = collectStats(5);
    QMap<QString, int> teamStats = collectStats(8);

    createPieChart(supporterStats, "Supporter Types");
    createPieChart(teamStats, "Supported Teams");

}

void StatWindow::createPieChart(const QMap<QString, int>& stats, const QString& title) {
    if (stats.isEmpty()) return;

    QPieSeries *series = new QPieSeries();
    int total = 0;
    for (auto count : stats) total += count;

    QList<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::cyan, Qt::magenta};
    int colorIndex = 0;

    for (auto it = stats.begin(); it != stats.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setColor(colors[colorIndex++ % colors.size()]);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2 (%3%)")
                            .arg(it.key())
                            .arg(it.value())
                            .arg(QString::number(it.value() * 100.0 / total, 'f', 1)));
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(title);
    chart->legend()->setVisible(true);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    layout()->addWidget(chartView);
}

QString StatWindow::generateReport(const QMap<QString, int>& stats, const QString& title) const {
    if (stats.isEmpty()) return title + "\nNo data available";

    int total = 0;
    for (auto count : stats) total += count;

    QString report = title + "\n\nTotal: " + QString::number(total) + "\n\n";
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        report += QString("%1: %2 (%3%)\n")
        .arg(it.key())
            .arg(it.value())
            .arg(QString::number(it.value() * 100.0 / total, 'f', 1));
    }
    return report;
}
