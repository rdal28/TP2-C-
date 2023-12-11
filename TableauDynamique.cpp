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
    // Ajoute un trajet au tableau dynamique
    if(this->nbTrajetsCourant == this->nbTrajetsMax-1)
    {   
        // Si le tableau est plein, on double sa taille
        this->nbTrajetsMax *= 2;
        Trajet ** newTab = new Trajet*[this->nbTrajetsMax];
        memcpy(newTab, this->tabDynamique, this->nbTrajetsMax*sizeof(Trajet*));
        delete[] this->tabDynamique;
        this->tabDynamique = newTab;
    }

    // Ajoute le trajet au tableau et incrémente le nombre de trajets
    this->tabDynamique[this->nbTrajetsCourant] = ptTrajet;
    this->nbTrajetsCourant++;

} //----- Fin de Méthode


Trajet* TableauDynamique::GetTrajet ( int i ) const
{   
    // Renvoie le trajet à l'indice i dans le tableau dynamique
    return this->tabDynamique[i];
}

int TableauDynamique::GetNbTrajetsCourant ( ) const 
{   
    // Renvoie le nombre de trajets actuellement dans le tableau dynamique
    return this->nbTrajetsCourant;
}

void TableauDynamique::Supprimer(int i)
{   
    // Supprime le trajet à l'indice i dans le tableau dynamique
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
    // Modifie le nombre de trajets actuellement dans le tableau dynamique
    this->nbTrajetsCourant = i;
}

void TableauDynamique::Modif(int i, Trajet* t)
{
    // Modifie le trajet à l'indice i dans le tableau dynamique
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
    // Constructeur par défaut
    this->nbTrajetsCourant = 0;
    this->nbTrajetsMax = 10;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];
}

TableauDynamique::TableauDynamique(int tabSizeInit) 
 // Constructeur avec initialisation de la taille maximale du tableau
{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = tabSizeInit;
this->tabDynamique = new Trajet*[this->nbTrajetsMax];

} //----- Fin de Trajet


TableauDynamique::~TableauDynamique ( )

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

