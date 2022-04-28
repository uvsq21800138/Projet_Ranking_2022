#include <stdio.h>
#include <stdlib.h>

#include "list_column.h"

/// Manipulation de la structure

// Insère une valeur en début de colonne
void insert_start(DATA *d,int x,double val) {
	// Si elle était vide, insère sur la racine
	if (d->val == -1.0)	{
		d->x = x ;
		d->val = val ;
		d->suiv = NULL ;
	}
	else	{
	 	// Sinon ajoute au début de la chaine
		DATA *tmp = malloc(sizeof(DATA)) ;
		tmp->x = d->x ;
		tmp->val = d->val ;
		tmp->suiv = d->suiv ;
		d->x = x ;
		d->val = val ;
		d->suiv = tmp ;
	}
}

// Insère une valeur en fin de colonne
void insert_end(DATA *d,int x,double val) {
	// Si elle était vide
	if (d->val == -1.0)	{
		d->x = x ;
		d->val = val ;
		d->suiv = NULL ;
	}
	else	{
		DATA *tmp = d;
		// Avance dans la séquence
		while(tmp->suiv != NULL) {
			tmp = tmp->suiv;
		}
	 	// Sinon ajoute au bout de la chaine
		DATA *new = malloc(sizeof(DATA)) ;
		new->x = x ;
		new->val = val ;
		new->suiv = NULL ;
		tmp->suiv = new ;
	}
}

/// Allocation et libération de la mémoire

// Initie la structure de tableau de liste colonne
DATA *init_tab_list(long int n) {
	DATA *T = malloc(n*sizeof(DATA));
	// Si la séquence n'était pas vide
	for (int i = 0; i < n; i++)	{
		T[i].val = -1.0;
	}
	return T ;
}

void free_list(DATA *d) {
	if(d->suiv != NULL)	{
		DATA *tmp1 = d->suiv;
		DATA *tmp2 ;
		while(tmp1->suiv != NULL) {
			tmp2 = tmp1->suiv;
			free(tmp1);
			tmp1 = tmp2;
		}
		free(tmp1);
	}	
}

void free_tab_list(long int n, DATA *T)	{
	for (int i = 0; i < n; i++)	{
		free_list(T+i);
	}
	free(T);
}

/// Affichage du tableau de liste

void printf_tab_list(long int n, DATA *T)	{
	for (int i = 0; i < n; i++)	{
		printf("%d : ",i+1);
		DATA *tmp = T+i;
		while(tmp->suiv != NULL)	{
			printf("%d %f ",tmp->x,tmp->val);
			tmp = tmp->suiv;
		}
		printf("%d %f\n",tmp->x,tmp->val);
	}
}
