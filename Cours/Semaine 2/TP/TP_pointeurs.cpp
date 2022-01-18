#include <iostream>
using namespace std;

void exo1();
void exo2();
void exo3();
void exo4();
void exo5();

int main()
{

    exo1();

    exo2();

    exo3();

    exo4();

    exo5();

    return 0;
}

/*
 * Exercice 1 :
 * Ecrire un programme qui demande a l'utilisateur d'entrer 10 entiers
 * Ces entiers sont stockes dans un tableau de taille 10
 * Le programme renvoie ensuite dans le terminal les entiers strictement superieurs a 5
 */

void exo1() {
    cout << endl;
    cout << "********************" << endl;
    cout << "****   EXO 1   *****" << endl;
    cout << "********************" << endl;

}

/*
 * Exercice 2 :
 * Ecrire un programme qui demande a l'utilisateur d'entrer 10 entiers
 * Ces entiers sont stockes dans un tableau de taille 10
 * L'utilisateur entre ensuite un autre entier
 * Le programme dit si oui ou non cet autre entier est contenu dans le tableau
 * (vous pouvez partir du programme precedent)
 */

void exo2() {
    cout << endl;
    cout << "********************" << endl;
    cout << "****   EXO 2   *****" << endl;
    cout << "********************" << endl;

}

/*
 * Exercice 3 :
 * Ecrire un programme qui demande a l'utilisateur d'entrer 10 entiers
 * Ces entiers sont stockes dans un tableau de taille 10
 * L'utilisateur entre ensuite un autre entier
 * Le programme supprime toutes les occurences de cet entier dans le tableau
 * Les nombres suivants sont ensuite decales vers la gauche, de sorte que les cases 'vides'
 * se trouvent a la fin du tableau.
 * Les cases vides sont ensuite remplies par des zeros
 * (vous pouvez partir du programme precedent)
 */

void exo3() {
    cout << endl;
    cout << "********************" << endl;
    cout << "****   EXO 3   *****" << endl;
    cout << "********************" << endl;

}

/*
 * Exercice 4 :
 * Ecrire une fonction qui prend deux entiers a et b en parametres
 * Cette fonction rangera dans a le plus petit d'entre eux et dans b le plus grand
 * (la valeur de ces deux entiers doit etre modifiee a l'exterieur du programme)
 */

void exo4() {
    cout << endl;
    cout << "********************" << endl;
    cout << "****   EXO 4   *****" << endl;
    cout << "********************" << endl;

}

/*
 * Exercice 5 :
 * Ecrire une fonction qui prend en parametres un tableau d'entiers et un entier n compris entre 1 et 20 representant la taille du tableau
 * La fonction renvoie le nombre de valeurs comprises entre 0 et 10 parmi les n premieres entrees du tableau
 */
void exo5() {
    cout << endl;
    cout << "********************" << endl;
    cout << "****   EXO 5   *****" << endl;
    cout << "********************" << endl;

}

/*
 * Exercice 6 :
 * Ecrire une fonction qui prend en parametres un tableau d'entiers, un entier n compris entre 1 et 20 representant la taille du tableau
 * et deux pointeurs vers des entiers p_min et p_max
 * La fonction entrera dans p_min et p_max la valeur minimale et maximale contenue dans le tableau
 */


/*
 * Exercice 7 :
 * Ecrire une fonction qui prend en parametres un tableau de char et un entier n compris entre 1 et 20 representant la taille du tableau
 * La fonction va parcourir le tableau et renvoyer le nombre d'occurences du char 'A'
 * Le parcour du tableau devra se faire a l'aide d'un pointeur
 */


/*
 * Exercice 8 :
 * Ecrire un programme qui gere un tableau d'entiers de maniere dynamique avec l'aide d'un menu 
 * Le programme demandera a l'utilisateur a travers un menu s'il veut
 * 1. afficher le tableau
 * 2. ajouter un entier au tableau
 * 3. retirer un entier du tableau
 * 4. afficher la moyenne des entiers du tableau
 * 5. trier le tableau par ordre croissant
 * 6. mettre fin au programme
 * Lorqu'une action est effectuee, le menu est ensuite repropose a l'utilisateur jusqu'a ce que celui-ci quitte le programme
 * Les entiers seront stockes dans un tableau dynamique
 * La taille de ce tableau sera initialisee a cinq
 * Lorsqu'on atteint la taille maximale et qu'on souhaite ajouter un entier, de la memoire supplementaire sera allouee
 * Pour cela, on allouera un nouveau tableau de taille augmentee de cinq et on recopiera les valeurs de l'ancien tableau
 * il faudra aussi penser a liberer la memoire de l'ancien tableau
 * Un entier sera utilise pour reperer le nombre de cases utilisees
 * Quand on supprimera un entier, tous les entiers suivants seront decales vers la gauche
 * Lorsqu'il y aura au moins dix cases inutilisees dans le tableau on reduira sa taille de dix (en utilisant le meme procede que pour l'aggrandir)
 * Ne pas oublier de liberer la memoire a la fin du programme
 * Au passage, vous avez ici un excellent exemple de l'utilite de l'allocation dynamique de memoire
 * pouvez-vous commenter ?
 */

/*
 * Exercice 9 :
 * Ecrire une fonction qui prend en arguments un tableau de double a double entree, le nombre de lignes, le nombre de colonnes
 * La fonction affiche ensuite dans le terminal cette matrice avec a la fin de chaque ligne la moyenne des valeurs de la ligne,
 * a la fin de chaque colonne, la moyenne des valeurs de la colonne
 * Il faut aussi afficher la moyenne de toutes les valeurs du tableau
 */

/*
 * Exercice 10 :
 * Ecrire une fonction qui prend en entree un tableau de char et sa taille
 * Cette fonction doit remplacer toutes les voyelles minuscules non accentuees du tableau par des points
 */

/*
 * Exercice 11 :
 * Ecrire un programme qui demande a l'utilisateur de taper un mot de moins de 20 char (il est stocke dans un tableau de char)
 * le programme indique ensuite si oui ou non ce mot est un palindrome (mot qui se lie indifferemment dans les deux sens)
 */
