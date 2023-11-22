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
    if (this->nbTrajetsCourant == 0)
    {
        cout << "Le catalogue est vide" << endl << endl;
    } else {
        cout << "Le catalogue contient les trajets suivants :" << endl;
        for(int i = 0; i < this->nbTrajetsCourant; i++)
        {
            cout << "Trajet numéro" << i+1 << " : ";
            this->tabTrajets[i]->Afficher();
        }
    }

} //----- Fin de Méthode

void Catalogue::Ajouter ( Trajet * ptTrajet )
{
    
    if(this->nbTrajetsCourant == this->nbTrajetsMax-1)
    {   
        this->nbTrajetsMax *= 2;
        Trajet ** newTab = new Trajet*[this->nbTrajetsMax];
        memcpy(newTab, this->tabTrajets, this->nbTrajetsMax*sizeof(Trajet*));
        delete[] this->tabTrajets;
        this->tabTrajets = newTab;
    }

    this->tabTrajets[this->nbTrajetsCourant] = ptTrajet;
    this->nbTrajetsCourant++;

} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = TAILLE_MAX;
this->tabTrajets = new Trajet*[this->nbTrajetsMax];

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif

delete[] this->tabTrajets;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

