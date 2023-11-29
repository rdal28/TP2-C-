/*************************************************************************
                           TableauDynamique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TableauDynamique> (fichier TableauDynamique.h) ----------------
#if ! defined ( TRAJET_H )
#define TABLEAUDYNAMIQUE_H

#define TAILLE_MAX_INIT 10

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TableauDynamique>
//
//
//------------------------------------------------------------------------

class TableauDynamique
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques


    void Ajouter ( Trajet * ptTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

    const Trajet* GetTrajet ( int i );

    const int GetNbTrajetsCourant ( );

//-------------------------------------------- Constructeurs - destructeur

    TableauDynamique( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TableauDynamique ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

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



