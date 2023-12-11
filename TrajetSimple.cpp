/*************************************************************************
                               TrajetSimple
                             -------------------
    début                : 22/11/2023
    copyright            : (C) 2023 par CHAOUKI Youssef, CHIKHI Djalil, DALAOUI Riad, HANADER Rayan
    e-mail               : youssef.chaouki@insa-lyon.fr
                           djalil.chikhi@insa-lyon.fr
                           riad.dalaoui@insa-lyon.fr
                           rayan.hanader@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const char * TrajetSimple::GetTransport () const
{
    return this->moyenTransport; //Retourne le mode de transport du trajet
}


void TrajetSimple::Afficher (  ) const
// Méthode affichage d'un trajet simple
{   
    cout << " " << this->villeDepart << " ------ " << "( " << this->moyenTransport << " )"<< " ------> " <<this->villeArrivee << endl;
} //----- Fin de la méthode Afficher


bool TrajetSimple::operator==(const Trajet& autre) const {
    const TrajetSimple* autreSimple = dynamic_cast<const TrajetSimple*>(&autre);
    if (!autreSimple) {
        return false; // Impossible de comparer un TrajetSimple avec autre chose qu'un TrajetSimple
    }

    // Comparaison des attributs pour vérifier l'égalité en utilisant les méthodes d'accès
    if (strcmp(this->GetDepart(), autreSimple->GetDepart()) != 0 ||
        strcmp(this->GetArrivee(), autreSimple->GetArrivee()) != 0 ||
        strcmp(this->GetTransport(), autreSimple->GetTransport()) != 0) {
        return false;
    }

    return true;
} //------ Fin de surchage d'opérateur ==


//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const TrajetSimple& autre) : Trajet(autre)
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif

    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    strcpy(this->moyenTransport, autre.GetTransport());
} //-------- Fin constructeur par copie TrajetSimple


TrajetSimple::TrajetSimple (  )
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
cout << endl << "Veuillez saisir la ville de depart :" << endl;
cin >> this->villeDepart;
cout << endl << "Veuillez saisir la ville d'arrivee :" << endl;
cin >> this->villeArrivee;
cout << endl<< "Veuillez saisir le mode de transport" << endl;
cin >> this->moyenTransport;

} //----- Fin de TrajetSimple


TrajetSimple::TrajetSimple ( char A[50], char B[50],char T[50] ){
    strcpy(this->villeDepart,A);
    strcpy(this->villeArrivee,B);
    strcpy(moyenTransport,T);
};


TrajetSimple::~TrajetSimple ( )
//Destructeur
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

