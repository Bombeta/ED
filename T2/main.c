#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "leituraGeo.h"
#include "leituraQry.h"
#include "parametros.h"
#include <string.h>
#include "StartSvg.h"

int main(int argc, char *argv[]) {
    // Declarar variáveis e inicializar
    FILE *arqGeo = NULL;
    FILE *arqQry = NULL;
    char *geo = NULL;
    char *qry = NULL;
    char *destGeo = NULL;
    char *destQry = NULL;
    char* comandosGeo[100];
    char* comandosQry[100];
    char *path = NULL;
    char *startGeo = NULL; 
    char *dest = NULL;
    char *startQry = NULL;
    char *svgGeo = NULL;
    char *svgQry = NULL;
    char *txtQry = NULL;
    char *nomeBarra = NULL;
    char *nomeBarra2 = NULL;
    int i = 0;
    int end = 1000;
    
    // Receber parametros
    path = recebePath(argc, argv, path);
    startGeo = recebeGeo(argc, argv, startGeo);
    startQry = recebeQry(argc, argv, startQry);
    dest = recebeDest(argc, argv, dest);
    
    // Alocar memória
    geo = (char *)malloc((strlen(startGeo)+ (strlen(path))+1)*sizeof(char));
      
    destGeo = (char *)malloc((strlen(dest) + (strlen(startGeo))+5)*sizeof(char));

    // Se -f começa com / então armazenar sem concatenar com path
    if (strcmp(path, "./") == 0 && startGeo[0] == '/') {
        strcpy(geo, startGeo);
    } else { // Senão concatena com path
        strcpy(geo, path);
        strcat(geo, startGeo);
    }
    
    // Pegar o nome do arquivo .geo
    nomeBarra = tiraBarra(startGeo, nomeBarra);
    
  
    // Pegar diretório de saida concatenada ao nome do arquivo .geo
    strcpy(destGeo, dest);
    strcat(destGeo, nomeBarra);
    svgGeo = nomeSvg(destGeo, svgGeo);

    // Abrir arquivo .geo
    arqGeo = fopen(geo, "r");
    if (arqGeo == NULL) {
       exit(0);
    }

    Kd k = createKdTree();
    
    readFileGeo(arqGeo, svgGeo, k);

    // Verificar se arquivo .qry foi informado e fazer as devidas operações
    if (startQry != NULL) {

        // Alocar memória
        qry = (char *)malloc((strlen(startQry)+ (strlen(path))+1)*sizeof(char));
        
        // Se -q começa com / então armazenar sem concatenar com path
        if (strcmp(path, "./") == 0 && startQry[0] == '/') {
            strcpy(qry, startQry);
        } else { // Senão concatena com path
            strcpy(qry, path);
            strcat(qry, startQry);
        }
        // Pegar nome do arquivo .qry
        nomeBarra2 = tiraBarra(startQry, nomeBarra2);
        destQry = (char *)malloc((strlen(dest) + strlen(nomeBarra) + strlen(nomeBarra2) + 7)*sizeof(char));

        // Pegar diretório de saída concatenada ao nome do arquivo .qry
        strcpy(destQry, dest);
        strcat(destQry, nomeBarra);
        
        // Abrir arquivo .qry
        arqQry = fopen(qry, "r");
        if (arqQry == NULL) {
            exit(0);
        }
       
        // Adicionar complemento -nomeArquivoQry
        strcat(destQry, "-");
        strcat(destQry, nomeBarra2);
        svgQry = nomeSvg(destQry, svgQry);
        txtQry = nomeTxt(destQry, txtQry);

        readFileQry(arqQry, svgQry, txtQry, k);

       
        fclose(arqQry);
        free(qry);
        free(destQry);
        free(startQry);
        free(txtQry);
        free(svgQry);
        free(nomeBarra2);
    }
    
    //Free restante variaveis
   
    fclose(arqGeo);
    free(geo);
    free(destGeo);
    free(path);
    free(startGeo);
    free(dest);
    free(svgGeo);
    free(nomeBarra);
    
    return 0;
}
