#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "qry.h"
#include "linha.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "pilha.h"

//#include "lista.h"
//#include "circulo.h"
//#include "ret.h"
// #include <stdbool.h>

//*está fazendo a linha e desenhando (falta saber pq fica por baixo)
// Sobrepoem = cor1, não sobrepoem cor2

void sobrepoem(int j, int k, int id, char* cor1, char* cor2, char* qryTxt, List listaCircle, List listaRect, List listaLinha){
    printf("Função Sobrepoem");
    // char tipo1;
    // char tipo2;
    FILE* saidaTxt;
    
    
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

    saidaTxt = fopen(qryTxt, "a+");

    void *fig1_Circ = searchListCircle(listaCircle,j);
    if(fig1_Circ == NULL){
        void* figura1_Ret = searchListRect(listaRect, j);
	}
    void *fig2_Circ = searchListCircle(listaCircle,k);

    if(fig2_Circ == NULL){
        void* figura2_Ret = searchListRect(listaRect, k);
    }

    // Dois circulos
    if(fig1_Circ != NULL && fig2_Circ != NULL){
        
        x1 = getXCircle(fig1_Circ);
        y1 = getYCircle(fig1_Circ);
        x2 = getXCircle(fig2_Circ);
        y2 = getYCircle(fig2_Circ);


        //printf("Y2 CIRCLE %lf", y2);

        r1 = getRCircle(fig1_Circ);
        r2 = getRCircle(fig2_Circ);

        dist_x = (x1 -x2);
        dist_y = (y1 -y2);

        //printf("X1 = %.2lf", x1);

        distance = sqrt((dist_x * dist_x) + (dist_y * dist_y));

        soma_raio = r1 + r2;

        // SOBREPOEM 
        if(soma_raio > distance){

            //Saida txt
            fprintf(saidaTxt,"o? %d %d", j, k);
            fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"%d: circulo %d: circulo SIM", j, k);
            fprintf(saidaTxt,"\n");
            
            //Troca a cor de preenchimento:
            fig1_Circ = setFillCircle(cor1, fig1_Circ);
            fig2_Circ = setFillCircle(cor1, fig2_Circ);

        }else{

            // NÃO SOBREPOEM

            //Saida txt
            fprintf(saidaTxt,"o? %d %d", j, k);
            fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"%d: circulo %d: circulo NÃO", j, k);
            fprintf(saidaTxt,"\n");
            
            //Troca a cor de preenchimento:
            fig1_Circ = setFillCircle(cor2, fig1_Circ);
            fig2_Circ = setFillCircle(cor2, fig2_Circ);

            linha L = cria_Linha( id, x1, y1, x2, y2, "black");

            insert(listaLinha, L);


        }

        // Dois retangulos 
        // if(fig1_Rect != NULL && fig2_Rect != NULL){

        //     x1 = getXRect(figura1_Ret);
        //     y1 = getYRect(figura1_Ret);



        // }
     

       

	}
}



