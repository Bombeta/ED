// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// // #include "lista.h"
// // #include "ret.h" 
// // #include "circulo.h"

// typedef struct element Element;

// struct element{
// 	struct element *prev
// 	struct Figuras dados; /*void??*/
// 	struct element *next;
// }

// /*Aloca lista e retorna ela vazia */
// Lista* createLista(){
// 	Lista* li = (Lista*) malloc(sizeof(Lista));
// 	if(li != NULL){
// 		*li = NULL;
// 	}

// 	return li;
// }

// int length(Lista* li){
// 	if(li == NULL){
// 		printf("Lista vazia!");
// 		return 0;
// 	}
// 	int cont = 0;
// 	Elem* no = *li;
// 	while(no != NULL){
// 		cont++;
// 		no = no->next;
// 	}

// 	return cont
// }

// void insertFirst(Lista* li, int p){

// 	if(li == NULL){
// 		printf("A lista não foi alocada.");
// 		return 0;
// 	}

// 	/*Alocando novo elemento para lista */
// 	Elem* no = (Elem*) malloc(sizeof(Elem));
// 	if(no == NULL){
// 		printf("no não foi alocado!");
// 		return 0;
// 	}

// 	/*fazer o cast aqui?? */
// 	no->dados = al;
// 	no->next = (*li);
// 	no->prev = NULL;

// 	// para lista não vazia: apontar para elemento anterior
// 	if(*li != NULL){
// 		(*li)->prev = no;
// 	}
// 	*li = no;

	
// }

// void remove(Lista* li, int p){

// }

// Lista* getList(Lista* li, int p){

// }

// Lista* insertBefore(Lista* li, int p){

// }

// Lista* insertAfter(Lista* li, int p){

// }

// Lista* getFirst(Lista* li){

// }

// Lista* getNext(Lista* li){

// }


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

