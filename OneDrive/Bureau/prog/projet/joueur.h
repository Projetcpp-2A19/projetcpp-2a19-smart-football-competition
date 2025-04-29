#ifndef JOUEUR_H
#define JOUEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

class Joueur
{
private:
    int id;
    QString nom;
    QString prenom;
    QString poste;
    int nbr_but;
    int nbr_passe;
    int carton_j;
    int carton_r;
public:
    Joueur();
    Joueur (int, QString, QString, QString, int, int, int, int);
    ~Joueur();

    int getId(){return id;};
    QString getNom(){return nom;};
    QString getPrenom(){return prenom;};
    QString getPoste(){return poste;};
    int getNbrB(){return nbr_but;};
    int getNbrP(){return nbr_passe;};
    int getCartonJ(){return carton_j;};
    int getCartonR(){return carton_r;};

    void setId(int n){id = n;};
    void setNom(QString s){nom = s;};
    void setPrenom(QString s){prenom = s;};
    void setPoste(QString s){poste = s;};
    void setNbrB(int n){nbr_but = n;};
    void setNbrP(int n){nbr_passe = n;};
    void setCartonJ(int n){carton_j = n;};
    void setCartonR(int n){carton_r = n;};


    bool ajouter ();
    QSqlQueryModel * afficher();
    void modifier ();
    bool supprimer(int);
};

#endif // JOUEUR_H
