#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ret.h"


void cria_Retangulo(LIST* l, int id, double x, double y, double w, double h, char *fill, char *border)
{
	int i;
	int r;

	i = l->nroElem;
	r = l->nroR;

	if(i > MAX-1)
	{
		printf("A LISTA está cheia!\n");
		exit(0);
	}

	l->R[r].id = id;
	l->R[r].x = x;
	l->R[r].y = y;
	l->R[r].w = w;
	l->R[r].h = h;
	strcpy(l->R[r].fill, fill);
	strcpy(l->R[r].border, border);

	l->nroElem = i + 1;

}