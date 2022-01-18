#include <iostream>
#include <fstream>
#include "matrices.hpp"
#include "GC.hpp"
#include <time.h>



void testsGC(int n)
{
    using std::cout;
    using std::endl;

    cout << "//////////////////////   GC    ////////////////////////" << endl;

    cout << "////////////  matrice identite : " << endl;
    {
        ///////  idMat  /////////
        vector B(n), sol(n);
        for(int i=0; i<n; i++)
            B[i] = i;
        idMat ID(n);
        double eps = 1E-12;
        int itermax = 100;

        clock_t t1, t2;
        t1 = clock();
        GradientConjugue(ID, sol, B, itermax, eps);
        t2 = clock();
        cout << "temps avec idMat : " << (float)(t2-t1) / CLOCKS_PER_SEC << "s" << endl;

        cout << "(sol-B).norm2() = " << (sol-B).norm2() // doit renvoyer 0 en 1 iteration
             << endl;
    }
    {
        ///////  fullMat  ///////
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
    cout << "///////////////   tests avec matrice triangulaire" << endl;
    {
        // temps
        clock_t t1, t2;

        t1 = clock();
        fullMat mat(n,n);
        for(int i=0; i<n-1; i++)
        {
            mat(i,i) = 2.0; mat(i,i+1) = 1.0; mat(i+1,i) = 1.0;
        }
        mat(n-1,n-1) = 2.0;

        vector B(n);
        B[0] = 3.0;
        for(int i=1; i<n-1; i++)
            B[i] = 4.0;
        B[n-1] = 3.0;

        vector sol(n);
        for(int i=0; i<n; i++)
            sol[i] = 0.0;

        vector sol_ex(n);
        for(int i=0; i<n; i++)
            sol_ex[i] = 1.0;

        double eps = 1E-12;
        int itermax = 10000;

        GradientConjugue(mat, sol, B, itermax, eps);

        cout << "(sol-sol_ex).norm2() = " << (sol-sol_ex).norm2() // doit renvoyer < eps
             << endl;
        t2 = clock();
        cout << "temps fullMat : " << (float)(t2-t1) / CLOCKS_PER_SEC << "s" << endl;
    }


}

//////////////////////////////////////////////////////////

int main(int argc, const char ** argv)
{
    using std::cout;
    using std::endl;

    int n = 1000;

    testsGC(n);

    cout << "end prog" << endl;
    return 0;
}
