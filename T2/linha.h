#ifndef _H_LINHA
#define _H_LINHA

typedef void *linha;

linha cria_Linha(int id, double x1, double y1, double x2, double y2, char* color);

int getIdLinha(void* linha);

double getX1Linha(void* linha);

double getY1Linha(void* linha);

double getX2Linha(void* linha);

double getY2Linha(void* linha);

char* getColorLinha(void* linha);

char getTipoLinha(void* linha);

double getP1Linha(void* linha);

double getP2Linha(void* linha);

void setIdLinha(int id, void* linha);

void setX1Linha(double x1, void* linha);

void setY1Linha(double y1, void* linha);

void setX2Linha(double x2, void* linha);

void setY2Linha(double y2, void* linha);

void setColorLinha(char* color, void* linha);

void drawLine(linha l, char* svgQry);

//void print_Linha(linha l);

#endif