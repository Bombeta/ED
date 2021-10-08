#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
// #include "ret.h" 
// #include "circulo.h"

typedef struct node{
    Info info;
    struct node* next;
    struct node* previous;
}node;

typedef struct list{
	Node *head;
    Node *tail;
    int size;
}Lista;

/*Aloca lista e retorna ela vazia */
List createLista(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l != NULL){
        printf("Lista criada com sucesso");
    }
	l->head = NULL;
	l->tail = NULL;
	l->size = 10;

	return l;
}

int length(List l){    
	if(l == NULL){
		printf("Lista não inicializada vazia!");
		return 0;
	}
    Lista* li = (Lista*) l;
	return li->size;
}

Node insert(List l, Info info){

	if(l == NULL || info == NULL){
		printf("A lista não foi alocada.");
		return 0;
	}

    Lista* li = (Lista*) l;

    node* NODE = (node*) malloc(sizeof(node));
    NODE->info = info;

	/*Alocando novo elemento para lista */
	Lista* no = (Lista*) malloc(sizeof(Lista));
	if(no == NULL){
		printf("no não foi alocado!");
		return 0;
	}

    //lista vazia
    if(li->head == NULL){
        li->head = NODE;
        NODE->previous = NULL;
    }else{
        NODE->previous = li->tail;
        NODE->previous->next = NODE;
    }

    li->tail = NODE;
    NODE->next = NULL;

    li->size++;

    return NODE;

}
// void releaseList(Lista* li){
// 	/*Verifica se a lista não está vazia*/
// 	if(li != NULL){
// 		Elem* no;
// 		while((*li) != NULL){
// 			no = *li;
// 			*li = (*li)->next;
// 			free(no);
// 		}
// 		free(li);
// 	}
// }

