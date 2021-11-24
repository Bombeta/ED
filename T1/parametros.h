#ifndef ___PARAMETROS_H_
#define ___PARAMETROS_H_

#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Garantir que tenha barra final do path
char* arrumaBarra(char* path);
// Receber parametro -e
char* recebePath(int argc, char *argv[], char *path);
// Receber parametro -f
char* recebeGeo(int argc, char *argv[], char *geo);
// Receber parametro -q
char* recebeQry(int argc, char *argv[], char *qry);
// Receber parametro -o
char* recebeDest(int argc, char *argv[], char *dest);

#endif
