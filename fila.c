#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

typedef struct nodeFila{
    InfoF info;
    struct nodeFila *next;

}NodeFila;

typedef struct queue{
    NodeFila *start;
    NodeFila *end;
    int size
}Queue;

Fila *createFila(){
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if(q != NULL){
        //printf("Fila criada com sucesso!");
    }

    q->start = NULL;
    q->end = NULL;
    q->size = 0;
    return q;
}

NodeF insertFila(Fila f, InfoF info){
    if(f == NULL){
        printf("Erro na criação da fila.\n");
        return 0;
    }

    Queue* q = (Queue*) f;

    NodeFila* nf = (NodeFila*) malloc(sizeof(NodeFila));
    if(nf == NULL){
        printf("Erro na alocação de um novo no");
        return 0;
    }

    nf->info = info;
    nf->next = NULL;

    if(q->end != NULL){
        q->end->next = nf;
    }else{
        q->start = nf;
    }

    q->end = nf;
    q->size++;
    return q;
}

//refazer
int emptyFila(Fila f){
    Queue* q = (Queue*) f;
    return q->size == 0;
}

void removeFila(Fila f){
    if(!empty(f)){
        Queue* q = (Queue*) f;
        NodeFila* nf = q->start;
        void* aux = nf->info;
        q->start = nf->next;
        q->size--;

        if(q->start == NULL){
            q->end = NULL;
        }

        free(nf);
        return aux;

    }

    return NULL;
}