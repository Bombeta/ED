#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


/*Aloca o tamanho */
char* aloca_tamanho(int len, char* str)
{
	// char *str = NULL;
	str = (char*) malloc(sizeof(char)*(len)+5);
	return str;
	
}

/* Tratando a barra no final */
char *arruma_path(char *str)
{
	char ultimo = str[strlen(str) - 1];
	char *aux; 
	if(ultimo != '/')
	{
		aux = (char*) malloc(sizeof(char) *strlen(str)+5);
		strcpy(aux, str);
		strcat(aux, "/");
		free(str);
		return aux;
	}
	return str;
}
	
// char *criaString(char *dir, char *nome, char *ext)
// {	
// 	char *aux = malloc(sizeof(char)* strlen(dir) + 5);
// 	strcpy(aux, dir);
// 	aux = concatena(aux, nome);
// 	aux = concatena(aux, ext);
// 	return aux;

// }

char *concatena(char *str, char *str2)
{	
	char *aux;
	int l1;
	int l2;
	int l3;

	l1 = strlen(str);
	l2 = strlen(str2);
	l3 = l1 + l2;

	aux = (char*) malloc(sizeof(char)*(l3)+5);
	aux = strcpy(aux,str);
	aux = strcat(aux,str2);
	// printf("****8");
	// printf("\nresultado da concatenação: %s\n", aux);
	return aux;
}


char *tiraGeo(char *str)
{
	char *aux;
	int i;
	int l;
	char c;

	l = strlen(str);
	l  = l + 5;
	aux = (char *) malloc(sizeof(char)* (l) + 5);
	strcpy(aux, str);


	for(i=0;i<l;i++)
	{
		if(aux[i]=='.')
		{
			aux[i] = '\0';
			return aux;
		}
	}
}

char* recebeEntrada(int argc,char *argv[],char *DirIn)
{
   	int i = 1;

	// printf("\nentrou aqui\n");

	    
   while(i<argc)
   {

        if(strcmp("-e", argv[i]) == 0)
		{   

			int l = 0; /* l eh o comprimento */ 
			l = strlen(argv[i+1]);
			aloca_tamanho(l,DirIn);
			strcpy(DirIn,argv[i+1]);
            // printf("DirIn: %s", DirIn);
			DirIn = arruma_path(DirIn);	
			
								
		}
		i = i + 2;
   }    

    // printf("\n***************\n");
	// printf("\nDirnIn que saiu: %s\n", DirIn);
   	return DirIn;
}

// char* recebeEntrada(int argc,char *argv[],char *DirTwo)
// {
//     int i = 1;
// 	
// 	printf("ENTROU-2");
//     while(i<argc)
// 	{

//         if(strcmp("-e", argv[i]) == 0)
// 		{
// 			int l = 0; /* l eh o comprimento */ 
// 			l = strlen(argv[i+1]);
// 			DirTwo = aloca_tamanho(l, str);
// 			strcpy(DirTwo, argv[i+1]);
// 			DirTwo = arruma_path(DirTwo);	
		
// 			printf("DirTwo: %s", DirTwo);

// 		}

// 		i = 1 + 2;
//     }

//     return DirTwo;

// }
char* recebeGeo(int argc,char *argv[],char *arqGeo){
    int i = 1;
	
    while(i<argc)
	{
        if(strcmp("-f", argv[i]) == 0)
		{
			int l = 0;
			l =strlen(argv[i+1]);
			arqGeo = aloca_tamanho(l, arqGeo);
			strcpy(arqGeo, argv[i+1]);
			
			printf("\n ARQGEO: %s\n", arqGeo);
		}
		i= i + 2;
    }

    return arqGeo;

}
char* recebeCons(int argc,char *argv[],char *arqCons){
    int i = 1;
	
    while(i<argc){
         if(strcmp("-q", argv[i]) == 0)
		{
			int l;
			l = strlen(argv[i+1]);
			aloca_tamanho(l, arqCons);
			strcpy(arqCons,argv[i+1]);
			
			
		}
		i= i + 2;
    }

    return arqCons;
}
char* recebeDiretorioSaida(int argc, char *argv[],char *DirOut){
    int i = 1;
	
    while(i<argc){
        if(strcmp("-o", argv[i]) == 0)
		{	
			int l = 0;
			l =strlen(argv[i+1]);
			DirOut = aloca_tamanho(l, DirOut);
			strcpy(DirOut, argv[i+1]);
			DirOut = arruma_path(DirOut);
			
		}
		i = i + 2;
    }

    return DirOut;
}