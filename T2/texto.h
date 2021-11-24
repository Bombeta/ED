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

void setIdText(int id, void* text);

void setXText(double x, void* text);

void setYText(double y, void* text);

void setFillText(char* fill, void* text);

void setBorderText(char* border, void* text);

void print_Texto(text c);

void drawText(text t, char* svgQry);


#endif