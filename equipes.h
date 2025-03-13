#ifndef EQUIPES_H
#define EQUIPES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

class Equipes {
private:
    int ID_Equipe;       // ID
    QString Nom_Equipe;  // Name
    int Score;           // Score
    QString Origine;     // Origin
    int Rang;            // Rank
    QString lastError;   // error message

public:
    // Constructors and Destructor
    Equipes();
    Equipes(int id, QString nom, int score, QString origine, int rang);
    ~Equipes();

    // Getters
    int getId() { return ID_Equipe; }
    QString getNom() { return Nom_Equipe; }
    int getScore() { return Score; }
    QString getOrigine() { return Origine; }
    int getRang() { return Rang; }
    QString getLastError() const; // Method to get the last error message

    // Setters
    void setId(int id) { ID_Equipe = id; }
    void setNom(QString nom) { Nom_Equipe = nom; }
    void setScore(int score) { Score = score; }
    void setOrigine(QString origine) { Origine = origine; }
    void setRang(int rang) { Rang = rang; }

    // Database operations
    bool create();                      // Create
    QSqlQueryModel* read();             // Read
    bool update(int id);                // Update
    bool delet(int id);                 // Delete
    bool checkIfEquipeExists(int id);

    // Static method to calculate score
    static int calculateScore(int wins, int losses, int draws);
};

#endif // EQUIPES_H
