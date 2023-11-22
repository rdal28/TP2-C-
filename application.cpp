#include <iostream>
using namespace std;
#include <cstring>
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

int main()
{   
    cout << "Initialisation de l'application" << endl << endl << "--------------------------------" << endl << "Auteurs : Dalaoui Riad, Chaouki Youssef, Chikhi Djalil et Hanader Rayan" << endl << endl;
    cout << "Bienvenue dans l'application de gestion de trajets" << endl << endl;
    Catalogue catalogue;
    
    cout << "Veuillez saisir :" << endl << "1 pour ajouter un trajet au catalogue" << endl
    << "2 pour afficher le catalogue" << endl << "3 pour rechercher un trajet" << endl << "4 pour quitter l'application" << endl << endl;

    int choix;
    cin >> choix;
    while (choix != 4)
    {   

        char * villeDepart = new char[50];
        char * villeArrivee = new char[50];

        switch (choix)
        {
            case 1:
            {   
                cout << "Veuillez saisir la ville de depart :" << endl;
                cin >> villeDepart;
                cout << "Veuillez saisir la ville d'arrivee :" << endl;
                cin >> villeArrivee;

                cout << "Veuillez saisir :" << endl << "1 pour ajouter un trajet simple" << endl
                << "2 pour ajouter un trajet compose" << endl << endl;
                int choixAjout;
                cin >> choixAjout;
                if (choixAjout == 1)
                {
                    ///////////////////////////// A COMPLETER /////////////////////////////
                }
                else if (choixAjout == 2)
                {
                    ///////////////////////////// A COMPLETER /////////////////////////////
                }
            }

            case 2:
            {
                catalogue.Afficher(); ////////// VERIFIER CATALOGUE VIDE DANS LA METHODE AFFICHER ///////////
            }

            case 3 :
            {
                cout << "Veuillez saisir la ville de depart :" << endl;
                cin >> villeDepart;
                cout << "Veuillez saisir la ville d'arrivee :" << endl;
                cin >> villeArrivee;
                
                catalogue.Rechercher(villeDepart, villeArrivee);
            }
        }
    }

    return 0;
}