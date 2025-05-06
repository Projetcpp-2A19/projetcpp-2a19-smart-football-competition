#ifndef STATWINDOW_H
#define STATWINDOW_H

#include <QDialog>
#include <QAbstractItemModel>
#include <QMap>

namespace Ui {
class StatWindow;
}

class StatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StatWindow(QWidget *parent = nullptr, QAbstractItemModel *dataModel = nullptr);
    ~StatWindow();

private:
    Ui::StatWindow *ui;
    QAbstractItemModel *model;

    QMap<QString, int> collectStats(int column) const;
    void showStatistics();
    void createPieChart(const QMap<QString, int>& stats, const QString& title);
    QString generateReport(const QMap<QString, int>& stats, const QString& title) const;
};

#endif // STATWINDOW_H
