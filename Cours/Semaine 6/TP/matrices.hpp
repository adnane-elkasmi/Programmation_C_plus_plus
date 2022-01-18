#include "vector.hpp"
#include <vector>

#ifndef ABSTRACTMATRICESDEF
#define ABSTRACTMATRICESDEF

class fullMat
{
private:
    int n,m;
    double **data; // contient les coefficients de la matrice
public:
    fullMat(int n_, int m_);
    fullMat(const fullMat& M);
    void operator=(const fullMat& M);
    const double operator() (int i, int j) const;
    double & operator() (int i, int j);
    const vector operator*(const vector X) const;
    int rows() const {return n;}
    int cols() const {return m;}
    ~fullMat();
};

#endif
