#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manipulaFile.h"
#include "StartSvg.h"
#include "lista.h"

// FILE* abreFileGeo(FILE *arq, char *DirGeo){

//     arq = fopen(DirGeo, "r");

//     if(arq == NULL)
//     {
//         printf("Arquivo GEO não foi aberto!\n");
// 		exit(0);
//     }

//     return arq;
// }

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

void readFile(FILE *arq, char *DirGeo, FILE*arqSvg, char *outSvg){

    char nx[3] = "nx";
    int tam = 1000;	
    char fig;

    int id;
    int xd;

    double r, x, y, w, h, x1, y1, x2, y2;
	char fill[100];
	char border[100];
	char color[100];
	char txto;

	// Lista *li;
	// // li = cria_lista();
	// // int vazia = lista_vazia(Lista* li);
	


    LIST* lista = (LIST*) malloc(sizeof(LIST));
	inicia_Lista(lista);


	arqSvg = fopen(outSvg, "w");

    if(arqSvg == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	arq = fopen(DirGeo, "r");

    if(arq == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		fgets(nx,3,arq);

		if(strncmp(nx,"nx",2) == 0)
		{
			fscanf(arq,"%d", &tam);
			printf("O tamanho do vetor eh: %d\n",tam);

		}


		

		while((fscanf(arq,"%c", &fig))!=EOF)
		{	

			printf("\n%c\n", fig);

			if(fig=='c')
			{	
				fscanf(arq, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
				
				/*Adiciona um circulo a lista */
				cria_Circulo(lista, id, x, y, r, fill, border);

				arqSvg = fopen(outSvg,"a");

				desenha_Circulo(arqSvg, lista);		
			
				fclose(arqSvg);
							
			}

			
			if(fig=='r')
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);
				
				/*Adiciona um retangulo a lista */
				cria_Retangulo(lista, id, x, y, w, h, fill, border); 

				arqSvg = fopen(outSvg, "a+"); 

				desenha_Retangulo(arqSvg, lista); 	
				
				fclose(arqSvg);
						
			}

			if(fig=='l')
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, &color);


				fclose(arqSvg);
			}
			
			/*Veriricar Valgrind linha 314*/
			if(fig=='t')
			{
				fscanf(arq, "%d %lf %lf %s %s\n", &id, &x, &y, fill, border);
				
				cria_Texto(lista, id, x, y, fill, border);		
				
				arqSvg = fopen(outSvg, "a+");
		
				desenha_Texto(arqSvg, lista, arq);				
				
				fclose(arqSvg);
				
			}

			
			
		}

		exibir_Lista(lista);
	}

	if(x == 1){
		printf("LISTA VAZIA!");
	}else if(x == 0){
		printf("A LISTA NÃO ESTÁ VAZIA");
	}

    arqSvg = fopen(outSvg,"a");
	fprintf(arqSvg, "</svg>");


	
	fclose(arqSvg);
	fclose(arq);
    free(lista);
	// free(DirGeo);
	// free(outSvg);

}
