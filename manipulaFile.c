#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manipulaFile.h"
#include "StartSvg.h"
#include "lista.h"
#include "circulo.h"

FILE* abreFileGeo(FILE *arq, char *DirGeo){

	printf("\nAbrindo file Geo");
	printf("\n**********");
	printf("\nDirGeo: %s\n", DirGeo);

    arq = fopen(DirGeo, "r");

    if(arq == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }

    return arq;
}

// FILE* abreFileSvg(FILE* arqSvg, char *outSvg){
    
//     arqSvg = fopen(outSvg, "w");

//     if(arqSvg == NULL)
// 	{
// 		printf("Arquivo SVG não foi criado!\n");
// 		exit(0);
// 	}

//     cria_SVG(arqSvg);

//     return arqSvg;
// }

void readFile(FILE *arq, char *DirGeo, FILE*arqSvg){

    char nx[3] = "nx";
    int tam = 1000;	
    char fig[5];

    int id;
    int xd;

	int qtd_circulo = 0;
	int qtd_retangulo = 0;
	int qtd_linha = 0;
	int qtd_texto = 0;

	int linha = 0;

    double r, x, y, w, h, x1, y1, x2, y2;
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];

	int tamanho = 0;

	arqSvg = fopen("saida.svg", "w");

    if(arqSvg == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	List li = createLista();

	tamanho = length(li);

	printf("Tamanho da lista: %d", tamanho);

	arq = fopen(DirGeo, "r");

    if(arq == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(arq,"%s", &fig))!=EOF)
		{	

			// printf("\n%c\n", fig);

			if(strcmp(fig,"c") == 0)
			{	
				fscanf(arq, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
	
				arqSvg = fopen("saida.svg","a+");

				desenha_Circulo(arqSvg, r, x, y, fill, border);		
			
				fclose(arqSvg);

				/*Adiciona um circulo a lista */
				circulo C = cria_Circulo(id, r, x, y, fill, border);

				insert(li, C);

				printf("\n entrou aqui: %d", length(li));

				qtd_circulo = qtd_circulo + 1;

				printf("\nqtd circulo %d\n", qtd_circulo);
							
			}

			
			if(strcmp(fig,"r") == 0)
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);
				
				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Retangulo(arqSvg, w, h, x, y, fill, border); 	
				
				fclose(arqSvg);

				// /*Adiciona um retangulo a lista */
				// Retangulo R = cria_Retangulo(lista, id, x, y, w, h, fill, border); 

				// insert(li, R);

				qtd_retangulo = qtd_retangulo + 1;

				printf("\nqtd retangulo %d\n", qtd_retangulo);
						
			}

			if(strcmp(fig, "l") == 0)
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s\n", &id, &x1, &y1, &x2, &y2, &color);

				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Linha(arqSvg, x1, x2, y1, y2, color);

				fclose(arqSvg);
			}
			
			/*Veriricar Valgrind linha 314*/
			if(strcmp(fig, "t") == 0)
			{
				fscanf(arq, "%d %lf %lf %s %s\n", &id, &x, &y, fill, border);
				fgets(texto,100,arq);

				arqSvg = fopen("saida.svg", "a+");
		
				desenha_Texto(arqSvg, x, y, fill, border, texto);

				// /*Adiciona um texto a lista */
				// Texto T = cria_Texto(lista, id, x, y, fill, border);

				// insert(li, T);
				
				fclose(arqSvg);
				
			}

			

			
			
		}

		
	}
	
	arqSvg = fopen("saida.svg","a+");
	fprintf(arqSvg, "</svg>");


	
	fclose(arqSvg);
	fclose(arq);
    //free(lista);
	// free(DirGeo);
	// free(outSvg);

}
