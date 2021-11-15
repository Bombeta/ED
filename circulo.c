#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circulo.h"


//* TESTES FUNCIONANDO *//

typedef void *circulo;

typedef struct Circulo{
   
	int id;
	double x, y, r;
	char fill[100];
	char border[100];
	char tipo[12];
	
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

char getTipoCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->tipo;
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



circulo cria_Circulo(int id, double r, double x, double y, char *fill, char *border, char* tipo)
{
	circulo_t* circulo = malloc(sizeof(circulo_t));

	circulo->id = id;
	circulo->x = x;
	circulo->y = y;
	circulo->r =r;
	strcpy(circulo->fill, fill);
	strcpy(circulo->border, border);
	strcpy(circulo->tipo,tipo);
	

	return circulo;

}


void printCircle(circulo c){
	circulo_t* this;
	this = (circulo_t*) c;
	//printf("PRINTA CIRCULO\n");
	printf("%d\n", this->id);
	printf("%lf\n", this->x);
	printf("%lf\n", this->y);
	printf("%lf\n", this->r);
	printf("%s\n", this->fill);
	//printf("\n");
	
}

void drawCircle(circulo c){
	// circulo_t* this;
	// this = (circulo_t*) c;

	//printf("PRINTA CIRCULO\n");
	
	
	double x = getXCircle(c);
	double y = getYCircle(c); 
	double r = getRCircle(c);
	char fill[100];
	char border[100];

	// printf("X = %lf\n", x);
	// printf("Y = %lf\n", y);
	// printf("R = %lf\n", r);

	strcpy(fill, getFillCircle(c));
	strcpy(border, getBorderCircle(c));

	// printf("FILL: %s", fill);
	// printf("BORDER: %s", border);

	desenha_Circulo("saidaQry.svg", r, x, y, fill, border);
	
	printf("\n");
	
}

