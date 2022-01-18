#include "matrices.hpp"
#include "vector.hpp"

#ifndef GCHEADERFILE
#define GCHEADERFILE

// methode du gradient conjugue pour resoudre un systeme lineaire
// A : matrice (symetrique definie positive)
// X : vecteur solution contenant une initialisation
// B : second membre
// nbiterax : nb maximum d'iterations de la procedure
// eps : critere d'arret
int GradientConjugue(const fullMat &A, vector &X, const vector &B,
                     const int nbitermax, const double eps)
{
    int iter = 0;
    vector res = A * X - B; // initialisation du residu
    vector p = - res; // initialisation de la direction de descente

    // norme
    double res2 = res.dot(res);


    while(iter < nbitermax && std::sqrt(res2) > eps)
    {
        double alpha = - res.dot(p) / (p.dot(A * p));

        // nouveau X
        X = X + alpha * p;

        // nouveau residu
        res = res + alpha * (A * p);

        // nouvelle norme
        double res2_old = res2;
        res2 = res.dot(res);

        // nouvelle direction de descente
        p = - res + (res2 / res2_old) * p;

        iter++;
    }
    std::cout << "gradient conjugue ended : " << iter << " iterations" << std::endl;
    return 0;
}

#endif
