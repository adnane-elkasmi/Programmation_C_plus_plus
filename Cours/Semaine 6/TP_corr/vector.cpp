#include "vector.hpp"


// copie d'un vecteur
vector & vector::operator=(const vector &a) {
    assert( n == a.size() );
    for(int i=0; i < n; i++)
        v[i] = a[i];

    return *this;
}

// produit scalaire
double vector::dot(const vector &a) const {
    assert( n == a.size() );
    double ret = 0.0;
    for(int i=0; i<n; i++)
    {
        ret += v[i] * a[i];
    }
    return ret;
}

// norme l2
double vector::norm2() const{
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
vector vector::operator+(const vector &a) const {
    assert( n == a.size() );
    vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = v[i] + a[i];
    }
    return ret;
}

// soustraction de deux vecteurs
vector vector::operator-(const vector &a) const {
    assert( n == a.size() );
    vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = v[i] - a[i];
    }
    return ret;
}

// operateur unitaire -
vector vector::operator-() const {
    vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = - v[i];
    }
    return ret;
}

// multiplication a droite par un scalaire
vector vector::operator*(double a) const {
    vector ret(n);
    for(int i=0; i<n; i++)
    {
        ret[i] = a * v[i];
    }
    return ret;
}

// multiplication a gauche par un scalaire
vector operator*(const double a, const vector w)
{
    int n = w.size();
    vector ret( n );
    for(int i=0; i<n; i++)
    {
        ret[i] = a * w.v[i];
    }
    return ret;
}
