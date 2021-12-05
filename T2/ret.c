#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ret.h"

/*falta testar */

typedef void* retangulo;

typedef struct Retangulo{
	int id;
	double w;
	double h;
	double x;
	double y;
	char fill[100];
	char border[100];
	char tipo[12];
	double p1;
	double p2;
	double p3;
	double p4;
	double energy;
    
}retangulo_t;


void printRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	
	printf("ID = %d\n", this->id);
	printf("%lf\n", this->x);
	printf("%.2lf\n", this->y);
	printf("%.2lf\n", this->w);
	printf("%.2lf\n", this->h);
	printf("%s\n", this->fill);
	printf("%s\n", this->border);
	printf("\n*********\n");

}

int getRectId(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->id;
}

double getWidthRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->w;
}

double getHeightRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->h;
}

double getXRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->x;
}

double getYRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->y;
}

char* getFillRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->fill;
}

char* getBorderRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->border;
}

double getP1Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->p1;
}

double getP2Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->p2;
}

double getP3Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->p3;
}

double getP4Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->p4;
}

double getEnergyRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->energy;
}


char* getTipoRect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->tipo;
}

void setIdRect(int id, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->id = id;
}

void setWidthRect(double w, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->w = w;
}

void setHeightRect(double h, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->h = h;
}

void setXRect(double x, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->x = x;
}

void setYRect(double y, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->y = y;
}

void setFillRect(char* fill, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	bzero(this->fill, 100);
	strcpy(this->fill, fill);
}

void setBorderRect(char* border, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	bzero(this->fill, 100);
	strcpy(this->border, border);
}

void setEnergyRect(double energy, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->energy = energy;
}



retangulo cria_Retangulo(int id, double w, double h, double x, double y, char *fill, char *border)
{
	retangulo_t* retangulo = malloc(sizeof(retangulo_t));

	retangulo->id = id;
    retangulo->w = w;
    retangulo->h = h;
	retangulo->x = x;
	retangulo->y = y;
	
	strcpy(retangulo->fill, fill);
	strcpy(retangulo->border, border);
	//strcpy(retangulo->tipo, tipo);

	retangulo->p1 = 0.0;
	retangulo->p2 = 0.0;
	retangulo->p3 = 0.0;
	retangulo->p4 = 0.0;

	

	return retangulo;

}


void drawRect(retangulo r, char* svgQry){
	
	double w = getWidthRect(r);
	double h = getHeightRect(r);
	double x = getXRect(r);
	double y = getYRect(r); 
	
	char fill[100];
	char border[100];

	strcpy(fill, getFillRect(r));
	strcpy(border, getBorderRect(r));

	desenha_Retangulo(svgQry , w, h, x, y, fill, border);
	
}
