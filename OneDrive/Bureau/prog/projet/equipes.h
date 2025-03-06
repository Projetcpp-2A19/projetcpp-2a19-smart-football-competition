#ifndef EQUIPES_H
#define EQUIPES_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipes {
public:
    Equipes();
    Equipes(int id, QString nom, QString score, QString origin, int rang);

    bool create();
    QSqlQueryModel* read();
    bool update(int id);
    bool delet(int id);

private:
    int ID_Equipe;
    QString Nom_Equipe;
    QString Score;
    QString Origin;
    int Rang;
};

#endif // EQUIPES_H
