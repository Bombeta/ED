#include <stdio.h>
#include <stdlib.h>
#include "kd-tree.h"
#include "circulo.h"
#include "ret.h"
#include "linha.h"
#include "texto.h"
#include "lista.h"

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

    //printf("ÁRVORE CRIADA!\n");

    return k;
}


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

    //printf("LOOK THAT!\n");
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

// Pega o tipo pela struct
int getTipo(Kd k){
    nodeKd* K = (nodeKd*) k;
    //printf("K do getTipo: %d", K->tipo);
    return K->tipo;
}
// Pega Id pela struct
int getId(Kd k){
    nodeKd* K = (nodeKd*) k;
    return K->id;
}

// int getIdInfo(Kd k){

// }

void energyAllByTree(Kd k, double v){
    KdTree* K = (KdTree*) k;
    energyAll(K->first, v);
}

void energyAll(Kd k, double v){
    
    int id;
    int tipo;
    double v1;
    double v2;
    double v3;
    double v4;
    
    nodeKd* no = (nodeKd*) k;
    
    //id = getId(no);
    

    if(no!= NULL){
        //id = getId(no);
        tipo = getTipo(no);


        //printf("GET ID: %d\n", id);
        printf("GET TYPE: %d\n", tipo);

        if(tipo == 1){

            v1 = v/3;
            v2 = v/3;
            v3 = v/3;

            //printf("\n JOLYNE CUJOH\n ");   

            setV1Circle(v1, no->info);
            setV2Circle(v2, no->info);
            setV3Circle(v3, no->info);

            //printf("V: %lf", v);

            printf("\nv1: %lf\n", v1);

            //setEnergyCircle(v, no->info);         
        }
        if(tipo == 2){

            v1 = v / 4;
            v2 = v / 4;
            v3 = v / 4;
            v4 = v / 4;

            //setEnergyRect(v, no->info);
            setV1Rect(v1, no->info);
            setV2Rect(v2, no->info);
            setV3Rect(v3, no->info);
            setV4Rect(v4, no->info);

            printf("V1: %lf", v1);
            printf("V2: %lf", v2);
            printf("V3: %lf", v3);
            printf("V4: %lf", v4);

        }
        if(tipo == 3){
            
            v1 = v / 2;
            v2 = v / 2;

            setV1Linha(v1, no->info);
            setV2Linha(v2, no->info);
        }

        if(tipo == 4){

            v1 = v;

            setV1Text(v1, no->info);
        }

        energyAll(no->left, v);            
        energyAll(no->right, v);

    }
}

void xAllByTree(Kd k, double v){
    KdTree* K = (KdTree*) k;
    xAll(K->first, v);
}

void xAll(Kd k, double v){

    int id;
    int tipo;
    double v1;
    double v2;
    double v3;
    double v4;
    
    nodeKd* no = (nodeKd*) k;
    
    //id = getId(no);
    

    if(no!= NULL){
        //id = getId(no);
        tipo = getTipo(no);


        //printf("GET ID: %d\n", id);
        //printf("GET TYPE: %d\n", tipo);

        if(tipo == 1){

            v1 = getV1Circle(no->info);
            v2 = getV2Circle(no->info);
            v3 = getV3Circle(no->info);

            v1 = v1 + v;
            v2 = v2 + v;
            v3 = v3 + v;

            setV1Circle(v1, no->info);
            setV2Circle(v2, no->info);
            setV3Circle(v3, no->info);
              
        }
        if(tipo == 2){

            v1 = getV1Rect(no->info);
            v2 = getV2Rect(no->info);
            v3 = getV3Rect(no->info);
            v4 = getV4Rect(no->info);

            v1 = v1 + v;
            v2 = v2 + v;
            v3 = v3 + v;
            v4 = v4 + v;
            //setEnergyRect(v, no->info);
            setV1Rect(v1, no->info);
            setV2Rect(v2, no->info);
            setV3Rect(v3, no->info);
            setV4Rect(v4, no->info);
        }
        if(tipo == 3){

            v1 = getV1Linha(no->info);
            v2 = getV2Linha(no->info);
            
            v1 = v1 + v;
            v2 = v2 + v;

            setV1Linha(v1, no->info);
            setV2Linha(v2, no->info);
        }

        if(tipo == 4){

            v1 = getV1Text( no->info);
            
            v1 = v1 + v;

            setV1Text(v1, no->info);
        }

        xAll(no->left, v);            
        xAll(no->right, v);

    }

}

