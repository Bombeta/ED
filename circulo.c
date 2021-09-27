#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "circulo.h"



//* TESTES FUNCIONANDO *//

typedef void *circulo;

typedef struct Circulo{
   
	int id;
	double x, y, r;
	char fill[100];
	char border[100];


}circulo_t;

int getId(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->id;
}

double getX(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->x;
}

double getY(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->y;
}

double getR(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->r;
}

char* getFill(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->fill;
}

char* getBorder(void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	return this->border;
}

void setId(int id, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->id = id;
}

void setX(double x, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->x = x;
}

void setY(double y, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->y = y;
}

void setR(double r, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	this->r = r;
}

void setFill(char* fill, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	//Função para limpar string em C */
	bzero(this->fill, 100);
	strcpy(this->fill, fill);
}

void setBorder(char* border, void* circulo){
	circulo_t* this;
	this = (circulo_t*) circulo;
	//Função para limpar string em C */
	bzero(this->border, 100);
	strcpy(this->border, border);
}



circulo cria_Circulo(int id, double x, double y, double r, char *fill, char *border)
{
	circulo_t* circulo = malloc(sizeof(circulo_t));

	circulo->id = id;
	circulo->x = x;
	circulo->y = y;
	circulo->r =r;
	strcpy(circulo->fill, fill);
	strcpy(circulo->border, border);

	return circulo;

}

int main (){

	void* circulo_teste;
	circulo_teste = cria_Circulo(10, 10, 2, 4, "blue", "red");
	setId(30, circulo_teste);
	setX(4, circulo_teste);
	setY(6,circulo_teste);
	setR(3, circulo_teste);
	setFill("purple", circulo_teste);
	setBorder("Polnareff" , circulo_teste);
	
	printf("teste get: \n");
	printf("%d\n",getId(circulo_teste));
	printf("getX: %lf \n",getX(circulo_teste));
	printf("getY: %lf \n",getY(circulo_teste));
	printf("getR: %lf \n",getR(circulo_teste));
	printf("getFill: %s \n",getFill(circulo_teste));
	printf("getBorder: %s \n",getBorder(circulo_teste));


	return 0;
}