#ifndef _H_LISTA
#define _H_LISTA
#define MAX 9000

typedef void* List;
typedef void* Info;
typedef void* Node;

List createLista();
int length(List l);
Node insert(List l, Info info);

#endif 