void courseKdTreeByRoot(Kd k, List l, char* qryTxt){
    KdTree* K = (KdTree*) k;
    courseKdtree(K->first, l, qryTxt);
}

void courseKdtree(Kd k, List l, char* qryTxt){
    
    int tipo;
    int id;

    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    nodeKd* no = (nodeKd*) k;

    if(no!= NULL){

        tipo = getTipo(no);

        if(tipo == 1){
            id = getCircleId(no->info);
        }

        if(tipo == 2){
            id = getRectId(no->info);
        }

        if(tipo == 3){
            id = getIdLinha(no->info);
        }

        if(tipo == 4){
            id = getTextId(no->info);
        }

        fprintf(saidaTxt, "%d\n", id);
        
        courseKdtree(no->left, l, qryTxt);            
        courseKdtree(no->right, l, qryTxt);
    }     
}

void printKdtreebyRoot(Kd k){
    KdTree* K = (KdTree*) k;
    printKdTree(K->first);
}

Nodekd getType(Kd k, int id){
    KdTree* K = (KdTree*) k;
    return searchTypeKdtree(K->first, id);
}


int searchTypeKdtree(Kd k, int id){
    
    int tipo;

    nodeKd* no = (nodeKd*) k;

    if(no!= NULL){
        
        if(id == getId(no)){
            tipo = getTipo(no);

            return tipo;
        }
    }

}

Nodekd searchKdTreebyRoot(Kd k, int id){
    KdTree* K = (KdTree*) k;
    return searchKdTree(K->first, id);
}

Nodekd searchKdTree(Kd k , int id){
    
    int tipo;
    double p1;

    //double Z;
    
    nodeKd* no = (nodeKd*) k;

    if(no != NULL){

        //tipo = getId(no);
        //printf("ID do node: %d", tipo);
        //Z = getXCircle(no->info);

        if(id == getId(no)){
            
           //printf("\n!!!!!!!!! X: %lf !!!!!!!!!!\n", Z);
           //setP1Circle(100.00, no->info);  
           return (no->info);          

        }

        //printf("KKKKKKKKKKK");
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

    // KdTree* K = (KdTree*) k;
    nodeKd* no = (nodeKd*) k;

    //printf("Entrou aqui\n");

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
        
        printKdTree(no->left);
        printKdTree(no->right);
       
    }

    //printf("FIM x = %lf", x);
}


void drawExitbyRoot(Kd k, char* svgQry){
    KdTree* K = (KdTree*) k;
    drawExit(K->first, svgQry);
}

