#include "joueur.h"
#include <QSqlError>

Joueur::Joueur() {
    id_joueur = 0;
    nom = "";
    prenom = "";
    poste = "";
    nbr_but = 0;
    nbr_passe = 0;
    carton_j = 0;
    carton_r = 0;
    id_equipe = 0;
}

Joueur::Joueur(int n1, QString s1, QString s2, QString s3, int n2, int n3, int n4, int n5, int n6){
    id_joueur = n1;
    nom = s1;
    prenom = s2;
    poste = s3;
    nbr_but = n2;
    nbr_passe = n3;
    carton_j = n4;
    carton_r = n5;
    id_equipe = n6;
}

Joueur::~Joueur(){

}

bool Joueur::ajouter() {
    QSqlQuery query;

    // Récupérer le prochain id_joueur disponible
    query.prepare("SELECT MAX(id_joueur) FROM joueur");
    if (!query.exec() || !query.next()) {
        qDebug() << "Erreur lors de la récupération du prochain ID :" << query.lastError().text();
        return false;
    }
    int nextId = query.value(0).toInt() + 1; // Incrémente l'id maximum

    // Préparation de la requête d'insertion
    query.prepare("INSERT INTO joueur (id_joueur, nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r, id_equipe) "
                  "VALUES (:id_joueur, :nom, :prenom, :poste, :nbr_but, :nbr_passe, :carton_j, :carton_r, :id_equipe)");

    // Liaison des valeurs
    query.bindValue(":id_joueur", nextId); // Utilise l'id généré automatiquement
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":poste", poste);
    query.bindValue(":nbr_but", nbr_but);
    query.bindValue(":nbr_passe", nbr_passe);
    query.bindValue(":carton_j", carton_j);
    query.bindValue(":carton_r", carton_r);
    query.bindValue(":id_equipe", id_equipe);

    // Exécution de la requête
    return query.exec();
}


bool Joueur::supprimer(int id){
    QSqlQuery query;
    QString res = QString :: number(id);

    query.prepare("Delete from joueur where id_joueur = :id");
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Joueur::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from Joueur");
    model->setHeaderData (0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Goals"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Assits"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Carton R"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Carton J"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("Equipe"));

    return model;
}

bool Joueur::modifier(){
    QSqlQuery query;
    QString res = QString :: number(id_joueur);

    query.prepare("UPDATE joueur SET nom = :nom, prenom = :prenom, poste = :poste, "
                  "nbr_but = :nbr_but, nbr_passe = :nbr_passe, carton_j = :carton_j, "
                  "carton_r = :carton_r, id_equipe = :id_equipe WHERE id_joueur = :id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":nbr_but",nbr_but);
    query.bindValue(":nbr_passe",nbr_passe);
    query.bindValue(":carton_j",carton_j);
    query.bindValue(":carton_r",carton_r);
    query.bindValue(":id_equipe", id_equipe);

    return query.exec();
}

bool Joueur::checkIfJoueurExists(int id){
    QSqlQuery query;
    query.prepare("SELECT id_joueur FROM joueur WHERE id_joueur = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return true;  // Le joueur existe
    }
    return false;  // Le joueur n'existe pas
}

