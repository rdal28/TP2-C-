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
<<<<<<< HEAD

cout << "Veuillez saisir la ville de depart :" << endl;
cin >> this->villeDepart;
cout << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> this->villeArrivee;

=======
cout << "Veuillez saisir la ville de depart :" << endl;
cin >> arretDepart;
cout << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> arretArrivee;
>>>>>>> 4d6f9ca2ce46c63fb566a3c243b8532c31379baf
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

