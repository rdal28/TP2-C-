/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
void Trajet::Afficher (  )
// Algorithme :
//
{

} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet() 
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif

cout << "Veuillez saisir la ville de depart :" << endl;
cin >> this->villeDepart;
cout << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> this->villeArrivee;

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

