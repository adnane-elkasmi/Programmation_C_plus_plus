#include <math.h>
#include <cassert>

#include "vector.hpp"

#ifndef MATRIXHEADERDEF

#define MATRIXHEADERDEF

class Matrix
{
	private:
		int n; //nombre de lignes de la matrice coeffs
		int m; //nombre de colonnes de la matrice coeffs
		double** coeffs; //contenu de la matrice (valeurs)

	public:
		Matrix(int n_, int m_) : n(n_), m(m_) //constructeur
		{
			coeffs = new double*[n];
			for (int i = 0; i < n; ++i)
			{
				coeffs[i] = new double[m];
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++)
				{
					coeffs[i][j] = 0.0;
				}
			}
		}

		Matrix(const Matrix& a) :n(a.n), m(a.m) //constructeur par copie
		{ 
			coeffs = new double* [n];
			for (int i = 0; i < n; ++i)
			{
				coeffs[i] = new double[m];
			}
			operator=(a); 
		}

		Matrix& operator=(const Matrix& a); //operateur de copie =

		int rows() const { return n; } //retourner le nombre de lignes de coeffs

		int cols() const { return m; } //retourner le nombre de colonnes de coeffs

		double& operator()(int i, int j) { assert(i >= 0 && i < n && j >= 0 && j < m); return coeffs[i][j]; } //operateur d'accès aux coefficients

		double& operator()(int i, int j) const { assert(i >= 0 && i < n && j >= 0 && j < m); return coeffs[i][j]; } //operateur d'accès aux coefficients de matrice constante

		Matrix operator+(const Matrix& a) const; //operateur d'addition de deux matrices

		Matrix operator-(const Matrix& a) const; //operateur de soustraction de deux matrices

		Matrix operator-() const; //operateur unaire

		friend Vector operator*(const Matrix m, const Vector x); //operateur de multiplication d'une matrice par un vecteur pour rendre un vecteur

		~Matrix() // destructeur de la classe matrix pour libérer la mémoire
		{
			for (int i = 0; i < n; i++) 
			{
				delete coeffs[i];
			}
			delete[] coeffs;
		}

};
#endif
