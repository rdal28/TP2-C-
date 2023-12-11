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

const char * Trajet::GetTransport () const
{
    return nullptr;
}

int Trajet::GetNbEscales (  ) const {
    return 0;
}

const char * Trajet::GetDepart () const
{   
    return this->villeDepart;
}

const char * Trajet::GetArrivee () const
{   
    return this->villeArrivee;
}

void Trajet::Afficher (  ) const 
// Algorithme :
//
{
    cout << "Entree dans Afficher de Trajet" << endl;
} //----- Fin de Méthode

 bool Trajet::operator==(const Trajet& autre) const
 {

 }




//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const Trajet& autre)
{
cout << "Appel au constructeur de copie de <Trajet>" << endl;
} //----- Fin de Trajet (constructeur de copie)

Trajet::Trajet() 
// Algorithme :
//

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

