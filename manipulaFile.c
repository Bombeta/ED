#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "manipulaFile.h"
#include "StartSvg.h"
#include "lista.h"
#include "circulo.h"
#include "ret.h"

FILE* abreFileGeo(FILE *arq, char *DirGeo){

	// printf("\nAbrindo file Geo");
	// printf("\n**********");
	// printf("\nDirGeo: %s\n", DirGeo);

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

void readFile(FILE *arq, FILE *qry, char *DirGeo, char *DirQry, FILE*arqSvg){

    char nx[3] = "nx";
    int tam = 1000;	
    char fig[5];

	int i,j,k;

    int id;

	int pd;		/*Identificador para pilha */
	int fd;		/*Identificador para fila */
	int ld;		/*Identificador para lista */
    
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
	char cor1[100];
	char cor2[100];

	int sizeList = 0;
	int tamanho = 0;

	bool interno;

	FILE* saidaTxt;

	arqSvg = fopen("saida.svg", "w");

    if(arqSvg == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	List listaCircle = createLista();
	List listaRect = createLista();
	List listaText = createLista();

	tamanho = length(listaCircle);

	// printf("Tamanho da lista: %d", tamanho);

	arq = fopen(DirGeo, "r");

	//* Comandos Geo *//
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
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
	
				arqSvg = fopen("saida.svg","a+");

				desenha_Circulo(arqSvg, r, x, y, fill, border);		
			
				fclose(arqSvg);

				/*Adiciona um circulo a lista */
				circulo C = cria_Circulo(id, r, x, y, fill, border);

				insert(listaCircle, C);

				// printf("\n entrou aqui: %d", length(l));

				// qtd_circulo = qtd_circulo + 1;

				// printf("\nqtd circulo %d\n", qtd_circulo);
							
			}

			
			if(strcmp(fig,"r") == 0)
			{	
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);
				
				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Retangulo(arqSvg, w, h, x, y, fill, border); 	
				
				fclose(arqSvg);

				/*Adiciona um retangulo a lista */
				retangulo R = cria_Retangulo(id, w, h, x, y, fill, border);
				
				insert(listaRect, R);

				// qtd_retangulo = qtd_retangulo + 1;

				// printf("\nqtd retangulo %d\n", qtd_retangulo);
						
			}

			if(strcmp(fig, "l") == 0)
			{	
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %lf %lf %s\n", &id, &x1, &y1, &x2, &y2, &color);

				arqSvg = fopen("saida.svg", "a+"); 

				desenha_Linha(arqSvg, x1, y1, x2, y2, color);

				fclose(arqSvg);
			}
			
			/*Veriricar Valgrind linha 314*/
			if(strcmp(fig, "t") == 0)
			{
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %s %s", &id, &x, &y, fill, border);
				
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
	saidaTxt = fopen("saida.txt", "a+");
	fprintf(arqSvg, "</svg>");
	
	/*comandos qry */
	qry = fopen("/home/bombeta/Área de Trabalho/Pasta teste/teste.qry", "r");
	

	if(qry == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(qry,"%s", &fig))!=EOF)
		{	

			// printf("\n%c\n", fig);


			if(strcmp(fig,"o?") == 0)
			{	
				//printf("ENTREI\n");
				fscanf(qry, "%d %d %d %s %s\n", &j, &k, &id, &cor1, &cor2);
				copiaTxt(saidaTxt,j,k);

				/* Está funcionando */ 
				/* Achou um circulo */
				void* figura1 = searchListCircle(listaCircle, j);
				escreveFigura(saidaTxt,j,"circulo");
				// printCircle(figura1);
				

				if(figura1 == NULL){

					void* figura2 = searchListRect(listaRect, j);
					escreveFigura(saidaTxt,j,"retangulo");
					
				}

				void* figura2 = searchListCircle(listaCircle, k);
				escreveFigura(saidaTxt,k,"circulo");
				

				if(figura2 == NULL){
					figura2 = searchListRect(listaRect, k);
					escreveFigura(saidaTxt,k,"retangulo");
					
				}

				fprintf(saidaTxt, "\n");
			}

			
			if(strcmp(fig,"i?") == 0)
			{	
				fscanf(qry,"%d %lf %lf", &j, &x, &y);

				copiaTxt(saidaTxt,j,k);

				/* Está funcionando */
				/*Procura na lista de circulo */
				void* figura1 = searchListCircle(listaCircle, j);
				escreveFigura(saidaTxt,j,"circulo");
				interno = internoCirculo(figura1, x, y);

				arqSvg = fopen("saida.svg", "a+");

				if(interno == true){
					escreveInterno(saidaTxt,"interno");
					desenhaInterno(arqSvg,x,y,"blue");
				}else if(interno == false){
					escreveInterno(saidaTxt,"externo");
					desenhaInterno(arqSvg,x,y,"magenta");
				}


				/*Procura na lista de retangulo */
				if(figura1 == NULL){
					void* figura2 = searchListRect(listaRect, k);
					escreveFigura(saidaTxt,k,"retangulo");
				}

				fclose(arqSvg);

			
			}

			if(strcmp(fig, "pnt") == 0)
			{	
				fscanf(qry, "%d %s %s", &j, &border, &fill);

				copiaTxt(saidaTxt,j,k);

				arqSvg = fopen("saida.svg", "a+");

				/* Está funcionando */
				/*Procura na lista de circulo */
				void* figura1 = searchListCircle(listaCircle, j);

				setBorderCircle(border,figura1);	
				setFillCircle(fill,figura1);
				

				
				/*Procura na lista de retangulo */
				if(figura1 == NULL){
					void* figura2 = searchListRect(listaRect, k);
					escreveFigura(saidaTxt,k,"retangulo");
				}

				fclose(arqSvg);
	
			}
			
			
			// if(strcmp(fig, "delf") == 0)
			// {
			// 	fscanf(qry, "%d", &j);
			// }

			// if(strcmp(fig, "psh") == 0)
			// {
			// 	fscanf(qry, "%d %d", &pd, &i);
			// }

			// /* Não entendi */
			// if(strcmp(fig, "pop") == 0)
			// {
			// 	fscanf(qry, "%d %d ")
			// }

			// if(strcmp(fig, "inf") == 0)
			// {
			// 	fscanf(aqry,"%d %d", &fd, &i);
			// }

			// if(strcmp(fig, "rmf") == 0)
			// {
				
			// }

			// if(strcmp(fig, "ii") == 0)
			// {

			// }

			// if(strcmp(fig, "if") == 0)
			// {

			// }

			// if(strcmp(fig, "ia") == 0)
			// {

			// }

			// if(strcmp(fig, "id") == 0)
			// {

			// }

			// if(strcmp(fig, "da") == 0)
			// {

			// }

			// if(strcmp(fig, "dd") == 0)
			// {

			// }

			// if(strcmp(fig, "dpl") == 0)
			// {

			// }






		}		
	}

	
	
	




	
	fclose(arqSvg);
	fclose(arq);
    //free(lista);
	// free(DirGeo);
	// free(outSvg);

}
