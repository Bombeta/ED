#ifndef STRING_H
#define STRING_H
#endif

char *aloca_tamanho(int len);
char *arruma_path(char *str);
char *criaString(char *dir, char *nome, char *ext);
char *concatena(char *str, char *str2);
char *tiraGeo(char* str);
//char *nome_svg(char *str); 
//char *nome_txt(char *str); 

char* recebeEntrada(int argc, char *argv[], char* DirIn);
// char* recebeEntradaTwo(int argc,char *argv[],char *DirTwo);
char* recebeGeo(int argc,char *argv[],char *arqGeo);
char* recebeCons(int argc,char *argv[],char *arqCons);
char* recebeDiretorioSaida(int argc, char *argv[],char *DirOut);
