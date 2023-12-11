/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Afficher (  )
{   
    // Affiche les trajets du catalogue
    int nbTrajetsCourant = this->tabDynamique.GetNbTrajetsCourant();

    if (nbTrajetsCourant == 0)
    {
        cout << "Le catalogue est vide" << endl << endl;
    } else {
        cout << "Le catalogue contient les trajets suivants :" << endl <<endl;
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            cout << "Trajet numero " << i+1 << " : ";
            this->tabDynamique.GetTrajet(i)->Afficher();
        }
    }

} //----- Fin de Méthode


void Catalogue::Ajouter ( Trajet * ptTrajet )
{
    // Ajoute un trajet au catalogue
    this->tabDynamique.Ajouter(ptTrajet);

} //----- Fin de Méthode

// DirectedGraph* Catalogue::toGraph() {
//     // Création d'un nouveau graphe dirigé
//     DirectedGraph* graph = new DirectedGraph();

//     // Parcours de tous les trajets du catalogue
//     for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
//         // Récupération du trajet actuel
//         Trajet* trajet = tabDynamique.GetTrajet(i);

//         // Affichage du nombre d'escales du trajet (pour débogage)
//         cout << trajet->GetNbEscales() << endl;

//         // Ajout d'une arête en fonction du nombre d'escales
//         if (trajet->GetNbEscales() > 0) {
//             // Si le trajet a des escales, on ajoute une arête avec le label "trajet compose"
//             graph->addEdge(trajet->GetDepart(), trajet->GetArrivee(), "trajet compose");
//         } else {
//             // Sinon, on ajoute une arête avec le moyen de transport du trajet
//             graph->addEdge(trajet->GetDepart(), trajet->GetArrivee(), trajet->GetTransport());
//         }
//     }

//     // Retour du graphe construit
//     return graph;
// }
////laissé en commentaire que pour démo car utilise autre que iostream et string



void Catalogue::RechercheSimple (char* VilleA, char* VilleB)
{
    // Effectue une recherche simple de trajets entre VilleA et VilleB
    int nbrt = this->tabDynamique.GetNbTrajetsCourant();
    if(nbrt == 0)
    {
        cout << "Le catalogue est vide." << endl << endl;
        return;
    }

    bool trajetTrouve = false;

    cout << endl <<"Recherche simple en cours..." << endl << endl;

    for(int i= 0; i<nbrt; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);
        TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(t);
        if(trajetCompose){
            TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
            if (ts != nullptr) {
                cout << endl <<"Voici un trajet qui correspond à votre recherche (issu d'un Trajet Compose) :" << endl;
                ts->Afficher();
                trajetTrouve = true;
            }
        }

        if (!strcmp(t->GetArrivee(), VilleB) && !strcmp(t->GetDepart(), VilleA)) {
            cout << endl << "Voici un trajet qui correspond à votre recherche :" << endl;
            t->Afficher();
            trajetTrouve = true;   
        }
    }

    if (!trajetTrouve) {
        cout << endl << "Aucun trajet trouve dans le Catalogue de " << VilleA << " a " << VilleB << ".";
    }

} //----- Fin de Méthode


void Catalogue::RechercheBruteForce(const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant, int tailleChemin, bool& found) {

    if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), VilleB)) {
        found = true;
        return;
    }

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        if(tabDynamique.GetTrajet(i) == cheminCourant.GetTrajet(tailleChemin - 1)) continue;
        Trajet* nextTrajet = tabDynamique.GetTrajet(i);

        bool alreadyExists = false;
        for(int j = 0; j < tailleChemin; j++) {
            if(nextTrajet == cheminCourant.GetTrajet(j)) {
                alreadyExists = true;
                break;
            }
        }
        
        if (alreadyExists) continue;

        if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), nextTrajet->GetDepart())) {
            cheminCourant.Ajouter(nextTrajet);
            RechercheBruteForce(VilleA, VilleB, cheminCourant, tailleChemin + 1, found);
            if (found) {
                break;
            } else {
                cheminCourant.Supprimer(tailleChemin - 1);
            }
        }
    }
    return;
}


void Catalogue::UneCombinaison(Trajet* startTrajet, const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant){
    

    bool found = false; // Indicateur de chemin trouvé

    for(int i = 0; i < cheminCourant.GetNbTrajetsCourant(); i++)
    {
        cheminCourant.Modif(i, nullptr);
    }
    cheminCourant.SetNbTrajetsCourant(0);

    cheminCourant.Ajouter(startTrajet);
    RechercheBruteForce(VilleA, VilleB, cheminCourant, 1, found);

    return;
}


void Catalogue::RechercheAvancee(const char* VilleA, const char* VilleB) {

    const int MAX_PATH_LENGTH = 3; // Longueur maximale du chemin (réalloué si nécessaire)
    bool found = false; // Indicateur d'existance d'un chemin

    int nbrt = this->tabDynamique.GetNbTrajetsCourant(); // Réinitialisation du tableau dynamique
    if(nbrt == 0)
    {
        cout << "Le catalogue est vide." << endl << endl;
        return;
    }
    
    cout << endl << "Recherche avancee en cours..." << endl << endl;

    // Parcours tous les trajets pour stocker les trajets de départ
    TableauDynamique Departs(nbrt);
    int departsCount = 0;

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
        Trajet* startTrajet = tabDynamique.GetTrajet(i);
        
        if(!strcmp(startTrajet->GetDepart(), VilleA)) {
            // Retrait des doublons
            bool alreadyExists = false;
            for (int j = 0; j < departsCount; j++) {
                if (!strcmp(startTrajet->GetDepart(), Departs.GetTrajet(j)->GetDepart()) && !strcmp(startTrajet->GetArrivee(), Departs.GetTrajet(j)->GetArrivee())) {
                    alreadyExists = true;
                    break;
                }
            }
            TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(startTrajet);
            if (!alreadyExists) {
                if(strcmp(startTrajet->GetArrivee(), VilleB) == 0) {
                    cout << endl << "Un trajet direct correspondant a votre recherche est :" << endl;
                    startTrajet->Afficher();
                    found = true;
                } else if(trajetCompose){
                    TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
                    if (ts != nullptr) {
                        cout << endl <<"Un trajet direct correspond à votre recherche est :" << endl;
                        ts->Afficher();
                        found = true;
                    }
                } else {
                    Departs.Ajouter(startTrajet);
                    departsCount++;
                }
            }
        }
    }

    // Parcours tous les trajets de départ pour trouver les chemins possibles
    TableauDynamique cheminCourant = TableauDynamique(MAX_PATH_LENGTH); // Tableau pour stocker le chemin actuel

    for(int j=0; j<departsCount; j++){
        Trajet* startTrajet = Departs.GetTrajet(j);
        UneCombinaison(startTrajet, VilleA, VilleB, cheminCourant);
        if (cheminCourant.GetNbTrajetsCourant()!=1) {
            cout << endl << "Un ensemble de trajets correspondant à votre recherche est :" << endl;
            for(int i=0; i<cheminCourant.GetNbTrajetsCourant(); i++){
                cout << "Trajet numero " << i+1 << " : ";
                cheminCourant.GetTrajet(i)->Afficher();
                cout << endl;
                found = true;
            }
        }
    }


    if(found) cout << endl << "Fin de la recherche avancee" << endl << endl;
    else cout << endl << "Aucun chemin trouve dans le Catalogue de " << VilleA << " a " << VilleB << "." << endl << endl;
    
    return ;
}

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif


} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

