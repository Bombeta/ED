#ifndef _H_FILA
#define _H_FILA

typedef void* Fila;
typedef void* InfoF;
typedef void* NodeF;

Fila *createFila();
NodeF insertFila(Fila f, InfoF info);
void removeFila(Fila f);
int emptyFila(Fila f);

#endif