void interno(int j, double x ,double y, char* qryTxt, List listaCircle, List listaRect, List listaLinha){

    //char tipo;
    double x0;
    double y0;
    double r0;

    int id = 9000;

    double dist_x;
    double dist_y;
    double distance;
    double soma_raio;

    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    void* figCirc = searchListCircle(listaCircle ,j);    

    printf("Entra interno");

    //Cáculo para circulo
    //PASSOU EM TODOS OS TESTES

    if(figCirc != NULL){
        
        printf("TIPO C");
        x0 = getXCircle(figCirc);
        y0 = getYCircle(figCirc);
        r0 = getRCircle(figCirc);

        dist_x = (x - x0);
        dist_y = (y - y0);
        
        distance = sqrt((dist_x * dist_x) + (dist_y * dist_y));

        //Ponto externo a circunferência
        if(distance > r0){
            fprintf(saidaTxt,"i? %d %.2lf %.2lf", j , x, y);
            fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"%d: Circulo NAO INTERNO", j);
            fprintf(saidaTxt,"\n");

            circulo C = cria_Circulo(id, 1.0, x, y, "magenta", "none");
            insert(listaCircle, C);
            linha L = cria_Linha(99, x, y, x0, y0, "magenta");
            insert(listaLinha, L);

        }

        //Ponto interno a circunferencia
        if(distance < r0){

            
            fprintf(saidaTxt,"i? %d %.2lf %.2lf", j, x, y);
            fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"%d Circulo INTERNO", j);
            fprintf(saidaTxt,"\n");
            
            circulo C = cria_Circulo(id, 1.0, x, y, "blue", "none");
            insert(listaCircle, C);
            linha L = cria_Linha(id, x, y, x0, y0, "blue");
            insert(listaLinha, L);
            
        }

            
    }

    //printf("\nFIM\n");
    //Cálculo para retângulo

    if(figCirc == NULL){
        
        void* figRet = searchListRect(listaRect, j);

        double x0;
        double y0;

        double h;
        double w;

        double dist_x;
        double dist_y;

        //Centro de massa:

        double cx;
        double cy;

        x0 = getXRect(figRet);
        w = getWidthRect(figRet);
        dist_x = x0 + w;
        cx = x0 + (w/2);
        
        y0 = getYRect(figRet);
        h = getHeightRect(figRet);
        dist_y = y0 + h;
        cy = y0 + (h/2);



        // testar 
        // Interno
        if(x < x0 && x > dist_x && y < y0 && dist_y > y){

            fprintf(saidaTxt,"i? %d %lf %lf",j , x, y);
	        fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"Retangulo INTERNO");
            fprintf(saidaTxt,"\n");

            circulo C = cria_Circulo(99, 1.0, x, y, "magenta", "none");
            insert(listaCircle, C);
            linha L = cria_Linha(99, x, y, cx, cy, "magenta");
            insert(listaLinha, L);
            

        }else{

            fprintf(saidaTxt,"i? %lf %lf", x, y);
	        fprintf(saidaTxt,"\n");
            fprintf(saidaTxt,"Retangulo NÃO INTERNO");
            fprintf(saidaTxt,"\n");

            circulo C = cria_Circulo(99, 1.0, x, y, "magenta", "none");
            insert(listaCircle, C);
            linha L = cria_Linha(99, x, y, cx, cy, "magenta");
            insert(listaLinha, L);
        }


    }

}

//FUNCIONA 
void mudar_cor(int j, char* border, char* fill, char* qryTxt, List listaCircle, List listaRect, List listaLinha, List listaText){

    double x;
    double y;

    FILE* saidaTxt = NULL;

    saidaTxt = fopen(qryTxt, "a+");

    if(saidaTxt == NULL){
        printf("ERRO");
    }

    void* fig1_Circ = searchListCircle(listaCircle, j);
    void* figura1_Ret = NULL;
    void* figura1_Linha = NULL;
    void* figura1_Text = NULL;

    printf("BODER: %s\n", border);
	printf("FILL: %s\n", fill);

    if(fig1_Circ != NULL){

        printf("TESTE\n");
        setBorderCircle(fill, fig1_Circ);
		setFillCircle(border, fig1_Circ);

        x = getXCircle(fig1_Circ);
        y = getYCircle(fig1_Circ);

        //fprintf(saidaTxt,"o? %d %d", j, k);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
	    fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%lf %lf", x, y);
    }

    if(fig1_Circ == NULL){
        figura1_Ret = searchListRect(listaRect, j);
        setBorderRect(fill, figura1_Ret);
		setFillRect(border, figura1_Ret);

        x = getXRect(figura1_Ret);
        y =getYRect(figura1_Ret);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%lf %lf", x, y);

    }

    if(fig1_Circ == NULL && figura1_Ret == NULL){
        figura1_Linha = searchListRect(listaLinha, j);
        setBorderRect(fill, figura1_Linha);
		setFillRect(border, figura1_Linha);

        x = getXRect(figura1_Linha);
        y = getYRect(figura1_Linha);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%lf %lf", x, y);
    }

     if(fig1_Circ == NULL && figura1_Ret == NULL && figura1_Linha == NULL){
        figura1_Text = searchListRect(listaLinha, j);
        setBorderRect(fill, figura1_Text);
		setFillRect(border, figura1_Text);

        x = getXRect(figura1_Text);
        y = getYRect(figura1_Text);

        fprintf(saidaTxt,"pnt %d %s %s", j, border, fill);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%lf %lf", x, y);
    }
   
  

}

