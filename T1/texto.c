#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "texto.h"


//* TESTES FUNCIONANDO *//

typedef void *text;

typedef struct Texto{
   
	int id;
	double x;
	double y;
    char texto[100];
	char fill[100];
	char border[100];
	char tipo[12];

}text_t;

int getTextId(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->id;
}

double getXText(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->x;
}

double getYText(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->y;
}

char* getText(void* text){
    text_t* this;
	this = (text_t*) text;
	return this->texto;
}

char* getFillText(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->fill;
}

char* getBorderText(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->border;
}

char* getTipoText(void* text){
	text_t* this;
	this = (text_t*) text;
	return this->tipo;
}

void setIdText(int id, void* text){
	text_t* this;
	this = (text_t*) text;
	this->id = id;
}

void setXText(double x, void* text){
	text_t* this;
	this = (text_t*) text;
	this->x = x;
}

void setYText(double y, void* text){
	text_t* this;
	this = (text_t*) text;
	this->y = y;
}


void setText(char* texto, void* text){
    text_t* this;
	this = (text_t*) text;
	bzero(this->texto, 100);
	strcpy(this->texto, texto);
}

void setFillText(char* fill, void* text){
	text_t* this;
	this = (text_t*) text;
	//Função para limpar string em C */
	bzero(this->fill, 100);
	strcpy(this->fill, fill);
}

void setBorderText(char* border, void* text){
	text_t* this;
	this = (text_t*) text;
	//Função para limpar string em C */
	bzero(this->border, 100);
	strcpy(this->border, border);
}



text cria_Texto(int id, double x, double y, char *fill, char *border, char* texto)
{
	text_t* text = malloc(sizeof(text_t));

	text->id = id;
	text->x = x;
	text->y = y;
	//text->tipo = texto;
	strcpy(text->texto,texto);
	strcpy(text->fill, fill);
	strcpy(text->border, border);
	//strcpy(text->tipo, tipo);

	return text;

}


void print_Texto(text t){
	text_t* this;
	this = (text_t*) t;
	printf("PRINTA TEXTO\n");
	printf("%d\n", this->id);
	printf("%lf\n", this->x);
	printf("%lf\n", this->y);
	printf("%s\n", this->texto);
	printf("\n");
	
}



void drawText(text t, char* svgQry){
	// circulo_t* this;
	// this = (circulo_t*) c;

	//printf("PRINTA CIRCULO\n");
	
	
	
	double x = getXText(t);
	double y = getYText(t); 
	//double r = getRText(r);
	char fill[100];
	char border[100];
	char txt[100];

	// printf("X = %lf\n", x);
	// printf("Y = %lf\n", y);
	// printf("R = %lf\n", r);

	strcpy(fill, getFillText(t));
	strcpy(border, getBorderText(t));
	strcpy(txt, getText(t));

	// printf("FILL: %s", fill);
	// printf("BORDER: %s", border);


	desenha_Circulo(svgQry, x, y, fill, border, txt);
	
	printf("\n");
	
}
