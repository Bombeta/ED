#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StartSvg.h"
// #include "lista.h"


void cria_SVG(FILE* arqSvg)
{
	fprintf(arqSvg, "<svg viewBox=\"0 0 1000 1000\">"); 			
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
	fprintf(arqSvg, "<line x1=\"%.2f\" y1=\"%.2f\" x2=\"%.2f\" y2=\"%.2f\" stroke=\"%s\" stroke-width=\"3px\"/>", x1, y1, x2, y2, color);
	fprintf(arqSvg, "\n");
}

void desenha_Texto(FILE* arqSvg, double x, double y, char* fill, char* border, char*texto)
{
	
	fprintf(arqSvg, "<text x=\"%.2f\" y=\"%.2f\" font-family=\"Times New Roman\" font-size=\"50px\" fill=\"%s\" stroke=\"%s\" >", x, y, fill, border);	
	fprintf(arqSvg,texto);

	fprintf(arqSvg, "</text>");					
	fprintf(arqSvg, "\n");
		
}
