#include "vector.hpp"
#include <vector>

#ifndef ABSTRACTMATRICESDEF
#define ABSTRACTMATRICESDEF




class virtMat
{
protected:
    int n,m;

public:
    virtMat(int n_, int m_) : n(n_), m(m_) {assert(0<n && 0<m);}
    virtMat(int n_) : n(n_), m(n_) {assert(0<n);}
    virtual const double operator() (int i, int j) const = 0;
    virtual const vector operator*(const vector X) const = 0;
    // Le = 0 et le virtual declarent ces methodes comme virtuelles pures
    int rows() const {return n;}
    int cols() const {return m;}
};

////////////////////////////////////////

class idMat : public virtMat
{
public:
    idMat(int n_) : virtMat(n_) {}
    const double operator() (int i, int j) const;
    const vector operator*(const vector X) const;
};


/////////////////////////////////////////

class fullMat : public virtMat
{
private:
    double **data; // contient les coefficients de la matrice
public:
    fullMat(int n_, int m_);
    fullMat(const fullMat& M);
    void operator=(const fullMat& M);
    const double operator() (int i, int j) const;
    double & operator() (int i, int j);
    const vector operator*(const vector X) const;
    ~fullMat();
};



#endif
