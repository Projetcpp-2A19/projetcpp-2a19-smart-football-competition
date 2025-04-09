#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSortFilterProxyModel>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_searchbar_textEdited(const QString &text);
    void on_pushButton_6_clicked();
    void on_pattern_clicked();  // New slot for pattern button

    // Sort functions
    void sortByName();
    void sortByScore();
    void sortByRank();

private:
    Ui::Dialog *ui;
    QSortFilterProxyModel *proxyModel;
    void filterTable(const QString &text);
    void exportTableToPDF();
    QString getCurrentSortMethod() const;
};

#endif // DIALOG_H
