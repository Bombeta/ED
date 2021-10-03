#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "manipulaFile.h"
#include "StartSvg.h"
#include "lista.h"

FILE* abreFileGeo(FILE *arq, char *DirGeo){

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

void readFile(FILE *arq, char *DirGeo, FILE*arqSvg, char *outSvg){

    char nx[3] = "nx";
    int tam = 1000;	
    char fig[5];

    int id;
    int xd;

    double r, x, y, w, h, x1, y1, x2, y2;
	char fill[100];
	char border[100];
	char color[100];
	char txto;

	// Lista *li;
	// li = create_lista();
   

	// void* circulo_teste;
	// void* retangulo_teste;
	// void* linhas_teste;


	arqSvg = fopen("saida.svg", "w");

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

		while((fscanf(arq,"%s", &fig))!=EOF)
		{	

			if(strcmp(fig,"c") == 0)
			{	
				fscanf(arq, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
				
				/*Adiciona um circulo a lista */
				// cria_Circulo(lista, id, x, y, r, fill, border);

				arqSvg = fopen("saida.svg","a+");

				desenha_Circulo(arqSvg, r, x, y, fill, border);		
			
				fclose(arqSvg);
							
			}

			
			if(strcmp(fig,"r") == 0)
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);
				
				/*Adiciona um retangulo a lista */
				// cria_Retangulo(lista, id, x, y, w, h, fill, border); 

				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Retangulo(arqSvg, w, h, x, y, fill, border); 	
				
				fclose(arqSvg);
						
			}

			if(strcmp(fig,"l") == 0)
			{
				fscanf(arq, "%d %lf %lf %lf %lf %s\n", &id, &x1, &y1, &x2, &y2, &color);

				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Linha(arqSvg, x1, x2, y1, y2, color);

				fclose(arqSvg);
			}
			
			/*Veriricar Valgrind linha 314*/
			if(strcmp(fig,"t") == 0)
			{
				fscanf(arq, "%d %lf %lf %s %s\n", &id, &x, &y, fill, border);
				
				// cria_Texto(lista, id, x, y, fill, border);		
				
				arqSvg = fopen("saida.svg", "a+");
		
				desenha_Texto(arqSvg, x, y, fill, border);				
				
				fclose(arqSvg);
				
			}

			
			
		}		
	}

	arqSvg = fopen(outSvg,"a");
	fprintf(arqSvg, "</svg>");


	// libera_lista(li);
	fclose(arqSvg);
	fclose(arq);
    //free(lista);
	// free(DirGeo);
	// free(outSvg);

}
