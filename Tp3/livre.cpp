#include "livre.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

livre::livre(){
	id=0;
	titre="";
	auteur="";
}
livre::livre(int identifiant,string t,string a){
	id=identifiant;
	titre=t;
	auteur=a;
}
int livre::getid() {
    return id;
}
string livre::gettitre()  {
    return titre;
}
string livre::getauteur() {
    return auteur;
}
void livre::setid(int identifiant) {
      id=identifiant;
}
void livre::settitre(string t) {
    titre = t;
}
void livre::setauteur(string a) {
    auteur = a;
}
void livre::afficher() {
	cout<<"id du livre"<<id<<endl;
	cout<<"titre du livre"<<titre<<endl;
	cout<<"auteur du livre"<<auteur<<endl;
}
void livre::sauvegarder(FILE* fichier){
    if (!fichier) {
        cout << "Erreur : fichier invalide pour le sauvegard"<< endl;
        return;
    }
    fprintf(fichier, "%d\n", id);
    fprintf(fichier, "%s\n", titre.c_str());
    fprintf(fichier, "%s\n", auteur.c_str());
}
void livre::charger(FILE* fichier) {
    if (!fichier) {
        cout << "Erreur : fichier invalide pour le chargement" << endl;
        return;
    }
    
    char t[200];
    char a[200];
    
    if (fscanf(fichier, "%d\n", &id) != 1) {
        cout << "Erreur lors de la lecture de l'identifiant." << endl;
        return;
    }
    
    if (fgets(t, 200, fichier) == NULL) {
        cout << "Erreur lors de la lecture du titre." << endl;
        return;
    }
    titre =t;
    
    
    if (fgets(a, 200, fichier) == NULL) {
        cout << "Erreur lors de la lecture de l'auteur." << endl;
        return;
    }
    auteur =a;
}
