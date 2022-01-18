#include "vector.hpp"

// Lorsque l'on definit des methodes en dehors de la definition de la classe
// il faut faire preceder le nom des methodes par le nom de la classe suivie de ::
// ceci permet de specifier a quelle classe appartiennent les methodes qui sont definies

// copie d'un vecteur
Vector & Vector::operator=(const Vector &a) {
    assert( n == a.size() );
    for(int i=0; i < n; i++)
        v[i] = a[i];
    
    return *this;
}

// produit scalaire
double Vector::dot(const Vector &a) const {
    assert( n == a.size() );
    double ret = 0.0;
    for(int i=0; i<n; i++)
    {
        ret += v[i] * a[i];
    }
    return ret;
}

// norme l2
double Vector::norm2() const{
    // double sum = 0.0;
    // for(int i = 0; i < n; i++)
    // {
    //     double val = v[i];
    //     sum += val * val;
    // }
    // return std::sqrt(sum);
    return std::sqrt(this->dot(*this));
}

// somme de deux vecteurs
Vector Vector::operator+(const Vector &a) const {
    assert( n == a.size() );
    Vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = v[i] + a[i];
    }
    return ret;
}

// soustraction de deux vecteurs
Vector Vector::operator-(const Vector &a) const {
    assert( n == a.size() );
    Vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = v[i] - a[i];
    }
    return ret;
}

// operateur unaire -
Vector Vector::operator-() const {
    Vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = - v[i];
    }
    return ret;
}

// multiplication a droite par un scalaire
Vector Vector::operator*(double a) const {
    Vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = a * v[i];
    }
    return ret;
}

// multiplication a gauche par un scalaire
Vector operator*(const double a, const Vector w)
{
    int n = w.size();
    Vector ret( n );
    for(int i=0; i<n; i++)
    {
        ret[i] = a * w.v[i];
    }
    return ret;
}
