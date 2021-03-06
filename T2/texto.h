#ifndef _H_TEXT
#define _H_TEXT


typedef void *text;

text cria_Texto(int id, double x, double y, char *fill, char *border, char* texto);

int getTexttId(void* text);

double getXText(void* text);

double getYText(void* text);

char* getFillText(void* text);

char* getBorderText(void* text);

char* getTipoText(void* text);

// double getP1Text(void* text);

double getP1_X_Text(void* text);

double getP1_X_Text(void* text);

double getV1Text(void* text);

void setIdText(int id, void* text);

void setXText(double x, void* text);

void setYText(double y, void* text);

void setFillText(char* fill, void* text);

void setBorderText(char* border, void* text);

void setX1Text(double x1, void* text);

void setY1Text(double y1, void* text);

void setV1Text(double v1, void* text);

//void setEnergyText(double energy, void* text);

//void print_Texto(text c);

//void drawText(text t, char* svgQry);


#endif