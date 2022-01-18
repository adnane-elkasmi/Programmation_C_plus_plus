#include <iostream>
#include <assert.h>  // necessaire pour appeler assert(...)
#include <fstream>   // necessaire pour std::ifstream
#include "vector.hpp"
// note : <nom> signifie qu'on cherche les sources dans des repertoires de reference
//        "nom" signifie qu'on cherche les sources dans le repertoire de travail
using namespace std;

void process_mem_usage(double&);

void encapsulation();
void constructeurs();
void constantes();
void autres();
void vector();

int main()
{
    encapsulation();
    constructeurs();
    constantes();
    autres();
    vector();
    return 0;
}


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// Encapsulation

class Interval // represente un intervalle [a,b]
{
public:       // public dit qu'on peut acceder de l'exterieur aux membres qui suivent
    double a; // borne inf
    double b; // borne sup
};

///////////////

class Interval_private // represente un intervalle [a,b]
{
private:      // private dit qu'on ne peut pas acceder de l'exterieur aux membres qui suivent
    double a; // borne inf
    double b; // borne sup
public:
    // les fonctions membres sont appelees 'methodes' de la classe
    void setInterval(double a_, double b_)
    {
        assert( a_ < b_ ); // on verifie que a_ < b_
        a = a_;
        b = b_;
    }
    double get_a() {return a;} // renvoie a (par copie)
    double get_b() {return b;} // renvoie b (par copie)
};

///////////////

