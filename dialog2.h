#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <joueur.h>

namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = nullptr);
    ~Dialog2();

private:
    Ui::Dialog2 *ui;
    Joueur Jtmp;
};

#endif // DIALOG2_H
