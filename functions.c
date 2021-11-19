#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char* nomeSvg(char *nome, char *filename) {
    int end = strlen(nome);
    filename = (char *)malloc((end + 5)*sizeof(char));
    strcpy(filename, nome);
    strcat(filename, ".svg");
    return filename;
}

char* nomeTxt(char *nome, char *filename) {
    int c = strlen(nome);
    filename = (char *)malloc((c+5)*sizeof(char));
    strcpy(filename, nome);
    strcat(filename, ".txt");
    return filename;
}

char* tiraBarra(char *nome, char *filename) {
    char *aux = NULL;
    int i, end;
    aux = strrchr(nome, '/');
    if (aux != NULL) {
        i = strlen(aux) - 4;
        filename = (char *)malloc((i+1)*sizeof(char));
        strncpy(filename,aux, i);
        end = i;
        for (i=0;i<end-1;i++) {
            filename[i] = filename[i+1];
        }
        filename[i] = '\0';
    } else {
        i = strlen(nome) - 4;
        filename = (char *)malloc((i+1)*sizeof(char));
        strncpy(filename, nome, i);
        filename[i] = '\0';
    }
    return filename;
}

void copiaSvg(char *entrada, char *saida) {
    FILE *arqEntrada, *arqSaida;
    char ch;
    arqEntrada = fopen(entrada, "r");
    arqSaida = fopen(saida, "w");
    while ((ch = getc(arqEntrada))) {
        if (feof(arqEntrada))
            break;
        putc(ch,arqSaida);
    }
    fclose(arqEntrada);
    fclose(arqSaida);
}

int verificaFim(int i, int end) {
    if (i >= end)
        return 1;
    else
        return 0;
}
