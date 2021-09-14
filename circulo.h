#ifndef _H_CIRCULO
#define _H_CIRCULO
#include "lista.h"

typedef void *circulo;

void cria_Circulo(LIST* l, int id, double x, double y, double r, char *fill, char *border);

char* getNome(void* circulo);


#endif