// l'encapsulation correspond a l'idee qu'on va separer l'information
// contenue dans la classe du reste du code
// l'idee est de reduire les risques d'erreur (confusions et mauvaise utilisation de la classe)
void encapsulation()
{
    cout << "********************" << endl;
    cout << "** ENCAPSULATION  **" << endl;
    cout << "********************" << endl;

    {
        // on peut construire deux intervalles I1 et I2
        Interval I1, I2;
        I1.a = 0; I1.b = 1;  // I1 = [0,1]
        I2.a = -4; I2.b = 4; // I2 = [-4,4]

        // Ici chaque Interval a son 'a' et son 'b'
        // on ne peut pas appeler 'a', il faut appeler 'I1.a' ou 'I2.a'
        // ceci permet de ne pas confondre le 'a' d'un Interval avec le 'a' d'un autre
        cout << "I1 = [" << I1.a << "," << I1.b << "]" << endl;
        cout << "I2 = [" << I2.a << "," << I2.b << "]" << endl;
    }

    {
        // Une couche supplementaire d'encapsulation revient a 'proteger' les donnees de la classe
        // une des raisons est qu'on veut garantir que la classe soit dans un etat coherent
        // par exemple, on voudrait etre sur que a < b
        // pour cela, a, b vont devenir private (pour interdire leur acces depuis l'exterieur)
        // on va aussi ajouter des methodes pour lire ou ecrire dans ces variables
        // quand on ecrira, on pourra verifier que l'etat reste coherent
        Interval_private I1;
        // la commande suivante ne compile pas par ce que a et b sont private
        // I1.a = 0; I1.b = 1;

        // pour changer la valeur de a et b, il faut utiliser 'setInterval'
        I1.setInterval(0,1);

        // au passage, la commande suivante ne s'execute pas (grace au test assert)
        // I1.setInterval(1,0);
        // ceci permet de verifier que lorsqu'on modifie l'etat de la classe, on le garade coherent

        // pour renvoyer les valeurs de a et b, on utilise get_a et get_b
        cout << "I1 = [" << I1.get_a() << "," << I1.get_b() << "]" << endl;
    }

    
    
    cout << endl;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// Constructeurs / Destructeurs

class Interval_cons // represente un intervalle [a,b]
{
private:      // private dit qu'on ne peut pas acceder de l'exterieur aux membres qui suivent
    double a; // borne inf
    double b; // borne sup
public:
    // les fonctions membres sont appelees 'methodes' de la classe
    void setInterval(double a_, double b_)
    {
        assert( a_ < b_ ); // on verifie que a_ < b_
        a = a_;
        b = b_;
    }
    double get_a() {return a;} // renvoie a (par copie)
    // la declaration suivante specifie que cette methode est constante
    // double get_a() const {return a;} // renvoie a (par copie)
    double get_b() {return b;} // renvoie b (par copie)
    // constructeur : initialise a et b
    // cette fonction a le meme nom que la classe et ne renvoie pas de type
    // si aucun constructeur n'est code
    // alors un constructeur sans argument est automatiquement genere
    Interval_cons(double a_, double b_) : a(a_) , b(b_) {
        assert(a_ < b_);
        cout << "constructeur appele" << endl;
    }
    // constructeur par copie : meme fonctionnement mais travaille a partir
    // d'une autre instance de la classe (et recopie son etat)
    // si aucun constructeur par copie n'est code alors un est genere automatiquement
    Interval_cons(const Interval_cons &I) : a(I.a), b(I.b) {
        cout << "constructeur par copie" << endl;
    }
    // destructeur de la classe : appele quand la variable est eliminee
    ~Interval_cons() {cout << "destructeur appele" << endl;}
};

///////////////

void constructeurs()
{
    cout << "********************" << endl;
    cout << "** CONSTRUCTEURS ***" << endl;
    cout << "********************" << endl;

    // constructeur et destructeur
    {
        // dans la partie precedente I1 n'est pas dans un etat coherent apres Interval_private I1;
        Interval_private I1;
        cout << "I1 = [" << I1.get_a() << "," << I1.get_b() << "]" << endl;
        // une maniere de pouvoir initialiser correctement les membres de la classe est de coder
        // un constructeur :
        // il s'agit d'une fonction qui sera appelee lors de l'instanciation de la classe
        // cette fonction sert principalement a initialiser les membres de la classe

        // cette commande ne compile pas car maintenant il faut fournir a et b
        // Interval_cons I2;

        // cette commande ne s'execute pas (grace au assert)
        // Interval_cons I3(1,0);

        // cette commande genere un intervalle dans un etat coherent
        Interval_cons I4(0,1);
        cout << "I4 = [" << I4.get_a() << "," << I4.get_b() << "]" << endl;

        // lorsqu'une variable est detruite : le destructeur de la classe est appele
        // son utilisation est critique dans certains cas precis
        // (en particulier quand de la memoire est allouee)
    }

    // autres constructeurs
    {
        // Si on veut permettre l'utilisation de la commande suivante,
        // alors il faut coder un autre constructeur
        // Interval_cons I1;
    }
    // on appelle "constructeur par defaut" un constructeur qui ne prend pas d'argument
    // notons qu'un constructeur par defaut est genere automatiquement lorqu'aucun
    // constructeur n'est code (c'est le cas pour les classes Interval et Interval_private)

    // constructeur par copie
    {
        // par defaut, ce constructeur va copier tous les membres de la classe
        // si ce comportement n'est pas celui que l'on veut, alors il faut le reecrire
        Interval_cons I4(0,1);
        Interval_cons I5 = I4;
        cout << "I5 = [" << I5.get_a() << "," << I5.get_b() << "]" << endl;
        // on peut aussi utiliser
        Interval_cons I6(I4);
    }

    // plusieurs manieres d'appeler le constructeur
    {
        // constructeur appele mais pas le constructeur par copie
        Interval_cons I = Interval_cons(0,1);
        // C'est equivalent a
        // Interval_cons I(0,1);
    }
    
    cout << endl;
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// instances constantes / methodes constantes

/*
  Une instance constante d'une classe est une instance dont l'etat ne change pas 
  au cours de l'execution du code
  Une telle instance peut faire appel (uniquement) aux methodes constantes de la classe 
 */
void constantes()
{
    cout << "********************" << endl;
    cout << "**** CONSTANTES ****" << endl;
    cout << "********************" << endl;

    {
        // on genere une instance constante de Interval_cons
        // on ne pourra pas modifier son etat dans la suite du code
        const Interval_cons Ic(-4,4);

        // la commande suivante ne compile pas car non constante
        // Ic.setInterval(1,0);

        // on pourra utiliser la commande suivante une fois que get_a et get_b
        // seront des methodes constantes
        // cout << "Ic = [" << Ic.get_a() << "," << Ic.get_b() << "]" << endl;
    }

    cout << endl;
}

/*
  Declarer une methode constante permet :
  - de s'assurer que la methode ne modifie pas la classe
  - d'indiquer au compilateur que la methode est constante (pour optimiser le code)
  - d'indiquer a l'utilisateur que la methode est constante (pour une meilleur comprehension)
  - a la methode d'etre utilisee par les instances constantes de la classe
 */
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// autres

// un struct fonctionne exactement comme une classe
// seule difference : si les droits d'acces ne sont pas specifies
// ils sont public dans struct et private dans class
struct Complex {
    double a, b;
    friend ostream& operator<<(ostream& os, const Complex& c);
};

// une fonction friend est une fonction qui a acces a tous les membres de la classe
// (y compris private)
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.a << " + " << c.b << "i ";
    return os;
}


struct CI {
    Interval_cons I;
    CI() : I(0,1) {} // I ne possede pas de constructeur par defaut
                     // il faut donc preciser comment on l'initialise
};

void autres() {
    cout << "********************" << endl;
    cout << "****** DIVERS ******" << endl;
    cout << "********************" << endl;

    /*
     * Pointeur sur une instance de classe
     */
    {
        // on accede aux membres et methodes d'une instance avec un point (.)
        Interval I1;
        I1.a = 0; I1.b = 1;  // I1 = [0,1]
        cout << "I1 = [" << I1.a << "," << I1.b << "]" << endl;

        // si l'on considere un pointeur sur I1, on peut donc y acceder comme suit :
        Interval *p_I1 = &I1;
        cout << "*p_I1 = [" << (*p_I1).a << "," << (*p_I1).b << "]" << endl;

        // une maniere plus commode d'acceder aux membres et methodes depuis un pointeur
        // est d'utiliser une fleche (->)
        cout << "*p_I1 = [" << p_I1->a << "," << p_I1->b << "]" << endl;
    }

    /*
     * Utilisation de struct
     */
    {
        // meme utilisation de struct que class
        Complex c;
        c.a = 1;
        c.b = -2;
        cout << "c = " << c << endl;
    }


    /*
     * Utilisation de new
     */
    {
        // comme pour les types standards, on peut gerer l'allocation memoire avec new
        Interval_cons * p_I = new Interval_cons(0,1);

        // on peut allouer dynamiquement un tableau comme suit
        Interval_cons * p_J = new Interval_cons[3] { {2,5}, {3,4}, {10,12} };
        for(int i=0; i<3; i++)
            cout << "p_J[" << i << "] = ["
                 << p_J[i].get_a() << "," << p_J[i].get_b() << "]" << endl;


        // si l'on veut allouer dynamiquement un tableau sans donner d'arguments,
        // alors il faut definir un constructeur par defaut et utiliser la commande suivante
        // Interval_cons * p_K = new Interval_cons[3];
        // delete[] p_K;

        // notons qu'on peut facilement definir un constructeur par defaut en ajoutant des valeurs
        // par defaut aux arguments du constructeur deja defini

        // bien entendu, il ne faut pas oublier de liberer la memoire
        delete p_I;
        delete[] p_J;
    }

    /*
     * this
     */
    // Dans la definition d'une methode d'une classe,
    // le mot cle 'this' renvoie un pointeur vers l'instance de la classe
    // un exemple est donne dans le fichier vector.cpp

    /*
     * Le destructeur d'une classe appelle le destructeur de ses membres (idem pour le constructeur)
     */
    {
        cout << "on initialise une instance de CI :" << endl;
        CI ci;
    }

    cout << endl;
}



////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// modularite / abstraction

/* 
   La modularite represente le fait qu'on va creer des blocs logiques (modules)
   ces blocs auront une fonction (=utilite) et contiendront toutes les informations
   pour remplir cette fonction (1 bloc = 1 classe)
   de plus, on pourra communiquer avec le bloc grace a une interface faisant le lien
   entre exterieur et interieur de la classe
   En pratique, cela signifie que deux classes ayant la meme structure et la meme fonction
   seront facilement interchangeables (sans qu'elles aient la meme implementation interne)
*/
/*
  Au passage, il y a un lien avec l'abstraction :
  le fait que l'utilisateur passe par une interface fait qu'il n'a pas besoin de
  connaitre/comprendre l'implementation de la classe
  -> ceci facilite l'utilisation du module
*/
/*
  La classe vector que l'on presente ici est une application de ces concepts au cas
  de vecteurs reels : une instance de la classe represente des vecteurs
  Elle contient deux membres : la taille du vecteur et une adresse memoire dans
  laquelle stocker les coefficients du vecteur
  On definit un certain nombre de methodes pour agir sur les vecteurs
  (par exemple les operations de base entre vecteurs)
 */

/*
  Notons que le code de la classe Vector est reparti entre deux fichiers
  - le fichier vector.hpp est le fichier d'entete, il contient toutes les declarations
  - le fichier vector.cpp est le fichier source, il contient les definitions des methodes
  L'idee est que le fichier d'entete sera donne a tous les fichiers qui utilisent la classe
  avec #include "vector.hpp"
  Il faut donc que ce fichier soit le plus petit/synthetique possible
  -> pour limiter le temps de compilation des autres fichiers
  -> pour que l'utilisateur puisse le lire comme un resume des methodes disponibles
  Le gros du code sera place dans le fichier source (vector.cpp)
 */

void vector()
{
    cout << "********************" << endl;
    cout << "*****  VECTOR  *****" << endl;
    cout << "********************" << endl;

    /*
      en pratique, on separe la declaration d'une classe 
      (ainsi que les prototypes de ses methodes)
      du reste de l'implementation :
      declaration classe : dans un fichier toto.hpp
      implementation     : dans un fichier toto.cpp
      on peut ensuite inclure le header (hpp) la ou on en a besoin avec #include "toto.hpp"
    */

    int n = 10;

    /*
     * Constructeur :
     */

    // on a defini un constructeur de la classe qui prend un entier
    // notons que ce constructeur alloue de la memoire pour stocker les coefficients
    // aucun constructeur par defaut n'est genere, ainsi l'instruction suivante ne compile pas
    // Vector v; // verifier que cette instruction ne compile pas

    // par contre l'instruction suivante instancie un vecteur en utilisant le constructeur
    Vector v(n); // cette intruction doit fonctionner

    /*
     * Encapsulation :
     */

    // les membres n (taille) et v (pointeur) sont private, on ne peut donc
    // pas y acceder directement
    // v.n = n;  // verifier que cette instruction ne compile pas

    // pour acceder a ces membres (sans les mettre dans un etat incoherent)
    // on utilise des operateurs size() pour n et [] pour les coefficients
    cout << "v.size() = " << v.size() << endl; // doit renvoyer n dans le terminal

    // initialisation des valeurs
    // l'operateur [] renvoie une reference vers le coefficient
    // ceci permet de lire ou d'ecrire dans ce coefficient
    for(int i=0; i < n; i++) // attention : le n ici n'est pas celui de la classe
    {
        v[i] = i; // cette instruction doit fonctionner pour attribuer des valeurs aux coeff
    }

    // on a ajoute un assert dans l'operateur [] pour verifier que le coefficient
    // qu'on demande est valide
    // cout << "v[8] = " << v[8] << endl;             // doit renvoyer 8 dans le terminal
    // cout << "v[12] = " << v[12] << endl; // doit renvoyer une erreur claire a l'execution
    // cout << "v[-3] = " << v[-3] << endl; // doit renvoyer une erreur claire a l'execution

    
    /*
     * Constructeur par copie
     */
    {
        // le constructeur par copie genere de base copie tous les membres
        // il copierait donc l'adresse memoire du premier Vector
        // et en modifiant le premier on modifierait le deuxieme
        // on a donc reecrit le constructeur par copie de facon a allouer de la memoire
        // pour les coefficients puis les recopier dans le nouveau pointeur
        Vector V = v;
        // on peut aussi utiliser
        // Vector V(v);

        // V contient exactement la meme chose que v :
        cout << "V.size() = " << V.size() << endl;
        cout << "V = ";
        for(int i=0; i<n; i++)
            cout << V[i] << " ";
        cout << endl;

        // Si l'on modifie une valeur de V, ca ne modifie pas v
        // (grace au nouveau constructeur par copie)
        cout << "modif de V" << endl;
        V[3] += 10;
        cout << "v = ";
        for(int i=0; i<n; i++)
            cout << v[i] << " ";
        cout << endl;
        cout << "V = ";
        for(int i=0; i<n; i++)
            cout << V[i] << " ";
        cout << endl << endl;

        // notons au passage que le constructeur par copie est appele
        // lorsqu'on passe un argument par copie a une fonction
    }

    /*
     * Operateur de copie : operator=
     */
    // meme histoire que pour le constructeur par copie :
    // on redefinit cet operateur pour eviter d'avoir deux vecteurs qui partagent
    // la meme adresse memoire pour leurs coefficients
    // notons d'ailleurs que le constructeur par copie a ete defini a partir de l'operateur de copie
    // (a part l'allocation memoire qui est faite separement)

    /*
     * Autres operateurs
     */
    {
        // norm2 renvoie la norme l^2 du vecteur
        cout << "l^2-norm = " << v.norm2() << endl; // doit renvoyer 16.8819

        // operateur + : additionne deux vecteurs
        // on teste egalement que ces deux vecteurs ont la meme taille
        Vector w(2*n); // doit fonctionner
        Vector x(n);   // doit fonctionner
        for(int i=0; i < n; i++)
        {
            x[i] = n;     // doit fonctionner
            w[i] = i;     // doit fonctionner
            w[n+i] = n+i; // doit fonctionner
        }
        // Vector a = v + w; // doit renvoyer une erreur claire dans le terminal a l'execution
        //                   //   ( utiliser assert( ... ); )
        Vector b = v + x; // doit fonctionner
        cout << "b[3] = " << b[3] << endl; // doit renvoyer 13

        // operateur - : soustrait deux vecteurs
        // meme problematique que pour l'addition
        b = v - x;
        cout << "bis : b[3] = " << b[3] << endl; // doit renvoyer -7

        // operateur - unaire (change le signe de tous les coeffs d'un vecteur)
        b = -b;
        cout << "ter : b[3] = " << b[3] << endl; // doit renvoyer 7

        // produit scalaire entre deux vecteurs (penser a verifier qu'ils ont la meme taille)
        cout << "x.x = " << x.dot(x) << endl;  // doit renvoyer n^3

        // multiplication par un scalaire a droite
        Vector c(n);
        c = x*n;
        cout << "c[1] = " << c[1] << endl; // doit renvoyer n^2

        // multiplication par un scalaire a gauche
        // cette operation est definie avec une fonction friend
        c = n*x;
        cout << "c[1] = " << c[1] << endl; // doit renvoyer n^2
        cout << endl;
    }

    /*
     * Instances constantes de la classe
     */
    {
        const Vector A(v);
        // on veut pouvoir travailler sur les instances constantes de la classe
        // on precise donc que les methodes
        // size, norm2 et dot sont des methodes constantes pour pouvoir les utiliser
        // idem pour les operateurs binaires + et - et unaire -
        // ainsi que la multiplication par un scalaire

        // On peut donc appeler
        cout << "A.size() = " << A.size() << endl;
        // et de meme pour les autres methodes


        
        // Noter qu'on peut redefinir l'operateur [] pour les instances constantes
        // en renvoyant non pas une reference vers la valeur mais une reference constante
        // ceci permet de lire les valeurs des coefficients avec []
        cout << "A[2] = " << A[2] << endl;
        // mais ne permet pas d'ecrire
        // A[2] = 1; // ne doit pas compiler
    }

    cout << "Ajouter le test de fuite memoire" << endl;


    /*
     * Destructeur
     */
    // Lorsqu'un objet arrive a la fin de sa portee, son destructeur est appele
    // Le destructeur genere par defaut detruit l'instance de la classe
    // puis appelle les destructeurs des membres

    // Ici ce comportement n'est pas suffisant car il ne libere pas la memoire qui a ete allouee
    // pour stocker les coefficients du vecteur
    // on reecrit donc le destructeur en ajoutant la liberation memoire de v

    // dans cette boucle on fait 100 iterations
    // A chaque iteration on cree puis detruit un vecteur de taille 100.000
    // si le destructeur libere la memoire a chaque fois, alors la memoire vive
    // utilisee restera constante
    // Sinon elle augmentera a chaque iteration jusqu'a saturation de la memoire disponible
    // (ou jusqu'a la fin de la boucle si assez de memoire est disponible)
    // On designe cette situation par 'fuite memoire'

    // ce test est fait pour Ubuntu,
    // si vous travaillez sur windows, vous pouvez commenter cette boucle
    for(int i=0; i<100; i++)
    {
        Vector q(100000);
        double vm; // , rss;
        process_mem_usage(vm);
        cout << "VM: " << vm << ";" << endl; // renvoie un idicateur de la memoire utilisee
    }
    
    cout << endl;
}


void process_mem_usage(double& vm_usage)
{
    vm_usage     = 0.0;

    unsigned long vsize;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> vsize >> ignore;
    }

    vm_usage = vsize / 1024.0;
}
