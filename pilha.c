#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

typedef struct nodePilha{
    InfoP info;
    struct nodePilha* next;
    
}NodePilha;

typedef struct stack{
	NodeP *topo;
    int size;
}Stack;

Pilha createPilha(){
    Stack* p = (Stack*) malloc(sizeof(Stack));
    if(p != NULL){
        //printf("Pilha criada com sucesso!");
    }

    p->topo = NULL;
    p->size = 0;
    return p;
}

int lengthP(Pilha p){    
	if(p == NULL){
		printf("Lista não inicializada vazia!");
		return 0;
	}
    Stack* s = (Stack*) p;
	return s->size;
}

int empty(Pilha p){
    Stack* s = (Stack*) p;
    return s->size == 0;
}

NodeP push(Pilha p, InfoP info){
    if(p == NULL){
        printf("Erro na criação da lista.\n");
        return 0;
    }

    Stack* s = (Stack*) p;

    NodePilha* n = (NodePilha*) malloc(sizeof(NodePilha));
    if(n == NULL){
        printf("Erro de alocação de um novo nó!\n");
        return 0;
    }
    n->info = info;
    n->next = s->topo;
    s->topo = n;
    s->size++;

    return p;
}


void pop(Pilha p){
    if(!empty(p)){
        Stack* s = (Stack*) p;  
        NodePilha* n = s->topo;
        void *v = n->info;
        s->topo = n->next;
        s->size--;
        free(n);
        return v;
    }

    return NULL;
}


// Pilha createPilha(){
// 	Pilha_st* p = (Pilha_st*) malloc(sizeof(Pilha_st));
//     if(p != NULL){
//         printf("Pilha criada com sucesso\n");
//     }
//     p->topo = NULL;
//     // p->fundo = NULL;
// 	p->size = 10;

// 	return p;
// }




// NodeP push(Pilha p, InfoP info){
//     if(p == NULL){
//         printf("A lista não foi alocada.");
//         return 0;
//     }

//     // Pilha_st* pilha = (Pilha_st*) p;
//     // if(pilha == NULL){
//     //     printf(" foi alocado.");
//     //     return 0;
//     // }
//     Pilha_st* pilha = (Pilha_st) p;
    
//     nodeP* NODEP = (nodeP*) malloc(sizeof(nodeP));
//     NODEP->info = info;

//     if(pilha->topo== NULL){
//         pilha->topo= NODE;
//         NODE->previous = NULL;
//         NODE->next = NULL;
//     }else{
//         NODE->previous = pilha->topo;
//         NODE->previous->next = NODE;
//     }

//     pilha->size++;
// }

// NodeP pop(Pilha p){
    
//     Pilha_st* pilha = (Pilha_st) p;

//     if(pilha->size > 0){
//         if(pilha->size > 1){
//             pilha->topo = 
//         }

//         free
//     }
    
// }