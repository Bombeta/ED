// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "ret.h"

// /*falta testar */

// typedef void* retangulo;

// typedef struct Retangulo{
// 	int id;
// 	double w;
// 	double h;
// 	double x;
// 	double y;
// 	char fill[100];
// 	char border[100];
    
// }retangulo_t;

// int getId(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->id;
// }

// double getWidth(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->w;
// }

// double getHeight(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->h;
// }

// double getX(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->x;
// }

// double getY(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->y;
// }

// char* getFill(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->fill;
// }

// char* getBorder(void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	return this->border;
// }

// void setId(int id, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	this->id = id;
// }

// void setWidth(double w, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	this->w = w;
// }

// void setHeight(double h, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	this->h = h;
// }

// void setX(double x, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	this->x = x;
// }

// void setY(double y, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	this.y = y;
// }

// void setFill(char* fill, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	strcpy(this->fill, fill);
// }

// void setBorder(char* border, void* retangulo){
// 	retangulo_t* this;
// 	this = (retangulo_t*) retangulo;
// 	strcpy(this->border, border);
// }