#include "ecole.h"
#include <cstdio>
using namespace std;
// Constructor: initializes school with name, address, number of students, and array of students per level
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
// Copy constructor: creates a deep copy of another ecole object
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
// Destructor: frees dynamically allocated memory for nom, adresse, and eleve arrays
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
// Operator+: combines two schools into a new school with merged student counts
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
// Operator++: increments the total number of students in the school
ecole& ecole::operator++(){
    this->ne++;
    return *this;
}
// FIXED: sprintf now has buffer (chaine) as first argument
// Conversion operator: converts ecole object to string representation
ecole::operator char*() const {
    char* chaine= new char[500];
    sprintf(chaine, "Ecole: %s\nAdresse: %s\nNombre d'eleves: %d\nEleves par niveau: %d, %d, %d, %d, %d, %d\n",nom,adresse,ne,eleve[0],eleve[1],eleve[2],eleve[3],eleve[4],eleve[5]);
    return chaine;
}
// view(): displays school information (name, address, student count, students per level)
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


