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

// COMANDO EF
void energyFigure(Kd k,int id, double v){

    double v1;
    double v2;
    double v3;
    double v4;

    double x;

    int tipo;

    printf("ID energy: %d", id);

    tipo = getType(k,id);   

    void *figura = searchKdTreebyRoot(k, id);    

      // Caso ID seja diferente de * comando 
    if(id != 0){


        if(tipo == 1){

            //printf("\n ENTROU TIPO 1 \n");

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
// COMANDO Q?

void reportFigure(Kd k, int id, char* qryTxt){

    int tipo;
    double x;
    double y;
    double r;
    double w;
    double h;
    double x1;
    double y1;
    double x2;
    double y2;
    char fill[100];
    char border[100];
    char texto[100];
    char color[100];

    double p1_x;
    double p1_y;

    double p2_x;
    double p2_y;

    double p3_x;
    double p3_y;

    double p4_x;
    double p4_y;

    double v1;
    double v2;
    double v3;

    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    //Nodekd* nodeK = (Nodekd*) k;

    tipo = getType(k,id);

    void *figura = searchKdTreebyRoot(k, id);    

    //printf("REPORT FIGURE ID: %d", tipo);

    if(tipo == 1){

        //printf("REPORTA FIGURA\n");
        id = getCircleId(figura);
        x = getXCircle(figura);
        y = getYCircle(figura);
        r = getRCircle(figura);
        strcpy(fill, getFillCircle(figura));
        strcpy(border, getBorderCircle(figura));

        p1_x = getP1_X_Circle(figura);
        p2_x = getP2_X_Circle(figura);
        p3_x = getP3_X_Circle(figura);

        p1_y = getP1_Y_Circle(figura);
        p2_y = getP2_Y_Circle(figura);
        p3_y = getP3_Y_Circle(figura);

        v1 = getV1Circle(figura);
        v2 = getV2Circle(figura);
        v3 = getV3Circle(figura);

        // Sem pontos de fixação
        if(p1_x == 0.0 && p2_x == 0.0 && p3_x == 0.0 && p1_y == 0 && p2_y == 0 && p3_y == 0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
        }else{           

            fprintf(saidaTxt, "%d %lf %lf %lf %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf", id, r, x, y, border, fill, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, v1, v2, v3);
        }

        //fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
    }  

    if(tipo == 2){
        
        id = getRectId(figura);
        x = getXRect(figura);
        y = getYRect(figura);
        w = getWidthRect(figura);
        h = getHeightRect(figura);
        strcpy(fill, getFillRect(figura));
        strcpy(border, getBorderRect(figura));

        p1_x = getP1_X_Rect(figura);
        p2_x = getP2_X_Rect(figura);
        p3_x = getP3_X_Rect(figura);
        p4_x = getP4_X_Rect(figura);

        p1_y = getP1_Y_Rect(figura);
        p2_y = getP2_Y_Rect(figura);
        p3_y = getP3_Y_Rect(figura);
        p4_y = getP4_Y_Rect(figura);

        // Sem pontos de fixação
        if(p1_x == 0.0 && p2_x == 0.0 && p3_x == 0.0 && p1_y == 0 && p2_y == 0 && p3_y == 0 && p4_x == 0 && p4_y == 0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, fill, border);
        }else{

            fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", id, w, h, x, y, fill, border, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y, v1, v2, v3);            
        }

    }else if(tipo == 3){

        id = getIdLinha(figura);
        x1 = getX1Linha(figura);
        y1 = getY1Linha(figura);
        x2 = getX2Linha(figura);
        y2 = getY2Linha(figura);
        strcpy(color, getColorLinha(figura));

        p1_x = getP1_X_Linha(figura);
        p2_x = getP2_X_Linha(figura);

        p1_y = getP1_Y_Linha(figura);
        p2_y = getP2_Y_Linha(figura);

        if(p1_x == 0 && p2_x ==0 && p1_y == 0 && p2_y == 0){
            fprintf(saidaTxt, "%d %lf %lf %lf %lf %s",id, x1, y1, x2, y2, color);
        }else{
            fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %lf %lf %lf %lf %lf %lf", id, x1, y1, x2, y2, color, p1_x, p1_y, p2_x, p2_y, v1, v2);
        }


    }else if(tipo == 4){
        
        id = getTextId(figura);
        x = getXText(figura);
        y = getYText(figura);
        strcpy(fill,getFillText(figura));
        strcpy(border, getBorderText(figura));
        strcpy(texto, getText(figura));
       
        p1_x = getP1_X_Text(figura);
        p1_y = getP1_Y_Text(figura);

        v1 = getV1Text(figura);

        if(p1_x == 0 && p1_y == 0){
            fprintf(saidaTxt, "%d %lf %lf %s %s %s", id, x, y, fill, border, texto);
        }else{
            fprintf(saidaTxt, "%d %lf %lf %s %s %s %lf %lf %lf %lf", id, x, y, fill, border, texto, p1_x, p1_y, v1);
        }
    }


}

// COMANDO XF

void xFigure(Kd k, int id, double v){

    int tipo;

    double v1;
    double v2;
    double v3;
    double v4;

    void *figura = searchKdTreebyRoot(k, id);    

    tipo = getType(k,id);

    if(id != 0){

        if(tipo == 1){
            v1 = getV1Circle(figura);
            v2 = getV2Circle(figura);
            v3 = getV3Circle(figura);

            v1 = v1 + v;
            v2 = v2 + v;
            v3 = v3 + v;

            setV1Circle(v1, figura);
            setV2Circle(v2, figura);
            setV3Circle(v3, figura);
        }

        if(tipo == 2){
            v1 = getV1Rect(figura);
            v2 = getV2Rect(figura);
            v3 = getV3Rect(figura);
            v4 = getV4Rect(figura);

            v1 = v1 + v;
            v2 = v2 + v;
            v3 = v3 + v;
            v4 = v4 + v;

            setV1Rect(v1, figura);
            setV2Rect(v2, figura);
            setV3Rect(v3, figura);
            setV4Rect(v4, figura);

        }

        if(tipo == 3){
            v1 = getV1Linha(figura);
            v2 = getV2Linha(figura);

            v1 = v1 + v;
            v2 = v2 + v;

            setV1Linha(v1, figura);
            setV2Linha(v2, figura);
           
        }

        if(tipo == 4){
            v1 = getV1Text(figura);

            v1 = v1 + v;

            setV1Text(v1, figura);
        }
    }

    if(id == 0){
        xAllByTree(k, v);
    }

}



void reportFigureRegion(Kd k,int id,char* txtQry, double x, double y, double w, double h){
    
    int tipo;
    //int id;
    //double x;
    //double y;
    double r;
    //double w;
    //double h;
    double x1;
    double y1;
    double x2;
    double y2;
    char fill[100];
    char border[100];
    char texto[100];
    char color[100];
    
    double p1_x;
    double p1_y;

    double p2_x;
    double p2_y;

    double p3_x;
    double p3_y;

    double p4_x;
    double p4_y;

    double v1;
    double v2;
    double v3;
    
    int pointTrue = 0;

    FILE * saidaTxt;

    saidaTxt = fopen(txtQry, "a+");

    void *figura = searchKdTreebyRoot(k, id);

    tipo = getType(k,id);

     if(tipo == 1){

        p1_x = getP1_X_Circle(figura);
        p2_x = getP2_X_Circle(figura);
        p3_x = getP3_X_Circle(figura);
        p4_x = getP4_X_Circle(figura);

        p1_y = getP1_Y_Circle(figura);
        p2_y = getP2_Y_Circle(figura);
        p3_y = getP3_Y_Circle(figura);
        p4_y = getP4_Y_Circle(figura);

        int PontoInternoRet(double p1_x, double p1_y, double x, double y, double h, double w, int pointTrue){
        if (p1_x > x && p1_y >y && p1_x < (x+w) && p1_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p2_x, double p2_y, double x, double y, double h, double w, int pointTrue){
        if (p2_x > x && p2_y >y && p2_x < (x+w) && p2_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p3_x, double p3_y, double x, double y, double h, double w, int pointTrue){
        if (p3_x > x && p3_y >y && p3_x < (x+w) && p3_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p4_x, double p4_y, double x, double y, double h, double w, int pointTrue){
        if (p4_x > x && p4_y >y && p4_x < (x+w) && p4_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }


        if(pointTrue == 4){

            //printf("REPORTA FIGURA\n");
            id = getCircleId(figura);
            x = getXCircle(figura);
            y = getYCircle(figura);
            r = getRCircle(figura);
            strcpy(fill, getFillCircle(figura));
            strcpy(border, getBorderCircle(figura));


            v1 = getV1Circle(figura);
            v2 = getV2Circle(figura);
            v3 = getV3Circle(figura);

            // Sem pontos de fixação
            if(p1_x == 0.0 && p2_x == 0.0 && p3_x == 0.0 && p1_y == 0 && p2_y == 0 && p3_y == 0){
                fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, border, fill);
            }else{           

                fprintf(saidaTxt, "%d %lf %lf %lf %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf", id, r, x, y, border, fill, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, v1, v2, v3);
            }

        }

        
    }  

    if(tipo == 2){

        p1_x = getP1_X_Rect(figura);
        p2_x = getP2_X_Rect(figura);
        p3_x = getP3_X_Rect(figura);
        p4_x = getP4_X_Rect(figura);

        p1_y = getP1_Y_Rect(figura);
        p2_y = getP2_Y_Rect(figura);
        p3_y = getP3_Y_Rect(figura);
        p4_y = getP4_Y_Rect(figura);

        int PontoInternoRet(double p1_x, double p1_y, double x, double y, double h, double w, int pointTrue){
        if (p1_x > x && p1_y >y && p1_x < (x+w) && p1_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p2_x, double p2_y, double x, double y, double h, double w, int pointTrue){
        if (p2_x > x && p2_y >y && p2_x < (x+w) && p2_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p3_x, double p3_y, double x, double y, double h, double w, int pointTrue){
        if (p3_x > x && p3_y >y && p3_x < (x+w) && p3_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p4_x, double p4_y, double x, double y, double h, double w, int pointTrue){
        if (p4_x > x && p4_y >y && p4_x < (x+w) && p4_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        if(pointTrue == 4){
        
        id = getRectId(figura);
        x = getXRect(figura);
        y = getYRect(figura);
        w = getWidthRect(figura);
        h = getHeightRect(figura);
        strcpy(fill, getFillRect(figura));
        strcpy(border, getBorderRect(figura));

        

        // Sem pontos de fixação
        if(p1_x == 0.0 && p2_x == 0.0 && p3_x == 0.0 && p1_y == 0 && p2_y == 0 && p3_y == 0 && p4_x == 0 && p4_y == 0){
            fprintf(saidaTxt, "%d %lf %lf %lf %s %s", id, r, x, y, fill, border);
        }else{

            fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", id, w, h, x, y, fill, border, p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, p4_x, p4_y, v1, v2, v3);            
        }


    }


    }else if(tipo == 3){

        p1_x = getP1_X_Linha(figura);
        p2_x = getP2_X_Linha(figura);

        p1_y = getP1_Y_Linha(figura);
        p2_y = getP2_Y_Linha(figura);

        int PontoInternoRet(double p1_x, double p1_y, double x, double y, double h, double w, int pointTrue){
        if (p1_x > x && p1_y >y && p1_x < (x+w) && p1_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        int PontoInternoRet(double p2_x, double p2_y, double x, double y, double h, double w, int pointTrue){
        if (p2_x > x && p2_y >y && p2_x < (x+w) && p2_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        if(pointTrue == 2){

            id = getIdLinha(figura);
            x1 = getX1Linha(figura);
            y1 = getY1Linha(figura);
            x2 = getX2Linha(figura);
            y2 = getY2Linha(figura);
            strcpy(color, getColorLinha(figura));

   

            if(p1_x == 0 && p2_x ==0 && p1_y == 0 && p2_y == 0){
                fprintf(saidaTxt, "%d %lf %lf %lf %lf %s",id, x1, y1, x2, y2, color);
            }else{
                fprintf(saidaTxt, "%d %lf %lf %lf %lf %s %lf %lf %lf %lf %lf %lf", id, x1, y1, x2, y2, color, p1_x, p1_y, p2_x, p2_y, v1, v2);
            }
        }



    }else if(tipo == 4){

        p1_x = getP1_X_Text(figura);
        p1_y = getP1_Y_Text(figura);

        int PontoInternoRet(double p1_x, double p1_y, double x, double y, double h, double w, int pointTrue){
        if (p1_x > x && p1_y >y && p1_x < (x+w) && p1_y < (y+h)){
                pointTrue++;
                return pointTrue;
            }
            else{
                return pointTrue;
            }
        }

        if(pointTrue == 1){
            id = getTextId(figura);
            x = getXText(figura);
            y = getYText(figura);
            strcpy(fill,getFillText(figura));
            strcpy(border, getBorderText(figura));
            strcpy(texto, getText(figura));
        
        

            v1 = getV1Text(figura);

            if(p1_x == 0 && p1_y == 0){
                fprintf(saidaTxt, "%d %lf %lf %s %s %s", id, x, y, fill, border, texto);
            }else{
                fprintf(saidaTxt, "%d %lf %lf %s %s %s %lf %lf %lf %lf", id, x, y, fill, border, texto, p1_x, p1_y, v1);
        }
        }
        
       
    }

}


