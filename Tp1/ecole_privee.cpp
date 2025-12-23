#include "ecole_privee.h"
#include "ecole.h"
#include <cstdio>
#include <cstring>
using namespace std;
ecole_privee::ecole_privee(const char *nom, const char *adresse, int ne, int *eleve, const char *gerant, float capital) : ecole(nom, adresse, ne, eleve)
{
    if (gerant)
    {
        this->gerant = new char[strlen(gerant) + 1];
        strcpy(this->gerant, gerant);
    }
    else
    {
        this->gerant = nullptr;
    }
    if (capital > 0)
    {
        this->capital = capital;
    }
    else
    {
        this->capital = 0;
    }
}
ecole_privee::~ecole_privee()
{
    if (gerant)
    {
        delete[] gerant;
    }
}
ecole_privee &ecole_privee::operator++()
{
    ecole::operator++();
    return *this;
}
ecole_privee::operator char *() const
{
    char *chaine = new char[600];
    sprintf(chaine, "Ecole Privee: %s\nadresse: %s\ngerant: %s\ncapital: %f\nne: %d\neleve: %d,%d,%d,%d,%d,%d",
            nom, adresse, gerant, capital, ne, eleve[0], eleve[1], eleve[2], eleve[3], eleve[4], eleve[5]);
    return chaine;
}
void ecole_privee::view() const
{
    cout << "Ecole Privee: " << nom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Gerant: " << gerant << endl;
    cout << "Capital: " << capital << endl;
    cout << "Nombre d'eleves: " << ne << endl;
    cout << "Eleves par niveau: ";
    for (int i = 0; i < 6; i++)
    {
        cout << eleve[i];
        if (i < 5)
            cout << ", ";
    }
    cout << endl;
}