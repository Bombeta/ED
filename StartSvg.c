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

void desenha_Circulo(FILE* arqSvg, LIST* l)
{
	int i;

	i = l->nroC;

	fprintf(arqSvg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"3px\"/>", 
		l->C[i].x,
		l->C[i].y,
		l->C[i].r,
		l->C[i].fill,
		l->C[i].border);

	fprintf(arqSvg, "\n");
	printf("Qtd Circulo: %d\n", l->nroC);
	l->nroC = i + 1;
}

void desenha_Retangulo(FILE* arqSvg, LIST* l)
{
	int r;

	r = l->nroR;

	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"3px\"/>", 
		l->R[r].x,
		l->R[r].y,
		l->R[r].w,
		l->R[r].h,
		l->R[r].fill,
		l->R[r].border);

	fprintf(arqSvg, "\n");

	l->nroR = r + 1;
	
}

void desenha_Texto(FILE* arqSvg, LIST* l, FILE* arq)
{
	int t;
	char txto;

	t = l->nroT;

	fprintf(arqSvg, "<text x=\"%.2f\" y=\"%.2f\" font-family=\"Times New Roman\" font-size=\"50px\" fill=\"%s\" stroke=\"%s\" >", 
		l->T[t].x,
		l->T[t].y,
		l->T[t].fill,
		l->T[t].border);

	while((txto=fgetc(arq))!= '\n')
	{
		printf("%c",txto);
		fprintf(arq, "%c", txto);

	}

	fprintf(arqSvg, "</text>");					
	fprintf(arqSvg, "\n");

	l->nroT = t + 1;

	printf("%d\n",l->nroT);
}


/*Está funcionando */
void mudar_cor(LIST* l, int id, char *fill, char *border)
{

	int i;
	int k;

	/*Procura id no circulo */
	for(i=0; i < l->nroC; i++)
	{
		if(id == l->C[i].id)
		{
			strcpy(l->C[i].fill,fill);
			strcpy(l->C[i].border,border);
		}
	}

	/*Procura id no retangulo */
	for(i=0;i<l->nroR;i++)
	{
		if(id == l->R[i].id)
		{
			strcpy(l->R[i].fill,fill);
			strcpy(l->R[i].border,border);
		}
	}

	/*Procura id no texto */
	for(i=0;i<l->nroT;i++)
	{
		if(id == l->T[i].id)
		{
			strcpy(l->T[i].fill,fill);
			strcpy(l->T[i].border,border);
		}
	}
}

/*Está funcionando */
void mudar_cor_2(LIST* l, int id, int xd, char *fill, char *border)
{
	int i;
	int k;

	/*Laço para percorrer todos os ids */
	for(k = id; k <= xd; k++)
	{
		/*Procura id no circulo */
		for(i=0;i<l->nroC;i++)
		{
			if(k == l->C[i].id)
			{
				strcpy(l->C[i].fill,fill);
				strcpy(l->C[i].border,border);
			}
		}

		/*Procura id no retangulo */
		for(i=0;i<l->nroR;i++)
		{
			if(k == l->R[i].id)
			{
				strcpy(l->R[i].fill,fill);
				strcpy(l->R[i].border,border);
			}
		}

		/*Procura id no texto */
		for(i=0;i<l->nroT;i++)
		{
			if(k == l->T[i].id)
			{
				strcpy(l->T[i].fill,fill);
				strcpy(l->T[i].border,border);
			}
		}
	}

}


void linhaCheia(FILE* arqSvg, double rectX, double rectY, double width, double height)
{
	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"none\" stroke=\"green\" stroke-width=\"3px\" stroke-dasharray = \"5\"/>", 
		rectX,
		rectY,
		width,
		height);

	fprintf(arqSvg, "\n");
}

void linhaTracejada(FILE* arqSvg, double rectX, double rectY, double width, double height)
{
	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"none\" stroke=\"\" stroke-width=\"3px\" stroke-dasharray = \"5\"/>", 
		rectX,
		rectY,
		width,
		height);

	fprintf(arqSvg, "\n");
}

