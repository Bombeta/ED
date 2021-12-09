
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// #include "ret.h" 
// #include "circulo.h"

typedef struct node{
    InfoLista info;
    int tipo;
    struct node* next;
    struct node* previous;
}node;

typedef struct list{
	Node *head;
    Node *tail;
    int size;
}Lista;


/*Funciona */
/*Aloca lista e retorna ela vazia */
List createLista(){
	Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l != NULL){
        printf("Lista criada com sucesso\n");
    }
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;

	return l;
}


Node insertList(List l, InfoLista info, int tipo){

	if(l == NULL || info == NULL){
		printf("A lista não foi alocada.");
		return 0;
	}

    Lista* li = (Lista*) l;

    node* NODE = (node*) malloc(sizeof(node));
    NODE->info = info;
    NODE->tipo = tipo;

	/*Alocando novo elemento para lista */
	// Lista* no = (Lista*) malloc(sizeof(Lista));
	// if(no == NULL){
	// 	printf("no não foi alocado!");
	// 	return 0;
	// }

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

    //printf("\nINSERT LIST \n");

    /*retorno  posic */
    return NODE;

}

void printList(List l){
    
    int id;
    double x;
    double y;
    double r;
    double p1;
    double p2;
    double p3;
    char fill[100];
    char border[100];
    double v;

    int tipo;
    
    if(l == NULL){
        printf("Erro na lista\n");
        return NULL;
    }

    Lista* li = (Lista*) l;

    node* no;
    no = li->head;

    while(no != NULL){
        tipo = no->tipo;

        if(tipo == 1){
            id = getCircleId(no->info);
            x = getXCircle(no->info);
            y = getYCircle(no->info);
            r = getRCircle(no->info);
            strcpy(fill, getFillCircle(no->info));
            strcpy(border, getBorderCircle(no->info));
            p1 = getP1Circle(no->info);
            p2 = getP2Circle(no->info);
            p3 = getP3Circle(no->info);
            v = getEnergyCircle(no->info);

            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", r);

            printf("ASSISTA JOJO\n");
            printf("%s\n", fill);
            printf("%s\n", border);

            printf("%lf\n", p1);
            printf("%lf\n", p2);
            printf("%lf\n", p3);
            //printf("%lf\n", v);

        }

        no = no->next;
    }
}