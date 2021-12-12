
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
    
    int tipo;
    int id;
    double x;
    double y;
    double r;
    double w;
    double h;
    double P1_X;
    double P2_X;
    double P3_X;
    double P1_Y;
    double P2_Y;
    double P3_Y;
    double x2;
    double y2;
    double v1;
    double v2;
    double v3;
    double v4;
    char fill[100];
    char border[100];
    char color[100];

   
    
    if(l == NULL){
        printf("Erro na lista\n");
        return NULL;
    }

    Lista* li = (Lista*) l;

    node* no;
    no = li->head;

    while(no != NULL){
        tipo = no->tipo;

        if(tipo == 1 ){
            id = getCircleId(no->info);
            x = getXCircle(no->info);
            y = getYCircle(no->info);
            r = getRCircle(no->info);
            strcpy(fill, getFillCircle(no->info));
            strcpy(border, getBorderCircle(no->info));
            P1_X = getP1_X_Circle(no->info);
            P2_X = getP2_X_Circle(no->info);
            P3_X = getP3_X_Circle(no->info);
            v1 = getV1Circle(no->info);
            v2 = getV2Circle(no->info);
            v3 = getV3Circle(no->info);

            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", r);

            printf("ASSISTA JOJO\n");
            printf("%s\n", fill);
            printf("%s\n", border);

            printf("%lf\n", P1_X);
            printf("%lf\n", P2_X);
            printf("%lf\n", P3_X);
            printf("%lf\n", v1);
            printf("%lf\n", v2);
            printf("%lf\n", v3);
            //printf("%lf\n", v);

            printf("\n*********\n");
        }

        if(tipo == 2){
            id = getRectId(no->info);
            x = getXRect(no->info);
            y = getYRect(no->info);
            w = getWidthRect(no->info);
            h = getHeightRect(no->info);
            // strcpy(fill, getFillCircle(no->info));
            // strcpy(border, getBorderCircle(no->info));
            P1_X = getP1_X_Rect(no->info);
            P2_X = getP2_X_Rect(no->info);
            P3_X = getP3_X_Rect(no->info);

            v1 = getV1Rect(no->info);
            v2 = getV2Rect(no->info);
            v3 = getV3Rect(no->info);
            v4 = getV4Rect(no->info);
            
            // p4 = getP4Rect(no->info);

            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", w);
            printf("%lf\n", h);

            printf("P1: %lf\n", P1_X);
            printf("P2: %lf\n", P2_X);
            printf("P3: %lf\n", P3_X);

            printf("V1: %lf", v1);
            printf("V2: %lf", v2);
            printf("V3: %lf", v3);
            printf("V4: %lf", v4);

            // printf("%lf\n", p1);
            // printf("%lf\n", p2);
            // printf("%lf\n", p3);
            // printf("%lf\n", p4);
            // printf("%s\n", fill);
            // printf("%s\n", border);
        }

        if(tipo == 3){

            id = getIdLinha(no->info);
            x = getX1Linha(no->info);
            y = getY1Linha(no->info);
            x2 = getX2Linha(no->info);
            y2 = getY2Linha(no->info);
            
            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", x2);
            printf("%lf\n", y2);

        }

        if(tipo == 4){

            printf("teste 4\n");
        }
        

        no = no->next;
    }
}