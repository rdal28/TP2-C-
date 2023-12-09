/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher (  )
// Algorithme :
//
{
    cout << "Trajet compose avec ville initiale : " << this->villeDepart << " et ville finale : " << this->villeArrivee << endl;
    cout << endl << "Voici les sous trajets simples qui le composent :" << endl << endl;
    for(int i = 0; i < this->tabDynamique.GetNbTrajetsCourant(); i++)
    {   
        cout << "Sous trajet numero " << i+1 << " :" << endl<<endl;
        this->tabDynamique.GetTrajet(i)->Afficher();
        cout << endl;
    }
} //----- Fin de Méthode

const TableauDynamique TrajetCompose::GetTableau (  )
// Algorithme :
//
{
    return this->tabDynamique;
} //----- Fin de Méthode

const TrajetSimple* TrajetCompose::RechercheDansTrajetCompose(const char* VilleA, const char* VilleB) {
        for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
            TrajetSimple* trajet = (TrajetSimple*) tabDynamique.GetTrajet(i);
            if (!strcmp(trajet->GetArrivee(), VilleB) && !strcmp(trajet->GetDepart(), VilleA)) {
                return trajet;
            }
        }
        return nullptr;
    }

//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif

cout << endl << "Veuillez saisir le nombre d'escales de votre parcours, c'est a dire le nombre d'arrets entre votre arret initial et votre arret final" << endl;
cin >> this->nbEscales;
cout << "Votre trajet compose se sub-divise en sous trajets simples :" << endl << endl;
for(int i = 0; i <= this->nbEscales; i++)
{
    cout << "Sous trajet numero " << i+1 << " :" << endl<<endl;
    TrajetSimple * TS = new TrajetSimple();
    this->tabDynamique.Ajouter(TS);
    cout << endl;
}

} //----- Fin de Trajet


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif

for(int i = 0; i < this->tabDynamique.GetNbTrajetsCourant(); i++)
{
    this->tabDynamique.GetTrajet(i)->~Trajet();
    delete this->tabDynamique.GetTrajet(i);
}
this->tabDynamique.~TableauDynamique();
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

