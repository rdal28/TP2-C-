/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher (  )
// Algorithme :
//
{
    cout << "Trajet compose de " << this->villeDepart << " a " << this->villeArrivee << endl;

    int compteur;
    for (compteur=0;compteur<this->nb_escales+1;compteur++)  
    {
     cout << "Etape " << compteur+1<< " : de "<< this->tabtrajet[compteur][0]<< " a " << this->tabtrajet[compteur][2] << " en " << this->tabtrajet[compteur][1] << endl;   
    }  
} //----- Fin de Méthode



//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif


    cout << "Veuillez saisir le nombre d'escales" << endl << endl;
    cin >> this->nb_escales;


    int i;
    for (i=0;i<this->nb_escales+1;i++)
    {
        this->tabtrajet[i]= new char[3];
    }

    cout << "Veuillez saisir la ville de depart" << endl << endl;
    cin >> this->tabtrajet[0][0];

    cout << "Veuillez saisir la ville d'arrivée" << endl << endl;
    cin >> this->tabtrajet[this->nb_escales+1][2];

    for (i=0;i<this->nb_escales;i++)
    {

        cout << "Veuillez saisir l'escale" << i+1 << endl;
        cin >> this->tabtrajet[i][2];
        cin >> this->tabtrajet[i+1][0];

        cout << "Veuillez saisir le moyen de transport entre" << this->tabtrajet[i][0]<< "et "<< this->tabtrajet[i][2]<< endl;
        cin >> this->tabtrajet[i][1];

    }

    cout << "Veuillez saisir le moyen de transport entre" << this->tabtrajet[this->nb_escales+1][0]<< "et "<< this->tabtrajet[this->nb_escales+1][2]<< endl;
    cin >> this->tabtrajet[this->nb_escales][1];







} //----- Fin de Trajet

TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

