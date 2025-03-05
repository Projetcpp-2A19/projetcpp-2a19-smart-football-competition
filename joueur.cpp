#include "joueur.h"

Joueur::Joueur() {
    id = 0;
    nom = "";
    prenom = "";
    poste = "";
    nbr_but = 0;
    nbr_passe = 0;
    carton_j = 0;
    carton_r = 0;
}

Joueur::Joueur(int n1, QString s1, QString s2, QString s3, int n2, int n3, int n4, int n5){
    id = n1;
    nom = s1;
    prenom = s2;
    poste = s3;
    nbr_but = n2;
    nbr_passe = n3;
    carton_j = n4;
    carton_r = n5;
}

Joueur::~Joueur(){

}

bool Joueur :: ajouter(){
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("insert into joueur(id, nom, prenom, poste, nbr_but, nbr_passe, carton_j, carton_r)" "values(:id, :nom, :prenom, :poste, :nbr_but, :nbr_passe, :carton_j, :carton_r)");

    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":poste",poste);
    query.bindValue(":nbr_but",nbr_but);
    query.bindValue(":nbr_passe",nbr_passe);
    query.bindValue(":carton_j",carton_j);
    query.bindValue(":carton_r",carton_r);

    return query.exec();
}


bool Joueur::supprimer(int id){
    QSqlQuery query;
    QString res = QString :: number(id);

    query.prepare("Delete from joueur where ID = :id");
    query.bindValue(":id",res);

    return query.exec();
}

QSqlQueryModel * Joueur::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from etudiant");
    model->setHeaderData (0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Poste"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Nombre de buts"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nombre de passe décisive"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Nombre de carton jaune"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Nombre de carton rouge"));

    return model;
}
