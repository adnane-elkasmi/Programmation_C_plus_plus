#include <iostream>
#include <assert.h>
#include <math.h> // necessaire pour sin
#include <vector>
#include <algorithm>
#include <time.h>

using std::cout;
using std::endl;
using std::string;

void animaux();
void droits();
void virt();
void construc();
void quads();
void vehicule();

int main()
{
    animaux();

    droits();

    virt();

    construc();

    quads();

    vehicule();

    return 0;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


/*
 * Classe Animal representant un animal (de compagnie)
 */
class Animal {
public:
    Animal(string name) : name(name) {}
    Animal(const Animal& a) : name(a.name) { cout << "Utilisation de l'operateur de copie" << endl;}
    virtual void info() const {cout << name << " est un animal" << endl;}
    void manger() const {cout << name << " est repu" << endl;}
    void dormir() const {cout << name << " est en forme" << endl;}
    bool operator<(const Animal& a) const { return (name<a.name);}
protected: // protected est un troisieme droit d'acces apres public et private
           // les membres protected ne sont pas accessibles depuis l'exterieur de la classe
           // ils sont cependant accessibles depuis les methodes d'une classe fille
    string name;
};

/*
 * Classe Chat : un animal qui peut miauler
 */
class Chat : public Animal {
public:
    void miauler() const {cout << name << " : Miaou !!" << endl;}
    Chat(string name) : Animal(name) {}
    void info() const {cout << name << " est un chat" << endl;}
};

/*
 * Classe Chien : un animal qui peut aboyer
 */
class Chien : public Animal {
public:
    void aboyer() const {cout << name << " : Wouff !!" << endl;}
    Chien(string name) : Animal(name) {}
    void info() const {cout << name << " est un chien" << endl;}
};

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void animaux() {
    /*
     * Presentation de l'heritage :
     * l'heritage permet de specialiser certaines classes :
     * quand une classe A est un cas particulier d'une autre classe B 
     * alors on peut dire que A herite de B
     * d'un point de vue informatique cela permet a A d'avoir acces a tout le code de B sans avoir a le reecrire
     * (B est un modele de depart pour construire A)
     */

    /*
     * La classe derivee contient les membres et methodes de sa (ses) classe(s) de base
     * On peut de plus lui rajouter des membres et/ou methodes supplementaires
     */

    cout << "**********************" << endl;
    cout << "****** ANIMAUX *******" << endl;
    cout << "**********************" << endl;

    // creons un animal "Hans" et faisons-le manger puis dormir
    Animal hans("Hans");
    hans.manger();
    hans.dormir();
    cout << endl;

    // creons maintenant un chat "Marcel", faisons-le dormir puis miauler
    Chat marcel("Marcel");
    marcel.dormir();
    marcel.miauler();
    marcel.info();
    cout << endl;

    // par contre Hans ne peut pas miauler
    // hans.miauler();

    // creons un chien Judith et faisons-la manger puis aboyer
    Chien judith("Judith");
    judith.manger();
    judith.aboyer();
    judith.info();
    cout << endl;
    
    // par contre Judith ne peut pas miauler et Marcel ne peut pas aboyer
    // judith.miauler();
    // marcel.aboyer();

    /*
     * On parle d'extensibilite pour representer le fait qu'on reutilise le code de Animal pour definir Chat et Chien
     */

    // Une autre application des classes filles est qu'on peut les incorporer dans des listes de type classe mere (idem pour les arguments de fonction)
    // On parle de polymorphisme (dynamique) pour representer cet effet
    std::vector<Animal> chenil;
    chenil.push_back(hans);
    chenil.push_back(marcel);
    chenil.push_back(judith);
    cout << "chenil : " << endl;
    for(auto it = chenil.begin(); it != chenil.end(); it++)
        it->info();
    cout << endl;


    sort(chenil.begin(), chenil.end());
    cout << "chenil : " << endl;
    for(auto it = chenil.begin(); it != chenil.end(); it++)
        it->info();
    cout << endl;

    /*
     * Notons ici que si l'on ne met pas le mot cle virtual devant la methode info() de la classe Animal
     * alors les commandes marcel.info() et judith.info() font appel a la methode de la classe fille
     * tandis que la commande it->info() fait appel a la methode de la classe mere
     * (car it est un iterateur sur un conteneur d'Animal)
     * le mot cle virtual fait en sorte que lorsqu'on fait appel a Animal::info(), le code va d'abord chercher s'il
     * on ne peut pas plutot faire appel a la fonction info() d'une classe fille
     * -> essayer d'ajouter/enlever virtual devant Animal::info()
     */
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// une classe A avec des membres public, protected, private
class A {
public:
    int a;
protected:
    int b;
private:
    int c;
};


/*
 * Ce qu'il faut savoir :
 * - les membres private d'une classe mere ne sont pas accessibles depuis une classe fille
 * - les membres public et protected sont accessibles depuis une classe fille
 *   et leur droit d'acces sont alors le droit le plus restrictif
 *    entre le droit dans la classe mere et le droit de l'heritage
 * Par exemple :
 * un membre public dans la classe mere sera public dans la fille si l'heritage est public
 * et protected si l'heritage est protected et private si l'heritage est private
 * un membre protected dans la classe mere sera protected dans la classe fille si l'heritage
 * est public, protected si l'heritage est protected et private si l'heritage est private
 */


/*
 * Parmi le code suivant, determiner quels sont les appels qui ne compileront pas
 * puis decommenter pour verifier
 */

// // X herite de A de facon public
// class X : public A {
//     void modif_b() {b++;}
//     // void modif_c() {c++;}
// };

// // Y herite de A de facon protected
// class Y : protected A {
//     void modif_b() {b++;}
//     // void modif_c() {c++;}
// };

// // Z herite de A de facon private
// class Z : private A {
//     void modif_b() {b++;}
//     // void modif_c() {c++;}
// };

void droits() {
    cout << "**********************" << endl;
    cout << "******* DROITS *******" << endl;
    cout << "**********************" << endl;

    // X x;
    // cout << "x.a = " << x.a << endl;
    // cout << "x.b = " << x.b << endl;
    // cout << "x.c = " << x.c << endl;

    // Y y;
    // cout << "y.a = " << y.a << endl;
    // cout << "y.b = " << y.b << endl;
    // cout << "y.c = " << y.c << endl;

    // Z z;
    // cout << "z.a = " << z.a << endl;
    // cout << "z.b = " << z.b << endl;
    // cout << "z.c = " << z.c << endl;

    cout << endl;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void virt() {


    cout << "**********************" << endl;
    cout << "****** VIRTUAL *******" << endl;
    cout << "**********************" << endl;

    /*
     * Si on declare une methode virtuelle (mot clef virtual)
     * son appel n'est pas resolu a la compilation mais a l'execution
     * -> le programme regarde quel est le vrai type de l'objet avant d'appeler la methode
     *    (ceci ralentit l'execution)
     */

    Animal* p_an;

    p_an = new Chat("chat");

    p_an->info();

    delete p_an;

    Animal hans("Hans");
    Chat marcel("Marcel");
    Chien judith("Judith");

    /*
     * L'utilisation de std::vector<Animal> ne permet pas un polymorphisme efficace
     * raison : quand on ajoute un element a ce vecteur, cet element est converti
     * en Animal par l'operateur de copie
     * Tous les elements de ce vecteur sont donc de type Animal
     * Pour verifier ceci, on peut reecrire l'operateur de copie de Animal
     * (decommenter l'operateur de copie de Animal)
     */


    std::vector<Animal> chenil;
    // tester avec et sans l'instruction chenil.reserve(3);
    // (il faut avoir decommente l'operateur de copie de Animal)
    // qu'est-ce qui change et pourquoi ?
    chenil.reserve(3);
    chenil.push_back(hans);
    cout << "Hans" << endl;
    chenil.push_back(marcel);
    cout << "Marcel" << endl;
    chenil.push_back(judith);

    cout << endl << "Utilisation de vector<Animal> : " << endl;
    for(auto it = chenil.begin(); it != chenil.end(); it++)
        it->info();

    /*
     * Pour pouvoir utiliser ce polymorphisme sur un conteneur,
     * il faut considerer un conteneur de pointeurs std::vector<Animal*>
     * Ici les adresses sont recopiees et on ne change pas le type de l'objet
     */

    std::vector<Animal*> chenil2;
    chenil2.push_back(&hans);
    chenil2.push_back(&marcel);
    chenil2.push_back(&judith);

    cout << endl << "Utilisation de vector<Animal*> : " << endl;
    for(auto it = chenil2.begin(); it != chenil2.end(); it++)
        (*it)->info();


    cout << endl;
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// Constructeurs :
/*
 * Ce qu'il faut savoir :
 * Quand on appelle un constructeur de la classe fille,
 * il faut specifier un constructeur de la classe mere a appeler
 * si aucun constructeur de la classe mere n'est specifie
 * alors le constructeur par defaut est appele
 * Si la classe mere n'a pas de constructeur par defaut, alors on est oblige de specifier
 * le constructeur utilise dans la classe fille
 */

class Cons_mere {
public:
    Cons_mere() {cout << "appel du constructeur mere" << endl;}
    Cons_mere(int a) {cout << "appel du deuxieme constructeur mere avec a = " << a << endl;}
};

class Cons_fille : public Cons_mere {
public:
    Cons_fille() : Cons_mere(1) {cout << "appel du constructeur fille" << endl;}
};

void construc() {

    cout << "**********************" << endl;
    cout << "**** CONSTRUCTORS ****" << endl;
    cout << "**********************" << endl;

    Cons_fille f;

    cout << endl;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// heritage multiple et heritage virtuel

#define VIRTUALINHERITANCE // A commenter pour enlever l'heritage virtuel

class Quadrilatere { // on va representer le quadrilatere a partir de ses cotes et de ses angles
public:
    double a,b,c,d; // quatre cotes
    double alpha, beta, gamma, delta; // quatre angles
    Quadrilatere(double a, double b, double c, double d, double alpha, double beta, double gamma, double delta) : a(a), b(b), c(c), d(d), alpha(alpha), beta(beta), gamma(gamma), delta(delta) {
        // ici il faudrait ajouter des assert pour verifier la coherence des donnees
    }
    virtual double perimetre() { return a+b+c+d; } // le mot cle virtual rend cette methode virtuelle : on peut la redefinir dans les classes filles
};

// un rectangle est un quadrilatere avec quatre angles droits et des cotes egaux deux a deux
#ifdef VIRTUALINHERITANCE
class Rectangle : virtual public Quadrilatere {
#else
class Rectangle : public Quadrilatere {
#endif
public:
    Rectangle(double a, double b) : Quadrilatere(a,b,a,b,90,90,90,90) {assert( (a > 0) && (b > 0) );}
    // on peut facilement calculer son aire
    double aire() { return a*b; }
#ifndef VIRTUALINHERITANCE
    // notons que lorsqu'on utilise l'heritage virtuel, on ne peut pas reecrire deux fois
    // la methode perimetre()
    double perimetre() { return 2*(a+b); }
#endif
};

// un losange est un quadrilatere avec quatre cotes egaux
#ifdef VIRTUALINHERITANCE
class Losange : virtual public Quadrilatere {
#else
class Losange : public Quadrilatere {
#endif
public:
    Losange(double a, double alpha) : Quadrilatere(a,a,a,a,alpha, 180-alpha, alpha, 180-alpha) { assert( (a>0) && (alpha>0) ); }
    double aire() { return a*a*sin(alpha * 3.14 / 180.); }
    double perimetre() { return 4*a; }
};

// un carre est a la fois un rectangle et un losange
class Carre : public Rectangle, public Losange {
public:
#ifdef VIRTUALINHERITANCE
    // si l'on utilise l'heritage virtuel, alors il faut indiquer comment initialiser Quadrilatere
    Carre(double a) : Rectangle(a,a), Losange(a, 90), Quadrilatere(a,a,a,a,90,90,90,90) {}
#else
    Carre(double a) : Rectangle(a,a), Losange(a, 90) {}
#endif

    /*
     * Ici, il y a une ambiguite sur le fait que les methodes aire() et perimetre()
     * de Carre peuvent venir de Rectangle ou de Losange
     * Cette ambiguite vient de l'heritage multiple de Carre
     * On peut lever cette ambiguite avec les commandes suivantes
     */
    using Rectangle::aire; // quand on appelle aire() on utilisera le aire() de Rectangle
    using Losange::perimetre; // le perimetre() sera celui de Losange
};

void quads() {

    cout << "**********************" << endl;
    cout << "******* QUADS ********" << endl;
    cout << "**********************" << endl;

    // un carre
    Carre unite(1); // carre unite
    // si on ne specifie pas l'utilisation de aire() et perimetre(),
    // les commandes suivantes ne compilent pas
    cout << "unite.aire() = " << unite.aire() << endl;
    cout << "unite.perimetre() = " << unite.perimetre() << endl;
    cout << endl;

    // sans heritage virtuel, les commandes suivantes ne compilent pas
    Quadrilatere q = unite;
    cout << "unite.a = " << unite.a << endl;

    // Une autre possibilite serait d'utiliser un static_cast
    Quadrilatere q2 = static_cast<Rectangle>(unite);
    cout << "unite.a = " << static_cast<Rectangle>(unite).a << endl;

    // le plus simple dans ce cas precis est d'utiliser un heritage virtuel
    // ceci permet egalement de reduire l'espace memoire utilise par Carre
    // (puisqu'il n'y aura qu'un seul Quadrilatere associe a chaque Carre)
    cout << "sizeof(Quadrilatere) = " << sizeof(Quadrilatere) << endl;
    cout << "sizeof(Rectangle) = " << sizeof(Rectangle) << endl;
    cout << "sizeof(Losange) = " << sizeof(Losange) << endl;
    cout << "sizeof(Carre) = " << sizeof(Carre) << endl;

    // pour rappel, un double est code sur 8 octets
    // Quadrilatere occupe donc 8*8 = 72 octets

    // Si l'on utilise l'heritage virtuel, l'espace memoire occupe change :
    // en fait, le Quadrilatere utilise par Rectangle et par Losange est "separe"
    // de ces deux instances
    // ces deux classes utilisent donc plus de memoire pour localiser leur Quadrilatere
    // par contre, on gagne de la memoire sur Carre car cette classe ne possede
    // qu'un seul ancetre Quadrilatere
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


/*
 * On definit une classe abstraite Vehicule
 * Une classe abstraite est une classe qui a au moins une methode virtuelle pure
 * Une telle classe ne peut pas etre instanciee
 */

class Vehicule {
public:
    virtual void se_deplacer() const = 0; // cette methode est une methode virtuelle pure (=0)
};

class Velo : public Vehicule {
public:
    void se_deplacer() const { cout << "on pedale, on avance ..." << endl; }
};

class Voiture : public Vehicule {
public:
    void se_deplacer() const { cout << "on allume le moteur, on appuie sur l'accelerateur ..." << endl; }
};


void test(const Vehicule& m) {
    m.se_deplacer();
}

void vehicule() {
    /*
     * On presente ici les methodes virtuelles pures et les classes abstraites
     */

    cout << "**********************" << endl;
    cout << "***** vehicule *******" << endl;
    cout << "**********************" << endl;

    /*
     * Une methode virtuelle est une methode qui peut etre entierement redefinie dans les classes filles (mais pas necessairement)
     */
    /*
     * Une methode virtuelle pure est une methode qui n'est pas definie en l'etat et qui peut etre redefinie dans les classes filles
     */
    /*
     * Une classe abstraite est une classe possedant au moins une methode virtuelle pure
     * Cette methode n'etant pas definie, on ne peut pas instancier une classe abstraite
     * Pour pouvoir instancier une classe fille, il FAUT redefinir la (les) methode virtuelle pure
     * Notons que le but d'une classe abstraite est de servir d'interface commune a ses classes filles
     */

    // on ne peut pas instancier Vehicule
    // Vehicule m;
    // cout << "Vehicule : ";
    // m.se_deplacer();

    // on peut instantier Velo (et utiliser sa methode se_deplacer() )
    Velo f1;
    cout << "Velo : ";
    f1.se_deplacer();

    // on peut instantier Voiture (et utiliser sa methode se_deplacer() )
    Voiture f2;
    cout << "Voiture : ";
    f2.se_deplacer();

    /*
     * l'interet de la classe abstraite Vehicule est de servir d'interface,
     * par exemple pour pouvoir utiliser la fonction test()
     * ici, la fonction test() a ete ecrite en utilisant la classe abstraite Vehicule
     * et on peut l'utiliser pour toutes les classes filles
     */
    test(f1);
    test(f2);
    cout << endl;
}
