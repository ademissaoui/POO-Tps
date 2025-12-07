#include "ecole_privee.h"
#include "ecole.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
    ecole_privee e("ecole1","adresse1",100,new int[6]{10,20,30,15,15,10},"gerant1",500);
    e.view(); 
    ecole* a = new ecole_privee("ecole2","adresse2",150,new int[6]{23,32,40,25,20,15},"gerant2",75);
    a->view();  
    
    delete a; // cleanup dynamically allocated object before exit
    return 0;
}