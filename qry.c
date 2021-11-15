#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "qry.h"
#include "linha.h"
#include "circulo.h"
#include "ret.h"
#include "linha.h"

//#include "lista.h"
//#include "circulo.h"
//#include "ret.h"
// #include <stdbool.h>

//*está fazendo a linha e desenhando (falta saber pq fica por baixo)
// Sobrepoem = cor1, não sobrepoem cor2

void sobrepoem(int j, int k, List l, int id, char* cor1, char* cor2, FILE* saidaTxt){
    printf("Função Sobrepoem");
    char tipo1;
    char tipo2;
    double x1;
    double y1;
    double x2;
    double y2;
    double r1;
    double r2;
    double soma_raio;
    double dist_x, dist_y;
    double distance;
    char tipo;

    tipo = 'l';

    void* f1 = searchList(l,j);

    x1 = getXCircle(f1);
    //printf("*********** X1 = %.2lf ***********", x1);


    void* f2 = searchList(l,k);

    x2 = getXCircle(f2);
    //printf("*********** X2 = %.2lf ***********", x2);
    
    tipo1 = getTipoCircle(f1);
    tipo2 = getTipoCircle(f2);

    // if(tipo1 == 'c'){
    //     printf(" Circulo\n");
    // }else if(tipo2 == 'r'){
    //     printf(" RETANGULO SAIDA.\n");
    // }

    

    // if(tipo2 == 'c'){
    //     printf(" Circulo\n");
    // }else if(tipo2 == 'r'){
    //     printf(" RETANGULO SAIDA.\n");
    // }


    // FUNCIONA PARA TESTE 1 COMPLETO
    if(tipo1 == 'c' && tipo2 == 'c'){
        x1 = getXCircle(f1);
        y1 = getYCircle(f1);
        x2 = getXCircle(f2);
        y2 = getYCircle(f2);


        //printf("Y2 CIRCLE %lf", y2);

        r1 = getRCircle(f1);
        r2 = getRCircle(f2);

        dist_x = (x1 -x2);
        dist_y = (y1 -y2);

        //printf("X1 = %.2lf", x1);

        distance = sqrt((dist_x * dist_x) + (dist_y * dist_y));

        soma_raio = r1 + r2;

        // SOBREPOEM 
        if(soma_raio > distance){

            //Saida txt
            fprintf(saidaTxt,"i? %d %d", j, k);
            fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"%d: circulo %d: circulo SIM", j, k);
            fprintf(saidaTxt,"\n");
            
            //Troca a cor de preenchimento:
            f1 = setFillCircle(cor1, f1);
            f2 = setFillCircle(cor1, f2);

        }
       
        // NÃO SOBREPOEM

        //Saida txt
        fprintf(saidaTxt,"i? %d %d", j, k);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%d: circulo %d: circulo NÃO", j, k);
        fprintf(saidaTxt,"\n");
        
        //Troca a cor de preenchimento:
        f1 = setFillCircle(cor2, f1);
        f2 = setFillCircle(cor2, f2);

        linha L = cria_Linha( id, x1, y1, x2, y2, "black", tipo);

        insert(l, L);

       

    }
}



void interno(int j, double x ,double y ,List l, FILE* saidaTxt){

    char tipo;
    double x0;
    double y0;
    double r0;

    double dist_x;
    double dist_y;
    double distance;
    double soma_raio;

    

    printf("\n");
    printf("X: %lf", x);
    printf("Y: %lf", y);
    //valores corretos até aqui

    void* f1 = searchList(l,j);
    
    tipo = getTipoCircle(f1);

    printf("Entra interno");

    //Cáculo para circulo
    // PASSOU EM TODOS OS TESTES
    if(tipo == 'c'){

        printf("TIPO C");
        x0 = getXCircle(f1);
        y0 = getYCircle(f1);
        r0 = getRCircle(f1);

        dist_x = (x - x0);
        dist_y = (y - y0);
        
        distance = sqrt((dist_x * dist_x) + (dist_y * dist_y));

        //Ponto externo a circunferência
        if(distance > r0){
            fprintf(saidaTxt,"i? %d %.2lf %.2lf", j , x, y);
	        fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"Circulo NAO INTERNO");
            fprintf(saidaTxt,"\n");

            circulo C = cria_Circulo(99, 1.0, x, y, "magenta", "none", 'c');
            insert(l, C);
            linha L = cria_Linha(99, x, y, x0, y0, "black", 'l');
            insert(l, L);

        }

        //Ponto interno a circunferencia
        if(distance < r0){

            
            fprintf(saidaTxt,"i? %d %.2lf %.2lf", j, x, y);
	        fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"Circulo INTERNO");
            fprintf(saidaTxt,"\n");
            
            circulo C = cria_Circulo(99, 1.0, x, y, "blue", "none", 'c');
            insert(l, C);
            linha L = cria_Linha(99, x, y, x0, y0, "black", 'l');
            insert(l, L);
            
        }

        
   }

    printf("\nFIM\n");
    //Cálculo para retângulo

    // if(tipo == 'r'){
        
    //     printf("TIPO R");

    //     char tipo;
    //     double x0;
    //     double y0;

    //     double h;
    //     double w;

    //     double dist_x;
    //     double dist_y;

    //     x0 = getXRect(f1);
    //     dist_x = x0 - w;


    //     y0 = getYRect(f1);
    //     dist_y = y0 - h;


    //     // testar 
    //     // Interno
    //     if(x <= x0 && x >= dist_x && y <= y0 && dist_y >= y){

    //         fprintf(saidaTxt,"i? %d %d", x, y);
	//         fprintf(saidaTxt,"\n");
    //         fprintf(saidaTxt,"Retangulo é interno");
    //         fprintf(saidaTxt,"\n");

    //         desenha_Circulo("saidaSvg", 0.1 , x, y, "blue", "none");

    //         //Ver com qual ID colcoar a linha (criar outra lista?);
    //         //linha L = cria_Linha(id, x1, y1, x2, y2, "black");

    //         //insert(l, L);


    //     }else{

    //         fprintf(saidaTxt,"i? %d %d", x, y);
	//         fprintf(saidaTxt,"\n");
    //         fprintf(saidaTxt,"Retangulo não é interno");
    //         fprintf(saidaTxt,"\n");

    //         desenha_Circulo("saidaSvg", 0.1 , x, y, "magenta", "none");

    //         //Ver com qual ID colcoar a linha (criar outra lista?);
    //         //linha L = cria_Linha(id, x1, y1, x2, y2, "black");

    //         //insert(l, L);


    //     }


    // }

}


mudar_cor(int j, char* border, char* fill, List l, FILE* saidaTxt){

    char tipo;
    double x;
    double y;

    void* f = searchList(l);

    tipo = getTipoCircle(f);

    if(tipo == 'c'){
        printf(" Circulo\n");

        setBorderCircle(fill, f);
		setFillCircle(border, f);

        getXCircle(f);
        getYCircle(f);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
	    fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%lf %lf", x, y);



    }
    
    if(tipo == 'r'){
        printf(" RETANGULO SAIDA.\n");

        setBorderRect(fill, f);
		setFillRect(border, f);

        getXRect(f);
        getYRect(f);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
    }


}