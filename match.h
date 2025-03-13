#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Match {
public:
    Match();
    Match(int, QDate, QString, QString, QString, QString, QString);

    int getIdMatch();
    QDate getDateMatch();
    QString getHeureMatch();
    QString getStade();
    QString getScore();
    QString getNomEquipe1();
    QString getNomEquipe2();

    void setIdMatch(int);
    void setDateMatch(QDate);
    void setHeureMatch(QString);
    void setStade(QString);
    void setScore(QString);
    void setNomEquipe1(QString);
    void setNomEquipe2(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool checkIfMatchExists(int);
    bool modifierE(int id_match);

private:
    int id_match;
    QDate date_match;
    QString heure_match;
    QString stade;
    QString score;
    QString nom_equipe1;
    QString nom_equipe2;
};

#endif // MATCH_H
