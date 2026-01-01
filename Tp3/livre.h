#include <string>
#include <cstdio>
using namespace std;

class livre {
private:
    int id;
    string titre;
    string auteur;
public:
    livre();
    livre(int identifiant,string t,string a);
    int getid();
    string gettitre();
    string getauteur();
    void setid(int identifiant);
    void settitre(string t);
    void setauteur(string a);
    void afficher();
    void sauvegarder(FILE* fichier);
    void charger(FILE* fichier);
};
