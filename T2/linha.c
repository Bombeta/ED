#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linha.h"

typedef void *linha;

typedef struct Linha{
   
	int id;
	double x1;
	double y1;
    double x2;
    double y2;
    char color[100];
	
	double P1_X;
	double P1_Y;

	double P2_X;
	double P2_Y;
	
	double v1;
	double v2;
	//char tipo[12];

}linha_t;


int getIdLinha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->id;
}

double getX1Linha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->x1;
}

double getY1Linha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->y1;
}

double getX2Linha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->x2;
}

double getY2Linha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->y2;
}


char* getColorLinha(void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	return this->color;
}

double getP1_X_Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->P1_X;
}

double getP1_Y_Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->P1_Y;
}

double getP2_X_Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->P2_X;
}


double getP2_Y_Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->P2_Y;
}

double getV1Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->v1;
}

double getV2Linha(void* linha){
	linha_t* this;
	this = (linha_t*) linha;
	return this->v2;
}

// double getP2Linha(void* linha){
// 	linha_t* this;
// 	this = (linha_t*) linha;
// 	return this->p2;
// }


// double getEnergyLinha(void* linha){
// 	linha_t* this;
// 	this = (linha_t*) linha;
// 	return this->energy;
// }


void setIdLinha(int id, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	this->id = id;
}

void setX1Linha(double x1, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	this->x1 = x1;
}

void setY1Linha(double y1, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	this->y1 = y1;
}

void setX2Linha(double x2, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	this->x2 =x2;
}

void setY2Linha(double y2, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	this->y2 = y2;
}

void setColorLinha(char* color, void* linha){
    linha_t* this;
	this = (linha_t*) linha;
	//bzero(this->color, 100);
	strcpy(this->color, color);
}

void setV1Linha(double v1, void*linha){
	linha_t* this;
	this = (linha_t*) linha;
	this->v1 = v1;
}

void setV2Linha(double v2, void*linha){
	linha_t* this;
	this = (linha_t*) linha;
	this->v2 = v2;
}


linha cria_Linha(int id, double x1, double y1, double x2, double y2, char *color){
	
	linha_t* linha = malloc(sizeof(linha_t));

	

	linha->id = id;
	linha->x1 = x1;
	linha->y1 = y1;
    linha->x2 = x2;
    linha->y2 = y2;

	linha->P1_X = x1;
	linha->P1_Y = y1;

	linha->P2_X = x2;
	linha->P2_Y = y2;
	
	//strcpy(linha->tipo, tipo);	
    
    strcpy(linha->color,color);
	return linha;

}


void drawLine(linha l, char* svgQry){
		
	
	double x1 = getX1Linha(l);
	double y1 = getY1Linha(l);
	double x2 = getX2Linha(l);
	double y2 = getY2Linha(l); 
	char color[100];

	strcpy(color, getColorLinha(l));

	desenha_Linha(svgQry, x1, y1, x2, y2, color);
	
}
