#include <iostream>
#include <fstream>
#include "vector.hpp"
#include "matrix.hpp"

void process_mem_usage(double&);

int main(int argc, const char ** argv)
{
    using std::cout;
    using std::endl;

    // {
    //     cout << "//// TESTS constructeur, getters et operateur() ////" << endl;
    //     int n = 20;
    //     int m = 10;

    //     // Matrix M(); // ne doit pas compiler
    //     Matrix M(n,m); // doit compiler

    //     cout << "M.rows() = " << M.rows() << std::endl; // doit renvoyer n = 20
    //     cout << "M.cols() = " << M.cols() << std::endl; // doit renvoyer m = 10

    //     M(1,2) = 2.0;
    //     M(2,2) = 1.5;

    //     cout << "M(1,1) = " << M(1,1)              // doit renvoyer 0
    //          << "   M(1,2) = " << M(1,2)           // doit renvoyer 2
    //          << "   M(2,2) = " << M(2,2) << endl;  // doit renvoyer 1.5
    // }

    // Matrix Mat(2,3);
    // Mat(0,0) = 1.0; Mat(0,1) = 2.0;  Mat(0,2) = 5.0;
    // Mat(1,0) = 5.0; Mat(1,1) = -2.0; Mat(1,2) = -4.0;

    // {
    //     cout << endl;
    //     cout << "//// TESTS sur le produit Matrix / Vector ////" << endl;
    //     Vector X(3);
    //     Vector c(2);

    //     X[0] = 0.0;     X[1] = 2.0;      X[2] = -1.0;

    //     // Vector Y = Mat * c; // doit renvoyer une erreur a l'execution
    //     Vector Z = Mat * X; // doit fonctionner

    //     cout << "Z.size() = " << Z.size() // doit renvoyer 2
    //          << "    Z[0] = " << Z[0]     // doit renvoyer -1
    //          << "    Z[1] = " << Z[1]     // doit renvoyer 0
    //          << endl;

    // }

    // {
    //     cout << endl;
    //     cout << "//// TESTS sur le constructeur par copie ////" << endl;
    //     Matrix Mat2 = Mat;
    //     Mat2(1,1) = 1.0;

    //     cout <<   "Mat2(1,1) = " << Mat2(1,1) // doit renvoyer 1
    //          << "  Mat(1,1) =  " << Mat(1,1)  // doit renvoyer -2
    //          << endl;
    // }

    // {
    //     cout << endl;
    //     cout << "//// TESTS sur l'op\'erateur de copie ////" << endl;
    //     Matrix Mat2(2,3);
    //     Matrix Mat3(5,3);

    //     // Mat3 = Mat; // doit renvoyer une erreur a l'execution (mauvaises dimensions)
    //     Mat2 = Mat;  // doit s'executer
    //     Mat2(1,1) = 1.0;

    //     cout <<   "Mat2(1,1) = " << Mat2(1,1) // doit renvoyer 1
    //          << "  Mat(1,1) =  " << Mat(1,1)  // doit renvoyer -2
    //          << endl;
    // }

    // {
    //     cout << endl;
    //     cout << "//// TESTS sur les operateurs + et - ////" << endl;

    //     Matrix Mat2(2,3);
    //     Matrix Mat3(5,3);

    //     Mat2(0,0) = 1; Mat2(0,1) = 6; Mat2(0,2) = -1;
    //     Mat2(1,0) = 0.5; Mat2(1,1) = -2; Mat2(1,2) = 1;

    //     Matrix Mat4(2,3);
    //     // Mat4 = Mat + Mat3; // doit renvoyer une erreur a l'execution
    //     // Mat4 = Mat - Mat3; // doit renvoyer une erreur a l'execution

    //     Mat4 = Mat + Mat2; // doit s'executer
    //     cout << "Mat + Mat2 = " << endl;
    //     for(int i=0; i < Mat4.rows(); i++)
    //     {
    //         for(int j=0; j < Mat4.cols(); j++)
    //             cout << Mat4(i,j) << "  ";
    //         cout << endl;
    //     }

    //     // doit renvoyer
    //     // 2 8 4
    //     // 5.5 -4 -3

    //     cout << endl;
    //     Mat4 = Mat - Mat2; // doit s'executer
    //     cout << "Mat - Mat2 = " << endl;
    //     for(int i=0; i < Mat4.rows(); i++)
    //     {
    //         for(int j=0; j < Mat4.cols(); j++)
    //             cout << Mat4(i,j) << "  ";
    //         cout << endl;
    //     }
    //     // doit renvoyer
    //     // 0 -4 6
    //     // 4.5 0 -5
    // }


    // {
    //     cout << endl;
    //     cout << "//// TESTS sur les instances constantes ////" << endl;
    //     const Matrix A = Mat;
    //     // A(1,1) = 1.0; // ne doit pas compiler

    //     // dimensions
    //     cout << "A.rows() = " << A.rows()
    //          << "  A.cols() = " << A.cols() << endl; // doit renvoyer 2 et 3
    //     // sortie des coeffs de A
    //     cout << "A = " << endl;
    //     for(int i=0; i < A.rows(); i++)
    //     {
    //         for(int j=0; j < A.cols(); j++)
    //             cout << A(i,j) << "  ";
    //         cout << endl;
    //     }
    //     // doit renvoyer
    //     // 1  2  5
    //     // 5 -2 -4
    // }

    // {
    //     cout << endl;
    //     cout << "//// TESTS sur la memoire ////" << endl;
    //     cout << "verifier que la memoire n'augmente pas a chaque iteration" << endl;
    //     for(int i=0; i<10; i++)
    //     {
    //         Matrix Q(1000,1000);
    //         double vm;
    //         process_mem_usage(vm);
    //         cout << "VM: " << vm << ";" << endl; // renvoie un idicateur de la memoire utilisee

    //         // verifier que la memoire n'augmente pas a chaque iteration
    //     }
    // }

    return 0;
}



void process_mem_usage(double& vm_usage)
{
    vm_usage     = 0.0;

    unsigned long vsize;
    {
        std::string ignore;
        std::ifstream ifs("/proc/self/stat", std::ios_base::in);
        ifs >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore >> ignore
                >> ignore >> ignore >> vsize >> ignore;
    }

    vm_usage = vsize / 1024.0;
}
