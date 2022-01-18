#include <iostream>
#include <assert.h>
// using namespace std;
using std::cout;
using std::endl;

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
 * Ecrire une fonction qui calcule la valeur absolue d'un int ou d'un double
 * Utiliser un template sur le type (int ou double)
 * Tester cette fonction sur un int et sur un double
 */
void exo1() {
    cout << "********************" << endl;
    cout << "**** EXERCICE 1 ****" << endl;
    cout << "********************" << endl;

    cout << endl;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////

/*
 * Exercice 2 :
 * Reprendre la classe Smart_tab du cours
 * Ajouter un operateur de copie adapte ainsi que des operateurs + et -
 * Ecrire au moins un operateur a l'interieur de la classe et au moins un a l'exterieur
 * Faire des tests
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
 * Ecrire une classe de tableau avec allocation statique de memoire
 * Ce tableau contiendra des coefficients de type double
 * Un template portera sur la taille du tableau
 * On pourra ajouter des assert dans la classe pour eviter les operations illicites
 */
void exo3() {
    cout << "********************" << endl;
    cout << "**** EXERCICE 3 ****" << endl;
    cout << "********************" << endl;

    cout << endl;
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
/*
 * Exercice 4 :
 * La probabilite de pluie sur les N jours a venir est stockee dans un tableau de double de taille N
 * Pour chaque jour, cette probabilite doit avoir une valeur comprise entre 0 et 1
 * Cependant, ces probabilites ont ete calculees numeriquement, il y a donc une erreur machine d'au plus 1.e-6
 * Les coefficients peuvent donc avoir des valeurs entre -1.-6 et 1+1.e-6
 * Reprendre la classe de l'exercice 3 et la modifier de maniere a stocker ces probabilites
 * Il faudra egalement modifier l'acces aux coefficients de maniere a ce que la valeur stockee
 * est renvoyee si elle est entre 0 et 1.
 * Si la valeur stockee est entre 0 et -1e-6, on renvoie 0
 * Si la valeur stockee est entre 1 et 1+1.e-6, on renvoie 1
 * Sinon une erreur est signalee a l'utilisateur
 */

// Si vous avez fini ces quatre exercices, vous pouvez commencer le TP sur la STL
