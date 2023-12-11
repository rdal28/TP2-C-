/*************************************************************************
                               TrajetCompose
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H
#define TAILLE_MAX_INIT 10
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TableauDynamique.h"
#include "Catalogue.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>

// La classe TrajetCompose permet de créer et manipuler des trajets composés, elle hérite de la classe Trajet
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  ) const;
    // Méthode pour afficher les détails du trajet composé

    const TableauDynamique& GetTableau (  ) const;
    // Méthode pour obtenir le tableau dynamique de trajets

    int GetNbEscales (  ) const;
    // Méthode pour obtenir le nombre d'escales dans le trajet composé


    const TrajetSimple* RechercheDansTrajetCompose(const char* VilleA, const char* VilleB);
    // Méthode pour rechercher un trajet simple dans le trajet composé en fonction des villes de départ et d'arrivée

    bool operator==(const Trajet& autre) const;
    // Surcharge de l'opérateur d'égalité pour comparer deux trajets composés


//-------------------------------------------- Constructeurs - destructeur


    TrajetCompose(const TrajetCompose& autre);
    // Constructeur de copie

    
    TrajetCompose ( );
    // Constructeur par défaut

    ~TrajetCompose ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int nbEscales;
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
    // Attribut protégé représentant un tableau dynamique de trajets simples 
};

#endif // TRAJETCOMPOSE_H



