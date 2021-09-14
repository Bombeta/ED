#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "texto.h"
#include "lista.h"


void cria_Texto(LIST* l, int id, float x, float y, char *fill, char *border)
{
	int i;
	int t;

	if(l->nroElem > MAX-1)
	{
		printf("A lista está cheia\n");
		exit(0);
	}

	t = l->nroT;
	i = l->nroElem;

	l->T[t].id = id;
	l->T[t].x = x;
	l->T[t].y = y;
	strcpy(l->T[t].fill,fill);
	strcpy(l->T[t].border,border);

	l->nroElem = i + 1; 
	l->nroT = t + 1;

}