void drawExit(Kd k, char* svgQry){

    nodeKd* no = (nodeKd*) k;

    int tipo;
    int id;
    int amountPoints;
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
    double P4_X;
    double P4_Y;
    double x2;
    double y2;
    double x1;
    double y1;
    double v1;
    double v2;
    double v3;
    double v4;
    char fill[100];
    char border[100];
    char color[100];
    char texto[100];

    if(no!=NULL){
        tipo = getTipo(no);
        
        printf("\nTIPO SAIDA QRY\n: %d", tipo);

        if(tipo == 1){
            id = getCircleId(no->info);
            x = getXCircle(no->info);
            y = getYCircle(no->info);
            r = getRCircle(no->info);
            strcpy(fill, getFillCircle(no->info));
            strcpy(border, getBorderCircle(no->info));
            P1_X = getP1_X_Circle(no->info);
            P2_X = getP2_X_Circle(no->info);
            P3_X = getP3_X_Circle(no->info);
            P1_Y = getP1_Y_Circle(no->info);
            P2_Y = getP2_Y_Circle(no->info);
            P3_Y = getP3_Y_Circle(no->info);
            v1 = getV1Circle(no->info);
            v2 = getV2Circle(no->info);
            v3 = getV3Circle(no->info);

            amountPoints = 0;

            desenha_Circulo(svgQry, r, x, y, fill, border);

            if(v1 > 0){
                amountPoints++;
            }

            if(v2 > 0){
                amountPoints++;
            }

            if(v3 > 0){
                amountPoints++;
            }

            if(amountPoints == 0){
                desenha_Circulo(svgQry, 1.0, P1_X, P1_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P2_X, P2_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P3_X, P3_Y, "#d3d3d3", "#d3d3d3");
                
            }else if(amountPoints == 1){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 2.0, P1_X, P1_Y, "#FF00FF", "#FF00FF");
                }
                if(v2 > 0){
                    desenha_Circulo(svgQry, 2.0, P2_X, P2_Y, "#FF00FF", "#FF00FF");
                }
                if(v3 > 0){
                    desenha_Circulo(svgQry, 2.0, P3_X, P3_Y, "#FF00FF", "#FF00FF");
                }
                
            }else if(amountPoints == 2){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 3.0, P1_X, P1_Y, "#008080", "#008080");
                }
                if(v2 > 0){
                    desenha_Circulo(svgQry, 3.0, P2_X, P2_Y, "#008080", "#008080");
                }
                if(v3 > 0){
                    desenha_Circulo(svgQry, 3.0, P3_X, P3_Y, "#008080", "#008080");
                }
            }else if(amountPoints == 3){
                desenha_Circulo(svgQry, 4.0, P1_X, P1_Y, "#FF0000", "#FF0000");
                desenha_Circulo(svgQry, 4.0, P2_X, P2_Y, "#FF0000", "#FF0000");
                desenha_Circulo(svgQry, 4.0, P3_X, P3_Y, "#FF0000", "#FF0000");
            }


       
        }

        if(tipo == 2){
            id = getRectId(no->info);
            x = getXRect(no->info);
            y = getYRect(no->info);
            w = getWidthRect(no->info);
            h = getHeightRect(no->info);
            strcpy(fill,getFillRect(no->info));
            strcpy(border,getBorderRect(no->info));

            P1_X = getP1_X_Rect(no->info);
            P2_X = getP2_X_Rect(no->info);
            P3_X = getP3_X_Rect(no->info);
            P4_X = getP4_X_Rect(no->info);
            P1_Y = getP1_Y_Rect(no->info);
            P2_Y = getP2_Y_Rect(no->info);
            P3_Y = getP3_Y_Rect(no->info);
            P4_Y = getP4_Y_Rect(no->info);

            v1 = getV1Rect(no->info);
            v2 = getV2Rect(no->info);
            v3 = getV3Rect(no->info);
            v4 = getV4Rect(no->info);

            amountPoints = 0;

            desenha_Retangulo(svgQry, w, h, x, y, fill, border);

            if(v1 > 0){
                amountPoints++;
            }

            if(v2 > 0){
                amountPoints++;
            }

            if(v3 > 0){
                amountPoints++;
            }

            if(v4 > 0){
                amountPoints++;
            }

            if(amountPoints == 0){
                desenha_Circulo(svgQry, 1.0, P1_X, P1_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P2_X, P2_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P3_X, P3_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P4_X, P4_Y, "#d3d3d3", "#d3d3d3");
                // desenha_Circulo(svgQry. 1.0, P4_X, P4_Y, "#d3d3d3", "#d3d3d3");            
            }else if(amountPoints == 1){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 2.0, P1_X, P1_Y, "#FF00FF", "#FF00FF");
                }
                if(v2 > 0){
                    desenha_Circulo(svgQry, 2.0, P2_X, P2_Y, "#FF00FF", "#FF00FF");
                }
                if(v3 > 0){
                    desenha_Circulo(svgQry, 2.0, P3_X, P3_Y, "#FF00FF", "#FF00FF");
                }
                if(v4 > 0){
                    desenha_Circulo(svgQry, 2.0, P4_X, P4_Y, "#FF00FF", "#FF00FF");
                }
                
            }else if(amountPoints == 2){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 3.0, P1_X, P1_Y, "#008080", "#008080");
                }
                if(v2 > 0){
                    desenha_Circulo(svgQry, 3.0, P2_X, P2_Y, "#008080", "#008080");
                }
                if(v3 > 0){
                    desenha_Circulo(svgQry, 3.0, P3_X, P3_Y, "#008080", "#008080");
                }
                if(v4 > 0){
                    desenha_Circulo(svgQry, 3.0, P4_X, P4_Y, "#008080", "#008080");
                }
            }else if(amountPoints == 3){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 4.0, P1_X, P1_Y, "#FF0000", "#FF0000");
                }

                if(v2 > 0){
                    desenha_Circulo(svgQry, 4.0, P2_X, P2_Y, "#FF0000", "#FF0000");
                }

                if(v3 > 0){
                    desenha_Circulo(svgQry, 4.0, P3_X, P3_Y, "#FF0000", "#FF0000");
                } 

                if(v4 > 0){
                    desenha_Circulo(svgQry, 4.0, P4_X, P4_Y, "#008080", "#008080");
                }             
                
                
            }else if(amountPoints == 4){
                desenha_Circulo(svgQry, 4.0, P1_X, P1_Y, "#FF0000", "#FF0000");
                desenha_Circulo(svgQry, 4.0, P2_X, P2_Y, "#FF0000", "#FF0000");
                desenha_Circulo(svgQry, 4.0, P3_X, P3_Y, "#FF0000", "#FF0000");
                desenha_Circulo(svgQry, 4.0, P4_X, P4_Y, "#FF0000", "#FF0000");
            }

          
        }

        if(tipo == 3){

            id = getIdLinha(no->info);
            x = getX1Linha(no->info);
            y = getY1Linha(no->info);
            x2 = getX2Linha(no->info);
            y2 = getY2Linha(no->info);
            
            strcpy(color, getColorLinha(no->info));

            P1_X = getP1_X_Linha(no->info);
            P2_X = getP2_X_Linha(no->info);
            P1_Y = getP1_Y_Linha(no->info);
            P2_Y = getP2_Y_Linha(no->info);

            v1 = getV1Linha(no->info);
            v2 = getV2Linha(no->info);

            amountPoints = 0;

            desenha_Linha(svgQry, x1, y1, x2, y2, color);

            
            if(v1 > 0){
                amountPoints++;
            }

            if(v2 > 0){
                amountPoints++;
            }

            if(amountPoints == 0){
                desenha_Circulo(svgQry, 1.0, P1_X, P1_Y, "#d3d3d3", "#d3d3d3");
                desenha_Circulo(svgQry, 1.0, P2_X, P2_Y, "#d3d3d3", "#d3d3d3");
            }else if(amountPoints == 1){
                
                if(v1 > 0){
                    desenha_Circulo(svgQry, 2.0, P1_X, P1_Y, "#FF00FF", "#FF00FF");
                }

                if(v2 > 0){
                    desenha_Circulo(svgQry, 2.0, P2_X, P2_Y, "#FF00FF", "#FF00FF");
                }

            }else if(amountPoints == 2){
                if(v1 > 0){
                    desenha_Circulo(svgQry, 3.0, P1_X, P1_Y, "#008080", "#008080");
                }

                if(v2 > 0){
                    desenha_Circulo(svgQry, 3.0, P2_X, P2_Y, "#008080", "#008080");
                }
            }



        }

        if(tipo == 4){

            id = getTextId(no->info);
            x = getXText(no->info);
            y = getYText(no->info);
            strcpy(fill, getFillText(no->info));
            strcpy(border, getBorderText(no->info));
            strcpy(texto, getText(no->info));

            P1_X = getP1_X_Text(no->info);
            P1_Y = getP1_Y_Text(no->info);

            v1 = getV1Text(no->info);

            amountPoints = 0;

            desenha_Texto(svgQry, x, y, fill, border, texto);

            if(v1 > 0){
                amountPoints++;
            }

            if(amountPoints == 0){
                desenha_Circulo(svgQry, 1.0, P1_X, P1_Y, "#d3d3d3", "#d3d3d3");
            }else if(amountPoints == 1){
                desenha_Circulo(svgQry, 2.0, P1_X, P1_Y, "#FF00FF", "#FF00FF");
            }
            
        }
        
        drawExit(no->left, svgQry);
        drawExit(no->right, svgQry);

    }
    
}


