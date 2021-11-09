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

/*Funciona */
int length(List l){    
	if(l == NULL){
		printf("Lista não inicializada vazia!");
		return 0;
	}
    Lista* li = (Lista*) l;
	return li->size;
}

/* Funciona */
Node insert(List l, Info info){

	if(l == NULL || info == NULL){
		printf("A lista não foi alocada.");
		return 0;
	}

    Lista* li = (Lista*) l;

    node* NODE = (node*) malloc(sizeof(node));
    NODE->info = info;

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

    /*retorno  posic */
    return NODE;

}

// void remove(List l, node Posic){

// }


Info get(List l, void* Posic){
    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return 0;
    }

    if(Posic == NULL){
        printf("Erro: Posic não existe\n");
    }

    node *NODE = (node*) Posic;
    return NODE->info;
}

// Node InsertBefore(List l, node Posic){

// }

// Node InsertAfter(List l, node Posic){

// }


Node getFirst(List l){

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }


    return li->head;

}

Node getNext(List l){

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    // node *NODE = li->next;

    /*verifica se o node é o último elemento da lista */
    // if(NODE == NULL){
    //     return NULL;
    // }

    // return NODE;
}

Node getLast(List l){
    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    return li->tail;

}

Node getPrevious(List l, void* Posic){

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    node *NODE = (node*) Posic;

    /*Verifica se o node é o primeiro elemento da lista */
    if(NODE->previous == NULL){
        return NULL;
    }   
    return NODE->previous;
}

Node searchList(List l, int id){

    printf("\nSearch List circulo: \n");

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    node* no;
    no = li->head;

    
    
    while(no!=NULL){
        // printf("%p\n", no);
        if(getCircleId(no->info) == id){
            printf("CIRCULO ID = %d\n", id);
            //printCircle(no-);
            
            return no->info;
        }else if(getRectId(no->info) == id){
            printf("RETANGULO ID = %d\n", id);
            //printRect(no->info);

            return no->info;
        }
        no = no->next;
    }
    return NULL;
      
}

// Node searchListRect(List l, int id){

//     printf("entra aqui quadrado\n");

//     if(l == NULL){
//         printf("Erro: Lista não existe\n");
//         return NULL;
//     }

//     Lista* li = (Lista*) l;
//     if(li->size == 0){
//         printf("Erro: a lista está vazia\n");
//         return NULL;
//     }

//     node* no;
//     no = li->head;
    
//     while(no!=NULL){
        
//         printf("RETANGULO ID = %d\n", id);
//         if(getRectId(no->info) == id){
//             return no->info;
//         }
//         no = no->next;
//     }
//     return NULL;
      
// }


// Node searchListText(List l, int id){

//     printf("entra aqui texto\n");

//     if(l == NULL){
//         printf("Erro: Lista não existe\n");
//         return NULL;
//     }

//     Lista* li = (Lista*) l;
//     if(li->size == 0){
//         printf("Erro: a lista está vazia\n");
//         return NULL;
//     }

//     node* no;
//     no = li->head;
    
//     while(no!=NULL){
        
//         printf("TEXTO = %d\n", id);
//         if(getRectId(no->info) == id){
//             return no->info;
//         }
//         no = no->next;
//     }
//     return NULL;
      
// }

//Comandos do QRY

Node drawListFigure(List l){

    printf("\nSearch List circulo: \n");

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    node* no;
    no = li->head;

    char tipo;
    
    
    while(no!=NULL){
        //strcpy(tipo,no->tipo);
      
        if(getTipoCircle(no->info) == 'c'){
            drawCircle(no->info);
        }else if(getTipoRect(no->info) == 'r'){
            drawRect(no->info);
        }
             
        no = no->next;
    }
    return NULL;
      
}

/*Node drawListRect(List l){

    printf("\nSearch List circulo: \n");

    if(l == NULL){
        printf("Erro: Lista não existe\n");
        return NULL;
    }

    Lista* li = (Lista*) l;
    if(li->size == 0){
        printf("Erro: a lista está vazia\n");
        return NULL;
    }

    node* no;
    no = li->head;

    
    
    while(no!=NULL){
        drawRect(no->info);
        no = no->next;
    }
    return NULL;
      
}*/






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