// TESTAR 
remove_forma(int j, char* qryTxt, List listaCircle, List listaRect,List listaText, List listaLinha){

    int id;
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
    char cor[100];
    char texto[100];
    
    FILE * saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");

    void* fig1 = searchListCircle(listaCircle, j);
    void* fig2 = NULL;
    void* fig3 = NULL;
    void* fig4 = NULL;

    //CIRCULO
    if(fig1 != NULL){

        id = getCircleId(fig1);
        x = getXCircle(fig1);
        y = getYCircle(fig1);
        r = getRCircle(fig1);

        strcpy(border, getBorderCircle(fig1));
        strcpy(fill, getFillCircle(fig1));

        removeListaCircle(listaCircle, j);

        fprintf(saidaTxt,"delf %d", j);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%d %lf %lf %lf %s %s", id, x, y, r, fill, border);
    }

    // RETANGULO
    if(fig1 == NULL){
        fig2 = searchListRect(listaRect, j);

        id = getRectId(fig2);
        x = getXRect(fig2);
        y = getYRect(fig2);
        w = getWidthRect(fig2);
        h = getHeightRect(fig2);

        strcpy(border, getBorderRect(fig2));
        strcpy(fill, getFillRect(fig2));

        //removeListaRect(listaRect, j);

        fprintf(saidaTxt,"delf %d", j);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%d %lf %lf %lf %lf %lf %s %s", id, w, h, x, y, r, fill, border);

    }

    //LINHA
    if(fig1 == NULL && fig2 == NULL){
        fig3 = searchListLinha(listaLinha, j);

        x1 = getX1Linha(fig3);
        y1 = getY1Linha(fig3);
        x2 = getX2Linha(fig3);
        y2 = getY2Linha(fig3);

        strcpy(cor, getColorLinha(fig3));

        //removeListaLinha(listaLinha, j);

        fprintf(saidaTxt,"delf %d", j);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%d %lf %lf %lf %lf %s %s", id, x1, y1, x2, y2, cor);

    }

    //TEXTO
    if(fig1 == NULL && fig2 == NULL && fig2 == NULL){
        fig4 = searchListText(listaText, j);

        id = getTextId(fig4);
        x = getXText(fig4);
        y = getYText(fig4);

        strcpy(border, getBorderText(fig4));
        strcpy(fill, getFillText(fig4));
        strcpy(texto, getText(fig4));

        //removeText(listaText, j);

        fprintf(saidaTxt,"delf %d", j);
        fprintf(saidaTxt,"\n");
        fprintf(saidaTxt,"%d %lf %lf %s %s %s", id, x, y, fill, border, texto);


    }


}

void push_Pilha(int pd, int i, Pilha *vetPilha, List listaCircle, List listaRect, List listaLinha, List listaText){

    int id;
    double x;
    double y;
    double h;
    double w;
    double r;
    double x1;
    double y1;
    double x2;
    double y2;
    char fill[100];
    char border[100];
    char texto[100];
    char color[100];
    char tipo[12];

    printf("ATE AQUI FOI");

    //Procura na lista de circulo 
    void* fig1 = searchListCircle(listaCircle, i);
    void* fig2 = NULL;
    void* fig3 = NULL;
    void* fig4 = NULL;

    //Pilha pilha = createPilha();
    //Pilha p = createPilha();

    if(fig1 != NULL){
        
        id = getCircleId(fig1);	
        x = getXCircle(fig1);					
        y = getYCircle(fig1);
        r = getRCircle(fig1);

        strcpy(fill, getFillCircle(fig1));
        strcpy(border, getFillCircle(fig1));
        
        
        circulo C = cria_Circulo(id, r, x, y, fill, border);

        push(vetPilha[pd], C);
        setTipo(vetPilha[pd],'c');

        printf("FIMN: %d", id);
    
        //push(pilha,C); 
    }
    // /// RETANGULO
    
    // VER PQ NÃ FUNCIONA 
    // if(fig1 == NULL){
    //     fig2 = searchListRect(listaRect, i);
        
    //     id = getRectId(fig2);
    //     printf("Katy\n");
        
    //     x = getXRect(fig2);					
    //     y = getYRect(fig2);
    //     h = getHeightRect(fig2);
    //     w = getWidthRect(fig2);

    //     strcpy(fill, getFillRect(fig2));
    //     strcpy(border, getBorderRect(fig2));
        

    //     Pilha R = cria_Retangulo(id, w, h, x, y, fill, border);

    //     push(vetPilha[pd], R);
    //     setTipo(vetPilha[pd],'r'); 
    // }

    ///// LINHA
    if(fig1 == NULL && fig2 == NULL){
        
        fig3 = searchListLinha(listaLinha, i);

        id = getIdLinha(fig3);
        x1 = getX1Linha(fig3);
        x2 = getX2Linha(fig3);
        y1= getY1Linha(fig3);
        y2 = getY2Linha(fig3);
        
        strcpy(color, getColorLinha(fig3));

        linha L = cria_Linha(id, x1, y1, x2, y2, color);
    
        push(vetPilha[pd], L);
        setTipo(vetPilha[pd],'l');
    }

    ///// TEXTO
    if(fig1 == NULL && fig2 == NULL && fig3 == NULL){
        
        fig4 = searchListText(listaText, i);

        id = getTextId(fig4);
        x = getXText(fig4);
        y = getYText(fig4);

        strcpy(fill, getFillText(fig4));
        strcpy(border, getBorderText(fig4));
        strcpy(texto, getText(fig4));
        

        printf("pilha\n");
        text T = cria_Texto(id, x, y, fill, border, texto);

        push(vetPilha[pd], T);
        setTipo(vetPilha[pd],'t');
    }
    
    printf("TAMNHO DA PILHA\n");
    //printf("%d\n",lengthP(p));
}


