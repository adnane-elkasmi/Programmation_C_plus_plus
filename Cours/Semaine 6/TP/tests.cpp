#include <iostream>
#include <fstream>
#include "matrices.hpp"
#include "GC.hpp"
#include <time.h>

using std::cout;
using std::endl;


void testFull(int n) {
    vector B(n), sol(n);
    fullMat mat(n,n);
    for(int i=0; i<n; i++)
    {
        B[i] = i;
        mat(i,i) = 1.;
    }

    double eps = 1E-12;
    int itermax = 100;

    clock_t t1, t2;
    t1 = clock();
    GradientConjugue(mat, sol, B, itermax, eps);
    t2 = clock();
    cout << "temps avec fullMat : " << (float)(t2-t1) / CLOCKS_PER_SEC << "s" << endl;

    cout << "(sol-B).norm2() = " << (sol-B).norm2() // doit renvoyer 0 en 1 iteration
         << endl;
}


int main(int argc, const char ** argv)
{

    // vous pouvez realiser vos tests ici

    int n = 100;
    testFull(n);

    cout << "end prog" << endl;
    return 0;
}
