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

double getP1_X_Circle(void* circulo);

double getP2_X_Circle(void* circulo);

double getP3_X_Circle(void* circulo);

double getP1_Y_Circle(void* circulo);

double getP2_Y_Circle(void* circulo);

double getP3_Y_Circle(void* circulo);

double getEnergyCircle(void* circulo);

double getV1Circle(void* circulo);

double getV2Circle(void* circulo);

double getV3Circle(void* circulo);

void setIdCircle(int id, void* circulo);

void setXCircle(double x, void* circulo);

void setYCircle(double x, void* circulo);

void setRCircle(double r, void* circulo);

// void setP1Circle(double p1, void* circulo);

// void setP2Circle(double p2, void* circulo);

// void setP2Circle(double p3, void* circulo);

void setV1Circle(double v1, void* circulo);

void setV2Circle(double v2, void* circulo);

void setV3Circle(double v3, void* circulo);

void setEnergyCircle(double energy, void* circulo);

void drawCircle(circulo c, char* svgQry);

void printCircle(void* circulo);


#endif