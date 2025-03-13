#ifndef EQUIPES_H
#define EQUIPES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

using namespace std;

class Equipes {
private:
    int ID_Equipe;       // ID of the team
    QString Nom_Equipe;  // Name of the team
    int Score;           // Score of the team (calculated from W, L, D)
    QString Origine;     // Origin of the team
    int Rang;            // Rank of the team
    QString lastError;   // Store the last error message

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
    bool create();                      // Add a new team to the database
    QSqlQueryModel* read();             // Display all teams
    bool update(int id);                // Update a team's information
    bool delet(int id);                 // Delete a team from the database
    bool checkIfEquipeExists(int id);   // Check if a team exists

    // Static method to calculate score
    static int calculateScore(int wins, int losses, int draws);
};

#endif // EQUIPES_H
