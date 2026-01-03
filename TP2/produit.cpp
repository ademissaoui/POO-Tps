#include "produit.h"
#include <string>
#include <iostream>

using namespace std;

produit::produit()
{
    id = 0;
    qte = 0;
    nom = "";
    categorie = "";
    prix = 0;
}

produit::produit(int id, const string &nom, const string &categorie, double prix, int qte)
{
    this->id = id;
    this->nom = nom;
    this->categorie = categorie;
    this->prix = prix;
    this->qte = qte;
}

produit::produit(const produit &autre)
{
    this->id = autre.id;
    this->nom = autre.nom;
    this->categorie = autre.categorie;
    this->prix = autre.prix;
    this->qte = autre.qte;
}

produit::~produit()
{
}

int produit::get_id() const
{
    return id;
}

void produit::set_id(int id)
{
    this->id = id;
}

int produit::get_qte() const
{
    return qte;
}

void produit::set_qte(int qte)
{
    this->qte = qte;
}

double produit::get_prix() const
{
    return prix;
}

void produit::set_prix(double prix)
{
    this->prix = prix;
}

string produit::get_nom() const
{
    return nom;
}

void produit::set_nom(const string &nom)
{
    this->nom = nom;
}

string produit::get_categorie() const
{
    return categorie;
}

void produit::set_categorie(const string &categorie)
{
    this->categorie = categorie;
}

void produit::afficher() const
{
    cout << "ID: " << id
         << " | Nom: " << nom
         << " | Categorie: " << categorie
         << " | Prix: " << prix
         << " | Quantite: " << qte << endl;
}
