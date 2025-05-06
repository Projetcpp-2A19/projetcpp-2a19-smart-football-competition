#ifndef SUPPORTER_H
#define SUPPORTER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>


class supporter
{
     friend class MainWindow;
private:
    int id_supp;
    QString nom;
    QString prenom;
    QString tel;
    QString e_mail;
    QString type_supp;
    int point_fidelite;
    QDate dob;
    QString equipe;
    void setupModelHeaders(QSqlQueryModel* model);
    void sendConfirmationSMS(const QString& tele, const QString& nom );

public:
    supporter();
    supporter(int, QString, QString, QString, QString, QString, int, QDate ,QString);
    ~supporter();

    // Getters
    int getId() { return id_supp; }
    QString getNom() { return nom; }
    QString getPrenom() { return prenom; }
    QString getTel() { return tel; }
    QString getEmail() { return e_mail; }
    QString getTypesupp() { return type_supp; }
    int getPointFidelite() { return point_fidelite; }
    QDate getDob() { return dob; }
    QString getequipe() {return equipe;}

    // Setters
    void setId(int id) { id_supp = id; }
    void setNom(QString n) { nom = n; }
    void setPrenom(QString p) { prenom = p; }
    void setTel(QString t) { tel = t; }
    void setEmail(QString mail) { e_mail = mail; }
    void setTypesupp(QString type) { type_supp = type; }
    void setPointFidelite(int points) { point_fidelite = points; }
    void setDob(QDate date) { dob = date; }
    void setequipe(QString e) {equipe=e;}

    // CRUD Operations
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier(int id, QString nom, QString prenom, QString tel, QString email, QString type, int points, QDate dob,QString e );
    bool supprimer(int id);

    // Check if supporter exists
    bool checkIfsupporterExists(int id);

    // Sorting methods
    QSqlQueryModel* trierParNom();
    QSqlQueryModel* trierParPrenom();
    QSqlQueryModel* trierParId();
    QSqlQueryModel* trierParPoints();
    QSqlQueryModel* trierParDob();
};

#endif // SUPPORTER_H
