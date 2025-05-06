#include "match.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QIntValidator>
#include <QSqlError>
#include <QString>
#include <QComboBox>


Match::Match() {
    id_match = 0;
    date_match = QDate();
    heure_match = "";
    stade = "";
    score = "";
    nom_equipe1 = "";
    nom_equipe2 = "";
}

Match::Match(int id_match, QDate date_match, QString heure_match, QString stade, QString score, QString nom_equipe1, QString nom_equipe2) {
    this->id_match = id_match;
    this->date_match = date_match;
    this->heure_match = heure_match;
    this->stade = stade;
    this->score = score;
    this->nom_equipe1 = nom_equipe1;
    this->nom_equipe2 = nom_equipe2;
}

int Match::getIdMatch() { return id_match; }
QDate Match::getDateMatch() { return date_match; }
QString Match::getHeureMatch() { return heure_match; }
QString Match::getStade() { return stade; }
QString Match::getScore() { return score; }
QString Match::getNomEquipe1() { return nom_equipe1; }
QString Match::getNomEquipe2() { return nom_equipe2; }

void Match::setIdMatch(int id_match) { this->id_match = id_match; }
void Match::setDateMatch(QDate date_match) { this->date_match = date_match; }
void Match::setHeureMatch(QString heure_match) { this->heure_match = heure_match; }
void Match::setStade(QString stade) { this->stade = stade; }
void Match::setScore(QString score) { this->score = score; }
void Match::setNomEquipe1(QString nom_equipe1) { this->nom_equipe1 = nom_equipe1; }
void Match::setNomEquipe2(QString nom_equipe2) { this->nom_equipe2 = nom_equipe2; }

bool Match::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MATCHES (ID_MATCH, DATE_MATCH, HEURE_MATCH, STADE, SCORE, NOM_EQUIPE1, NOM_EQUIPE2) "
                  "VALUES (:id_match, :date_match, :heure_match, :stade, :score, :nom_equipe1, :nom_equipe2)");

    query.bindValue(":id_match", id_match);
    query.bindValue(":date_match", date_match);
    query.bindValue(":heure_match", heure_match);
    query.bindValue(":stade", stade);
    query.bindValue(":score", score);
    query.bindValue(":nom_equipe1", nom_equipe1);
    query.bindValue(":nom_equipe2", nom_equipe2);

    if (!query.exec()) {
        qDebug() << "Error inserting match: " << query.lastError().text();
        return false;
    }

    return true;
}


QSqlQueryModel* Match::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID_MATCH, TO_CHAR(DATE_MATCH, 'YYYY-MM-DD') AS DATE_MATCH, HEURE_MATCH, STADE, SCORE, NOM_EQUIPE1, NOM_EQUIPE2, STATUT FROM MATCHES");
    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError().text();  // Log any SQL errors
        return nullptr;  // Return nullptr if the query fails
    }

    model->setQuery(query);

    // Set the headers if the query is successful
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Heure"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Stade"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Score"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Equipe 1"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Equipe 2"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Statut"));

    return model;
}


bool Match::supprimer(int id_match) {
    QSqlQuery query;
    query.prepare("DELETE FROM MATCHES WHERE ID_MATCH = :id_match");
    query.bindValue(":id_match", id_match);
    return query.exec();
}

bool Match::checkIfMatchExists(int id_match) {
    QSqlQuery query;
    query.prepare("SELECT ID_MATCH FROM MATCHES WHERE ID_MATCH = :id_match");
    query.bindValue(":id_match", id_match);
    if (query.exec() && query.next()) {
        return true;
    } else {
        return false;
    }
}

bool Match::modifierE(int id_match) {
    QSqlQuery query;
    query.prepare("UPDATE MATCHES SET DATE_MATCH = :date_match, HEURE_MATCH = :heure_match, STADE = :stade, SCORE = :score, NOM_EQUIPE1 = :nom_equipe1, NOM_EQUIPE2 = :nom_equipe2 "
                  "WHERE ID_MATCH = :id_match");
    query.bindValue(":id_match", id_match);
    query.bindValue(":date_match", date_match);
    query.bindValue(":heure_match", heure_match);
    query.bindValue(":stade", stade);
    query.bindValue(":score", score);
    query.bindValue(":nom_equipe1", nom_equipe1);
    query.bindValue(":nom_equipe2", nom_equipe2);

    if (!query.exec()) {
        qDebug() << "SQL Error:" << query.lastError().text(); // Print SQL error
        return false;
    }
    return true;
}
