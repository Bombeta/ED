#include <stdio.h>
#include <stdlib.h>
#include "kd-tree.h"

enum figuras{c = 1, r = 2, l = 3, t = 4};

typedef struct node{
    double x;
    double y;
    int tipo;
    InfoK info;
    struct node *left;
    struct node *right;
    struct node *leaf;
    //int depht;
}Nodekd;

typedef struct kdTree{
    Nodekd *root;
    int size;   
}KdTree;


Kd createKdTree(){
    KdTree* k = (KdTree*) malloc(sizeof(KdTree));
    k->root = NULL;
    k->size = 0;

    printf("ÁRVORE CRIADA!\n");

    return k;
}

int length(Kd tree){
    KdTree* K = (KdTree*) tree;
    return K->size;
}

//Ver ENUM;

// COMPARAÇÃO ENTRE FLOAT

//(a-b) < epilson 
// epilson = 0.0000000001;

// eh_igual(A,B): |A - B| < epilson

void insert(Kd k, double x, double y, char tipo, InfoK info){

    int depth = 1;

    KdTree* K = (KdTree*) k;
    Nodekd* novo = (Nodekd*) malloc(sizeof(Nodekd));

    novo->x = x;
    novo->y = y;    
    novo->info = info;

    // switch(tipo){
    //     if()
    // }

    if(K->root == NULL){
        novo->leaf == NULL;
        K->root = novo;
    }else{
        Nodekd* no = K->root;
        while(no != NULL){
            if(depth % 2 != 0){ // valores ímpares para x 
                if(novo->x > no->x){ // se x for maior que seu "pai" será inderido na direta
                    novo->leaf = no;
                    if(no->right == NULL){
                        no->right = novo;
                        break;
                    }
                    no = no->right;
                }else if(novo->x < no->x){ // se x for menor que seu "pai" será inserido na esquerda
                    novo->leaf = no;
                    if(no->left == NULL){
                        no->left = novo;
                        break;
                    }
                    no = no->left;
                }
            }else if(depth % 2 == 0){  // valores pares para y;
                if(novo->y > no->y){
                    novo->leaf = no;
                    if(no->right == NULL){
                        no->right = novo;
                        break;
                    }
                    no = no->right;

                }else if(novo->y < no->y){
                    novo->leaf = no;
                    if(no->left == NULL){
                        no->left = novo;
                        break;
                    }
                    no = no->left;
                }
            }

            depth = depth + 1;
        }
    }

   novo->right;
   novo->left;
   K->size++;
   
}

//https://www.geeksforgeeks.org/k-dimensional-tree/