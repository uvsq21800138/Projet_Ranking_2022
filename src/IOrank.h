#include <stdio.h>
#include <stdlib.h>

void ecriture_res(FILE *O,long int n, double *res, int cmpt, double al, double ep);

long int read_file_param(FILE *F);
void read_file_list(FILE *F,long int n, DATA *P, int *f);
