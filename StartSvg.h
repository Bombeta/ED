#ifndef H_START_SVG 
#define H_START_SVG
#include "lista.h"


/*Inicializa o SVG */
void cria_SVG(FILE* arqSvg);	

void desenha_Circulo(FILE* arqSvg, LIST* l);

void desenha_Retangulo(FILE* arqSvg, LIST* l); 

void desenha_Texto(FILE* arqSvg, LIST* l, FILE* arq);

void mudar_cor(LIST* l, int id, char *fill, char *border);

void mudar_cor_2(LIST* l, int id, int xd, char *fill, char *border);

void linhaCheia(FILE* arqSvg, double rectX, double rectY, double width, double height);

void linhaTracejada(FILE* arqSvg, double rect, double rectY, double widht, double height);


#endif