#include <stdio.h>
#include <stdlib.h>

void printf_vect(long int n, double *t);
void printf_mat(long int n, double **m);

void init_tab_double(long int n, double *t, double val);
void init_tab_int(long int n, int *t, int val);
void transfert(long int n, double *des, double *v);

void add_vect_scal(long int n, double *v, double scal);
double mult_vect_lc(long int n, double *a, int *b);
