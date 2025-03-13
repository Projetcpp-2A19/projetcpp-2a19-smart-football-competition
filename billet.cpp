#include "billet.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

using namespace std;

Billet::Billet()
{
    prix_billet = 0.0;
    nom_stade = "";
    zone = "";
    num_place = 0;
}

Billet::Billet(QDateTime dateheure, float prix_billet, QString nom_stade, QString zone, int num_place)
{

    this->dateheure = dateheure;
    this->prix_billet = prix_billet;
    this->nom_stade = nom_stade;
    this->zone = zone;
    this->num_place = num_place;
}

bool Billet::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO billet (dateheure, prix_billet, nom_stade, zone, num_place) VALUES (:dateheure, :prix_billet, :nom_stade, :zone, :num_place)");
    query.bindValue(":dateheure", dateheure);
    query.bindValue(":prix_billet", prix_billet);
    query.bindValue(":nom_stade", nom_stade);
    query.bindValue(":zone", zone);
    query.bindValue(":num_place", num_place);
    return query.exec();
}


bool Billet::modifier(int val)
{
    QSqlQuery query;
    query.prepare("UPDATE billet SET dateheure = :dateheure, prix_billet = :prix_billet, nom_stade = :nom_stade, zone = :zone, num_place = :num_place WHERE ID_BILLET = :id");
    query.bindValue(":id", val);
    query.bindValue(":dateheure", dateheure);
    query.bindValue(":prix_billet", prix_billet);
    query.bindValue(":nom_stade", nom_stade);
    query.bindValue(":zone", zone);
    query.bindValue(":num_place", num_place);
    return query.exec();
}

QSqlQueryModel * Billet::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM billet");
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Dateheure"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom stade"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("num place"));
    return model;
}

bool Billet::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM billet WHERE ID_BILLET = :id");
    query.bindValue(":id", id);
    return query.exec();
}
