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
void TrajetSimple::Afficher (  )
// Algorithme :
//
<<<<<<< HEAD
{
    cout << "Trajet simple de " << this->villeDepart << " a " << this->villeArrivee << " en " << this->moyenTransport << endl;
=======
{   
    cout<<"Vous partez de "<< this->arretDepart;
    cout<<" et arrivez a "<< this->arretArrivee;
    cout<<" en "<< this->moyenTransport<<"."<<endl;

>>>>>>> 4d6f9ca2ce46c63fb566a3c243b8532c31379baf
} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

<<<<<<< HEAD
TrajetSimple::TrajetSimple (  )
=======
TrajetSimple::TrajetSimple()
    : Trajet()
>>>>>>> 4d6f9ca2ce46c63fb566a3c243b8532c31379baf
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
<<<<<<< HEAD

cout << "Veuillez saisir le mode de transport" << endl << endl;
cin >> this->moyenTransport;
=======
cout << "Veuillez saisir le moyen de transport :" << endl;
cin >> moyenTransport;

>>>>>>> 4d6f9ca2ce46c63fb566a3c243b8532c31379baf

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

