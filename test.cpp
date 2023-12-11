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
    TrajetSimple * t5 = new TrajetSimple("Alger","Lyon","Train");
    TrajetSimple * t7 = new TrajetSimple("Alger","Nantes","Avion");
    TrajetSimple * t8 = new TrajetSimple("Nantes","Marseille","Train");
    TrajetSimple * t6 = new TrajetSimple("Alger","Marseille","Avion");
    TrajetSimple * t2 = new TrajetSimple("Paris","Lyon","Train");
    TrajetSimple * t3 = new TrajetSimple("Lyon","Marseille","Voiture");
    TrajetSimple * t4 = new TrajetSimple("Paris","Marseille","Avion");
    catalogue.Ajouter(t1);
    catalogue.Ajouter(t2);
    catalogue.Ajouter(t3);
    catalogue.Ajouter(t4);
    catalogue.Ajouter(t5);
    catalogue.Ajouter(t6);
    catalogue.Ajouter(t7);
    catalogue.Ajouter(t8);
    

    cout << endl;
    cout << "Recherche Simple :" << endl << endl;
    catalogue.RechercheSimple("Alger","Marseille");
    cout << endl;
    cout << "Recherche Avancee :" << endl << endl;
    catalogue.RechercheAvancee("Alger","Marseille");
    return 0;
}