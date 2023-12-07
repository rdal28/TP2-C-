TP C++ n°2 : Héritage - Polymorphisme


Prérequis : 

Faire un makefile
Utiliser Valgrind pour debugger / perte de mémoire
Comprendre les concepts d'héritage 


On peut enlever les surcharges de copie

Objectif : créer et manipuler un catalogue de trajets

Fonctionnalité 1 : ajouter des trajets
Type du trajet : simple ou composé
Ville A
Ville B
Moyen de transport

tu met un virtuel dans l’ancetre comme ca si il y a afficher dans les enfants il fait le afficher de l’ancetre


Choix d’une structure de donnée pour le catalogue
Liste chaînée ?
Tableau alloué dynamiquement ?

On a choisi un tableau alloué dynamiquement qui contiendra les trajets
=> Si le tableau est rempli, on multiplie par 2 sa capacité

Quelles sont les classes que l’on utilisera ?
Classe ancêtre : Trajet
Classes fils : Trajet simple et composé qui héritent de Trajet
Quelles sont les fonctionnalités ?

Ajouter les trajets dans le catalogue

Etape 1 : on lui demande le type de trajet 
Etape 2 : on lui demande la ville de départ et d’arrivée D et A 
Etape 3 : Si trajet simple : on demande le moyen de transport et c’est fini
	     Si trajet composé : nombre d’escales

Etape 4 : Demander le moyen de transport entre l’escale et le précédent ou l’escale et la destination
Répéter Etape 4 tant que le nombre d’escale n’est pas atteint

Classe Trajet

{
Attribut : 
Départ : char* 50
Arrivée : char* 50
Méthodes : 
Virtual Afficher()
Constructeur => Trajet(départ,arrivée)
Destructeur => ~Trajet()
}

Classe TrajetSimple : Trajet

{
Attribut : 
Moyen de transport : char* 10
Hérite de Départ et Arrivée
Méthodes : 
Afficher()
Constructeur 
Destructeur 
}

Classe TrajetComposé : Trajet
{
Attribut : 
nombre
Méthodes : 
Afficher()
Constructeur 
Destructeur 
}
Classe Catalogue
{
attribut : 
methode : 
insérer 
afficher 
rechercher
}








	





QUESTION IMPORTANTE EST-CE QUE UN TRAJET PEUT ETRE EFFECTUé EN ALLER ET EN RETOUR ?
Genre pour la recherche on dmd arret de depart (A) arret d'arrivée (B) et on print A->B
ou bien on demande juste les deux arrets et on print B->A ou A->B
DMD A RAYAN SI PAS COMPRIS JE REFORMULE IRL 