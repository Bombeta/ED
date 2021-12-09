#ifndef _H_LISTA
#define _H_LISTA


typedef void* List;
typedef void* InfoLista;
typedef void* Node;


List createLista();
Node insertList(List l, InfoLista info, int tipo);
void printList(List l);

#endif
