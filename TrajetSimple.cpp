/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

char * TrajetSimple::GetTransport ()
{
    return this->moyenTransport;
}

void TrajetSimple::Afficher (  )
// Algorithme :
//
{
    cout << "Trajet simple de " << this->villeDepart << " a " << this->villeArrivee << " en " << this->moyenTransport << endl;
} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (  )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif

cout << "Veuillez saisir le mode de transport" << endl << endl;
cin >> this->moyenTransport;

} //----- Fin de Trajet


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

