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
{   
    cout<<"Vous partez de "<< this->arretDepart;
    cout<<" et arrivez a "<< this->arretArrivee;
    cout<<" en "<< this->moyenTransport<<"."<<endl;

} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple()
    : Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
cout << "Veuillez saisir le moyen de transport :" << endl;
cin >> moyenTransport;


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

