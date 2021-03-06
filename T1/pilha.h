#ifndef _H_PILHA
#define _H_PILHA
//#define MAX 9000

typedef void* Pilha;
typedef void* InfoP;
typedef void* NodeP;

Pilha createPilha();
int lengthP(Pilha p);
NodeP push(Pilha p, InfoP info);
NodeP pop(Pilha p);
void setTipo(Pilha p, char tipo);
char getTipo(Pilha p);
InfoP getInfo(Pilha p);

#endif