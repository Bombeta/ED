#ifndef _H_QRY
#define _H_QRY


typedef void* List;
typedef void* Pilha;
//typedef void* List;

void sobrepoem(int j, int k, int id, char* cor1, char* cor2, char* qryTxt, List listaCircle, List listaRect, List listaLinha);

void interno(int j, double x ,double y, char* qryTxt, List listaCircle, List listaRect, List listaLinha);

void mudar_cor(int j, char* border, char* fill, char* qryTxt, List listaCircle, List listaRect, List listaLinha, List listaText);

void remove_forma(int j, char* qryTxt, List listaCircle, List listaRect, List listaText,List ListaLinha);

void push_Pilha(int pd, int i, Pilha *vetPilha, List listaCircle, List listaRect, List listaLinha, List listaText);

void pop_Pilha(int pd, int i, double dx, double dy, double prop, char *qryTxt, Pilha *vetPilha, List listaCircle, List listaRect, List listaLinha, List listaText);

#endif