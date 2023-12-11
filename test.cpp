#include "TableauDynamique.h"
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
using namespace std;

int main(){
    Catalogue catalogue;
    TrajetSimple * t1 = new TrajetSimple("Alger","Paris","Avion");
    TrajetSimple * t5 = new TrajetSimple("Alger","Paris","Train");
    TrajetSimple * t7 = new TrajetSimple("Alger","Paris","Voiture");
    TrajetCompose * t2 = new TrajetCompose();
    TrajetCompose * t3 = new TrajetCompose();
    catalogue.Ajouter(t1);
    catalogue.Ajouter(t5);
    catalogue.Ajouter(t7);
    catalogue.Ajouter(t2);
    catalogue.Ajouter(t3);
    

    cout << endl;
    cout << "Recherche Simple :" << endl ;
    catalogue.RechercheSimple("Alger","Paris");
    cout << endl;

    return 0;
}