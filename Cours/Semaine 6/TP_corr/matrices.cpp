#include "matrices.hpp"

/////////////  class idMat   //////////////////

const double idMat::operator() (int i, int j) const
{
    assert( 0 <= i && i < n && 0 <= j && j < n);
    if(i == j)
        return 1.0;
    else
        return 0.0;
}

const vector idMat::operator*(const vector X) const
{
    assert(X.size() == m);

    return X;
}


/////////////  class fullMat   //////////////////

// constructeur
fullMat::fullMat(int n_, int m_) : virtMat(n_,m_)
{
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
fullMat::fullMat(const fullMat& M) : virtMat(M.rows(), M.cols())
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
