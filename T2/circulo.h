#ifndef _H_CIRCULO
#define _H_CIRCULO


typedef void *circulo;

circulo cria_Circulo(int id, double r, double x, double y, char *fill, char *border, double p1, double p2, double p3);

int getCircleId(void* circulo);

double getXCircle(void* circulo);

double getYCircle(void* circulo);

double getRCircle(void* circulo);

char* getFillCircle(void* circulo);

char* getBorderCircle(void* circulo);

char* getTipoCircle(void* circulo);

double getP1Circle(void* circulo);

double getP2Circle(void* circulo);

double getP3Circle(void* circulo);

void setIdCircle(int id, void* circulo);

void setXCircle(double x, void* circulo);

void setYCircle(double x, void* circulo);

void setRCircle(double r, void* circulo);

void setP1Circle(double p1, void* circulo);

void setP2Circle(double p2, void* circulo);

void setP2Circle(double p3, void* circulo);

void drawCircle(circulo c, char* svgQry);

void printCircle(void* circulo);


#endif