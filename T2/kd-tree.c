#include <stdio.h>
#include <stdlib.h>
#include "kd-tree.h"
#include "circulo.h"
#include "ret.h"
#include "linha.h"
#include "texto.h"

enum figuras{c = 1, r = 2, l = 3, t = 4};

typedef struct node{
    double x;
    double y;    
    int id;
    int tipo;
    InfoK info;
    struct node *left;
    struct node *right;
    struct node *father;
    //int depht;
}nodeKd;

typedef struct Tree{
    Nodekd *first;
    Nodekd *last;
    int size;   
}KdTree;


Kd createKdTree(){
    KdTree* k = (KdTree*) malloc(sizeof(KdTree));
    k->first = NULL;
    k->last = NULL;
    k->size = 0;

    printf("ÁRVORE CRIADA!\n");

    return k;
}

// int getID(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->id;
// }

// double getX(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->x;
// }

// double getY(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->y;
// }

// double getH(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->h;
// }

// double getW(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->w;
// }


// double getX2(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->x2;
// }

// double getY2(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->y2;
// }

// char *getFill(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->fill;
// }

// char getBorder(Node n){
//     Nodekd *no = (Nodekd*)elemento;
//     return no->border;
// }

int length(Kd tree){
    KdTree* K = (KdTree*) tree;
    return K->size;
}


// Nodekd getRoot(Kd k){
   
// }

//Ver ENUM;

// COMPARAÇÃO ENTRE FLOAT

//(a-b) < epilson 
// epilson = 0.0000000001;

// eh_igual(A,B): |A - B| < epilson

void insert(Kd k, double x, double y, char tipo, int id, InfoK info){

    int depth = 1;
    
    //int id;

    double z;

    KdTree* K = (KdTree*) k;
    nodeKd* novo = (nodeKd*) malloc(sizeof(nodeKd));

    // circulo_t * test = (circulo_t*) info;
    // printf("Circulo T->x: %lf", test->x);

    switch(tipo){
        case 'c':
            tipo  = 1;
            break;
        
        case 'r':
            tipo = 2;
            break;

        case 'l':
            tipo = 3;
            break;  

        case 't':
            tipo = 4;
            break;       
    }

    novo->x = x;
    novo->y = y;
    novo->id = id;

    novo->info = info;

    printf("LOOK THAT!\n");
    //z = getXRect(novo->info);
    // printf("\n********* X = %lf", getXCircle(info));
    // printf("\n ********** Z = %lf", z);

    novo->tipo = tipo;

    //t = getXCircle(novo->info);

    printf("\n*****INSERT*****\n");
    //printf("\nX = %lf\n", t);
    
    // switch(tipo){
    //     if()
    // }

    if(K->first == NULL){
        novo->father == NULL;
        // novo->right = NULL;
        // novo->left = NULL;
        K->first = novo;

    }else{
        nodeKd* no = K->first;
        while(no != NULL){
            if(depth){
                if(depth % 2 != 0){ // valores ímpares para x 
                    if(novo->x > no->x){ // se x for maior que seu "pai" será inderido na direta
                        novo->father = no;
                        if(no->right == NULL){
                            no->right = novo;
                            break;
                        }
                        no = no->right;
                    }else if(novo->x < no->x){ // se x for menor que seu "pai" será inserido na esquerda
                        novo->father = no;
                        if(no->left == NULL){
                            no->left = novo;
                            break;
                        }
                        no = no->left;
                    }
                }else if(depth % 2 == 0){  // valores pares para y;
                    if(novo->y > no->y){
                        novo->father = no;
                        if(no->right == NULL){
                            no->right = novo;
                            break;
                        }
                        no = no->right;

                    }else if(novo->y < no->y){
                        novo->father = no;
                        if(no->left == NULL){
                            no->left = novo;
                            break;
                        }
                        no = no->left;
                    }
                }
            }
            depth = depth + 1;
        }
    }

  

   novo->right = NULL;
   novo->left = NULL;
   K->last = novo;
   K->size++;
   
}

int getTipo(Kd k){
    nodeKd* K = (nodeKd*) k;
    printf("K do getTipo: %d", K->tipo);
    return K->tipo;
}

int getId(Kd k){
    nodeKd* K = (nodeKd*) k;
    return K->id;
}

void printKdtreebyRoot(Kd k){
    KdTree* K = (KdTree*) k;
    printKdTree(K->first);
}

Nodekd searchKdTreebyRoot(Kd k, int id){
    KdTree* K = (KdTree*) k;
    return searchKdTree(K->first, id);
}


Nodekd searchKdTree(Kd k , int id){
    
    int tipo;

    double Z;
    
    nodeKd* no = (nodeKd*) k;

    //tipo = getTipo(no);
  
    
    

    if(no != NULL){

        tipo = getId(no);
        printf("ID do node: %d", tipo);
        Z = getXCircle(no->info);

        if(id == getId(no)){
            
           printf("\n!!!!!!!!! X: %lf !!!!!!!!!!\n", Z);
           return (no->info);          

        }

        printf("KKKKKKKKKKK");
        searchKdTree(no->left, id);            
        searchKdTree(no->right, id);
        
        
    }else{
        return NULL;
    }

    
}

void printKdTree(Kd k){

    int tipo;
    int id;
    double x;
    double y;
    double r;
    double w;
    double h;
    double x2;
    double y2;
    char fill[100];
    char border[100];
    char color[100];

    // KdTree* K = (KdTree*) k;
    nodeKd* no = (nodeKd*) k;

    printf("Entrou aqui\n");

    //x = 9999999.00;

    if(no != NULL){
        tipo = getTipo(no);
        printf("Tipo da figura: %d\n", tipo);
        if(tipo == 1 ){
            id = getCircleId(no->info);
            x = getXCircle(no->info);
            y = getYCircle(no->info);
            r = getRCircle(no->info);
            strcpy(fill, getFillCircle(no->info));
            strcpy(border, getBorderCircle(no->info));

            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", r);
            printf("ASSISTA JOJO\n");
            printf("%s\n", fill);
            printf("%s\n", border);
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

            printf("%d\n", id);
            printf("%lf\n", x);
            printf("%lf\n", y);
            printf("%lf\n", w);
            printf("%lf\n", h);
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
        
        printKdTree(no->left);
        printKdTree(no->right);
       
    }

    //printf("FIM x = %lf", x);
}





//https://www.geeksforgeeks.org/k-dimensional-tree/
//https://www.youtube.com/watch?v=VmKkAQtnjsM&ab_channel=Programa%C3%A7%C3%A3oDin%C3%A2mica
//https://www.youtube.com/watch?v=_0Yu9BSYXGY&ab_channel=Programa%C3%A7%C3%A3oDescomplicadaLinguagemC
//https://edisciplinas.usp.br/pluginfile.php/5639098/mod_resource/content/1/rec.pdf
//https://www.youtube.com/watch?v=_0Yu9BSYXGY&ab_channel=Programa%C3%A7%C3%A3oDescomplicadaLinguagemC