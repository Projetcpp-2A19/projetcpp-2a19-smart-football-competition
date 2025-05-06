#ifndef pagejoueur_H
#define pagejoueur_H

#include <QDialog>
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
#include <qstandardpaths.h>

#include <QPixmap>
#include <QLabel>
#include <QImage>

#include <QVector>
#include <QTabWidget>
#include <QRandomGenerator>

#include "arduino.h"
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class pagejoueur;
}
QT_END_NAMESPACE


class pagejoueur : public QDialog
{
    Q_OBJECT

public:
    pagejoueur(QWidget *parent = nullptr);
    ~pagejoueur();


private slots:
     void on_lineEdit_nom_textChanged(const QString &text);
     void on_lineEdit_prenom_textChanged(const QString &text);

    void on_pushButton_ajouter_clicked();
    void on_pushButton_supp_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_modifier_clicked();


    void on_pushButton_pdf_clicked();

    void on_pushButton_photo_clicked();

    void on_comboBox_trie_currentIndexChanged(int index);

    void on_pushButton_lock_clicked();

    //void on_pushButton_scan_clicked();

    void readSerial();
    void on_page_controle_entered();
    void on_page_controle_left();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::pagejoueur *ui;
    Joueur Jtmp;
    QSortFilterProxyModel *proxyModel;
    void trierLignes(int colonne, bool croissant);
    QString m_photoTemp;
    int m_joueurId;

    QByteArray data;
    QSerialPort *serial;
    bool rfidScanEnabled = false;

    Arduino A;
public:
    int getNextId();
    void remplirComboBoxEquipe();
    void afficherProfil (int id);
    void rechercherJoueur();
    void genererPDF();
    void loadImageToDatabase(const QString &filePath);
    void afficherPhotoJoueur(int idJoueur, QLabel* labelPhoto);
    double calculerNoteParMatch(int joueurId, int matchId);
    void afficherNotesDansTable(int idJoueur);
    void incrementerEntrees(int joueurId);
    void afficher_entree();
    //void switch_page();

};

#endif // pagejoueur_H
