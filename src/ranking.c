#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "list_column.h"
#include "debug.h"
#include "IOrank.h"
#include "vector.h"

// Returns the maximum of two numbers
# define MAX(A, B) ((A) > (B) ? (A) : (B))

// Returns the minimum of two numbers
# define MIN(A, B) ((A) < (B) ? (A) : (B))

// Variables Globales
double epsi = 1e-6;
double alpha = 0.85;
long int N = 0;
long int M = 0;

///
///	Fonctions de l'algo
///

// Norme 1 de la différence absolue entre 2 vecteurs
double norme1_dif(double *opi, double *npi)	{
	double tmp = 0.0;
	for (int i = 0; i < N; i++)	{
		tmp += MAX(opi[i], npi[i]) - MIN(opi[i], npi[i]);
	}
	return (double)tmp;
}

// Produit alpha * vecteur * P sous forme de listes-colonne
void axP(double *npi, double *opi, DATA *T)	{
	init_tab_double(N,npi, 0.0);
	for (int j = 0; j < N; j++)	{
		//npi[j] = 0.0;
		DATA *tmp = T+j;
		// retire les cas de degré nul
		if(T[j].val != -1)	{
			while(tmp->suiv != NULL)	{
				npi[j] += (double) opi[tmp->x] * tmp->val;
				tmp = tmp->suiv;
			}
			npi[j] += (double) opi[tmp->x] * tmp->val;
		}
		npi[j] = (double) alpha * npi[j];
	}
}

///
/// Algorithme PageRank
///
void PageRank(FILE *F, FILE *O) {
	// lecture variables de base
	N = read_file_param(F);
	M = read_file_param(F);
	
	DATA *P = init_tab_list(N);
	int *f = calloc(N,sizeof(int));
	init_tab_int(N,f,0);
	double **pi = calloc(2,sizeof(double*));
	pi[0] = calloc(N,sizeof(double));
	pi[1] = calloc(N,sizeof(double));
	init_tab_double(N,pi[0],(double) 1/N);
	
	// lecture des valeurs de P dans T et f
	read_file_list(F,N,P,f);
	
	int cmpt = 0;
	double xf = 0.0;
	double scal = 0.0;
	double inv = (double) 1/N;

	// premier tour
	xf = mult_vect_lc(N,pi[0], f);
	axP(pi[1], pi[0], P);
	scal = (double)((1-alpha)*inv) + (double)(alpha * inv * xf);
	add_vect_scal(N, pi[1], scal);
	cmpt++;
	// boucle 
	while(norme1_dif(pi[0], pi[1]) > epsi)	{
		xf = mult_vect_lc(N,pi[cmpt%2], f);
		axP(pi[1-cmpt%2], pi[cmpt%2], P);
		scal = (double)((1-alpha)*inv) + (double)(alpha * inv * xf);
		add_vect_scal(N, pi[1-cmpt%2], scal);
		cmpt++;
		//printf_vect(N,pi[1-cmpt%2]);
		//printf("%d \n",cmpt);
	}
	printf("Convergence en %d iterations\n",cmpt);
	
	ecriture_res(O,N,pi[1-cmpt%2],cmpt, alpha, epsi);
	
	free_tab_list(N,P);
	free(f);
	free(pi[0]);
	free(pi[1]);
	free(pi);
}

///
///	Main
///
int main(int argc, char **argv)	{
	// y a t-il un fichier en paramètre?
	if (argc>1)	{
		FILE *F = fopen(argv[1], "r");
		if(!F)	{
			db_file(1,argv[1]);
		}
		/// gestion du nom de sortie
		char file[40] = "out/";
		// si 2eme paramètre alors il devient le nom dans le dossier out/
		if(argc>2)	{
			int length = strlen(argv[2]);
			for (int i = 0; i <= length && i < 36; i++)	{
				file[4+i] = argv[2][i];
			}
		// sinon on prend output.txt comme nom par défaut 
		} else {
			char name[10] = "output.txt";
			for (int i = 0; i < 10; i++)	{
				file[4+i] = name[i];
			}
		}
		FILE *O = fopen(file, "w");
		if(!F)	{
			db_file(2,file);
		}
		printf("Sortie dans %s ;\n",file);
		PageRank(F,O);
		exit(0);
	}
	else {
		db_file(3,"");
	}
}
