/*************************************************************************
                                TrajetSimple
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// La classe TrajetSimple permet de créer et manipuler des trajets simples, elle hérite de la classe Trajet
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher ( ) const; 
    // Méthode pour afficher les détails d'un trajet simple (sans escales)

    const char* GetTransport ( ) const; 
    // Méthode pour obtenir le moyen de transport d'un trajet

    bool operator==(const Trajet& autre) const; 
    // Surcharge de l'opérateur d'égalité pour comparer deux trajets

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const TrajetSimple& autre);
    // Constructeur de copie

    
    TrajetSimple();
    // Constructeur par défaut

    TrajetSimple ( char A[50], char B[50],char T[50] );
    // Constructeur prenant en paramètre les villes de départ et d'arrivée, ainsi que le moyen de transport


    ~TrajetSimple ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char moyenTransport[50];
    // Attribut protégé représentant le moyen de transport du trajet
    
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H



