#include <iostream>
#include <assert.h>
#include <vector> // pour vector
#include <deque>  // pour deque
#include <stack>
#include <set>
#include <map> // pour map
#include <queue> // pour priority_queue
#include <algorithm>
using namespace std;

void conteneurs();
void iterateurs();
void autres();
void algos();

int main()
{

    conteneurs();

    iterateurs();

    autres();

    algos();

    return 0;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void conteneurs() {
    /*
     * On liste ici les principaux conteneurs de la STL
     */

    cout << "**********************" << endl;
    cout << "***** CONTENEURS *****" << endl;
    cout << "**********************" << endl;

    {
	/*
	 * vector
	 */

	cout << "// vector : tableau de taille dynamique :" << endl;
	vector<int> vec; // ici le template indique qu'on va remplir vec avec des int
	vec.push_back(5); // ajoute un element (5) a la fin
	vec.push_back(8);
	vec.push_back(1);

	cout << "vec = ";
	for(int i=0; i<vec.size(); i++)
	    cout << vec[i] << " ";
	cout << endl << "vec.size() = " << vec.size() << endl << endl;

	vec.pop_back(); // retire le dernier element
	vec.pop_back();
	vec.push_back(15);
	cout << "vec = ";
	for(int i=0; i<vec.size(); i++)
	    cout << vec[i] << " ";
	cout << endl << "vec.size() = " << vec.size() << endl << endl;

        // size() : nombre d'elements presents dans la liste
        // capacity() : nombre d'elements pour lesquels la memoire est allouee
        cout << "vec.size() = " << vec.size() << endl;
        cout << "vec.capacity() = " << vec.capacity() << endl << endl;

	// resize() : change la taille du vecteur :
        // cree des elements en utilisant le constructeur par defaut (s'il faut en ajouter)
        // ou detruit les elements de la fin du vecteur (s'il faut en retirer)
        // reserve() : alloue l'espace memoire pour le nombre d'elements demandes :
	// pour diminuer le nombre d'operations de reallocation de memoire (couteuses)
	vec.resize(10);
        vec.reserve(30);

        cout << "vec.size() = " << vec.size() << endl;
        cout << "vec.capacity() = " << vec.capacity() << endl;
        cout << "vec = ";
	for(int i=0; i<vec.size(); i++)
	    cout << vec[i] << " ";
        cout << endl << endl;
    }

    {
	/*
	 * deque (Double Ended QUEue)
	 */
	// memes operations que pour vector
	cout << "// deque : tableau de taille dynamique a double entree :" << endl;
	deque<int> dq;
	dq.push_back(5); // ajoute un element (5) a la fin
	dq.push_back(8);
	dq.push_back(1);

	cout << "dq = ";
	for(int i=0; i<dq.size(); i++)
	    cout << dq[i] << " ";
	cout << endl << "dq.size() = " << dq.size() << endl << endl;

	dq.pop_back(); // retire le dernier element
	dq.pop_back();
	dq.push_back(15);
	cout << "dq = ";
	for(int i=0; i<dq.size(); i++)
	    cout << dq[i] << " ";
	cout << endl << "dq.size() = " << dq.size() << endl << endl;


	// resize() : change la taille du vecteur
        // reserve n'est pas disponible
	dq.resize(10);
	for(int i=0; i<dq.size(); i++)
	    cout << dq[i] << " ";
	cout << endl << "dq.size() = " << dq.size() << endl << endl;


	// la principale difference est qu'on peut aussi enlever / ajouter des elements en premiere position
	dq.pop_front();   // enleve un element au debut
	dq.pop_front();
	dq.push_front(3); // ajoute 3 au debut

	for(int i=0; i<dq.size(); i++)
	    cout << dq[i] << " ";
	cout << endl << "dq.size() = " << dq.size() << endl << endl;
    }


    {
	/*
	 * stack (pile) : une version simplifiee de vector avec moins d'operations
	 */
	// on peut empiler, depiler et lire la valeur sur la pile
	cout << "// stack : pile :" << endl;
	stack<int> pile;
	pile.push(1);
	pile.push(5);
	pile.pop();

	cout << "la pile a " << pile.size() << " element(s), celui du dessus est : " << pile.top() << endl << endl;
    }

    {
        /*
         * pair : une paire d'objets
         * le premier objet est stocke dans first
         * le second dans second
         * notons que ces objets peuvent etre des types de base mais aussi des classes
         */
        cout << "// pair :" << endl;
        pair<int,double> paire(1,2.3);
        cout << "paire = (" << paire.first << "," << paire.second << ")" << endl;
        cout << endl;
    }

    {
        /*
         * map : conteneur qui stocke des paires : valeur cle et valeur renvoyee
         * les valeurs cle sont utilisees pour identifier de maniere unique chaque element
         * les elements sont tries par ordre des cles
         */

        // on peut s'en servir comme d'un tableau avec seulement certains indices alloues
        cout << "// map " << endl;
        map<int,int> intMap;
        intMap[0] = -1;
        intMap[4] = 6;
        intMap[4] = 2; // notons qu'une seule valeur est enregistree par cle
                       // cette instruction modifie donc la valeur associee a 4

        for(pair<int,int> paire : intMap)
            cout << paire.first << " -> " << paire.second << endl;

        // on peut aussi utiliser d'autres types pour la "cle"
        map<string,string> verlan;
        verlan["fou"] = "ouf";
        verlan["bete"] = "teube";
        verlan["chien"] = "iench";
        verlan["fete"] = "teuf";
        verlan["bloque"] = "keblo";

        for(pair<string,string> paire : verlan)
            cout << paire.first << " -> " << paire.second << endl;

        // notons au passage que la map est triee par ordre des cles (ordre alphabetique pour les string)
        cout << endl;
    }
}



////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


void iterateurs() {
    /*
     * On presente ici les iterateurs
     */

    cout << "**********************" << endl;
    cout << "***** ITERATEURS *****" << endl;
    cout << "**********************" << endl;


    // les iterateurs sont equivalents a des pointeurs :
    // ils pointent vers des objets dans les conteneurs de la STL
    // on peut s'en servir pour parcourir les conteneurs de maniere efficace
    vector<int> v(3,10); // v est initialise avec 3 entiers (valeur 10)
    cout << "v = ";
    // apres for :
    // it est un iterator
    // v.begin() : renvoie un iterator sur le debut du vecteur
    // v.end()   : renvoie un iterator sur la fin du vecteur
    // ++it      : passe a l'element suivant  (idem it++)
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
	cout << *it << " "; // comme pour un pointeur *it permet d'acceder a la valeur associee a it
    }
    cout << endl;

    // on peut simplifier la boucle for en utilisant auto
    v.push_back(5);
    cout << "v = ";
    for(auto it = v.begin(); it != v.end(); ++it)
    {
	cout << *it << " ";
    }
    cout << endl;

    // En pratique c'est de cette facon qu'il est conseille de se deplacer dans les conteneurs
    // on peut aussi utiliser des iterateurs pour parcourir la liste en sens inverse
    cout << "v reverse = ";
    for(auto it = v.rbegin(); it != v.rend(); ++it)
	cout << *it << " ";
    cout << endl;

    // ca marche pareil pour les autres conteneurs
    deque<int> dq(3,10);
    cout << "dq = ";
    for(auto it = dq.begin(); it != dq.end(); it++)
	cout << *it << " ";
    cout << endl;

    // une autre possibilite pour parcourir les conteneurs est d'utiliser une range-based for loop
    cout << "v = ";
    for(auto el : v)
	cout << el << " ";
    cout << endl;
    // ceci marche aussi pour les autres conteneurs
    // par contre c'est moins flexible que les iterateurs : ici on parcourt forcement tout le conteneur

    cout << endl << "// ajout / suppression d'elements : " << endl;
    // on peut utiliser insert() pour ajouter des elements a une position donnee
    v.insert(v.begin() , 2); // ajoute 2 au debut du vector
    v.insert(v.begin() + 3, 2,4); // ajoute deux fois 4 en position 3 du vecteur

    cout << "insert : v = ";
    for(auto el : v)
	cout << el << " ";
    cout << endl;

    // on peut aussi utiliser insert pour inserer un autre tableau :
    int array[] = {4,6,8,18};
    v.insert(v.begin()+2, array, array+4); // insert array en pos 2

    cout << "insertion de array : v = ";
    for(auto el : v)
	cout << el << " ";
    cout << endl;


    // on peut utiliser erase pour supprimer des elements du vecteur
    v.erase(v.begin()+4); // supprime l'element 4

    cout << "erase 4e element : v = ";
    for(auto el : v)
	cout << el << " ";
    cout << endl;

    v.erase(v.begin()+1, v.begin()+3); // supprime les elements en pos de 1 a 2
    cout << "erase elements de 1 a 2 : v = ";
    for(auto el : v)
	cout << el << " ";
    cout << endl;

    cout << endl;
}

