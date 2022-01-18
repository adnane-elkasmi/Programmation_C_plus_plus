#include <iostream>

// fonction "sayHello"
// void signifie que cette fonction ne retourne pas de variable
// la parenthese vide signifie que cette fonction ne prend pas d'argument
// quand on appelle la fonction, le bloc de code entre accolades s'execute
void sayHello()
{
    // on ecrit "Hello !!" dans le terminal
    std::cout << "Hello !!" << std::endl;
}

// fonction "carre" : renvoie le carre d'un entier
// le premier "int" signifie que cette fonction renvoie un entier
// le "int a" entre parentheses signifie que cette fonction prend un entier en variable d'entree
// cette variable d'entree est stockee dans l'entier "a"
int carre(int a)
{
    // on calcule le carre de a
    int a2 = a * a;

    // on renvoie cette valeur en sortie de la fonction
    return a2;
}


// Si pour des raisons de clarte (ou autre) on ne veut pas definir la fonction f
// avant de l'utiliser, alors on peut se contenter d'ecrire au debut du fichier son prototype
double f(double a, double b);
double f(double a);

// quand on execute le programme la fonction "main" est appelee
int main()
{
    // on appelle la fonction sayHello
    sayHello();

    int a, a2;

    // on recupere un nombre entier a partir du terminal
    std::cout << "donner un nombre entier:" << std::endl;
    std::cin >> a;

    // on appelle la fonction carre, on stocke le resultat dans a2
    a2 = carre(a);

    std::cout << "le carre de " << a << " vaut " << a2 << std::endl;

    std::cout << "f(1.5,2.) = " << f(1.5,2.) << std::endl;
    std::cout << "f(1) = " << f(1) << std::endl;
    
    return 0;
}

// le corps de la fonction f doit ensuite etre defini
// fonction f : 2*a+b
double f(double a, double b)
{
    return 2*a + b;
}

// On peut surcharger une fonction :
// on peut definir une fonction avec le meme nom mais des arguments differents
double f(double a)
{
    return a;
}
// ici f(1,2) fera appel a la premiere fonction et f(1) a la deuxieme

// On peut egalement definir des arguments par defaut :
double D(double a, double b = 1)
{
    return a+b;
}
// ici D(1,2) fera appel a D avec a=1 et b=2 et D(3) fera appel a D avec a=3 et b=1
// (on a donne au deuxieme argument une valeur par defaut)


// On peut definir une fonction recursive (qui s'appelle elle-meme)
// l'exemple classique est la fonction factorielle
int Factorielle(int n) {
    // la factorielle de 0 ou 1 vaut 1
    if (n == 0 || n == 1)
        return 1;

    // sinon la factorielle de n vaut n*Factorielle(n-1)
    return n * Factorielle(n-1);
}
// Ainsi si on calcule Factorielle(3), on fera
// Factorielle(3) = 3*Factorielle(2)
// Factorielle(3) = 3*2*Factorielle(1)
// Factorielle(3) = 3*2*1 = 6
