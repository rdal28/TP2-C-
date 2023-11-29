#include "TableauDynamique.h"
#include "Trajet.h"
#include <iostream>
using namespace std;

int main(){

    Trajet *t= new Trajet();
    TableauDynamique *td = new TableauDynamique();
    td->Ajouter(t);
    td->Ajouter(t);
    td->Ajouter(t);
    cout << td->GetTrajet(0) << endl;
    cout << td->GetTrajet(1) << endl;
    cout << td->GetTrajet(2) << endl;

    return 0;
}