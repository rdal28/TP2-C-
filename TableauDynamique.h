/*************************************************************************
                                TableauDynamique
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TableauDynamique> (fichier TableauDynamique.h) ----------------
#if ! defined ( TABLEAUDYNAMIQUE_H )
#define TABLEAUDYNAMIQUE_H


#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TableauDynamique>
//
// Cette classe sert à créer un tableau dynamique qui stocke des sous-trajets constants dans un trajet composé
// afin d'avoir structure de données flexible pour gérer une séquence de trajets sans avoir à spécifier leur nombre à l'avance.
//------------------------------------------------------------------------

class TableauDynamique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    void Ajouter ( Trajet * ptTrajet );
    // Ajoute un trajet au tableau dynamique

    void Supprimer(int i);
    // Supprime le trajet à l'indice i dans le tableau dynamique

    Trajet* GetTrajet ( int i ) const;
    // Renvoie le trajet à l'indice i dans le tableau dynamique

    int GetNbTrajetsCourant ( ) const;
    // Renvoie le nombre de trajets actuellement dans le tableau dynamique

    void SetNbTrajetsCourant(int i);
    // Modifie le nombre de trajets actuellement dans le tableau dynamique

    void Modif(int i, Trajet* t);
    // Modifie le trajet à l'indice i dans le tableau dynamique

//-------------------------------------------- Constructeurs - destructeur


    TableauDynamique ( const TableauDynamique & autre ); 
    // Constructeur par copie


    TableauDynamique(); 
    //Constructeur par défaut


    TableauDynamique( int tabSizeInit );
    // Constructeur avec initialisation de la taille maximale du tableau

    virtual ~TableauDynamique ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Trajet* *tabDynamique;
    int nbTrajetsCourant;
    int nbTrajetsMax;
    
};

//-------------------------------- Autres définitions dépendantes de <TableauDynamique>

#endif // TABLEAUDYNAMIQUE_H



