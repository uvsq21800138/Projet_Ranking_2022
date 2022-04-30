#include <stdio.h>
#include <stdlib.h>

#include "list_column.h"
#include "debug.h"
#include "IOrank.h"

///
///	Fonctions sur fichier
///
// ecriture resultats
void ecriture_res(FILE *O,long int n, double *res, int cmpt, double al, double ep)	{
	fprintf(O,"alpha = %lf ; epsi = %lf ; iter = %d\n",al,ep,cmpt);
	for (int i = 0; i < n; i++)	{
		fprintf(O,"%lf\n",res[i]);
	}
	fclose(O);
}

// variables de travail
long int read_file_param(FILE *F)	{
	long int n;
	int debug = fscanf(F,"%ld\n", &n);
	if (debug<1)	{
			db_read(n,1,debug);
	}
	//printf("param = %ld\n", n);
	return n;
}

// matrice P sous forme de liste avec vide
void read_file_list(FILE *F,long int n, DATA *P, int *f)	{
	// P[j] : liste des valeur de chaque colonne
	// f[i] : liste des ligne de degré nul
	int debug = 0;
	for (int k = 0; k < n; k++)	{
		int i = -1, d = -1;
		debug = fscanf(F,"%d %d ", &i, &d);
		if (debug<2)	{
			db_read(1,k+3,debug);
		} else {
			//printf("%d %d : ", i, d);
			if (d==0)	{
				// cas des degrés nuls
				f[i-1] = 1;
			} else {
				// cas des degrés non nuls
				for (int l = 0; l < d; l++)	{
					int j;
					double value;
					debug = fscanf(F,"%d %lf ", &j, &value);
					if (debug<2)	{
						db_read(2,k+3,debug);
					} else {
						//printf("%d %lf ;", j, value);
						insert_start((P+j-1),i-1,value);
					}
				}
			}
		}
		debug = fscanf(F,"\n");
		if (debug<0)	{
			db_read(3,k+3,debug);
		}
		//printf("\n");
	}
	fclose(F);
}
