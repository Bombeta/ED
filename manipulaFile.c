#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "manipulaFile.h"
#include "StartSvg.h"
#include "lista.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "pilha.h"
#include "fila.h"

FILE* abreFileGeo(FILE *arq, char *DirGeo){

	arq = fopen(DirGeo, "r");

    if(arq == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }

    return arq;
}

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
	double dx, dy, prop;
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
	char tipo;

	int sizeList = 0;
	int tamanho = 0;

	bool interno;
	bool soprepoem;

	Pilha vetPilha[10];
	Fila vetFila[10];

	FILE* saidaTxt;
	FILE* saidaQry;



	arqSvg = fopen("saida.svg", "w");

    if(arqSvg == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

    cria_SVG(arqSvg);

	List l = createLista();
	// List listaRect = createLista();
	// List listaText = createLista();

	// Pilha pilhaCircle = createPilha();
	// Pilha pilhaRect = createPilha();
	// Pilha pilhaText = createPilha();
	
	//Já está criando as 10 pilhas

	for(i=0;i<10;i++){
		Pilha p = createPilha();
		vetPilha[i] = p;
		tamanho = lengthP(vetPilha[i]);
		printf("tamanho da pilha: %d\n", tamanho);
	}

	printf("\n");

	for(i=0;i<10;i++){
		Fila f = createFila();
		vetFila[i] = f;
		//tamanho = lengthF(vetFila);
		printf("tamanho da fila: %d\n", tamanho);
	}
	
	

	// tamanho = lengthP(VetPilha[0]);
	//printf("tamanho da pilha eh: %d", tamanho);

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
	
				//arqSvg = fopen("saida.svg","a+");

				desenha_Circulo("saida.svg", r, x, y, fill, border);		
			
				//fclose(arqSvg);
				tipo = 'c';

				/*Adiciona um circulo a lista */
				circulo C = cria_Circulo(id, r, x, y, fill, border, tipo);

				insert(l, C);

				// printf("\n entrou aqui: %d", length(l));

				// qtd_circulo = qtd_circulo + 1;

				// printf("\nqtd circulo %d\n", qtd_circulo);
							
			}

			
			if(strcmp(fig,"r") == 0)
			{	
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &w, &h, &x, &y, fill, border);
				
				//arqSvg = fopen("saida.svg", "a+"); 

				desenha_Retangulo("saida.svg", w, h, x, y, fill, border); 	
				
				//fclose(arqSvg);
				tipo = 'r';

				/*Adiciona um retangulo a lista */
				retangulo R = cria_Retangulo(id, w, h, x, y, fill, border, tipo);
				
				insert(l, R);

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
			
			/*Testar erro aqui */

			if(strcmp(fig, "t") == 0)
			{
				fflush(stdin);
				fscanf(arq, "%d %lf %lf %s %s", &id, &x, &y, fill, border);
				
				fgets(texto,100,arq);			

				
				//arqSvg = fopen("saida.svg", "a+");
		
				desenha_Texto("saida.svg", x, y, fill, border, texto);

				// /*Adiciona um texto a lista */
				text T = cria_Texto(id, x, y, fill, border, texto);

				insert(l, T);
				
				//fclose(arqSvg);
				
			}		
		}		
	}

	//* A cópia está funcionando */
	// List listaCircleQry = listaCircle;
	// List listaRectQry = listaRect;
	// List listaTextQry = listaTextQry ;
	//List listaLinhaQry;

	arqSvg = fopen("saida.svg","a+");
	saidaTxt = fopen("saida.txt", "a+");
	fprintf(arqSvg, "</svg>");
	
	/*comandos qry */
	qry = fopen("/home/bombeta/Área de Trabalho/Pasta teste/pilha-teste.qry", "r");
	// if(qry != NULL){
	// 	saidaQry = fopen("saidaQry.svg", "a");
	// 	cria_SVG(saidaQry);
	// }
	
	saidaQry = fopen("saidaQry.svg", "w");

    if(saidaQry == NULL)
	{
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

	cria_SVG(saidaQry);

	if(qry == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(qry,"%s", &fig))!=EOF)
		{	

			// printf("\n%c\n", fig);

			// Cheguei a conclusão que n erro do valgrind é a parte q ele tenta achar a figura com ID 4 mas n acha pois é um retangulo ae crasha
			if(strcmp(fig,"o?") == 0)
			{	
				printf("Entrou comando o?\n");
				//printf("ENTREI\n");
				fscanf(qry, "%d %d %d %s %s\n", &j, &k, &id, &cor1, &cor2);
				copiaTxt(saidaTxt,j,k);

				saidaQry = fopen("saidaQry.svg", "a+");


				/* Está funcionando */ 
				/* Achou um circulo */
				void* figura1_Circ = searchList(l, j);
				escreveFigura(saidaTxt,j,"circulo");
				//printCircle(figura1_Circ);
				x1 = getXCircle(figura1_Circ);
				y1 = getYCircle(figura1_Circ);
				printf("Circulo 1 X = %.2lf\n", x1);
				printf("CIrculo 1 Y = %.2lf\n", y1);

				

				if(figura1_Circ == NULL){

					void* figura1_Ret = searchList(l, j);
					escreveFigura(saidaTxt,j,"retangulo");
					
				}

				void* figura2_Circ = searchList(l, k);
				escreveFigura(saidaTxt,k,"circulo");
				x2 = getXCircle(figura2_Circ);
				y2 = getYCircle(figura2_Circ);
				printf("Circulo 2 X = %.2lf\n", x2);
				printf("CIrculo 2 Y = %.2lf\n", y2);
				

				if(figura2_Circ == NULL){
					void* figura2_Ret = searchList(l, k);
					escreveFigura(saidaTxt,k,"retangulo");
					
				}

				// *Comparação entre as figuras *//
				// Compara dois circulos
				if(figura1_Circ != NULL && figura2_Circ != NULL){
					//soprepoem = CompareTwoCircle();

					//desenha_Linha();

					// if(soprepoem == true){

					// }else{

					// }
				}
				

				fprintf(saidaTxt, "\n");
				fclose(saidaQry);
			}

			
			if(strcmp(fig,"i?") == 0)
			{	

				printf("ENTROU COMANDO I?\n");

				fscanf(qry,"%d %lf %lf", &j, &x, &y);

				copiaTxt(saidaTxt,j,k);

				/* Está funcionando */
				/*Procura na lista de circulo */
				void* figura1 = searchList(l, j);
				escreveFigura(saidaTxt,j,"circulo");
				interno = internoCirculo(figura1, x, y);

				// Só para lembrar n tem arqSvg, aqui é arqQry
				//arqSvg = fopen("saida.svg", "a+");

				if(interno == true){
					escreveInterno(saidaTxt,"interno");
					desenhaInterno(arqSvg,x,y,"blue");
				}else if(interno == false){
					escreveInterno(saidaTxt,"externo");
					desenhaInterno(arqSvg,x,y,"magenta");
				}


				/*Procura na lista de retangulo */
				if(figura1 == NULL){
					void* figura2 = searchList(l , k);
					escreveFigura(saidaTxt,k,"retangulo");
				}

				//fclose(arqSvg);

			
			}
			

			/* Comando está funcionando  FULL */
			if(strcmp(fig, "pnt") == 0)
			{	
				fscanf(qry, "%d %s %s", &j, &border, &fill);

				fprintf(saidaTxt, "pnt %d %s %s", j, &border, &fill);
				fprintf(saidaTxt,"\n");
				
				/* Está funcionando */
				/*Procura na lista de circulo */
				void* figura1 = searchList(l, j);
				
				if(figura1 != NULL){

					// x = getXCircle(figura1);
					// y = getYCircle(figura1);
					// r = getRCircle(figura1);
					setBorderCircle(fill, figura1);
					setFillCircle(border, figura1);
					//char* saidaQry = malloc(sizeof(char)*13);
					//desenha_Circulo("saidaQry.svg", r, x, y, fill, border);
					fprintf(saidaTxt, "%lf %lf", x, y);
					fprintf(saidaTxt,"\n");
				}
			
				/*Procura na lista de retangulo */
				void* figura2 = searchList(l, j);

				if(figura1 == NULL && figura2 != NULL){
					
					// x = getXRect(figura2);
					// y = getYRect(figura2);
					// w = getWidthRect(figura2);
					// h = getHeightRect(figura2);

					// printf("Comando pnt: \n");
					// printf("x: %.2lf\n", x);
					// printf("y: %.2lf\n", y);
					// printf("w: %.2lf\n", w);
					// printf("h: %.2lf\n", h);

					setBorderRect(fill, figura2);
					setFillRect(border, figura2);
					//desenha_Retangulo("saidaQry.svg", w, h, x, y, fill, border);
					fprintf(saidaTxt, "%lf %lf", x, y);
					fprintf(saidaTxt,"\n");

				}

				/*Procura um texto na lista */

				/* RODAR E VER SAIDA TXT NÃO FUNCIONA */
				if(figura1 == NULL && figura2 == NULL){
					void* texto1 = searchList(l, j);
					
					x = getXText(texto1);
					y = getYText(texto1);
					strcpy(texto, getText(texto1));
					//texto = getText(texto1);

					desenha_Texto("saidaQry.svg", x, y, fill, border, texto);
					fprintf(saidaTxt, "saida texto %lf %lf", x, y);
					fprintf(saidaTxt,"\n");
				}

			}
			
			drawListFigure(l);
			//drawListRect(l);
			

			
			// if(strcmp(fig, "delf") == 0)
			// {
			// 	fscanf(qry, "%d", &j);
			// }

			/*Pilha Funciona falta printar */
			if(strcmp(fig, "psh") == 0)
			{
				fscanf(qry, "%d %d", &pd, &i);

				//Procura na lista de circulo 
				void* figura1 = searchList(l, i);
				
				if(figura1 != NULL){

					id = getCircleId(figura1);	
					x = getXCircle(figura1);					
					y = getYCircle(figura1);
					r = getRCircle(figura1);

					strcpy(fill, "black");
					strcpy(border, "red");
					

					circulo C = cria_Circulo(id, r, x, y, fill, border, 'c');

					push(vetPilha[pd], C);

					
										
				}
				// printf("Comando pnt: \n");
				// printf("x: %.2lf\n", x);
				// printf("y: %.2lf\n", y);
				// printf("r: %.2lf\n", r);		
								
				//Procura na lista de retangulo
				void* figura2 = searchList(l, i);

				if(figura1 == NULL && figura2 != NULL){
					
					x = getXRect(figura2);
					y = getYRect(figura2);
					w = getWidthRect(figura2);
					h = getHeightRect(figura2);

					// printf("Comando pnt: \n");
					// printf("x: %.2lf\n", x);
					// printf("y: %.2lf\n", y);
					// printf("w: %.2lf\n", w);
					// printf("h: %.2lf\n", h);

					retangulo R = cria_Retangulo(id, w, h, x, y, fill, border, 'r');

					push(vetPilha[pd], R);



				}

				//Procura um texto na lista 

				// RODAR E VER SAIDA TXT NÃO FUNCIONA 
				if(figura1 == NULL && figura2 == NULL){
					void* texto1 = searchList(l, j);
					
					x = getXText(texto1);
					y = getYText(texto1);
					strcpy(texto, getText(texto1));
					//texto = getText(texto1);
					
				}

				
			}
			
			int tamanhoP = lengthP(vetPilha[pd]);
			printf("Tamanho pilha empilhada %d\n", tamanhoP);
			

			/* Não entendi */
			if(strcmp(fig, "pop") == 0)
			{
				fscanf(qry, "%d", &pd);

				pop(vetPilha[pd]);

			}

			int tamanhoPop = lengthP(vetPilha[pd]);
			printf("Tamanho final da pilha : %d\n", tamanhoPop);


			/*TESTAR AS FILAS */

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
		saidaQry = fopen("saidaQry.svg", "a+");
		fprintf(saidaQry, "</svg>");
		fclose(saidaQry);
	}

	
	
	




	
	fclose(arqSvg);
	fclose(arq);
    //free(lista);
	// free(DirGeo);
	// free(outSvg);

}
