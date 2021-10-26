#ifndef _H_CIRCULO
#define _H_CIRCULO
// #include "lista.h"

typedef void *circulo;

circulo cria_Circulo(int id, double x, double y, double r, char *fill, char *border);

int getCircleId(void* circulo);

double getXCircle(void* circulo);

double getYCircle(void* circulo);

double getRCircle(void* circulo);

char* getFillCircle(void* circulo);

char* getBorderCircle(void* circulo);

void setIdCircle(int id, void* circulo);

void setXCircle(double x, void* circulo);

void setYCircle(double x, void* circulo);

void setRCircle(double r, void* circulo);

// void getFIll(char* fill, void* cirulo);

bool internoCirculo(circulo c, double x, double y);

void printCircle(circulo c);

#endif