#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circulo.h"


typedef void *circulo;

typedef struct Circulo{
   
	int id;
	double x, y, r;
	char fill[100];
	char border[100];
		
}circulo_t;

int getCircleId(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->id;
}

double getXCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->x;
}

double getYCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->y;
}

double getRCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->r;
}

char* getFillCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->fill;
}

char* getBorderCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->border;
}

void setIdCircle(int id, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->id = id;
}

void setXCircle(double x, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->x = x;
}

void setYCircle(double y, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->y = y;
}

void setRCircle(double r, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->r = r;
}

void setFillCircle(char* fill, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	//Função para limpar string em C */
	bzero(this->fill, 100);
	strcpy(this->fill, fill);
}

void setBorderCircle(char* border, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	//Função para limpar string em C */
	bzero(this->border, 100);
	strcpy(this->border, border);
}



circulo cria_Circulo(int id, double r, double x, double y, char *fill, char *border)
{
	circulo_t* circulo = malloc(sizeof(circulo_t));

	circulo->id = id;
	circulo->x = x;
	circulo->y = y;
	circulo->r =r;
	strcpy(circulo->fill, fill);
	strcpy(circulo->border, border);
	//strcpy(circulo->tipo, tipo);
	

	return circulo;

}


void drawCircle(circulo c, char* svgQry){
	
	double x = getXCircle(c);
	double y = getYCircle(c); 
	double r = getRCircle(c);
	char fill[100];
	char border[100];

	strcpy(fill, getFillCircle(c));
	strcpy(border, getBorderCircle(c));

	desenha_Circulo(svgQry, r, x, y, fill, border);
	
}

