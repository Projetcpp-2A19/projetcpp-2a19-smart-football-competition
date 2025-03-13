#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "billet.h"
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
    void on_pushButton_6_clicked();


    void on_pushButton_10_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
    Billet ba;
};

#endif // DIALOG_H