void pop_Pilha(int pd, int i, double dx, double dy, double prop, char* qryTxt, Pilha *vetPilha, List listaCircle, List listaRect, List listaLinha, List listaText){

    int id;
    double x;
    double y;
    double h;
    double w;
    double r;
    double x1;
    double y1;
    double x2;
    double y2;
   
    char fill[100];
    char border[100];
    char color[100];
    char texto[100];

    // double newX;
    // double newY;
    double newR;
    double newH;
    double newW;

    char newFill[100];
    char newBorder[100];
    char tipo;

    void* figura = getInfo(vetPilha[pd]);

    tipo = getTipo(vetPilha[pd]);

    FILE* saidaTxt;

    saidaTxt = fopen(qryTxt, "a+");   
   
    //printf("TIPO POP: %c", tipo);

    dx = dx + x;
    dy = dy + y;
    
    //pop(vetPilha[pd]); 

    //Procura na lista de circulo 
    if(tipo == 'c'){
                
        id = getCircleId(figura);	
        x = getXCircle(figura);					
        y = getYCircle(figura);
        r = getRCircle(figura);

        strcpy(fill, getFillCircle(figura));
        strcpy(border, getFillCircle(figura));
        
        

        newR = r * prop;

        strcpy(newFill, fill);
        strcpy(newBorder, border);

       // x e y transladados???

        circulo C = cria_Circulo(i, newR, dx, dy, newFill, newBorder);

        
        fprintf(saidaTxt,"%d %lf %lf %s %s %s", id, x, y, fill, border);

    }
    // /// RETANGULO
    if(tipo == 'r'){
        
        id = getRectId(figura);	
        x = getXRect(figura);					
        y = getYRect(figura);
        h = getHeightRect(figura);
        w = getWidthRect(figura);

        strcpy(fill, getFillRect(figura));
        strcpy(border, getBorderRect(figura));
        
        pop(vetPilha[pd]); 

        newH = h * prop;
        newW = w * prop;

        strcpy(newFill, fill);
        strcpy(newBorder, border);

        retangulo R = cria_Retangulo(i, newW, newH, dx, dy, newFill, newBorder);

        fprintf(saidaTxt,"%d %lf %lf %lf %lf %s %s %s", id, w, h, x, y, fill, border);

    }
    // /// LINHA
    if(tipo == 'l'){
        

        // printf("TIPO POP: %c\n", tipo);

        id = getIdLinha(figura);
        // printf("ID: %d", id);        
        x1 = getX1Linha(figura);
        // printf("X1: %lf", x1);
        x2 = getX2Linha(figura);
        // printf("X2: %lf", x2);
        y1= getY1Linha(figura);
        // printf("Y1: %lf", y1);
        y2 = getY2Linha(figura);
        // printf("Y2: %lf", y2);

        x2 = x2 * prop;
        y2 = y2 * prop;
        
        strcpy(color, getColorLinha(figura));

        pop(vetPilha[pd]); 

        linha L = cria_Linha(i, dx, dy, x2, y2, color);

        printf("REMOVEU\n");

        fprintf(saidaTxt,"%d %lf %lf %lf %lf %s\n", id, x1, y1, x2, y2, color);
        
    }

    /// TEXTO PROPORÇÃO ????
    if(tipo == 't'){
        
        id = getTextId(figura);
        x = getXText(figura);
        y = getYText(figura);

        strcpy(fill, getFillText(figura));
        strcpy(border, getBorderText(figura));
        strcpy(texto, getText(figura));
        
        pop(vetPilha[pd]);

        //text T = cria_Texto(id, x, y, fill, border, texto, tipo);

        
    }
   

}