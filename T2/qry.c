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
void energyFigure(Kd k,int id, double v){

    double p1;
    double p2;
    double p3;
    double p4;

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

            // p1 = v / 3.0;
            // p2 = v / 3.0;
            // p3 = v / 3.0;

            //printf("P1:     %lf", p1);

            //figura->p1 = p1;

            //setP1Circle(p1, figura);
            // setP2Circle(p2, figura);
            // setP3Circle(p3, figura);

            // figura->p1 = v/3;
            // figura->p2 = v/3;
            // figura->p3 = v/3;

            x = getXCircle(figura);

            //p4 = getXCircle(figura);

            printf("P4:     %lf", x);
        }

        if(tipo == 2){

            p1 = v / 4;
            p2 = v / 4;
            p3 = v / 4;
            p4 = v / 4;

            // figura->p1 = v/4;
            // figura->p2 = v/4;
            // figura->p3 = v/4;
            // figura->p4 = v/4;
        }

        if(tipo == 3){

            p1 = v / 2;
            p2 = v / 2;

            
        }

        if(tipo == 4){
            
            p1 = v;
        }

    }

  if(id == 0){
      energyAllByTree(k, v);
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
    double p1;
    double p2;
    double p3;
    double p4;

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
    }  

    if(tipo == 2){

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

    }else if(tipo == 3){

        

    }else if(tipo == 4){

    }


}

void selectFigure(Kd k, double x, double y, double w, double h, List lista){

    // Seleciona figuras dentro do retangulo
    if(x != 0 && y != 00 && w != 0 && h != 0){

    }


    // Seleciona todas as figuras
    if(x == 0 && y == 0, && w == 0, && h == 0){

    }

}


void xFigure(Kd k, int id, double d){



    if(id != 0){

    }


    if(id == 0){

    }

}


