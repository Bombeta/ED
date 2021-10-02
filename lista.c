#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "ret.h" 
#include "circulo.h"

typedef struct element Element;

struct element{
	struct element *prev
	struct Figuras dados; /*void??*/
	struct element *next;
}

/*Aloca lista e retorna ela vazia */
Lista* createLista(){
	Lista* li = (Lista*) malloc(sizeof(Lista));
	if(li != NULL){
		*li = NULL;
	}

	return li;
}

int length(Lista* li){
	if(li == NULL){
		printf("Lista vazia!");
		return 0;
	}
	int cont = 0;
	Elem* no = *li;
	while(no != NULL){
		cont++;
		no = no->next;
	}

	return cont
}

void insert(Lista* li, int p){

}

void remove(Lista* li, int p){

}

Lista* getList(Lista* li, int p){

}

Lista* insertBefore(Lista* li, int p){

}

Lista* insertAfter(Lista* li, int p){

}

Lista* getFirst(Lista* li){

}

Lista* getNext(Lista* li){

}


void releaseList(Lista* li){
	/*Verifica se a lista não está vazia*/
	if(li != NULL){
		Elem* no;
		while((*li) != NULL){
			no = *li;
			*li = (*li)->next;
			free(no);
		}
		free(li);
	}
}


// void inicia_Lista(LIST* l)
// {
// 	l->nroElem = 0;
// 	l->nroC = 0;
// 	l->nroR = 0;
// 	l->nroT = 0;

// }


// void remove_Lista(LIST* l, int id)
// {
// 	int i;
// 	int k;
	
// 	/*Procura id no círculo */
// 	for(i=0;i<l->nroC;i++)
// 	{
// 		if(id == l->C[i].id)
// 		{
// 			/*Circulo no inicio da lista*/
// 			if(i==0)
// 			{
// 				for(k=0; k < l->nroC; k++)
// 				{
// 					l->C[k] = l->C[k + 1];
// 				}

// 				l->nroC = l->nroC - 1;
// 			}

// 			/*Texto no meio da lista  esta funcionando*/
// 			if(i>0 || i < l->nroC)
// 			{
// 				for(k=i; k<l->nroC; k++)
// 				{
// 					l->C[k] = l->C[k + 1];
// 				}

// 				l->nroC = l->nroC - 1;
// 			}

// 			/*Texto no final da lista  esta funcionando*/
// 			if(i == l->nroC - 1)
// 			{
// 				l->nroC = l->nroC - 1;
// 			}

			
// 		}
// 	}

// 	/*Porcura id no retangulo */
// 	for(i=0;i<l->nroT;i++)
// 	{
// 		if(l->T[i].id == id)
// 		{
// 			/*Texto no inicio da lista*/
// 			if(i == 0)
// 			{
// 				for(k=0; k < l->nroT; k++)
// 				{
// 					l->T[k] = l->T[k + 1];
// 				}

// 				l->nroT = l->nroT - 1;
// 			}

// 			/*Texto no meio da lista*/
// 			if(i>0 || i < l->nroT)
// 			{
// 				for(k=i; k<l->nroT; k++)
// 				{
// 					l->T[k] = l->T[k + 1];
// 				}

// 				l->nroT = l->nroT - 1;
// 			}

// 			/*Texto no final da lista */
// 			if(i == l->nroT - 1)
// 			{
// 				l->nroT = l->nroT - 1;
// 			}
// 		}
// 	}

// 	l->nroElem = l-> nroElem - 1;
// }


// void remove_Lista_2(LIST* l,int id, int xd)
// {
// 	printf("codigo aqui\n");
// } 


// void exibir_Lista(LIST* l)
// {
// 	int i;

// 	for(i=0;i < l->nroT; i++)
// 	{
// 		printf("Lista texto: %d\n", l->T[i].id);
// 		printf("%.2lf\n", l->T[i].x);
// 		printf("%.2lf\n", l->T[i].y);
// 		printf("%s\n", l->T[i].fill);
// 		printf("%s\n", l->T[i].border);
// 	}

// 	for(i=0;i < l->nroC; i++)
// 	{
// 		printf("Lista circulo: %d\n", l->C[i].id);
// 		printf("r:	%.2lf\n", l->C[i].r);
// 		printf("x:	%.2lf\n", l->C[i].x);
// 		printf("y:	%.2lf\n", l->C[i].y);
// 		printf("fill:	%s\n", l->C[i].fill);
// 		printf("border:	%s\n", l->C[i].border);
// 	}



// 	printf("\n");

// 	printf("%d\n",l->nroT);
// 	printf("%d\n",l->nroR);
// 	printf("%d\n",l->nroC);
// 	printf("%d\n",l->nroElem);

// 	for(i=0;i < l->nroR; i++)
// 	{
// 		printf("Lista retangulo: %d\n", l->R[i].id);

// 		printf("%.2lf\n", l->R[i].x);
// 		printf("%.2lf\n", l->R[i].y);
// 		printf("%.2lf\n", l->R[i].w);
// 		printf("%.2lf\n", l->R[i].h);
// 		printf("%s\n", l->R[i].fill);
// 		printf("%s\n", l->R[i].border);
// 	}

	
	
// }
