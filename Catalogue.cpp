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


void Catalogue::BruteForceSearch(const char* VilleA, const char* VilleB, TableauDynamique& currentPath, int pathLength, bool& found) {

    if (!strcmp(currentPath.GetTrajet(pathLength - 1)->GetArrivee(), VilleB)) {
        found = true;
        return;
    }

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        if(tabDynamique.GetTrajet(i) == currentPath.GetTrajet(pathLength - 1)) continue;
        Trajet* nextTrajet = tabDynamique.GetTrajet(i);

        bool alreadyExists = false;
        for(int j = 0; j < pathLength; j++) {
            if(nextTrajet == currentPath.GetTrajet(j)) {
                alreadyExists = true;
                break;
            }
        }
        
        if (alreadyExists) continue;

        if (!strcmp(currentPath.GetTrajet(pathLength - 1)->GetArrivee(), nextTrajet->GetDepart())) {
            currentPath.Ajouter(nextTrajet);
            BruteForceSearch(VilleA, VilleB, currentPath, pathLength + 1, found);
            if (found) {
                break;
            } else 
            {currentPath.Supprimer(pathLength - 1);} // Retour en arrière pour essayer un autre trajet
        }
    }
    return;
}



void Catalogue::UneCombinaison(Trajet* startTrajet, const char* VilleA, const char* VilleB, TableauDynamique& currentPath){
    
    bool found = false; // Indicateur de chemin trouvé

    currentPath.Ajouter(startTrajet);
    BruteForceSearch(VilleA, VilleB, currentPath, 1, found);

    return;
}


void Catalogue::RechercheAvancee(const char* VilleA, const char* VilleB) {

    const int MAX_PATH_LENGTH = 3; // Longueur maximale du chemin (réalloué si nécessaire)
    
    // Parcours tous les trajets pour stocker les trajets de départ
    TableauDynamique Departs(this->tabDynamique.GetNbTrajetsCourant());
    int departsCount = 0;

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
        Trajet* startTrajet = tabDynamique.GetTrajet(i);
        
        if(!strcmp(startTrajet->GetDepart(), VilleA)) {
            // Retrait des doublons
            bool alreadyExists = false;
            for (int j = 0; j < departsCount; j++) {
                if (!strcmp(startTrajet->GetDepart(), Departs.GetTrajet(j)->GetDepart()) && !strcmp(startTrajet->GetArrivee(), Departs.GetTrajet(j)->GetArrivee())) {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists) {
                Departs.Ajouter(startTrajet);
                departsCount++;
            }
        }
    }

    for (int i = 0; i < departsCount; i++) {
        cout << "Trajet de depart numero " << i+1 << " : ";
        Departs.GetTrajet(i)->Afficher();
    }

    // Parcours tous les trajets de départ pour trouver les chemins possibles
    for(int j=0; j<departsCount; j++){
        cout << "Itération " << j << " : " << endl;
        Trajet* startTrajet = Departs.GetTrajet(j);
        TableauDynamique currentPath(MAX_PATH_LENGTH); // Tableau pour stocker le chemin actuel
        UneCombinaison(startTrajet, VilleA, VilleB, currentPath);
        if (currentPath.GetNbTrajetsCourant()!=1) {
            cout << endl << "Un ensemble de trajets correspondant à votre recherche est :" << endl << endl;
            for(int i=0; i<currentPath.GetNbTrajetsCourant(); i++){
                cout << "Trajet numero " << i+1 << " : ";
                cout << currentPath.GetTrajet(i) << endl;
                cout << currentPath.GetTrajet(i)->GetDepart() << endl;
                cout << currentPath.GetTrajet(i)->GetArrivee() << endl;
                cout << currentPath.GetTrajet(i)->GetTransport() << endl;
                cout << typeid(*currentPath.GetTrajet(i)).name() << endl;

                currentPath.GetTrajet(i)->Afficher(); // PETITE ERREUR DE MERDE A REGLER ICI 
                cout << endl;
            }
        }
    }


    cout << endl << "Fin de la recherche avancee" << endl << endl;
    
    return ;
} // GROS PROBLEME DE CETTE FONCTION : ELLE NE RENVOIE QUE LE PREMIER CHEMIN SI IL Y EN A PLUSIEURS QUI POSSIBLES A PARTIR D'UN MEME TRAJET DEPART

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

