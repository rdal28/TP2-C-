/*************************************************************************
                                Catalogue
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#define TAILLE_MAX_INIT 10


#include "TableauDynamique.h"
#include "TrajetCompose.h"
#include "DirectedGraph.h"

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
    // Affiche les trajets du catalogue

    DirectedGraph* toGraph();

    void RechercheSimple (char*, char*);
    // Effectue une recherche simple de trajets entre VilleA et VilleB

    void BruteForceSearch (const char* VilleA, const char* VilleB, TableauDynamique& currentPath, int pathLength, bool& found);
    // Effectue une recherche brute-force de trajets entre VilleA et VilleB

    void UneCombinaison(Trajet* startTrajet,const char* VilleA, const char* VilleB , TableauDynamique& currentPath);
    // Recherche récursive d'une combinaison de trajets entre VilleA et VilleB

    void RechercheAvancee (const char*, const char*);
    // Recherche avancée de trajets entre VilleA et VilleB

    virtual void Ajouter ( Trajet * ptTrajet );
    // Ajoute un trajet au catalogue


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Constructeur par défaut

    virtual ~Catalogue ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
    // Tableau dynamique de trajets dans le catalogue
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H



