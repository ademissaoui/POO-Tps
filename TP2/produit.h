#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>

class produit
{
    int id;
    std::string nom;
    std::string categorie;
    double prix;
    int qte;

public:
    produit();
    produit(int id, const std::string &nom, const std::string &categorie, double prix, int qte);
    produit(const produit &autre);
    ~produit();
    int get_id() const;
    void set_id(int id);
    void set_qte(int qte);
    int get_qte() const;
    double get_prix() const;
    void set_prix(double prix);
    std::string get_nom() const;
    void set_nom(const std::string &nom);
    std::string get_categorie() const;
    void set_categorie(const std::string &categorie);
    void afficher() const;
};

#endif 