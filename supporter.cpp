#include "supporter.h"
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QNetworkRequest>

supporter::supporter() {
    id_supp = 0;
    nom = "";
    prenom = "";
    tel = "";
    e_mail = "";
    type_supp = "";
    point_fidelite = 0;
    dob = QDate();
    equipe = "";
}

supporter::supporter(int id, QString nom, QString prenom, QString tele, QString email, QString type, int points, QDate date,QString equipe) {
    id_supp = id;
    this->nom = nom;
    this->prenom = prenom;
    tel = tele;
    e_mail = email;
    type_supp = type;
    point_fidelite = points;
    dob = date;
    equipe = equipe;
}

supporter::~supporter() {}

bool supporter::ajouter() {
    QSqlQuery query;

    // Get the next available id_supp
    query.prepare("SELECT MAX(id_supp) FROM supporter");
    if (!query.exec() || !query.next()) {
        qDebug() << "Error getting next ID:" << query.lastError().text();
        return false;
    }
    int nextId = query.value(0).toInt() + 1;

    // Prepare insert query with DOB
    query.prepare("INSERT INTO Supporter (id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite, dob,equipe) "
                  "VALUES (:id_supp, :nom, :prenom, :tel, :e_mail, :type_supp, :point_fidelite, :dob, :equipe )");

    // Bind values
    query.bindValue(":id_supp", nextId);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", tel);
    query.bindValue(":e_mail", e_mail);
    query.bindValue(":type_supp", type_supp);
    query.bindValue(":point_fidelite", point_fidelite);
    query.bindValue(":dob", dob);
    query.bindValue(":equipe",equipe );

    if (!query.exec()) {
        qDebug() << "Error adding supporter:" << query.lastError().text();
        return false;
    }
    return true;
}

bool supporter::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM supporter WHERE id_supp = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Error deleting supporter:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* supporter::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite, TO_CHAR(dob, 'YYYY-MM-DD') as dob,equipe FROM Supporter");
    setupModelHeaders(model);
    return model;
}

bool supporter::modifier(int id, QString n, QString p, QString t, QString mail, QString type, int points, QDate date, QString e ) {
    QSqlQuery query;
    query.prepare("UPDATE Supporter SET nom = :nom, prenom = :prenom, tel = :tel, "
                  "e_mail = :e_mail, type_supp = :type_supp, point_fidelite = :point_fidelite, dob = :dob,equipe = :equipe "
                  "WHERE id_supp = :id");

    query.bindValue(":id", id);
    query.bindValue(":nom", n);
    query.bindValue(":prenom", p);
    query.bindValue(":tel", t);
    query.bindValue(":e_mail", mail);
    query.bindValue(":type_supp", type);
    query.bindValue(":point_fidelite", points);
    query.bindValue(":dob", date);
    query.bindValue(":equipe", e);


    if (!query.exec()) {
        qDebug() << "Error updating supporter:" << query.lastError().text();
        return false;
    }
    return true;
}

bool supporter::checkIfsupporterExists(int id) {
    QSqlQuery query;
    query.prepare("SELECT id_supp FROM Supporter WHERE id_supp = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return true;
    }
    return false;
}

// Sorting methods
QSqlQueryModel* supporter::trierParNom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite, TO_CHAR(dob, 'YYYY-MM-DD') as dob ,equipe FROM Supporter ORDER BY nom ASC");
    setupModelHeaders(model);
    return model;
}

QSqlQueryModel* supporter::trierParPrenom() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite,equipe, TO_CHAR(dob, 'YYYY-MM-DD') as dob FROM Supporter ORDER BY prenom ASC");
    setupModelHeaders(model);
    return model;
}

QSqlQueryModel* supporter::trierParId() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite,equipe, TO_CHAR(dob, 'YYYY-MRM-DD') as ID FROM Supporter ORDER BY id_supp ASC");
    setupModelHeaders(model);
    return model;
}

QSqlQueryModel* supporter::trierParPoints() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite,equipe, TO_CHAR(dob, 'YYYY-MM-DD') as dob FROM Supporter ORDER BY point_fidelite DESC");
    setupModelHeaders(model);
    return model;
}

QSqlQueryModel* supporter::trierParDob() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id_supp, nom, prenom, tel, e_mail, type_supp, point_fidelite,equipe  TO_CHAR(dob, 'YYYY-MM-DD') as dob FROM Supporter ORDER BY dob ASC");
    setupModelHeaders(model);
    return model;
}


void supporter::setupModelHeaders(QSqlQueryModel* model) {
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("E-mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type Supporter"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Points Fidélité"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Date de Naissance"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Equipe"));
}

