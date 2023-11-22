#include <iostream>
using namespace std;
#include <cstring>
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"

int main()
{   
    cout << endl << "Initialisation de l'application" << endl << endl << "--------------------------------" << endl << "Auteurs : Dalaoui Riad, Chaouki Youssef, Chikhi Djalil et Hanader Rayan" << endl << endl;
    cout << "Bienvenue dans l'application de gestion de trajets" << endl << endl;
    Catalogue catalogue;
    
    int choix=0;
    while (choix != 4)
    {   

        cout << "--------------------------------   " << "Veuillez saisir :" << endl << "1 pour ajouter un trajet au catalogue" << endl
        << "2 pour afficher le catalogue" << endl << "3 pour rechercher un trajet" << endl << "4 pour quitter l'application" << endl << endl;

        cin >> choix;

        char * villeDepart = new char[50];
        char * villeArrivee = new char[50];

        switch (choix)
        {
            case 1:
            {   

                cout << "Veuillez saisir :" << endl << "1 pour ajouter un trajet simple" << endl
                << "2 pour ajouter un trajet compose" << endl << endl;
                int choixAjout;
                cin >> choixAjout;
                if (choixAjout == 1)
                {
                    TrajetSimple * t = new TrajetSimple();
                    catalogue.Ajouter(t);
                    t->Afficher();
                }
                /*else if (choixAjout == 2)
                {
                    ///////////////////////////// A COMPLETER /////////////////////////////
                }*/


                break;
            }

            case 2:
            {
                catalogue.Afficher();
                break;
            }

            /*case 3 :
            {
                cout << "Veuillez saisir la ville de depart :" << endl;
                cin >> villeDepart;
                cout << "Veuillez saisir la ville d'arrivee :" << endl;
                cin >> villeArrivee;
                
                catalogue.Rechercher(villeDepart, villeArrivee);
                break;
            }*/
        }
    }

    return 0;
}