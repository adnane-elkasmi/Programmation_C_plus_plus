#include <iostream>
#include <assert.h>
// using namespace std;
using std::cout;
using std::endl;
using std::string;

void fn_max();
void rectangle();
void s_tab();

int main()
{

    fn_max();
    rectangle();
    s_tab();

    return 0;
}

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// definition d'une fonction max avec des template

// codons une fonction max qui prend le maximum entre deux entiers
// une qui prend le max entre deux double
// une entre un entier et un double, une entre un double et un entier

// definition de quatre fonctions avec surcharge
int max(int a, int b)
{
    if( a < b )
	return b;
    else
	return a;
}

double max(double a, double b)
{
    if( a < b )
	return b;
    else
	return a;
}

double max(int a, double b)
{
    if( a < b )
	return b;
    else
	return a;
}

double max(double a, int b)
{
    if( a < b )
	return b;
    else
	return a;
}
// en fait, on n'a pas vraiment besoin de ces quatre fonctions, grace au transtypage entre int et double
// mais des problemes similaires peuvent apparitre dans l'emploi de float, double, long double

// il faudrait faire de meme avec float et ainsi de suite ... c'est lourd ...
// la solution est l'utilisation de templates

// avec deux types differents, on utilise ce code
// cependant le retour est ici du meme type que le premier argument
template<typename T1, typename T2>
T1 maxt(const T1 a, const T2 b)
{
    if( a < b )
	return b;
    else
	return a;
}

// on peut regler le probleme en forcant le type de retour
template<typename T1, typename T2, typename R>
R maxt2(const T1 a, const T2 b)
{
    if( a < b )
	return b;
    else
	return a;
}

// ce type de polymorphisme est appele polymorphisme statique
// car les differentes fonctions sont generees a la compilation

// // specialisation possible pour les string
// // Attention : la specialisation doit etre ecrite APRES la fonction generique associee (sinon problemes de compilation)
// template<>
// string maxt(const string a, const string b)
// {
//     if( a.size() < b.size() )
// 	return b;
//     else
// 	return a;
// }

void fn_max() {
    cout << "********************" << endl;
    cout << "*** FONCTION MAX ***" << endl;
    cout << "********************" << endl;

    int a = 1;
    int b = 5;
    double c = 2.5;
    double d = -1.2;

    // on peut utiliser la surcharge de fonctions pour faire marcher ce code -> mais quatre fonctions differentes
    cout << "// Surcharge de fonction :" << endl;
    cout << "max(a,b) = " << max(a,b) << endl;
    cout << "max(a,c) = " << max(a,c) << endl;
    cout << "max(d,b) = " << max(d,b) << endl;
    cout << "max(c,d) = " << max(c,d) << endl;
    cout << endl;

    // utilisons une fonction generique avec des templates -> mais parfois le mauvais type de retour pour ce cas precis
    cout << "// Utilisation de templates :" << endl;
    cout << "maxt(a,b) = " << maxt<int,int>(a,b) << endl;
    cout << "maxt(a,c) = " << maxt(a,c) << endl;
    cout << "maxt(d,b) = " << maxt(d,b) << endl;
    cout << "maxt(c,d) = " << maxt(c,d) << endl;
    cout << endl;
    // on peut aussi utiliser la ligne suivante (mais pas necessaire)
    // cout << "maxt(a,b) = " << maxt<int,int>(a,b) << endl;

    // utilisons un template supplementaire pour le retour (plus complique a appeler -> pas de type implicite)
    cout << "// Utilisation de templates + type retour :" << endl;
    cout << "maxt2(a,b) = " << maxt2<int,int,int>(a,b) << endl;
    cout << "maxt2(a,c) = " << maxt2<int,double,double>(a,c) << endl;
    cout << "maxt2(d,b) = " << maxt2<double,int,double>(d,b) << endl;
    cout << "maxt2(c,d) = " << maxt2<double,double,double>(c,d) << endl;
    cout << endl;

    // utilisation de maxt avec des string
    cout << "// Application a des chaines de caracteres (et specialisation) :" << endl;
    cout << "maxt(Arbre,Chat) = " << maxt<string,string>("Arbre","Chat") << endl;
    cout << "maxt(Arbre,Chaton) = " << maxt<string,string>("Arbre","Chaton") << endl;
    cout << endl;

    // specialisation : actuellement max sur les string est fait par ordre alphabetique
    // si par hasard on veut que la comparaison se fasse par le nombre de caracteres
    // alors on peut ajouter une specialisation pour le type string (voir code commente)
    // reprendre le resultat precedent avec et sans la specialisation pour les string


}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// definition d'une classe avec des template

