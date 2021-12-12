#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "qry.h"
#include "linha.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "kd-tree.h"
#include "lista.h"

// COMANDO EF - falta fazer demais figuras 
void energyFigure(Kd k,int id, double v){

    double v1;
    double v2;
    double v3;
    double v4;

    double x;

    int tipo;

    printf("ID energy: %d", id);

    //printf("V:      %lf\n", v);

    tipo = getType(k,id);

    printf("getType: %d\n", tipo);

    //setP1ByRoot(k, id, v);

   // void *figura = searchKdTreebyRoot(k, id);

    void *figura = searchKdTreebyRoot(k, id);    

    //setIdCircle(id, figura);

    //printf("FIGURA: %d", figura);

    // Caso ID seja diferente de * comando 
    if(id != 0){


        if(tipo == 1){

            printf("\n ENTROU TIPO 1 \n");

            v1 = v / 3.0;
            v2 = v / 3.0;
            v3 = v / 3.0;

            setV1Circle(v1, figura);
            setV2Circle(v2, figura);
            setV3Circle(v3, figura);

       }

        if(tipo == 2){

            v1 = v / 4.0;
            v2 = v / 4.0;
            v3 = v / 4.0;
            v4 = v / 4.0;

            setV1Rect(v1, figura);
            setV2Rect(v2, figura);
            setV3Rect(v3, figura);
            setV4Rect(v4, figura);
        }

        if(tipo == 3){

            v1 = v / 2.0;
            v2 = v / 2.0;

            setV1Linha(v1, figura);
            setV2Linha(v2, figura);            
        }

        if(tipo == 4){
            
            v1 = v;

            setV1Text(v1, figura);
        }

    }

  if(id == 0){
      printf("\n!!DANGER !!\n");
      energyAllByTree(k, v);
  }

   

}



// COMANDO SF  * FALTA VER POR REGIÃO

List selectFigure(Kd k, double px, double py, double pw, double ph, List l, char* qryTxt){

    double x;
    double y;
    double xh;
    double yw;

    double r;
    double rt;
    double rl;
    double rb;
    double rr;

    double x1;
    double y1;

   
    double x2;
    double y2;

    // Seleciona figuras dentro do retangulo
    if(px != 0 && py != 00 && pw != 0 && ph != 0){

    }


    // Seleciona todas as figuras
    if(px == 0 && py == 0 && pw == 0 && ph == 0){
        courseKdTreeByRoot(k, l, qryTxt);

        //printf("\nSAIDA SF\n");
        //printList(l);

        return l;
    }

}

void reportFigure(Kd k, int id, char* qryTxt){

    int tipo;
    // int id;
    double x;
    double y;
    double r;
    double w;
    double h;
    double x2;
    double y2;
    char fill[100];
    char border[100];

    double p1_x;
    double p1_y;

    double p2_x;
    double p2_y;

    double p3_x;
    double p3_y;

    double p4_x;
    double p4_y;

    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    //Nodekd* nodeK = (Nodekd*) k;

    tipo = getType(k,id);

    void *figura = searchKdTreebyRoot(k, id);    

    //printf("REPORT FIGURE ID: %d", tipo);

    if(tipo == 1){

        //printf("REPORTA FIGURA\n");

        x = getXCircle(figura);
        y = getYCircle(figura);
        r = getRCircle(figura);
        strcpy(fill, getFillCircle(figura));
        strcpy(border, getBorderCircle(figura));

        p1_x = getP1_X_Circle(figura);
        p2_x = getP2_X_Circle(figura);
        p3_x = getP3_X_Circle(figura);

        // Sem pontos de fixação
        if(p1_x == 0.0 && p2_x == 0.0 && p3_x == 0.0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
        }else{           

            fprintf(saidaTxt, "%d %lf %lf %lf %s %s %lf %lf %lf", id, r, x, y, border, fill, p1_x, p2_x, p3_x);
        }

        //fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
    }  

    if(tipo == 2){

        x = getXRect(figura);
        y = getYRect(figura);
        w = getWidthRect(figura);
        h = getHeightRect(figura);
        strcpy(fill, getFillRect(figura));
        strcpy(border, getBorderRect(figura));

        // p1 = getP1Rect(figura);
        // p2 = getP2Rect(figura);
        // p3 = getP3Rect(figura);

        // // Sem pontos de fixação
        // if(p1 == 0 && p2 == 0 && p3 == 0){
        //     fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, fill, border);
        // }else{

        //     fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %s %lf %lf %lf", id, w, h, x, y, fill, border, p1, p2, p3);            
        // }

    }else if(tipo == 3){

        

    }else if(tipo == 4){

    }


}

// COMANDO EP



// void xFigure(Kd k, int id, double d){



//     if(id != 0){

//     }


//     if(id == 0){

//     }

// }



// reportFigureRegion(Kd k,int id,char* txtQry, double x, double y, double w, double h){

// }


