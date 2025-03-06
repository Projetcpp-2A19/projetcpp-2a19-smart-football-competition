#include "equipes.h"

Equipes::Equipes() : ID_Equipe(0), Nom_Equipe(""), Score(""), Origin(""), Rang(0) {}

Equipes::Equipes(int id, QString nom, QString score, QString origin, int rang)
    : ID_Equipe(id), Nom_Equipe(nom), Score(score), Origin(origin), Rang(rang) {}

bool Equipes::create() {
    QSqlQuery query;
    query.prepare("INSERT INTO Equipes (ID_Equipe, Nom_Equipe, Score, Origin, Rang) "
                  "VALUES (:id, :nom, :score, :origin, :rang)");
    query.bindValue(":id", ID_Equipe);
    query.bindValue(":nom", Nom_Equipe);
    query.bindValue(":score", Score);
    query.bindValue(":origin", Origin);
    query.bindValue(":rang", Rang);

    return query.exec();
}

QSqlQueryModel* Equipes::read() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Equipes");
    return model;
}

bool Equipes::update(int id) {
    QSqlQuery query;
    query.prepare("UPDATE Equipes SET Nom_Equipe=:nom, Score=:score, Origin=:origin, Rang=:rang "
                  "WHERE ID_Equipe=:id");
    query.bindValue(":id", id);
    query.bindValue(":nom", Nom_Equipe);
    query.bindValue(":score", Score);
    query.bindValue(":origin", Origin);
    query.bindValue(":rang", Rang);

    return query.exec();
}

bool Equipes::delet(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM Equipes WHERE ID_Equipe=:id");
    query.bindValue(":id", id);

    return query.exec();
}
