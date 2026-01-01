#include "livre.h"
#include "categorie.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

categorie::categorie()
{
 nom = "";
}

categorie::categorie(string n, vector<livre> l)
{
 nom = n;
 livres = l;
}

void categorie::ajout_livre(const livre &l)
{
 livres.push_back(l);
}
void categorie::view_categorie()
{
 cout << "nom de la categorie: " << nom << endl;
 cout << "Les livres de cette categorie: " << endl;
 for (int i = 0; i < livres.size(); i++)
 {
  cout << i + 1 << ": ";
  livres[i].afficher();
 }
}