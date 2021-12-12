#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circulo.h"


typedef void *circulo;

typedef struct Circulo{
   
	int id;
	double x;
	double y;
	double r;
	char fill[100];
	char border[100];

	double P1_X;
	double P1_Y;

	double P2_X;
	double P2_Y;	

	double P3_X;
	double P3_Y;

	double P4_X;
	double P4_Y;

	double v1;
	double v2;
	double v3;
		
}circulo_t;

void printCircle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	
}
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

double getP1_X_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P1_X;
}

double getP2_X_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P2_X;
}

double getP3_X_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P3_X;
}

double getP1_Y_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P1_Y;
}

double getP2_Y_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P2_Y;
}

double getP3_Y_Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->P3_Y;
}



double getV1Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	printf("\nGET V1 %.2lf\n", this->v1);
	return this->v1;
}


double getV2Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->v2;
}


double getV3Circle(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->v3;
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

void setP1_X_Circle(double p1, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P1_X = p1;
}


void setP2_X_Circle(double p2, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P2_X = p2;
}


void setP3_X_Circle(double p3, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P3_X = p3;
}

void setP4_X_Circle(double p4, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P4_X = p4;
}


void setP1_Y_Circle(double p1, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P1_Y = p1;
}


void setP2_Y_Circle(double p2, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P2_Y = p2;
}


void setP3_Y_Circle(double p3, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P3_Y = p3;
}

void setP4_Y_Circle(double p4, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->P4_Y = p4;
}



// void setEnergyCircle(double v, void* circulo){
// 	circulo_t* this;
// 	this = (circulo_t*) circulo;
// 	this->v1 = v;
// }

void setV1Circle(double v1, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->v1 = v1;
	//printf("SET V1	%.2lf", this->v1);
}

void setV2Circle(double v2, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->v2 = v2;
}


void setV3Circle(double v3, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->v3 = v3;
}



circulo cria_Circulo(int id, double r, double x, double y, char *fill, char *border, double p1, double p2, double p3)
{
	circulo_t* circulo = malloc(sizeof(circulo_t));

	circulo->id = id;
	circulo->x = x;
	circulo->y = y;
	circulo->r = r;
	strcpy(circulo->fill, fill);
	strcpy(circulo->border, border);

	circulo->P1_X = x-r;
	circulo->P1_Y = y;

	circulo->P2_X = x;
	circulo->P2_Y = y-r;

	circulo->P3_X = x + r;
	circulo->P3_Y = y;

	circulo->v1 = 0.0;
	circulo->v2 = 0.0;
	circulo->v3 = 0.0;

	//circulo->tipo = tipo;
	

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

