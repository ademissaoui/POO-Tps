#include "ecole.h"
#include <cstdio>
using namespace std;
ecole::ecole(const char *nom,const char *adresse, int ne, int *eleve)
{
    if (nom)
    {
        this->nom = new char[strlen(nom) + 1];
        strcpy(this->nom, nom);
    }
    else
    {
        this->nom = nullptr;
    }
    if (adresse)
    {
        this->adresse = new char[strlen(adresse) + 1];
        strcpy(this->adresse, adresse);
    }
    else
    {
        this->adresse = nullptr;
    }
   /* if (ne > 0)
    {
        this->ne = ne;
    }*/
   try {
    if (ne <0) throw "saisir un nombre positif d'enseigants" ;
   }
   catch(const char * message){
    cout<<message<<endl;
   }
    this->eleve = new int[6];
    
    if (eleve)
    {
        for (int i = 0; i < 6; i++)
        {
            this->eleve[i] = eleve[i];
        }
    }
    else {
        for (int i = 0; i < 6; i++) this->eleve[i] = 0;
    }
}
ecole::ecole(const ecole &e){
    if (e.nom)
    {
        this->nom = new char[strlen(e.nom) + 1];
        strcpy(this->nom, e.nom);
    }
    else
    {
        this->nom = nullptr;
    }
    if (e.adresse)
    {
        this->adresse = new char[strlen(e.adresse) + 1];
        strcpy(this->adresse, e.adresse);
    }
    else{
        this->adresse = nullptr;
    }
    if (e.ne > 0)
    {
        this->ne = e.ne;
    }
    this->eleve = new int[6];
    if (e.eleve)
    {
        for (int i = 0; i < 6; i++)
        {
            this->eleve[i] = e.eleve[i];
        }
    }
    else {
        for (int i = 0; i < 6; i++) this->eleve[i] = 0;
    }
}
ecole::~ecole()
{
    if (nom)
    {
        delete[] nom;
    }
    if (adresse)
    {
        delete[] adresse;
    }
    if (eleve)
    {
        delete[] eleve;
    }
}
char *ecole::get_nom()
{
    return nom;
}
int *ecole::get_eleve_niveau(int niveau)
{
    return eleve;
}
ecole& ecole::operator+(const ecole &autre){
    char nouveau_nom[50] , nouvelle_adresse[50];
    cout<<"Entrez le nom de la nouvelle ecole: ";
    cin>>nouveau_nom;
    cout<<"Entrez l'adresse de la nouvelle ecole: ";
    cin>>nouvelle_adresse;
    if (this->nom) delete[] this->nom;
    this->nom = new char[strlen(nouveau_nom) + 1];
    strcpy(this->nom, nouveau_nom);
    if (this->adresse) delete[] this->adresse;
    this->adresse = new char[strlen(nouvelle_adresse) + 1];
    strcpy(this->adresse, nouvelle_adresse);
    int nouveau_ne = this->ne + autre.ne;
    int newEleve[6];
    for(int i=0;i<6;i++){
        int a = (this->eleve ? this->eleve[i] : 0);
        int b = (autre.eleve ? autre.eleve[i] : 0);
        newEleve[i]= a + b;
    }
    if (this->eleve) delete[] this->eleve;
    this->eleve = new int[6];
    for(int i=0;i<6;i++) this->eleve[i] = newEleve[i];
    this->ne = nouveau_ne;
    return *this;
}
ecole& ecole::operator++(){
    this->ne++;
    return *this;
}
ecole::operator char*() const {
    char* chaine= new char[500];
    sprintf(chaine, "Ecole: %s\nAdresse: %s\nNombre d'eleves: %d\nEleves par niveau: %d, %d, %d, %d, %d, %d\n",nom,adresse,ne,eleve[0],eleve[1],eleve[2],eleve[3],eleve[4],eleve[5]);
    return chaine;
}
void ecole::view() const {
    cout<<"Ecole: "<<nom<<endl;
    cout<<"Adresse: "<<adresse<<endl;
    cout<<"Nombre d'eleves: "<<ne<<endl;
    cout<<"Nombre d'eleves par niveau: ";
    for(int i=0;i<6;i++){
        cout<<eleve[i]<<" ";
    }
    cout<<endl;
}


