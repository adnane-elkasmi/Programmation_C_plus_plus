#include <math.h>
#include <cassert>

#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

// les instructions commencant par un # sont lues et traitees par le precompilateur
// ici ces instructions servent a faire en sorte que le fichier ne sera inclus
// qu'une seule fois dans le code
// ceci sert a eviter certains bugs de compilation qui pourraient apparaitre si on ne faisait pas ca

class Vector
{
private:
    int n;     // size of the vector
    double *v; // values of the vector

public:
    // constructeur (a partir d'un entier)
    Vector(int n_) : n(n_) , v( new double[n_] ){for(int i=0; i<n; i++) v[i] = 0.0;}

    // constructeur par copie
    Vector(const Vector & a) :n(a.n), v( new double [n]) {operator=(a);}

    // copie d'un vecteur
    Vector & operator=(const Vector &a);

    // fonction size() (getter pour n)
    int size() const {return n;}

    // norme l^2
    double norm2() const;

    // un operateur [] pour acceder et assigner des valeurs
    double& operator[](int i){assert(i>=0 && i<n); return v[i];}

    // une version constante pour acceder aux coefficients des vecteurs constants
    const double& operator[](int i) const {assert(i>=0 && i<n); return v[i];}

    // operateur + pour sommer deux vecteurs
    Vector operator+(const Vector &a) const;

    // operateur - pour soustraire deux vecteurs
    Vector operator-(const Vector &a) const;

    // operateur - sur un vecteur
    Vector operator-() const;

    // produit scalaire
    double dot(const Vector &a) const;

    // multiplication a droite par un scalaire
    Vector operator*(double a) const;

    // destructeur (pour liberer la memoire utilisee)
    ~Vector() { delete[] v; }

    // multiplication a gauche par un scalaire
    friend Vector operator*(const double a, const Vector w);
};



#endif
