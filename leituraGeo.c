#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "leituraGeo.h"
#include "StartSvg.h"
#include "lista.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "pilha.h"
#include "fila.h"
#include "qry.h"
#include "linha.h"	


void readFileGeo(FILE *arqGeo, char *svg, List listaCircle, List listaRect, List listaLinha, List listaText){

    char fig[5];

	int i,j,k;

    int id;

	int pd;		/*Identificador para pilha */
	int fd;		/*Identificador para fila */
	int ld;		/*Identificador para lista */
	int re;		/*Identificador para registrador */
	int ro;
	int rd;
	
    
	int qtd_circulo = 0;
	int qtd_retangulo = 0;
	int qtd_linha = 0;
	int qtd_texto = 0;

	//int linha = 0;

	double r, x, y, w, h, x1, y1, x2, y2;
	double dx, dy, prop;
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
	char tipo[12];
	char tipo1;
	char tipo2;

	int sizeList = 0;
	int tamanho = 0;

	// Pilha vetPilha[10];
	// Fila vetFila[10];
	// List vetLista[10];

	// FILE* saidaTxt;
	// FILE* saidaQry;
	FILE* arqSvg = NULL;
	FILE *arq;

	printf("GEOOOO: %s\n", svg);

	
    arqSvg = fopen(svg, "w");	

    if(arqSvg == NULL){	
		printf("entra qyaqu\n");
		printf("Arquivo SVG não foi criado!\n");
		//exit(0);
	}

    //cria_SVG(arqSvg);

	//List l = createLista();
	
	

	// tamanho = lengthP(VetPilha[0]);
	//printf("tamanho da pilha eh: %d", tamanho);

	// printf("Tamanho da lista: %d", tamanho);

	//arq = fopen(arqGeo, "r");

	

	//arqSvg = fopen(arqSvg, "w");

    if(arqSvg == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	//* Comandos Geo *//
    if(arqGeo == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(arqGeo,"%s", &fig))!=EOF)
		{	

			// printf("\n%c\n", fig);

			if(strcmp(fig,"c") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
	
				//arqSvg = fopen(arqSvg,"a+");

				printf("1");

				desenha_Circulo(svg, r, x, y, fill, border);		
			
				strcpy(tipo,"circulo");

				/*Adiciona um circulo a lista */
				//circulo C = cria_Circulo(id, r, x, y, fill, border, tipo);

				circulo C = cria_Circulo(id, r, x, y, fill, border);

				insert(listaCircle, C);


				//printf("GET TIPO INICIO: %c", getTipoCircle(C));

				//insert(l, C);

				// printf("\n entrou aqui: %d", length(l));

				// qtd_circulo = qtd_circulo + 1;

				// printf("\nqtd circulo %d\n", qtd_circulo);
							
			}

			
			if(strcmp(fig,"r") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);

				printf(" 2");
				
				//arqSvg = fopen(arqSvg, "a+"); 

				desenha_Retangulo(svg, w, h, x, y, fill, border); 	

				strcpy(tipo,"retangulo");
				
				/*Adiciona um retangulo a lista */
				retangulo R = cria_Retangulo(id, w, h, x, y, fill, border);
				
				insert(listaRect, R);

				// /*Adiciona um retangulo a lista */
				// retangulo R = cria_Retangulo(id, w, h, x, y, fill, border, tipo);
				
				// insert(l, R);

				// qtd_retangulo = qtd_retangulo + 1;

				// printf("\nqtd retangulo %d\n", qtd_retangulo);
						
			}

			if(strcmp(fig, "l") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %lf %s\n", &id, &x1, &y1, &x2, &y2, &color);

				//arqSvg = fopen(arqSvg, "a+"); 

				printf(" 3");

				desenha_Linha(svg, x1, y1, x2, y2, color);

				//strcpy(tipo,"linha");

				// linha L = cria_Linha(id, x1, y1, x2, y2, color, tipo);

				// //print_Linha(L);

				// insert(l, L);

				linha L = cria_Linha(id, x1, y1, x2, y2, color);
				
				insert(listaLinha, L);

				//fclose(arqSvg);
			}
			
			/*Testar erro aqui */

			if(strcmp(fig, "t") == 0)
			{
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %s %s", &id, &x, &y, fill, border);
				
				fgets(texto,100,arqGeo);			
				
				//arqSvg = fopen(arqSvg, "a+");
		
				desenha_Texto(svg, x, y, fill, border, texto);

				//strcpy(tipo,"texto");

				// /*Adiciona um texto a lista */

				text T = cria_Texto(id, x, y, fill, border, texto);

				insert(listaText, T);

				// text T = cria_Texto(id, x, y, fill, border, texto, tipo);

				// insert(l, T);
				
				//fclose(arqSvg);
				
			}		
		}		
	}

	//* A cópia está funcionando */
	// List listaCircleQry = listaCircle;
	// List listaRectQry = listaRect;
	// List listaTextQry = listaTextQry ;
	//List listaLinhaQry;

	arqSvg = fopen(svg,"a+");
	//saidaTxt = fopen("saida.txt", "a+");
	fprintf(arqSvg, "</svg>");
	
	
	
	
	




	
	//fclose(arqSvg);
	//fclose(arqGeo);
    //free(lista);
	// free(arqGeo);
	// free(outSvg);

}
