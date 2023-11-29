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

void Catalogue::Rechercher (char* VilleA, char* VilleB)
{

    int nbrt = this->tabDynamique->nbTrajetsCourant;
    for(int i= 0; i<nbrt; i++){
        if(this->tabDynamique[i]->GetArrivee()==VilleA 
        && this->tabDynamique[i]->GetDepart()==VilleB) this->tabDynamique[i]->Afficher(); 
    }

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

