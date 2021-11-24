#ifndef ___FUNCTIONS_H_
#define ___FUNCTIONS_H_

struct structCirculo {
    int id;
    float raio, x, y;
    char cor1[20], cor2[20];
    struct structCirculo* next;
};
typedef struct structCirculo circulo;

struct structRetangulo {
    int id;
    float altura, largura, x, y;
    char cor1[20], cor2[20];
    struct structRetangulo* next;
};
typedef struct structRetangulo retangulo;

struct structTexto {
    float x, y;
    char texto[50];
    struct structTexto* next;
};
typedef struct structTexto texto;

struct structResult {
    float x, y, w, h;
};
typedef struct structResult resultRet;

// Adiciona extensão .svg ao fim da string
char* nomeSvg(char *nome, char *filename);
// Adiciona extensão .txt ao fim da string
char* nomeTxt(char *nome, char *filename);
// Pega apenas o nome do arquivo (geo ou qry)
char* tiraBarra(char *nome, char *filename);
// Copia o conteudo de um arquivo svg para outro
void copiaSvg(char *entrada, char *saida);
// Verifica se numero de figuras inferior ao comando nx
int verificaFim(int i, int end);

#endif