/*
 * on s'interesse a une classe de rectangle
 * on stockera la taille des cotes a et b
 * on utilisera des templates pour rendre la classe generique et pour que ses membres puissent etre de differents types
 */

template <typename T>
class Rectangle {
private:
    T a, b;
public:
    // aire est definie dans la classe donc on peut utiliser T sans le redefinir
    T aire() const { return a*b; }
    Rectangle(T a, T b) : a(a), b(b) {assert(a > 0 && b > 0);}
};

// // si on veut definir la methode "aire" a l'exterieur de la classe, alors on doit ecrire :
// template<typename T>
// T Rectangle<T>::aire() const { return a*b; }
// // ici il faut redefinir T (d'ou la ligne avec template)


// on peut utiliser la fonction suivante pour ne pas avoir a reecrire le type entre <...>
// c'est utile quand les types sont tres longs a ecrire (ca arrive...)
template<typename T>
Rectangle<T> make_rectangle(T a, T b)
{
    return Rectangle<T>(a,b);
}

void rectangle() {
    cout << "********************" << endl;
    cout << "**** RECTANGLE *****" << endl;
    cout << "********************" << endl;

    cout << "Instanciation de Rectangle :" << endl;
    
    // instanciation d'un Rectangle avec double
    Rectangle<double> recDouble(1.5,2.5);
    cout << "aire du premier rectangle : " << recDouble.aire() << endl;

    // instanciation d'un Rectangle avec int
    Rectangle<int> recInt(2,3);
    cout << "aire du deuxieme rectangle : " << recInt.aire() << endl;

    // si jamais on demande int et on fournit un double ...
    Rectangle<int> recInt2(3.5,3);
    cout << "aire du troisieme rectangle : " << recInt2.aire() << endl;
    cout << endl;


    cout << "Utilisation d'une fonction pour types implicites :" << endl;
    int a = 5, b = 2;
    auto rec = make_rectangle(a,b);
    // cette ligne est equivalente a la ligne suivante
    // Rectangle<int> rec = make_rectangle(a,b);
    // auto capture le type de retour de la fonction make_rectangle
    // cela permet de simplifier le code :
    // - prend moins de place -> plus facile a lire
    // - moins de changements a effectuer si a et b deviennent double -> plus facile a entretenir
    // attention : auto ne fonctionne que si le compilateur arrive a determiner le type
    cout << "aire de rec : " << rec.aire() << endl;
    cout << endl;

    // attention a l'utilisation de auto :
    auto x = 20; // ici auto donne un type int
    x += 2.5;
    cout << "x = " << x << endl;
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////



/*
 * on s'interesse a une classe de tableau intelligent (qui verifie qu'on ne depasse pas la limite autorisee)
 * on utilisera des templates pour rendre la classe generique
 */

template<typename T>
class Smart_tab {
public:
    Smart_tab(int n) : size(n), data(new T[n]) { assert(n > 0); }
    ~Smart_tab() { delete [] data; }
    T & operator[](int i) { return data[check(i)]; }
    T operator[](int i) const { return data[check(i)]; }

private:
    T *data;
    int size;
    int check(int i) const { assert( (i>=0) && (i<size) ); return i; }
};


void s_tab() {
    cout << "********************" << endl;
    cout << "**** SMART TAB  ****" << endl;
    cout << "********************" << endl;

    using T = double;
    // a partir d'ici T est double
    // c'est pratique pour ne pas avoir a changer tout le code quand on change un type

    int n = 10;
    // Smart_tab tab(n); // ne compile pas : il faut preciser le type de tab
    Smart_tab<T> tab(n); // ok

    // on peut aussi utiliser la commande suivante pour simplifier le type
    using Tab = Smart_tab<T>;
    Tab tab2(n);

    // tab[n] = 1; // doit renvoyer une erreur a l'execution

    cout << "tab[0] = " << tab[0] << endl;

    /*
     * Attention : lorsque des templates sont employes, on ne peut pas separer le code d'une classe
     * entre un fichier .hpp et un fichier .cpp
     * -> tout doit etre dans le fichier .hpp
     * (ou alors il faut utiliser des commandes plus subtiles)
     */

    cout << endl;
}

/*
 * S'il reste du temps, alors commencer a travailler sur le CM sur la STL
 */
