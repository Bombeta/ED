#ifndef _H_RET
#define _H_RET
// #include "lista.h"

typedef void *retangulo;

int getRectId(void* retangulo);

double getWidthRect(void* retangulo);

double getHeightRect(void* retangulo);

double getXRect(void* retangulo);

double getYRect(void* retangulo);

char* getFillRect(void* retangulo);

char* getBorderRect(void* retangulo);

void setIdRect(int id, void* retangulo);

void setWidthRect(double w, void* retangulo);

void setHeigthRect(double h, void* retangulo);

void setXRect(double x, void* retangulo);

void setYRect(double y, void* retangulo);

void setFillRect(char* fill, void* retangulo);

void setBorderRect(char* border, void* retangulo);


#endif