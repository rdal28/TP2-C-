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

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>
#include <typeinfo>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher (  ) const
// Affiche les détails du trajet composé en parcourant le tableau dynamique de trajets
{   
    const int j = this->GetTableau().GetNbTrajetsCourant();

    for(int i = 0; i < j; i++)
    {   

        const Trajet * trajet_i = this->GetTableau().GetTrajet(i);
        if(i==0){
            cout << " " << trajet_i->GetDepart() << " ------ " << "( " << trajet_i->GetTransport() << " )"<< " ------> " << trajet_i->GetArrivee();
        }else{
            cout << " ------ " << "( " << trajet_i->GetTransport() << " )"<< " ------> " << trajet_i->GetArrivee();
        }
        

    }
    cout<< endl;
} //----- Fin de Méthode


const TableauDynamique& TrajetCompose::GetTableau (  ) const
// Renvoie le tableau dynamique de trajets associé à ce trajet composé
{   
    return this->tabDynamique;
} //----- Fin de Méthode


int TrajetCompose::GetNbEscales (  ) const
 // Renvoie le nombre d'escales dans le trajet composé
{
    return this->nbEscales;
} //----- Fin de Méthode


const TrajetSimple* TrajetCompose::RechercheDansTrajetCompose(const char* VilleA, const char* VilleB) 
 // Recherche un trajet simple dans le trajet composé en fonction des villes de départ et d'arrivée
{
        for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
            TrajetSimple* trajet = (TrajetSimple*) tabDynamique.GetTrajet(i);
            if (!strcmp(trajet->GetArrivee(), VilleB) && !strcmp(trajet->GetDepart(), VilleA)) {
                return trajet;
            }
        }
        return nullptr;
}


bool TrajetCompose::operator==(const Trajet& autre) const 
// Surcharge de l'opérateur d'égalité pour comparer deux trajets composés
{
    const TrajetCompose* autreCompose = dynamic_cast<const TrajetCompose*>(&autre);
    if (!autreCompose) {
        return false;
    }

    if (strcmp(this->villeDepart, autreCompose->GetDepart()) != 0 ||
        strcmp(this->villeArrivee, autreCompose->GetArrivee()) != 0 ||
        this->nbEscales != autreCompose->GetNbEscales() ||
        this->tabDynamique.GetNbTrajetsCourant() != autreCompose->GetTableau().GetNbTrajetsCourant()) {
        return false;
    }
    
    for (int i = 0; i < this->tabDynamique.GetNbTrajetsCourant(); i++) {
        if (!(*(this->tabDynamique.GetTrajet(i)) == *(autreCompose->GetTableau().GetTrajet(i)))) {
            return false;
        }
    }

    return true;
}


//-------------------------------------------- Constructeurs - destructeur


TrajetCompose::TrajetCompose(const TrajetCompose& autre) : Trajet(autre)
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    this->nbEscales = autre.GetNbEscales();
    this->tabDynamique = TableauDynamique(autre.GetTableau());
    
}


TrajetCompose::TrajetCompose ( )
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    char final_end[50];
    cout << endl << "Quelle est la ville d'arrivee finale de ce trajet" << endl;
    cin >> final_end;
    this->nbEscales = 0;
    char start[50];
    char end[50]="";
    char mean[50];
    while(strcmp(end,final_end))
    {   
        if(this->nbEscales==0){
            cout << endl << "Veuillez saisir la ville de depart du trajet compose:" << endl;
            cin >> start;
            cout << endl << "Veuillez saisir la ville suivante:" << endl;
            cin >> end;
            cout << endl<< "Veuillez saisir le mode de transport:" << endl;
            cin >> mean;
            TrajetSimple * TS = new  TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
            this->nbEscales++;
            strcpy(this->villeArrivee, final_end);
            strcpy(this->villeDepart, start);
        }else{
            strcpy(start,end);
            cout << endl << "Veuillez saisir la ville suivante:" << endl;
            cin >> end;
            cout << endl<< "Veuillez saisir le mode de transport:" << endl;
            cin >> mean;
            TrajetSimple * TS = new TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
        }
    }



} //----- Fin de Trajet


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif


} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

