/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
    return this->moyenTransport;
}

void TrajetSimple::Afficher (  ) const
// Algorithme :
//
{   
    cout << " " << this->villeDepart << " ------ " << "( " << this->moyenTransport << " )"<< " ------> " <<this->villeArrivee << endl;
} //----- Fin de Méthode



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
}




//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple(const TrajetSimple& autre) : Trajet(autre)
{
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    strcpy(this->moyenTransport, autre.GetTransport());
}


TrajetSimple::TrajetSimple (  )
// Algorithme :
//
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

} //----- Fin de Trajet

TrajetSimple::TrajetSimple ( char A[50], char B[50],char T[50] ){
    strcpy(this->villeDepart,A);
    strcpy(this->villeArrivee,B);
    strcpy(moyenTransport,T);
};


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

