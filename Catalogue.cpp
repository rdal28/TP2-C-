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
        cout << "Le catalogue contient les trajets suivants :" << endl;
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            cout << "Trajet numero" << i+1 << " : ";
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

    cout << "Voici les trajets qui correspondent a votre recherche :" << endl;
    int nbrt = this->tabDynamique.GetNbTrajetsCourant();


    for(int i= 0; i<nbrt; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);

        if(!strcmp(t->GetArrivee(), VilleB) && !strcmp(t->GetDepart(), VilleA)){ // Considère que A vers B et pas B vers A mais on peut changer ça
            t->Afficher();
        } else if (typeid(*t) == typeid(TrajetCompose)) { // CODER ICI LA RECHERCHE D'UN TRAJET SIMPLE DANS LES TRAJETS COMPOSES
            int nbrtC = t->GetTableau().GetNbTrajetsCourant();
            for(int i = 0; i<nbrtC; i++){
                Trajet* ts = t->GetTableau().GetTrajet(i);
                if(!strcmp(ts->GetArrivee(), VilleB) && !strcmp(ts->GetDepart(), VilleA)){
                    ts->Afficher();
                }
            } 
        }
    }

} //----- Fin de Méthode


void Catalogue::RechercheComplexe (char* VilleA, char* VilleB)
{

} //----- Fin de Méthode

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

this->tabDynamique.~TableauDynamique();

} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

