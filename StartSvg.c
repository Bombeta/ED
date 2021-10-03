#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StartSvg.h"
#include "lista.h"


void cria_SVG(FILE* arqSvg)
{
	fprintf(arqSvg, "<svg viewBox=\"0 0 1000 1000\" xmlns=\"http://www.w3.org/2000\">"); 			
	fprintf(arqSvg, "\n"); 
	fclose(arqSvg);
}	

void desenha_Circulo(FILE* arqSvg, double r,double x, double y, char* fill, char* border)
{
	fprintf(arqSvg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"3px\"/>", x, y, r, fill, border);
	fprintf(arqSvg, "\n");
	}

void desenha_Retangulo(FILE* arqSvg, double w, double h, double x, double y, char* fill, char* border)
{
	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"3px\"/>", x, y, w, h, fill, border);
	fprintf(arqSvg, "\n");	
}

void desenha_Linha(FILE* arqSvg, double x1, double y1, double x2, double y2, char* color)
{
	fprintf(arqSvg, "<d L \"%.2f\" \"%.2f\" \"%.2f\" \"%.2f\" stroke=\"%s\" stroke-width=\"3px\"/>", x1, y1, x2, y2, color);
	fprintf(arqSvg, "\n");
}

void desenha_Texto(FILE* arqSvg, double x, double y, char* fill, char* border)
{
	int t;
	char txto;
	fprintf(arqSvg, "<text x=\"%.2f\" y=\"%.2f\" font-family=\"Times New Roman\" font-size=\"50px\" fill=\"%s\" stroke=\"%s\" >", x, y, fill, border);	

	while((txto=fgetc(arq))!= '\n')
	{
		printf("%c",txto);
		fprintf(arq, "%c", txto);
	}

	fprintf(arqSvg, "</text>");					
	fprintf(arqSvg, "\n");
		
}


// /*Está funcionando */
// void mudar_cor(LIST* l, int id, char *fill, char *border)
// {

// 	int i;
// 	int k;

// 	/*Procura id no circulo */
// 	for(i=0; i < l->nroC; i++)
// 	{
// 		if(id == l->C[i].id)
// 		{
// 			strcpy(l->C[i].fill,fill);
// 			strcpy(l->C[i].border,border);
// 		}
// 	}

// 	/*Procura id no retangulo */
// 	for(i=0;i<l->nroR;i++)
// 	{
// 		if(id == l->R[i].id)
// 		{
// 			strcpy(l->R[i].fill,fill);
// 			strcpy(l->R[i].border,border);
// 		}
// 	}

// 	/*Procura id no texto */
// 	for(i=0;i<l->nroT;i++)
// 	{
// 		if(id == l->T[i].id)
// 		{
// 			strcpy(l->T[i].fill,fill);
// 			strcpy(l->T[i].border,border);
// 		}
// 	}
// }

// /*Está funcionando */
// void mudar_cor_2(LIST* l, int id, int xd, char *fill, char *border)
// {
// 	int i;
// 	int k;

// 	/*Laço para percorrer todos os ids */
// 	for(k = id; k <= xd; k++)
// 	{
// 		/*Procura id no circulo */
// 		for(i=0;i<l->nroC;i++)
// 		{
// 			if(k == l->C[i].id)
// 			{
// 				strcpy(l->C[i].fill,fill);
// 				strcpy(l->C[i].border,border);
// 			}
// 		}

// 		/*Procura id no retangulo */
// 		for(i=0;i<l->nroR;i++)
// 		{
// 			if(k == l->R[i].id)
// 			{
// 				strcpy(l->R[i].fill,fill);
// 				strcpy(l->R[i].border,border);
// 			}
// 		}

// 		/*Procura id no texto */
// 		for(i=0;i<l->nroT;i++)
// 		{
// 			if(k == l->T[i].id)
// 			{
// 				strcpy(l->T[i].fill,fill);
// 				strcpy(l->T[i].border,border);
// 			}
// 		}
// 	}

// }


// void linhaCheia(FILE* arqSvg, double rectX, double rectY, double width, double height)
// {
// 	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"none\" stroke=\"green\" stroke-width=\"3px\" stroke-dasharray = \"5\"/>", 
// 		rectX,
// 		rectY,
// 		width,
// 		height);

// 	fprintf(arqSvg, "\n");
// }

// void linhaTracejada(FILE* arqSvg, double rectX, double rectY, double width, double height)
// {
// 	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"none\" stroke=\"\" stroke-width=\"3px\" stroke-dasharray = \"5\"/>", 
// 		rectX,
// 		rectY,
// 		width,
// 		height);

// 	fprintf(arqSvg, "\n");
// }

