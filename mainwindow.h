#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "joueur.h"

#include <QRegularExpressionValidator>
#include <QSqlQuery>
#include <QDebug>
#include <QSortFilterProxyModel>
#include <QList>

#include <QTextDocument>
#include <QPrinter>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
     void on_lineEdit_nom_textChanged(const QString &text);
     void on_lineEdit_prenom_textChanged(const QString &text);

    void on_pushButton_ajouter_clicked();
    void on_pushButton_supp_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_modifier_clicked();

    void on_TrieButton_clicked();

    void on_pushButton_pdf_clicked();

private:
    Ui::MainWindow *ui;
    Joueur Jtmp;
    QSortFilterProxyModel *proxyModel;
    void trierLignes(int colonne, bool croissant);
public:
    int getNextId();
    void remplirComboBoxEquipe();
    void afficherProfil (int id);
    void rechercherJoueur();
    void genererPDF();
};
#endif // MAINWINDOW_H
