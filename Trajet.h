/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (  ) const ;
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual const char * GetTransport () const;
    virtual int GetNbEscales (  ) const;
    const char* GetArrivee () const;
    const char* GetDepart ()const ;
    virtual bool operator==(const Trajet& autre) const;

//-------------------------------------------- Constructeurs - destructeur

    Trajet ( const Trajet& autre ) ;


    Trajet( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char villeDepart[50];
    char villeArrivee[50];
    
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H



