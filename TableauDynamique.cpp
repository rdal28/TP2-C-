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

const Trajet* TableauDynamique::GetTrajet ( int i )
{
    return this->tabDynamique[i];
}

const int TableauDynamique::GetNbTrajetsCourant ( )
{
    return this->nbTrajetsCourant;
}


//-------------------------------------------- Constructeurs - destructeur

TableauDynamique::TableauDynamique(int tabSize) 
// Algorithme :
//

{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = tabSize;
this->tabDynamique = new Trajet*[this->nbTrajetsMax];

} //----- Fin de Trajet


TableauDynamique::~TableauDynamique ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif


for(int i = 0; i < this->nbTrajetsCourant; i++)
{
    delete this->tabDynamique[i];
}
delete[] this->tabDynamique;
} //----- Fin de ~TableauDynamique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

