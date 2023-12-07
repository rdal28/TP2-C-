#include "TableauDynamique.h"
#include "Trajet.h"
#include "Catalogue.h"
#include <iostream>
using namespace std;

int main(){

    Catalogue c = new Catalogue();
    Trajet *t= new Trajet();
    TableauDynamique *td = new TableauDynamique(10);
    td->Ajouter(t);
    td->Ajouter(t);
    td->Ajouter(t);
    c->Ajouter(td);
    cout << c->RechercheSimple("Lyon", "M") << endl;
    cout << td->GetTrajet(1) << endl;
    cout << td->GetTrajet(2) << endl;

    return 0;
}