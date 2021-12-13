#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "leituraGeo.h"
#include "StartSvg.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "qry.h"
#include "linha.h"	
#include "kd-tree.h"



void readFileGeo(FILE *arqGeo, char *svg, Kd k){

    char fig[5];

	int id;

	double p1;

	double r;
	double x;
	double y;
	double w;
	double h;
	double x1;
	double y1;
	double x2;
	double y2;
	double dx, dy, prop;
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
		
	
	List lista = createLista();
	
	FILE* arqSvg = NULL;
	FILE *arq;

	arqSvg = fopen(svg, "w");	

    if(arqSvg == NULL){	
		// printf("Arquivo SVG não foi criado!\n");
		return 0;
	}

    if(arqSvg == NULL)
	{
		//printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	//* Comandos Geo *//
    if(arqGeo == NULL)
    {
        //printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(arqGeo,"%s", &fig))!=EOF)
		{	

			if(strcmp(fig,"c") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
	
				desenha_Circulo(svg, r, x, y, fill, border);		
			
				/*Adiciona um circulo a lista */
				circulo C = cria_Circulo(id, r, x, y, fill, border, 0.00 , 0.00 , 0.00);

			
				insertList(lista, C, 1);

				insert(k, x , y, 'c', id, C);

			}

			
			if(strcmp(fig,"r") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);

				desenha_Retangulo(svg, w, h, x, y, fill, border); 	

				/*Adiciona um retangulo a lista */
				retangulo R = cria_Retangulo(id, w, h, x, y, fill, border);
				
				printRect(R);

				insert(k, x, y, 'r', id, R);			
						
			}

			if(strcmp(fig, "l") == 0)
			{	
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %lf %lf %s\n", &id, &x1, &y1, &x2, &y2, &color);

				desenha_Linha(svg, x1, y1, x2, y2, color);

				linha L = cria_Linha(id, x1, y1, x2, y2, color);
				
				insert(k, x1, y1, 'l', id, L);

			}
			
			if(strcmp(fig, "t") == 0)
			{
				fflush(stdin);
				fscanf(arqGeo, "%d %lf %lf %s %s", &id, &x, &y, fill, border);
				
				fgets(texto,100,arqGeo);			
				
				desenha_Texto(svg, x, y, fill, border, texto);

				text T = cria_Texto(id, x, y, fill, border, texto);

				insert(k, x, y, 't', id, T);

				
			}		
		}		
	}

	

	//printKdtreebyRoot(k);

	
	//printList(lista);
	//exit(0);

	arqSvg = fopen(svg,"a+");	
	fprintf(arqSvg, "</svg>");
}
