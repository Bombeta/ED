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

// Energy para todas as figuras
// energyFigure(Kd k, double v){

//     Kd *pilha;
//     int t;

   

// }

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
    double p1;
    double p2;
    double p3;
    double p4;

    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    //Nodekd* nodeK = (Nodekd*) k;

    void *figura = searchKdTreebyRoot(k, id);

    //tipo = getTipo(figura);

    //printf("REPORT FIGURE ID: %d", tipo);

    

        printf("REPORTA FIGURA\n");

        x = getXCircle(figura);
        y = getYCircle(figura);
        r = getRCircle(figura);
        strcpy(fill, getFillCircle(figura));
        strcpy(border, getBorderCircle(figura));

        p1 = getP1Circle(figura);
        p2 = getP2Circle(figura);
        p3 = getP3Circle(figura);

        // Sem pontos de fixação
        if(p1 == 0.0 && p2 == 0.0 && p3 == 0.0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
        }else{           

            fprintf(saidaTxt, "%d %lf %lf %lf %s %s %lf %lf %lf", id, r, x, y, border, fill, p1, p2, p3);
        }

        //fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
        

    if(figura == 2){

        x = getXRect(figura);
        y = getYRect(figura);
        w = getWidthRect(figura);
        h = getHeightRect(figura);
        strcpy(fill, getFillRect(figura));
        strcpy(border, getBorderRect(figura));

        p1 = getP1Rect(figura);
        p2 = getP2Rect(figura);
        p3 = getP3Rect(figura);

        // Sem pontos de fixação
        if(p1 == 0 && p2 == 0 && p3 == 0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, fill, border);
        }else{

            fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %s %lf %lf %lf", id, w, h, x, y, fill, border, p1, p2, p3);            
        }

    }else if(figura == 3){

    }else if(figura == 4){

    }


}


