#ifndef _H_PILHA
#define _H_PILHA
//#define MAX 9000

typedef void* Pilha;
typedef void* InfoP;
typedef void* NodeP;

Pilha createPilha();
int lengthP(Pilha p);
NodeP push(Pilha p, InfoP info);
void pop(Pilha p);

#endif