#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMap>
#include <QPainter>
#include "aimodel.h"  // Include the aimodel class

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void on_page_3_clicked();
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void on_searchbar_textEdited(const QString &text);
    void on_pushButton_6_clicked();
    void on_pattern_clicked();
    void on_trii_clicked();

    void sortByName();
    void sortByScore();
    void sortByRank();
    void sortByPossession();
    void setSearchFilter(const QString &filter);

private:
    Ui::Dialog *ui;
    aimodel *aiModelWindow;  // Pointer to aimodel instance (non-GUI object)
    QString currentSearchFilter;

    QMap<QString, int> getTeamGoalsData();
    void drawHistogram(QPainter &painter, const QMap<QString, int> &data);
    void filterTable(const QString &text);
    void exportTableToPDF();
    QString getCurrentSortMethod() const;
};

#endif // DIALOG_H
