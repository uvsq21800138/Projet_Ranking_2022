#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

///	Fonctions d'affichage

void printf_vect(long int n, double *t)	{
	for (int i = 0; i < n; i++)	{
		printf("%e ",t[i]);
	}
	printf("\n");
}

void printf_mat(long int n, double **m)	{
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++)	{
			printf("%f ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/// Fonctions de modification sur matrices et vecteurs

void init_tab_double(long int n, double *t, double val)	{
	for (int i = 0; i < n; i++)	{
		t[i] = (double) val;
	}
}

void init_tab_int(long int n, int *t, int val)	{
	for (int i = 0; i < n; i++)	{
		t[i] = (int) val;
	}
}

void transfert(long int n, double *des, double *v)	{
	for (int i = 0; i < n; i++)	{
		des[i] = v[i];
	}
}

/// Fonctions d'opération sur matrices et vecteurs

// addition d'un scalaire à un vecteur
void add_vect_scal(long int n, double *v, double scal)	{
	for (int i = 0; i < n; i++)	{
		v[i] =  v[i] + scal;
	}
}

// multiplie 2 vecteurs de taille n ligne x colonne = scalaire
double mult_vect_lc(long int n, double *a, int *b)	{
	double tmp = 0.0;
	for (int i = 0; i < n; i++)	{
		tmp += (double) a[i] * b[i];
	}
	return tmp;
}
