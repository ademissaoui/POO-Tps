#ifndef ECOLE_PRIVEE_H
#define ECOLE_PRIVEE_H
#include "ecole.h"
#include <iostream>
#include <cstring>
using namespace std;
class ecole_privee:public ecole{
    private:
        char* gerant;
        float capital;
    public:
        ecole_privee(const char* nom, const char* adresse, int ne, int* eleve, const char* gerant, float capital);
        virtual ~ecole_privee();
        ecole_privee& operator++();
        operator char*() const ;
        void view()  const;
        




};





#endif