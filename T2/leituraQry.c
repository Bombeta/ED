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
#include "leituraQry.h"
//#include "kd-tree.h"

void readFileQry(FILE* arqQry, char* svgQry, char* txtQry){

    /*COMANDOS QRY */

    char fig[5];
	char parametro[5];

	int n;
    int id;


	double r, x, y, w, h, x1, y1, x2, y2;
	double v;			//energia
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
	
	
	FILE* saidaTxt;
	FILE* saidaQry;



	saidaQry = fopen(svgQry, "a");

    if(saidaQry == NULL){   
        // printf("Entrou aqui");
		// printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

	cria_SVG(saidaQry);


	//comandos qry
	if(arqQry == NULL)
    {
        // printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(arqQry,"%s", &fig))!=EOF)
		{				
			
			if(strcmp(fig,"ef") == 0)
			{	
				fscanf(arqQry, "%s %lf", &id, &v);
				//energyFigure();				
			}

			
			if(strcmp(fig,"sf") == 0)
			{	
				fscanf(arqQry,"%lf %lf %lf %lf", &x, &y, &w, &h);
				//selectFigure();
			}			

			
			if(strcmp(fig, "ep") == 0)
			{	
				
			}
			
			
			if(strcmp(fig, "ip") == 0){

				fscanf(arqQry, "%d", &n);
				//interactionPoint();
			}

			
			if(strcmp(fig, "xf") == 0)
			{
				//fscanf(arqQry, "%d %d", &id, &i);
				//xforce();
			}

			
			if(strcmp(fig, "sp") == 0)
			{
				fscanf(arqQry, "%lf %lf %lf", &x, &y, &v);
				//interactionPointCloser();				
			}

			if(strcmp(fig, "q?") == 0)
			{
				fscanf(arqQry,"%d", id);
				//reportFigure();			

			}

			if(strcmp(fig, "qr") == 0)
			{
				fscanf(arqQry, "%lf %lf %lf %lf", &x, &y, &w, &h);
				//reportFigureArea();		

			}

			if(strcmp(fig, "nf") == 0){

				//normalizeFigure();
				
			}
		}
		
		// drawListCircle(listaCircle, svgQry);
		// drawListRect(listaRect, svgQry);
		// drawListText(listaText, svgQry);
		// drawListLine(listaLinha, svgQry);
		saidaQry = fopen(svgQry, "a+");
		fprintf(saidaQry, "</svg>");
		fclose(saidaQry);
	}

}