#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <cstdio>
#include "produit.h"

using namespace std;

/* ===== FONCTEURS ===== */

struct TriParNom {
    bool operator()(const produit& p1, const produit& p2) {
        return p1.get_nom() < p2.get_nom();
    }
};

struct TriParPrix {
    bool operator()(const produit& p1, const produit& p2) {
        return p1.get_prix() < p2.get_prix();
    }
};

struct EstDisponible {
    bool operator()(const produit& p) {
        return p.get_qte() > 0;
    }
};

/* ===== AFFICHAGE ===== */

void afficherProduits(const vector<produit>& produits) {
    for (auto it = produits.begin(); it != produits.end(); ++it)
        it->afficher();
}

int main() {

    vector<produit> produits;
    map<int, produit> produitsMap;
    set<string> categories;
    list<produit> produitsDisponibles;

    /* ===== CHARGEMENT FICHIER ===== */
    FILE* f = fopen("produits.txt", "r");
    if (f != NULL) {
        int id, qte;
        double prix;
        char nom[50], cat[50];

        while (fscanf(f, "%d %s %s %lf %d",
                      &id, nom, cat, &prix, &qte) == 5) {

            produit p(id, nom, cat, prix, qte);
            produits.push_back(p);
            produitsMap[id] = p;
            categories.insert(cat);
        }
        fclose(f);
    }

    int choix;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Ajouter un produit\n";
        cout << "2. Supprimer un produit\n";
        cout << "3. Afficher tous les produits\n";
        cout << "4. Rechercher par ID\n";
        cout << "5. Trier par nom\n";
        cout << "6. Trier par prix\n";
        cout << "7. Produits disponibles\n";
        cout << "8. Vendre un produit\n";
        cout << "9. Reapprovisionner\n";
        cout << "10. Sauvegarder\n";
        cout << "0. Quitter\n";
        cout << "Choix: ";
        cin >> choix;

        switch (choix) {

        case 1: { // Ajouter
            int id, qte;
            double prix;
            string nom, cat;

            cout << "ID: "; cin >> id;
            cout << "Nom: "; cin >> nom;
            cout << "Categorie: "; cin >> cat;
            cout << "Prix: "; cin >> prix;
            cout << "Quantite: "; cin >> qte;

            produit p(id, nom, cat, prix, qte);
            produits.push_back(p);
            produitsMap[id] = p;
            categories.insert(cat);
            break;
        }

        case 2: { // Supprimer
            int id;
            cout << "ID: "; cin >> id;

            for (auto it = produits.begin(); it != produits.end(); ++it) {
                if (it->get_id() == id) {
                    produits.erase(it);
                    produitsMap.erase(id);
                    break;
                }
            }
            break;
        }

        case 3:
            afficherProduits(produits);
            break;

        case 4: { // Recherche
            int id;
            cout << "ID: "; cin >> id;

            auto it = produitsMap.find(id);
            if (it != produitsMap.end())
                it->second.afficher();
            else
                cout << "Produit introuvable\n";
            break;
        }

        case 5:
            sort(produits.begin(), produits.end(), TriParNom());
            break;

        case 6:
            sort(produits.begin(), produits.end(), TriParPrix());
            break;

        case 7: { // Disponibles
            produitsDisponibles.clear();

            for (auto it = produits.begin(); it != produits.end(); ++it)
                if (EstDisponible()(*it))
                    produitsDisponibles.push_back(*it);

            for (auto it = produitsDisponibles.begin();
                 it != produitsDisponibles.end(); ++it)
                it->afficher();
            break;
        }

        case 8: { // Vente
            int id;
            cout << "ID: "; cin >> id;

            auto it = produitsMap.find(id);
            if (it != produitsMap.end() && it->second.get_qte() > 0) {

                it->second.set_qte(it->second.get_qte() - 1);

                // synchronisation vector
                for (auto vit = produits.begin(); vit != produits.end(); ++vit)
                    if (vit->get_id() == id) {
                        vit->set_qte(it->second.get_qte());
                        break;
                    }
            }
            break;
        }

        case 9: { // Réapprovisionnement
            int id, q;
            cout << "ID: "; cin >> id;
            cout << "Quantite a ajouter: "; cin >> q;

            auto it = produitsMap.find(id);
            if (it != produitsMap.end()) {

                it->second.set_qte(it->second.get_qte() + q);

                // synchronisation vector
                for (auto vit = produits.begin(); vit != produits.end(); ++vit)
                    if (vit->get_id() == id) {
                        vit->set_qte(it->second.get_qte());
                        break;
                    }
            }
            break;
        }

        case 10: { // Sauvegarde
            FILE* f = fopen("produits.txt", "w");
            if (f != NULL) {
                for (auto it = produits.begin(); it != produits.end(); ++it) {
                    fprintf(f, "%d %s %s %.2f %d\n",
                            it->get_id(),
                            it->get_nom().c_str(),
                            it->get_categorie().c_str(),
                            it->get_prix(),
                            it->get_qte());
                }
                fclose(f);
            }
            break;
        }

        }

    } while (choix != 0);

    return 0;
}
