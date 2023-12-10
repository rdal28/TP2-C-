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

const char * TrajetSimple::GetTransport ()
{
    return this->moyenTransport;
}

void TrajetSimple::Afficher (  )
// Algorithme :
//
{
    cout << " " << this->villeDepart << " ------ " << "( " << this->moyenTransport << " )"<< " ------> " <<this->villeArrivee << endl;
} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple (  )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
cout << endl << "Veuillez saisir la ville de depart :" << endl;
cin >> this->villeDepart;
cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> this->villeArrivee;
cout << endl<< "Veuillez saisir le mode de transport" << endl;
cin >> this->moyenTransport;

} //----- Fin de Trajet

TrajetSimple::TrajetSimple ( char A[50], char B[50],char T[50] ){
    strcpy(this->villeDepart,A);
    strcpy(this->villeArrivee,B);
    strcpy(moyenTransport,T);
};


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

