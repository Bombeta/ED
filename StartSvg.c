#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StartSvg.h"
//#include "lista.h"


/* Falta verificar a saida do svg que está repetindo o texto lido */

void cria_SVG(FILE* arqSvg)
{
	fprintf(arqSvg, "<svg>"); 			
	fprintf(arqSvg, "\n"); 
	fclose(arqSvg);
}	

void desenha_Circulo(char* nomeSaida, double r, double x, double y, char* fill, char* border)
{	
	FILE* arqSvg = fopen(nomeSaida, "a+");
	
	fprintf(arqSvg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1px\" opacity=\"0.5\" />", x, y, r, fill, border);
	fprintf(arqSvg, "\n");
	fclose(arqSvg);
}


void desenha_Retangulo(char* nomeSaida, double w, double h, double x, double y, char* fill, char* border)
{	
	FILE* arqSvg = fopen(nomeSaida, "a+");

	fprintf(arqSvg, "<rect x=\"%.2f\" y=\"%.2f\" width=\"%.2f\" height=\"%.2f\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1px\" opacity=\"0.5\"/>", x, y, w, h, fill, border);
	fprintf(arqSvg, "\n");	
	fclose(arqSvg);
}

void desenha_Linha(char* nomeSaida, double x1, double y1, double x2, double y2, char* color)
{	
	FILE* arqSvg = fopen(nomeSaida, "a+");
	fprintf(arqSvg, "<line x1=\"%.2f\" y1=\"%.2f\" x2=\"%.2f\" y2=\"%.2f\" stroke=\"%s\" stroke-width=\"1px\"/>", x1, y1, x2, y2, color);
	fprintf(arqSvg, "\n");
	fclose(arqSvg);
}

void desenha_Texto(char* nomeSaida, double x, double y, char* fill, char* border, char*texto)
{
	FILE* arqSvg = fopen(nomeSaida, "a+");

	fprintf(arqSvg,"<text x=\"%.2f\" y=\"%.2f\" font-family=\"Times New Roman\" font-size=\"50px\" fill=\"%s\" stroke=\"%s\">", x, y, fill, border);	
	fprintf(arqSvg, texto);

	fprintf(arqSvg, "</text>");					
	fprintf(arqSvg, "\n");	
	fclose(arqSvg);
		
}

void copiaTxt(FILE* saidaTxt, int j, int k)
{
	fprintf(saidaTxt,"o? %d %d", j, k);
	fprintf(saidaTxt,"\n");
}

void escreveFigura(FILE* saidaTxt, int id, char* texto)
{
	fprintf(saidaTxt,"%d: %s ", id, texto);
	
}

void escreveInterno(FILE* saidaTxt, char* texto){
	fprintf(saidaTxt,"%s", texto);
}

void desenhaInterno(FILE* arqSvg, double x, double y, char* fill){
	fprintf(arqSvg, "<circle cx=\"%.2f\" cy=\"%.2f\" r=\"1\" fill=\"%s\" stroke=\"%s\" stroke-width=\"1px\"/>", x, y, fill);
	fprintf(arqSvg,"\n");
}

void escreveCoordenada(FILE* saidaTxt, float x, float y){
	fprintf(saidaTxt,"%.2lf %.2lf", x, y);
	fprintf(saidaTxt,"\n");
}

