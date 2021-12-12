#ifndef H_START_SVG 
#define H_START_SVG
//#include "lista.h"


/*Inicializa o SVG */
void cria_SVG(FILE* arqSvg);	

void cria_SVG_qry(FILE *saidaQry);

void desenha_Circulo(char* svg, double x, double y, double r, char* fill, char* border);

void desenha_Retangulo(char* svg, double w, double h, double x, double y, char* fill, char* border); 

void desenha_Linha(char* svg, double x1, double y1, double x2, double y2, char* color);

void desenha_Texto(char* svg, double x, double y, char* fill, char* border, char* texto);

#endif