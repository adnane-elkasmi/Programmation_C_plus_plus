#include <iostream>

using namespace std;

void exo1();
void exo2();
void exo3(int);
void exo4();
void exo5();
void exo6(int);
void exo7(int);
bool exo8(int);

int main()
{
    exo1();

    // exo2();

    // exo3(10000);

    // exo4();

    // exo5();

    // exo6(6);

    // exo7(4);

    // exo8(10);

    // exo9(5,5);
    // exo9(5);

    // exo10(6,2);
    // exo10(3);

    cout << endl;
    cout << "fin du programme" << endl;
    return 1;
}

/*
 * Exercice 1 :
 * Ecrire une fonction max qui prend deux entiers en entree
 * et renvoie le plus grand d'entre eux
 * Tester cette fonction
 */
void exo1() {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 1  //////" << endl;
    cout << "///////////////////////////" << endl;
}

/*
 * Exerice 2 :
 * Ecrire de quatre manieres differentes une boucle for
 * qui envoie dans le terminal les nombres pairs
 * compris entre 1 et 15
 * Faites la meme chose avec une boucle while (une seule)
 */
void exo2() {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 2  //////" << endl;
    cout << "///////////////////////////" << endl;
}


/*
 * Exerice 3 :
 * On se donne un entier S representant un nombre de secondes
 * Ecrire dans le terminal la duree de S secondes sous le format
 * heures : minutes : secondes
 * (avec 0 <= minutes < 60 et 0 <= secondes < 60)
 * Tester avec plusieurs durees differentes
 */
void exo3(int S) {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 3  //////" << endl;
    cout << "///////////////////////////" << endl;
}

/*
 * Exerice 4 :
 * Demander a l'utilisateur d'entrer cinq entiers a partir du terminal,
 * puis afficher leur moyenne
 */
void exo4() {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 4  //////" << endl;
    cout << "///////////////////////////" << endl;
}


/*
 * Exerice 5 :
 * Demander a l'utilisateur d'entrer un entier N a partir du terminal,
 * puis demander a l'utilisateur d'entrer N entiers a partir du terminal,
 * puis afficher la somme de ces N entiers
 * Ne pas oublier de verifier que N doit etre compris entre 1 et 20,
 * sinon : demander a l'utilisateur de recommencer
 */
void exo5() {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 5  //////" << endl;
    cout << "///////////////////////////" << endl;
}

/*
 * Exerice 6 :
 * Prend un entier n en entree
 * Afficher le ennieme nombre de la suite de Fibonacci
 * Tester avec plusieurs n
 */
void exo6(int n) {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 6  //////" << endl;
    cout << "///////////////////////////" << endl;
}

/*
 * Exercice 7 :
 * Prend un entier n en entree
 * Afficher dans le terminal les n premieres lignes du triangle de Pascal
 * (le triangle etant symetrique, on peut (si on veut) se contenter d'afficher sa moitie droite)
 */
void exo7(int n) {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 7  //////" << endl;
    cout << "///////////////////////////" << endl;
}


/*
 * Exercice 8 :
 * Ecrire une fonction qui prend un entier en entree et renvoie true si cet entier est premier, false s'il ne l'est pas
 * Tester avec plusieurs valeurs
 */
bool exo8(int n) {
    cout << endl;
    cout << "///////////////////////////" << endl;
    cout << "///////  EXERCICE 8  //////" << endl;
    cout << "///////////////////////////" << endl;
    return true;
}


/*
 * Exercice 9 :
 * Ecrire une fonction qui prend deux double en entree (a et b) et qui renvoie l'aire du rectangle (a*b)
 * Si on ne fournit qu'un seul parametre a, cette fonction renvoie l'aire du carre de cote a (a*a)
 * (on utilisera la surcharge de fonction)
 */


/*
 * Exercice 10 :
 * Un eleveur a des poules et des lapins
 * Ecrire une fonction qui prend en entree le nombre de poules et le nombre de lapins
 * et renvoie le nombre de pattes qu'il a dans son elevage
 * Si on ne donne qu'un argument a la fonction, alors c'est que l'eleveur n'a que des poules
 * (pensez aux arguments par defaut)
 */
