#include <stdio.h>
#include <stdlib.h>

#include "debug.h"

void db_read(int type, int line, int db)	{
	printf("Erreur lecture #%d : \n\tligne %d \n\tlue %d ;\n",type,line,db);
	exit(1);
}

void db_file(int type, char *name)	{
	if(type == 3)	{
		printf("Pas de fichier en parametre ;\n");
		exit(1);
	}
	printf("Probleme [%d] avec le fichier %s ;\n",type, name);
	exit(2);
}
