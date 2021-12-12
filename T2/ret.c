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
	double v4;
    
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

double getP1_X_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P1_X;
}

double getP1_Y_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P1_Y;
}

double getP2_X_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P2_X;
}

double getP2_Y_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P2_Y;
}

double getP3_X_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P3_X;
}

double getP3_Y_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P3_Y;
}

double getP4_X_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P4_X;
}

double getP4_Y_Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->P4_Y;
}

double getV1Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->v1;
}

double getV2Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->v2;
}

double getV3Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->v3;
}

double getV4Rect(void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	return this->v4;
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


void setP1_X_Rect(double p1, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P1_X = p1;
}


void setP2_X_Rect(double p2, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P2_X = p2;
}


void setP3_X_Rect(double p3, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P3_X = p3;
}


void setP4_X_Rect(double p4, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P4_X = p4;
}


void setP1_Y_Rect(double p1, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P1_Y = p1;
}


void setP2_Y_Rect(double p2, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P2_Y = p2;
}


void setP3_Y_Rect(double p3, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P3_Y = p3;
}


void setP4_Y_Rect(double p4, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->P4_Y = p4;
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

void setV1Rect(double v1, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->v1 = v1;
}


void setV2Rect(double v2, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->v2 = v2;
}

void setV3Rect(double v3, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->v3 = v3;
}

void setV4Rect(double v4, void* retangulo){
	retangulo_t* this;
	this = (retangulo_t*) retangulo;
	this->v4 = v4;
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

	retangulo->P1_X = x;
	retangulo->P1_Y = y;

	retangulo->P2_X = x + w;
	retangulo->P2_Y = y;

	retangulo->P3_X = x + w;
	retangulo->P3_Y = y + h;

	retangulo->P4_X = x;
	retangulo->P4_Y = y + h;

	retangulo->v1 = 0.0;
	retangulo->v2 = 0.0;
	retangulo->v3 = 0.0;
	retangulo->v4 = 0.0;

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
