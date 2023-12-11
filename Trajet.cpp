/*************************************************************************
                                   Trajet
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const char * Trajet::GetTransport () const
// Méthode virtuelle constante pour obtenir le moyen de transport du trajet
{
    return nullptr;
}

const char * Trajet::GetDepart () const
 // Méthode constante pour obtenir la ville de départ du trajet
{   
    return this->villeDepart;
}

const char * Trajet::GetArrivee () const
// Méthode constante pour obtenir la ville d'arrivée du trajet
{   
    return this->villeArrivee;
}

void Trajet::Afficher (  ) const 
// Méthode virtuelle pure pour afficher les détails du trajet
{
    #ifdef MAP
    cout << "Entree dans Afficher de Trajet" << endl;
    #endif

} //----- Fin de la méthode Afficher

 bool Trajet::operator==(const Trajet& autre) const
 { 
     // Méthode virtuelle constante pour comparer deux trajets (implémentée dans les classes dérivées)
 }




//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const Trajet& autre)
// Constructeur de copie de Trajet
{
    #ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
    #endif

} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet() 
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

