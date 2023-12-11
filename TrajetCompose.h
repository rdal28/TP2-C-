/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const TableauDynamique& GetTableau (  ) const;

    int GetNbEscales (  ) const;


    const TrajetSimple* RechercheDansTrajetCompose(const char* VilleA, const char* VilleB);

    bool operator==(const Trajet& autre) const;


//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    ~TrajetCompose ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int nbEscales;
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H



