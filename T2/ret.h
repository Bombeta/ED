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

void setIdRect(int id, void* retangulo);

void setWidthRect(double w, void* retangulo);

void setHeigthRect(double h, void* retangulo);

void setXRect(double x, void* retangulo);

void setYRect(double y, void* retangulo);

void setFillRect(char* fill, void* retangulo);

void setBorderRect(char* border, void* retangulo);

void drawRect(retangulo r, char* svgQry);


#endif