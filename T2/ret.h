#ifndef _H_RET
#define _H_RET


typedef void *retangulo;

retangulo cria_Retangulo(int id, double w, double h, double x, double y, char *fill, char *border);

int getRectId(void* retangulo);

double getWidthRect(void* retangulo);

double getHeightRect(void* retangulo);

double getXRect(void* retangulo);

double getYRect(void* retangulo);

char* getFillRect(void* retangulo);

char* getBorderRect(void* retangulo);

char* getTipoRect(void* circulo);

// double getP1Rect(void* retangulo);

// double getP2Rect(void* retangulo);

// double getP3Rect(void* retangulo);

// double getP4Rect(void* retangulo);

double getP1_X_Rect(void* retangulo);

double getP1_Y_Rect(void* retangulo);

double getP2_X_Rect(void* retangulo);

double getP2_Y_Rect(void* retangulo);

double getP3_X_Rect(void* retangulo);

double getP3_Y_Rect(void* retangulo);

double getP4_X_Rect(void* retangulo);

double getP4_Y_Rect(void* retangulo);

double getV1Rect(void* retangulo);

double getV2Rect(void* retangulo);

double getV3Rect(void* retangulo);

double getV4Rect(void* retangulo);

void setIdRect(int id, void* retangulo);

void setWidthRect(double w, void* retangulo);

void setHeigthRect(double h, void* retangulo);

void setXRect(double x, void* retangulo);

void setYRect(double y, void* retangulo);

void setFillRect(char* fill, void* retangulo);

void setBorderRect(char* border, void* retangulo);

void setEnergyRect(double energy, void* retangulo);

void drawRect(retangulo r, char* svgQry);


#endif