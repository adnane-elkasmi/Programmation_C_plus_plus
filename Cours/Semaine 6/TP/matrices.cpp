#include "matrices.hpp"

/////////////  class fullMat   //////////////////

// constructeur
fullMat::fullMat(int n_, int m_) : n(n_), m(m_)
{
    assert( n_>0 && m_>0 );

    // allocation memoire
    data = new double* [n_];
    for(int i=0; i<n_; i++)
    {
        data[i] = new double [m_];
    }

    // initialisation des coefficients a zero
    for(int i=0; i<n_; i++)
    {
        for(int j=0; j<m_; j++)
        {
            data[i][j] = 0.0;
        }
    }
}

// constructeur par copie
fullMat::fullMat(const fullMat& M) : n(M.rows()), m(M.cols())
{
    this->data = new double* [n];
    for(int i=0; i<n; i++)
    {
        this->data[i] = new double [m];

        for(int j=0; j<m; j++)
            this->data[i][j] = M(i,j);
    }
}


// operateur de copie
void fullMat::operator=(const fullMat& M)
{
    assert( n == M.rows() && m == M.cols() );
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            data[i][j] = M(i,j);
    }
}

// operation () pour acceder aux coefficients
double & fullMat::operator() (int i, int j)
{
    assert(i>=0 && i < n && j>=0 && j < m);
    return data[i][j];
}

// operation () pour acceder aux coefficients (version constante)
const double fullMat::operator() (int i, int j) const
{
    assert(i>=0 && i < n && j>=0 && j < m);
    return data[i][j];
}

// produit matrice-vecteur
const vector fullMat::operator*(const vector X) const
{
    assert(X.size() == m);

    // create a new vector
    vector ret( n );

    // compute values
    for(int i=0; i<n; i++)
    {
        double val = 0.0;
        for(int j=0; j<m; j++)
        {
            val += data[i][j] * X[j];
        }
        ret[i] = val;
    }
    return ret;
}

// destructeur
fullMat::~fullMat()
{
    for(int i=0; i<n; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}
