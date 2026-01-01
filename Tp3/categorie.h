#include "livre.h"
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

class categorie
{
private:
 string nom;
 vector<livre> livres;

public:
 categorie();
 categorie(string n, vector<livre> l);
 void ajout_livre(const livre &l);
 void view_categorie();
};
