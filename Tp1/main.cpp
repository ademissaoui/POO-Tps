#include "ecole_privee.h"
#include "ecole.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    ecole_privee e("ecole1", "adresse1", 100, new int[6]{10, 20, 30, 15, 15, 10}, "gerant1", 500);
    e.view();
    cout << "===================================================" << endl;

    // allocate a separate heap object and keep its pointer so we can delete it safely
    ecole *heapObj = new ecole_privee("ecole2", "adresse2", 150, new int[6]{23, 32, 40, 25, 20, 15}, "gerant2", 75);
    heapObj->view();
    cout << "============================================" << endl;

    // demonstrate polymorphism using a pointer to the stack object
    ecole *a = &e;
    a->view();
    cout << "=================================" << endl;

    // clean up the heap allocation only
    delete heapObj;
    return 0;
}