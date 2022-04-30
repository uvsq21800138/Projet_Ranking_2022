#include <stdio.h>
#include <stdlib.h>

typedef struct data {
	int x;
	double val;
	struct data *suiv;
} DATA;

void insert_start(DATA *d,int x,double val);
void insert_end(DATA *d,int x,double val);

DATA *init_tab_list(long int n);
void free_list(DATA *d);
void free_tab_list(long int n, DATA *T);

void printf_tab_list(long int n, DATA *T);
