#ifndef DIALOG_H
#define DIALOG_H
#include "connection.h"
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>
#include <QVBoxLayout>
#include <QLabel>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QDateTime>
#include <QSqlQueryModel>
#include "buzzer.h"
class Billet {
private:
    QString nom_etab;
    QString zone;
    double prix;
    QDateTime date;
    int num_place;

public:
    Billet();
    Billet(QString nom_etab, QString zone, double prix, QDateTime date, int num_place);

    bool ajouter_billet();
    static QSqlQueryModel* afficher_billets();
    static bool supprimer_billet(int id, QWidget *parent = nullptr);
    static bool modifier_billet(int id, const QString& newNomEtab, const QString& newZone,
                                double newPrix, const QDateTime& newDate, int newNumPlace,
                                QWidget* parent = nullptr);
    static bool billetExists(int id);
    static QSqlQueryModel* searchByNumPlace(int num_place);
    static QSqlQueryModel* sortByNumPlaceAsc();
    static QSqlQueryModel* sortByNumPlaceDesc();
    static QMap<QString, int> getTicketCountsByZone();

    // Getters
    QString getNomEtab() const { return nom_etab; }
    QString getZone() const { return zone; }
    double getPrix() const { return prix; }
    QDateTime getDate() const { return date; }
    int getNumPlace() const { return num_place; }

    static bool tirageAuSort(QWidget* parent = nullptr);
};

#endif // DIALOG_H
