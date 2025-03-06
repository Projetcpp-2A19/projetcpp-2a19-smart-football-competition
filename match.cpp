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
    score = 0;
    nom_equipe1 = "";
    nom_equipe2 = "";
}

Match::Match(int id_match, QDate date_match, QString heure_match, QString stade, int score, QString nom_equipe1, QString nom_equipe2) {
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
int Match::getScore() { return score; }
QString Match::getNomEquipe1() { return nom_equipe1; }
QString Match::getNomEquipe2() { return nom_equipe2; }

void Match::setIdMatch(int id_match) { this->id_match = id_match; }
void Match::setDateMatch(QDate date_match) { this->date_match = date_match; }
void Match::setHeureMatch(QString heure_match) { this->heure_match = heure_match; }
void Match::setStade(QString stade) { this->stade = stade; }
void Match::setScore(int score) { this->score = score; }
void Match::setNomEquipe1(QString nom_equipe1) { this->nom_equipe1 = nom_equipe1; }
void Match::setNomEquipe2(QString nom_equipe2) { this->nom_equipe2 = nom_equipe2; }

bool Match::ajouter() {
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

    return query.exec();
}

QSqlQueryModel* Match::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MATCHES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_MATCH"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("HEURE_MATCH"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STADE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("SCORE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NOM_EQUIPE1"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOM_EQUIPE2"));

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
