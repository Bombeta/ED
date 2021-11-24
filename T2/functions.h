#ifndef ___FUNCTIONS_H_
#define ___FUNCTIONS_H_

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
