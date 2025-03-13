#ifndef BILLET_H
#define BILLET_H
#include <QDateTime>
#include <QSqlQueryModel>
using namespace std;

class Billet
{
private:
    int id;
    QDateTime dateheure;
    float prix_billet;
    QString nom_stade;
    QString zone;
    int num_place;

public:
    Billet();
    Billet(QDateTime, float, QString, QString, int);  // Correct constructor declaration
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *afficher();
    int getId() { return id; }
    QDateTime getDateheure() { return dateheure; }
    float getPrixBillet() { return prix_billet; }
    QString getNomStade() { return nom_stade; }
    QString getZone() { return zone; }
    int getNumPlace() { return num_place; }
    void setId(int n){id = n;}
    void setDate(QDateTime d) { dateheure = d; }
    void setPrixBillet(float p) { prix_billet = p; }
    void setNomStade(QString ns) { nom_stade = ns; }
    void setZone(QString z) { zone = z; }
    void setNumPlace(int np) { num_place = np; }

};

#endif // BILLET_H
