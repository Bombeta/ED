#ifndef _H_LINHAS
#define _H_LINHAS

typedef void *linha;

int getId(void* linha);

double getX1(void* linha);

double getX2(void* linha);

double getY1(void* linha);

double getY2(void* linha);

char cor(void* linha);

void setId(int id, void* linha);

void setX1(double x1, void* linha);

void setX2(double x2, void* linha);

void setY1(double y1, void* linha);

void setY2(double y2, void* linha);

void setCor(char* cor, void* linha);

#endif