/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>
#include <typeinfo>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher (  )
{   
    int nbTrajetsCourant = this->tabDynamique.GetNbTrajetsCourant();

    if (nbTrajetsCourant == 0)
    {
        cout << "Le catalogue est vide" << endl << endl;
    } else {
        cout << "Le catalogue contient les trajets suivants :" << endl <<endl;
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            cout << "Trajet numero " << i+1 << " : ";
            this->tabDynamique.GetTrajet(i)->Afficher();
        }
    }

} //----- Fin de Méthode

void Catalogue::Ajouter ( Trajet * ptTrajet )
{

    this->tabDynamique.Ajouter(ptTrajet);

} //----- Fin de Méthode

void Catalogue::RechercheSimple (char* VilleA, char* VilleB)
{

    
    int nbrt = this->tabDynamique.GetNbTrajetsCourant();
    bool trajetTrouve = false;


    for(int i= 0; i<nbrt; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);

        if (!strcmp(t->GetArrivee(), VilleB) && !strcmp(t->GetDepart(), VilleA)) {
            cout << endl << "Voici les trajets qui correspondent a votre recherche :" << endl;
            t->Afficher();
            trajetTrouve = true;
        } else if (typeid(*t) == typeid(TrajetCompose)) {
            TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(t);
            TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
            if (ts != nullptr) {
                cout << endl <<"Voici les trajets qui correspondent a votre recherche :" << endl;
                ts->Afficher();
                trajetTrouve = true;
            }
        }
    }

    if (!trajetTrouve) {
        cout << endl << "Aucun trajet trouve de " << VilleA << " a " << VilleB << ".";
    }

} //----- Fin de Méthode


void Catalogue::BruteForceSearch(const char* VilleA, const char* VilleB, Trajet* currentPath[], int pathLength, bool& found) {
    // Si le trajet actuel est celui que nous recherchons, affichez le chemin
    if (!strcmp(currentPath[pathLength - 1]->GetArrivee(), VilleB)) {
        for (int i = 0; i < pathLength; i++) {
            currentPath[i]->Afficher();
        }
        found = true;
        return;
    }

    // Parcourez tous les trajets pour trouver le prochain trajet possible
    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        Trajet* nextTrajet = tabDynamique.GetTrajet(i);

        // Vérifiez si le prochain trajet est relié au dernier trajet dans le chemin actuel
        if (!strcmp(currentPath[pathLength - 1]->GetArrivee(), nextTrajet->GetDepart())) {
            // Ajoutez ce trajet au chemin actuel
            currentPath[pathLength] = nextTrajet;

            // Appelez récursivement la recherche pour explorer ce chemin
            BruteForceSearch(VilleA, VilleB, currentPath, pathLength + 1, found);

            // Si le trajet a été trouvé, arrêtez la recherche
            if (found) {
                return;
            }
        }
    }
}

void Catalogue::RechercheComplexe(const char* VilleA, const char* VilleB) {
    const int MAX_PATH_LENGTH = 100; // Taille maximale du chemin
    Trajet* currentPath[MAX_PATH_LENGTH]; // Tableau pour stocker le chemin actuel
    bool found = false; // Indicateur de trajet trouvé

    // Parcourez tous les trajets pour démarrer la recherche
    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        Trajet* startTrajet = tabDynamique.GetTrajet(i);

        // Si le départ correspond à VilleA, commencez la recherche à partir de ce trajet
        if (!strcmp(startTrajet->GetDepart(), VilleA)) {
            currentPath[0] = startTrajet;
            BruteForceSearch(VilleA, VilleB, currentPath, 1, found);
            if (found) {
                break;
            }
        } else {
            cout << "Aucun trajet trouve" << endl;
        }
        
    }
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

