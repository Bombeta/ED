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
#include "lista.h"
//#include "kd-tree.h"

void readFileQry(FILE* arqQry, char* svgQry, char* txtQry, Kd k){

    /*COMANDOS QRY */

    char fig[5];
	char parametro[5];

	int n;
    int id;

	char ID;
	//double X;

	double r, x, y, w, h, x1, y1, x2, y2;
	double v;			//atribui energia 
	double d;			//soma energia 
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
	
	
	FILE* saidaTxt;
	FILE* saidaQry;

	List l = createLista();



	saidaQry = fopen(svgQry, "w");

    if(saidaQry == NULL){   
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

				fscanf(arqQry, "%s", &ID);

				if( ID == '*' ){

					// caso seja *
					//int id_ = (int) ID;
					id = 0;

					fscanf(arqQry, "%lf", &v);

					energyFigure(k, id, v);
				}else{
					// caso seja um inteiro
					int id_ = (int) (ID > 47 && ID < 58) ? ID - 48 : -1;

					energyFigure(k, id_, v);
				}

				
			
					
			}
					
			
			if(strcmp(fig,"sf") == 0)
			{	
				
				fscanf(arqQry, "%s", &ID);

				if( ID == '*' ){

					// caso seja *
					//int id_ = (int) ID;
				
					fscanf(arqQry, "%lf", &y , &w, &h);

					selectFigure(k, x, y, w, h, l, txtQry);
				}else{
					// caso seja um double
					double x_ = (double) (ID > 47 && ID < 58) ? ID - 48 : -1;

						
					selectFigure(k, x_, y, w, h, l, txtQry);
				}


				//selectFigure();
			}			

			
			if(strcmp(fig, "ep") == 0)
			{	
				
			}
			
			
			if(strcmp(fig, "ip") == 0){

				//fscanf(arqQry, "%d", &n);
				//interactionPoint();
			}

			
			if(strcmp(fig, "xf") == 0)
			{
				fscanf(arqQry, "%s", &ID);

				if( ID == '*' ){

					// caso seja *
					id = 0;

					fscanf(arqQry, "%lf", &v);

					xFigure(k, id, v);
					
				}else{
					// caso seja um double
					double x_ = (double) (ID > 47 && ID < 58) ? ID - 48 : -1;

					xFigure(k, x_, d);
				}
				//xforce();
			}

			
			if(strcmp(fig, "sp") == 0)
			{
				fscanf(arqQry, "%lf %lf %lf", &x, &y, &v);
				//interactionPointCloser();				
			}

			if(strcmp(fig, "q?") == 0)
			{
				fscanf(arqQry,"%d", &id);
				reportFigure(k, id, txtQry);			

			}

			if(strcmp(fig, "qr") == 0)
			{
				fscanf(arqQry, "%lf %lf %lf %lf", &x, &y, &w, &h);
				reportFigureRegion(k, id, txtQry, x, y, w, h);		

			}

			if(strcmp(fig, "nf") == 0){

				//normalizeFigure();
				
			}
		}

		
		printKdtreebyRoot(k);
		drawExitbyRoot(k, svgQry);

		svgQry = fopen(svgQry,"a+");	
		fprintf(svgQry, "</svg>");
		
	
	}

}