#include "equipes.h"
#include <QSqlError>
#include <QDebug>

// Default constructor
Equipes::Equipes() : ID_Equipe(0), Nom_Equipe(""), Score(0), Origine(""), Rang(0), Possession("0%"), lastError("") {}

// Parameterized constructor
Equipes::Equipes(int id, QString nom, int score, QString origine, int rang, QString possession)
    : ID_Equipe(id), Nom_Equipe(nom), Score(score), Origine(origine), Rang(rang), Possession(possession), lastError("") {}

// Destructor
Equipes::~Equipes() {}

bool Equipes::create() {
    QSqlQuery query;

    // Get the next available ID_EQUIPE
    query.prepare("SELECT MAX(ID_EQUIPE) FROM EQUIPE");
    if (!query.exec() || !query.next()) {
        lastError = query.lastError().text();
        qDebug() << "Error fetching next ID:" << lastError;
        return false;
    }
    int nextId = query.value(0).toInt() + 1;

    // Prepare the insert query
    query.prepare("INSERT INTO EQUIPE (ID_EQUIPE, NOM_EQUIPE, SCORE, ORIGINE, RANG, POSSESSION) "
                  "VALUES (:ID_EQUIPE, :NOM_EQUIPE, :SCORE, :ORIGINE, :RANG, :POSSESSION)");

    // Bind values
    query.bindValue(":ID_EQUIPE", nextId);
    query.bindValue(":NOM_EQUIPE", Nom_Equipe);
    query.bindValue(":SCORE", Score);
    query.bindValue(":ORIGINE", Origine);
    query.bindValue(":RANG", Rang);
    query.bindValue(":POSSESSION", Possession);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Error inserting team:" << lastError;
        return false;
    }
    return true;
}

QSqlQueryModel* Equipes::read() {
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT ID_EQUIPE, NOM_EQUIPE, SCORE, ORIGINE, RANG, POSSESSION FROM EQUIPE ORDER BY RANG ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom d'équipe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Score"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Origine"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Rang"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Possession"));

    return model;
}

bool Equipes::update(int id) {
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("UPDATE EQUIPE SET NOM_EQUIPE = :NOM_EQUIPE, SCORE = :SCORE, "
                  "ORIGINE = :ORIGINE, RANG = :RANG, POSSESSION = :POSSESSION WHERE ID_EQUIPE = :id");
    query.bindValue(":id", res);
    query.bindValue(":NOM_EQUIPE", Nom_Equipe);
    query.bindValue(":SCORE", Score);
    query.bindValue(":ORIGINE", Origine);
    query.bindValue(":RANG", Rang);
    query.bindValue(":POSSESSION", Possession);

    return query.exec();
}

bool Equipes::delet(int id) {
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("DELETE FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", res);

    return query.exec();
}

bool Equipes::checkIfEquipeExists(int id) {
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

int Equipes::calculateScore(int wins, int losses, int draws) {
    return (wins * 3) + (losses * -1) + (draws * 1);
}

QString Equipes::getLastError() const {
    return lastError;
}
