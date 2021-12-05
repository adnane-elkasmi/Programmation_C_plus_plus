#include "matrix.hpp"


//operateur de copie =
Matrix & Matrix::operator=(const Matrix& a) {
    assert(n == a.rows() && m == a.cols());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            coeffs[i][j] = a(i,j);
        }
    }
    return *this;
}


//operateur d'addition de deux matrices
Matrix Matrix::operator+(const Matrix& a) const {
    assert(n == a.rows() && m == a.cols());
    Matrix ret(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret(i, j) = coeffs[i][j] + a(i, j);
        }
    }
    return ret;
}


//operateur de soustraction de deux matrices
Matrix Matrix::operator-(const Matrix& a) const {
    assert(n == a.rows() && m == a.cols());
    Matrix ret(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret(i, j) = coeffs[i][j] - a(i, j);
        }
    }
    return ret;
}


//operateur unaire
Matrix Matrix::operator-() const {
    Matrix ret(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ret(i, j) = - coeffs[i][j];
        }
    }
    return ret;
}


//operateur de multiplication d'une matrice par un vecteur pour rendre un vecteur
Vector operator*(const Matrix m, const Vector x)
{
    Vector ret(m.rows());
    double tmp = 0.0;
    for (int i = 0; i < m.rows(); i++)
    {
        tmp = 0.0;
        for (int j = 0; j < m.cols(); j++)
        {
            tmp = tmp + m(i, j) * x[j];
        }
        ret[i] = tmp;
    }
    return ret;
}