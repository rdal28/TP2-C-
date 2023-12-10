/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#define TAILLE_MAX_INIT 10


#include "TableauDynamique.h"
#include "TrajetCompose.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void RechercheSimple (char*, char*);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void BruteForceSearch (const char* VilleA, const char* VilleB, TableauDynamique currentPath, int pathLength, bool& found);


    TableauDynamique UneReponse(Trajet* startTrajet,const char* VilleA, const char* VilleB);


    void RechercheAvancee (const char*, const char*);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual void Ajouter ( Trajet * ptTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H



