#ifndef _H_LISTA
#define _H_LISTA
#define MAX 9000

typedef struct stRetangulo
{
	int id;
	double x;	
	double y;
	double w;
	double h;

	char border[50];
	char fill[50];

}StRetangulo;

typedef struct stCirculo
{
	int id;
	double x;
	double y;
	double r;

	char border[50];
	char fill[50];

}StCirculo;

typedef struct stTexto
{
	int id;
	float x;
	float y;
	char border[50];
	char fill[50];
}StTexto; 

typedef struct
{
	int nroC;
	int nroR;
	int nroT;
	int nroElem;
	StCirculo C[MAX];
	StRetangulo R[MAX];
	StTexto T[MAX];

}LIST;

void inicia_Lista(LIST* l);

void exibir_Lista(LIST* l);

void remove_Lista(LIST* l, int id);

void remove_Lista_2(LIST* l, int id, int xd); 

#endif 