/*
 * Notons que la plupart des conteneurs que nous avons vus peuvent etre utilises de maniere similaire
 * Notamment, on peut utiliser des iterateurs sur tous
 * Ceci est une forme d'abstraction : l'utilisateur n'a pas a se soucis du fonctionnement exact
 * de ces conteneurs pour pouvoir les utiliser
 * En fait, il ne faut vraiment les connaitre que si on cherche a optimiser les performances d'un programme
 */


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void autres() {
    /*
     * On donne ici des conteneurs supplementaires
     */

    cout << "**********************" << endl;
    cout << "******* AUTRES *******" << endl;
    cout << "**********************" << endl;

    {
    	/*
    	 * set
    	 */
    	cout << "// set : ensemble (elements uniques) :" << endl;
    	set<int> ens; // ici il n'y a pas de debut et de fin
    	ens.insert(5);
    	ens.insert(8);
    	ens.insert(1);

    	cout << "ens = ";
	for(auto it = ens.begin(); it != ens.end(); it++)
	    cout << *it << " ";
    	cout << endl << "ens.size() = " << ens.size() << endl;
	cout << "notons que les elements sont tries par ordre de grandeur" << endl << endl;

        cout << "Ici aussi on peut utiliser une range-based for loop :" << endl;
        for(auto el : ens)
            cout << el << " ";
        cout << endl << endl;
    }

    {
        /*
         * priority_queue
         */
        cout << "// priority_queue : file d'attente avec ordre de priorite :" << endl;
        priority_queue <int> PQ; // definit une PQ composee d'entiers
        // on ajoute maintenant des elements
        PQ.push(1); // ajoute 1 a la file
        PQ.push(10);
        PQ.push(-4);
        PQ.push(1);

        // attention : on ne peut pas utiliser d'iterator ni de range-based for loop sur une PQ
        // le seul element auquel on peut acceder est l'element de plus haute priorite
        // on peut aussi eliminer l'element de plus haute priorite pour acceder au suivant

        cout << "PQ = ";
        while(!PQ.empty()) // PQ.empty() renvoie true quand la PQ est vide
        {
            cout << PQ.top() << " "; // PQ.top() renvoie l'element de plus haute priorite
            PQ.pop(); // PQ.pop() retire l'element de plus haute priorite
        }
        cout << endl;
        // on remarque que les elements sont affiches du plus grand au plus petit
        // on remarque aussi qu'un element peut etre present plusieurs fois (ici 1)
        // par contre maintenant la PQ est vide

        // Notons enfin qu'une PQ peut prendre d'autres types que int, notamment tout type
        // ou classe qui a une relation d'ordre et cette relation d'ordre sert a
        // classer le grand comme plus prioritaire

        cout << endl;
    }
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

class Interval {
    double a,b;

public:
    Interval(int a, int b) : a(a), b(b) {}
    bool operator<(Interval interval) {
        return (a < interval.a);
    }
    friend ostream& operator<<(ostream& os, const Interval& interval);
};

ostream& operator<<(ostream& os, const Interval& interval) {
    os << "(" << interval.a << "," << interval.b << ")";
    return os;
}

void divide(int& a) {
    a = a/2;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

/*
 * Algorithmes
 */
void algos() {
    /*
     * On donne ici des algorithmes deja codes dans la STL
     */

    cout << "**********************" << endl;
    cout << "***  ALGORITHMES  ****" << endl;
    cout << "**********************" << endl;

    /*
     * Algos de tri
     */
    {
        cout << "// tri d'un array :" << endl;
        // array de int
        int array[] = {5,3,4,9,7,0,2,1,15};
        int n = sizeof(array) / sizeof(int);

        cout << "array avant sort : ";
        for(int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;
        sort(array, array+n);
        cout << "array apres sort : ";
        for(int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;

        // on peut aussi trier par ordre decroissant en ajoutant un argument supplementaire :
        sort(array, array+n, greater<int>());
        cout << "array apres sort en decroissant : ";
        for(int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;

        // on peut aussi choisir de ne trier qu'une partie du vecteur :
        sort(array+2, array+n-1);
        cout << "array apres sort sur le milieu du vecteur : ";
        for(int i=0; i<n; i++)
            cout << array[i] << " ";
        cout << endl;
        cout << endl;
    }

    {
        // ceci peut aussi etre applique a d'autres conteneurs (en utilisant les iterateurs) :
        cout << "// tri d'un vector de double :" << endl;
        vector<double> vect;
        vect.push_back(3.2);
        vect.push_back(-4.1);
        vect.push_back(8.3);
        vect.push_back(-1.2);
        vect.push_back(0.5);

        cout << "vector avant le tri : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;
        sort(vect.begin(), vect.end());
        cout << "vector apres le tri : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl << endl;
    }

    {
        // on peut aussi appliquer cela a des conteneurs ayant des types autres que les types fondamentaux
        cout << "// tri d'un vector d'intervalles :" << endl;
        vector<Interval> vect;
        vect.push_back( Interval(1,5) );
        vect.push_back( Interval(2,3) );
        vect.push_back( Interval(-1,5) );
        vect.push_back( Interval(0,2) );
        vect.push_back( Interval(1,3) );

        cout << "vector avant le tri : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;
        sort(vect.begin(), vect.end());
        cout << "vector apres le tri : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl << endl;
    }

    /*
     * Remarque : les algos de tri utilises ne sont pas l'algo glouton que vous coderiez
     * intuitivement : ces algos sont beaucoup plus efficaces
     * En bref : si vous voulez trier une liste, utilisez les algos de la STL
     * sauf si vous etes en train de developper un nouvel algo de tri et que vous voulez le coder
     * vous-meme (mais attention les algos de la STL sont deja tres efficaces)
     */


    /*
     * Algos de recherche
     */

    {
        cout << "// recherche d'un nombre dans un vector d'int :" << endl;
        vector<int> vect;
        vect.push_back(2);
        vect.push_back(8);
        vect.push_back(-5);
        vect.push_back(-7);
        vect.push_back(64);
        vect.push_back(1);
        vect.push_back(-1);
        vect.push_back(8);

        // nombre recherche :
        int a = 8; // essayer d'autres valeurs ...

        cout << "vector : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;
        cout << "on cherche le nombre : " << a << endl;

        // retourne un iterateur sur la (premiere) position contenant le nombre cherche
        // si le nombre n'a pas ete trouve, alors obtient un iterateur sur end()
        auto it = find(vect.begin(), vect.end(), a);

        if(it == vect.end())
            cout << "nombre non trouve" << endl;
        else
            cout << "Le nombre a ete trouve en position " << it - vect.begin() << endl;

        cout << endl;
    }
    /*
     * Remarque : A nouveau, on peut utiliser cet algorithme sur
     * d'autres conteneurs et d'autres types.
     * On peut aussi chercher sur une partie du vecteur seulement.
     */

    {
        cout << "// recherche dans un vector deja trie :" << endl;

        // des algorithmes de recherche beaucoup plus efficaces existent quand le conteneur
        // est deja trie

        vector<int> vect;
        vect.push_back(2);
        vect.push_back(8);
        vect.push_back(-5);
        vect.push_back(-7);
        vect.push_back(64);
        vect.push_back(8);
        vect.push_back(1);
        vect.push_back(-1);
        vect.push_back(8);

        int a = 8;

        cout << "vector : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;
        cout << "on cherche : a = " << a << endl;

        auto low = lower_bound(vect.begin(), vect.end(), a);
        auto up = upper_bound(vect.begin(), vect.end(), a);

        cout << "si la liste n'est pas triee, alors l'algorithme va s'arreter des qu'il sera entre un nombre plus grand que a et un nombre plus petit que a : " << endl;
        cout << "la premiere occurence est en position : " << low - vect.begin() << endl;
        cout << "la derniere occurence est en position : " << up - vect.begin()-1 << endl << endl;

        cout << "maintenant, trions la liste : " << endl;
        sort(vect.begin(), vect.end());
        cout << "vector : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;

        low = lower_bound(vect.begin(), vect.end(), a);
        up = upper_bound(vect.begin(), vect.end(), a);

        cout << "si la liste est triee, alors l'algorithme fonctionne : " << endl;
        cout << "la premiere occurence est en position : " << low - vect.begin() << endl;
        cout << "la derniere occurence est en position : " << up - vect.begin()-1 << endl << endl;

        if(up == low) cout << "en fait ce nombre n'est pas dans le vector" << endl;
    }
    /*
     * Notons tout de meme que trier la liste prend plus de temps que de chercher un nombre
     * dans une liste non triee.
     * L'idee est donc d'utiliser find() sur une liste non triee
     * et d'utiliser lower_bound() et upper_bound() sur une liste triee
     */

    {
        /*
         * Utilisation de for_each
         */

        cout << "// for_each : " << endl;
        int N = 10;
        vector<int> vect;
        vect.resize(N); // cree N objets vides

        for(int i=0; i<N; i++)
            vect[i] = i;

        // affichage
        cout << "vector : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;

        // application de divide a chaque element du vector
        // cette ligne execute divide N fois avec a chaque fois le ieme element de vect en argument
        for_each(vect.begin(), vect.end(), divide);

        // affichage
        cout << "vector apres for_each : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;

        // de maniere similaire, on peut ecrire
        for( auto& el : vect )
            el = el * 2;

        // affichage
        cout << "vector apres boucle : ";
        for(auto it = vect.begin(); it != vect.end(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << endl;
}
