/*************************************************************************
                           TableauDynamique  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TableauDynamique> (fichier TableauDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TableauDynamique.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TableauDynamique::Ajouter ( Trajet * ptTrajet )
{
    
    if(this->nbTrajetsCourant == this->nbTrajetsMax-1)
    {   
        this->nbTrajetsMax *= 2;
        Trajet ** newTab = new Trajet*[this->nbTrajetsMax];
        memcpy(newTab, this->tabDynamique, this->nbTrajetsMax*sizeof(Trajet*));
        delete[] this->tabDynamique;
        this->tabDynamique = newTab;
    }

    this->tabDynamique[this->nbTrajetsCourant] = ptTrajet;
    this->nbTrajetsCourant++;

} //----- Fin de Méthode

Trajet* TableauDynamique::GetTrajet ( int i ) const
{   
    return this->tabDynamique[i];
}

int TableauDynamique::GetNbTrajetsCourant ( ) const 
{   
    return this->nbTrajetsCourant;
}

void TableauDynamique::Supprimer(int i)
{   
    if(i < 0 || i > this->nbTrajetsCourant)
    {
        cout << "Erreur : indice invalide" << endl;
        return;
    }
    delete this->tabDynamique[i];
    this->tabDynamique[i] = nullptr;
    this->nbTrajetsCourant--;
}


void TableauDynamique::SetNbTrajetsCourant(int i)
{
    this->nbTrajetsCourant = i;
}

void TableauDynamique::Modif(int i, Trajet* t)
{
    this->tabDynamique[i] = t;
}

//-------------------------------------------- Constructeurs - destructeur


TableauDynamique::TableauDynamique ( const TableauDynamique & autre )
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TableauDynamique>" << endl;
    #endif

    // Copie des attributs de l'autre objet
    this->nbTrajetsCourant = autre.nbTrajetsCourant;
    this->nbTrajetsMax = autre.nbTrajetsMax;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];

    // Copie des trajets
    for (int i = 0; i < this->nbTrajetsCourant; ++i) {
        this->tabDynamique[i] = new Trajet(*autre.tabDynamique[i]);
    }
}
TableauDynamique::TableauDynamique()
{
        this->nbTrajetsCourant = 0;
        this->nbTrajetsMax = 10;
        this->tabDynamique = new Trajet*[this->nbTrajetsMax];
}

TableauDynamique::TableauDynamique(int tabSizeInit) 
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = tabSizeInit;
this->tabDynamique = new Trajet*[this->nbTrajetsMax];

} //----- Fin de Trajet


TableauDynamique::~TableauDynamique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif

cout << "Destruction du tableau dynamique" << endl;

for(int i = 0; i < this->nbTrajetsCourant; i++)
{
    delete this->tabDynamique[i];
}

cout << "Trajets détruits" << endl;
cout << "Destruction de l'attribut : " << endl;
delete[] this->tabDynamique;
cout << "Attribut détruit" << endl;

cout << "Tableau dynamique détruit" << endl;
} //----- Fin de ~TableauDynamique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

