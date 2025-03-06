#ifndef EQUIPES_H
#define EQUIPES_H
#include <string>
using namespace std;
class Equipes
{
public:
    Equipes();  
    void create();
    void read();
    void update();
    void delet();

private:
    int ID_Equipe;
    string Nom_Equipe;
    string Score;
    string Origin;
    int Rang;
};

#endif // EQUIPES_H
