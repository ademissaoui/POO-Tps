// Header includes for private and public school classes
#include "ecole_privee.h"
#include "ecole.h"
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
// Main program: demonstrates polymorphism with school objects
int main(){
    // Create a private school object with name, address, number of students, student distribution per level, manager, and capital
    ecole_privee e("ecole1","adresse1",100,new int[6]{10,20,30,15,15,10},"gerant1",50000.0f);
    e.view();  // Display the private school information
    // Create a pointer to base class (ecole) initialized with a derived class (ecole_privee) object
    // This demonstrates polymorphism - the view() method will call the derived class version
    ecole* a = new ecole_privee("ecole2","adresse2",150,new int[6]{20,30,40,25,20,15},"gerant2",75000.0f);
    a->view();  // Call virtual view() method - invokes ecole_privee::view() due to polymorphism
    
    return 0;
    delete a;
}