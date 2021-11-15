#ifndef _H_QRY
#define _H_QRY


typedef void* List;

void sobrepoem(int j, int k, List l, int id, char* cor1, char* cor2, FILE* saidaTxt);

void interno(int j, double x ,double y ,List l, FILE* saidaTxt);

void mudar_cor(int j, char* border, char* fill, List l, FILE* saidaTxt);

#endif