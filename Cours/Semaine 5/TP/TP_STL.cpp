#include <iostream>
#include <time.h> // pour calculer le temps

using namespace std;

void exo1();
void exo2();
void exo3();

int main()
{
    exo1();
    exo2();
    exo3();

    return 0;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

/*
 * Exercice 1 :
 * Comparer l'efficacite de vector, deque et list :
 * On fera les tests suivants :
 * - ajout d'un grand nombre d'elements a la fin
 * - ajout d'un grand nombre d'elements au debut
 * - ajout d'un grand nombre d'elements au milieu
 * - parcours de tous les elements avec une boucle for
 *
 * Dans quelle situation faut-il preferer quel conteneur ?
 * Pour vector, refaire les tests avec reserve()
 */

void exo1() {
    cout << "********************" << endl;
    cout << "**** EXERCICE 1 ****" << endl;
    cout << "********************" << endl;

    clock_t t1,t2;

    t1 = clock();

    t2 = clock();
    cout << "temps ecoule : " << (float)(t2-t1) / CLOCKS_PER_SEC << "s" << endl;

    cout << endl;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

/*
 * Exercice 2 :
 * Construire un vecteur de N entiers (non trie)
 * Rechercher un nombre contenu dans ce vecteur en utilisant find()
 * Trier ce vecteur
 * Rechercher le meme nombre en utilisant find()
 * Rechercher le meme nombre en utilisant lower_bound()
 * A chaque fois verifiez que vous obtenez la bonne position
 * Comparer les temps de chaque methode (prenez N suffisamment grand)
 * Quelle est la methode la plus efficace ?
 */

void exo2() {
    cout << "********************" << endl;
    cout << "**** EXERCICE 2 ****" << endl;
    cout << "********************" << endl;


    cout << endl;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

/*
 * Exercice 3 :
 * Ecrire une classe d'intervalles avec des bornes entieres
 * Construire un set d'intervalles
 * Essayer d'inserer plusieurs fois le meme intervalle dans ce set
 * Verifier que cet intervalle n'est compte qu'une seule fois
 * Verifier qu'a part les doublons aucun intervalle ne manque dans le set
 * Utiliser find pour obtenir un iterateur sur un intervalle du set
 *
 * Vous aurez surement des erreurs de compilation
 * Pour resoudre ces erreurs, vous devrez ajouter des methodes a la classe
 */

void exo3() {
    cout << "********************" << endl;
    cout << "**** EXERCICE 3 ****" << endl;
    cout << "********************" << endl;

    cout << endl;
}
