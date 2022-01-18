#include <cmath>
#include <cassert>


#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

class vector
{
private:
    int n;     // size of the vector
    double *v; // values of the vector

public:
    // premier constructeur
    vector(int n_) : n(n_) , v( new double[n_] ){for(int i=0; i<n; i++) v[i] = 0.0;}

    // constructeur par copie
    vector(const vector & a) :n(a.n), v( new double [n]) {operator=(a);}

    // copie d'un vecteur
    vector & operator=(const vector &a);

    // fonction size() (constante)
    const int size() const {return n;}

    // norme l^2
    double norm2() const;

    // un operateur [] pour acceder et assigner des valeurs
    double& operator[](int i){assert(i>=0 && i<n); return v[i];}

    // une version constante pour acceder aux vecteurs constants
    const double& operator[](int i) const {assert(i>=0 && i<n); return v[i];}

    // operateur + pour sommer deux vecteurs
    vector operator+(const vector &a) const;

    // operateur - pour soustraire deux vecteurs
    vector operator-(const vector &a) const;

    // operateur - sur un vecteur
    vector operator-() const;

    // produit scalaire
    double dot(const vector &a) const;

    // multiplication a droite par un scalaire
    vector operator*(double a) const;

    // destructeur (pour liberer la memoire utilisee)
    ~vector() { delete[] v; }

    // multiplication a gauche par un scalaire
    friend vector operator*(const double a, const vector w);
};



#endif
