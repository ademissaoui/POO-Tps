#ifndef "arbre_h"
#define "arbre_h"
#include "noeud.h"
using namespace std;
temaplate <typename t>
class arbre{
    private:
        noeud<t>* racine;
    public:
        arbre(){
            racine = nullptr;
        }
        arbre(const t &data){
            racine = new noeud<t>(data);
        }
        noeud<t>* getRacine(){
            return racine;
        }
        
        void ajouterEnfant(noeud<T>* parent, const T& data) {
            noeud<T>* nouveau = new noeud<T>(data);
            if (!parent->fils) {
                parent->fils = nouveau;
            } else {
                noeud<T>* temp = parent->fils;
                while (temp->frere)
                    temp = temp->frere;
                temp->frere = nouveau;
            }
        }
        void afficher(Noeud<T>* noeud){
        if (noeud == nullptr) {
            noeud = racine;
            if (!noeud) return;
        }

        cout << noeud->data.getNom() << std::endl;

        afficher(noeud->fils);
        afficher(noeud->frere);
}
        
    

};









#endif