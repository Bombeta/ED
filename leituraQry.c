#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "leituraGeo.h"
#include "StartSvg.h"
#include "lista.h"
#include "circulo.h"
#include "ret.h"
#include "texto.h"
#include "pilha.h"
#include "fila.h"
#include "qry.h"
#include "lista.h"
#include "linha.h"
#include "leituraQry.h"

void readFileQry(FILE* arqQry, char* svgQry, char* txtQry, List listaCircle, List listaRect, List listaLinha, List listaText){

    /*COMANDOS QRY */

    char fig[5];

	int i,j,k;

    int id;

	int pd;		/*Identificador para pilha */
	int fd;		/*Identificador para fila */
	int ld;		/*Identificador para lista */
	int re;		/*Identificador para registrador */
	int ro;
	int rd;
			
    
	int qtd_circulo = 0;
	int qtd_retangulo = 0;
	int qtd_linha = 0;
	int qtd_texto = 0;

	//int linha = 0;

	double r, x, y, w, h, x1, y1, x2, y2;
	double dx, dy, prop;
	char fill[100];
	char border[100];
	char color[100];
	char texto[100];
	char cor1[100];
	char cor2[100];
	char tipo[12];
	char tipo1;
	char tipo2;

	int sizeList = 0;
	int tamanho = 0;

	Pilha vetPilha[10];
	Fila vetFila[10];
	List vetLista[10];

	
	FILE* saidaTxt;
	FILE* saidaQry;

    // if(qry != NULL){
	// 	saidaQry = fopen(svgQry, "a");
	// 	cria_SVG(saidaQry);
	// }


	//Pilha pilha = createPilha();
		
	//Já está criando as 10 pilhas

	for(i=0;i<10;i++){
		Pilha pilha = createPilha();
		vetPilha[i] = pilha;
		//tamanho = lengthP(vetPilha[i]);
		//printf("tamanho da pilha: %d\n", tamanho);
	}

	printf("\n");

	for(i=0;i<10;i++){
		Fila f = createFila();
		vetFila[i] = f;
		//tamanho = lengthF(vetFila);
		//printf("tamanho da fila: %d\n", tamanho);
	}
	
	for(i=0;i<10;i++){
		List l = createLista();
		vetLista[i] = l;
	}
	
	/*Nó de registradores */

	Node reg[10];

	for(i=0;i<10;i++){
		reg[i] = NULL;
	}


	saidaQry = fopen(svgQry, "a");

    if(saidaQry == NULL)
	{   
        printf("Entrou aqui");
		printf("Arquivo SVG não foi criado!\n");
		exit(0);
	}

	cria_SVG(saidaQry);


	//comandos qry
	if(arqQry == NULL)
    {
        printf("Arquivo GEO não foi aberto!\n");
		exit(0);
    }else
	{	

		while((fscanf(arqQry,"%s", &fig))!=EOF)
		{	


			
			//Ver pq o cria Linha não funciona 149
			if(strcmp(fig,"o?") == 0)
			{	
				printf("Entrou comando o?\n");
				printf("ENTREI\n");
				fscanf(arqQry, "%d %d %d %s %s\n", &j, &k, &id, &cor1, &cor2);
				//copiaTxt(saidaTxt,j,k);

				saidaQry = fopen(svgQry, "a+");

				sobrepoem(j, k, id, cor1, cor2, txtQry, listaCircle, listaRect, listaLinha);

				fclose(saidaQry);
			}

			
			if(strcmp(fig,"i?") == 0)
			{	

				printf("ENTROU COMANDO I?\n");

				fscanf(arqQry,"%d %lf %lf", &j, &x, &y);

				printf("X: %lf", x);
				printf("Y: %lf", y);
				//valores corretos até aqui

				interno(j, x , y ,txtQry, listaCircle, listaRect, listaLinha);			
			}
			

			/* Comando está funcionando  FULL */
			if(strcmp(fig, "pnt") == 0)
			{	
				fscanf(arqQry, "%d %s %s", &j, &border, &fill);

				mudar_cor(j, border, fill, txtQry, listaCircle, listaRect, listaLinha, listaText);
			}
			
			
			if(strcmp(fig, "delf") == 0){

				fscanf(arqQry, "%d", &j);

				remove_forma(j, txtQry, listaCircle, listaRect, listaLinha, listaText);
			}

			/*Pilha Funciona falta printar */
			if(strcmp(fig, "psh") == 0)
			{
				fscanf(arqQry, "%d %d", &pd, &i);

				push_Pilha(pd, i, vetPilha, listaCircle, listaRect, listaLinha, listaText);

				// //Procura na lista de circulo 
				// void* figura1 = searchList(l, i);
				
				// if(figura1 != NULL){

				// 	id = getCircleId(figura1);	
				// 	x = getXCircle(figura1);					
				// 	y = getYCircle(figura1);
				// 	r = getRCircle(figura1);

				// 	strcpy(fill, "black");
				// 	strcpy(border, "red");
					

				// 	circulo C = cria_Circulo(id, r, x, y, fill, border);

				// 	push(vetPilha[pd], C);

					
										
				// }
				// printf("Comando pnt: \n");
				// printf("x: %.2lf\n", x);
				// printf("y: %.2lf\n", y);
				// printf("r: %.2lf\n", r);		
								
				// //Procura na lista de retangulo
				// void* figura2 = searchList(l, i);

				// if(figura1 == NULL && figura2 != NULL){
					
				// 	x = getXRect(figura2);
				// 	y = getYRect(figura2);
				// 	w = getWidthRect(figura2);
				// 	h = getHeightRect(figura2);

				// 	printf("Comando pnt: \n");
				// 	printf("x: %.2lf\n", x);
				// 	printf("y: %.2lf\n", y);
				// 	printf("w: %.2lf\n", w);
				// 	printf("h: %.2lf\n", h);

				// 	retangulo R = cria_Retangulo(id, w, h, x, y, fill, border);

				// 	push(vetPilha[pd], R);



				// }

				// //Procura um texto na lista 

				// //RODAR E VER SAIDA TXT NÃO FUNCIONA 
				// if(figura1 == NULL && figura2 == NULL){
				// 	void* texto1 = searchList(l, j);
					
				// 	x = getXText(texto1);
				// 	y = getYText(texto1);
				// 	strcpy(texto, getText(texto1));
				// 	texto = getText(texto1);
					
				// }

				
			// }
			
			int tamanhoP = lengthP(vetPilha[pd]);
			printf("Tamanho pilha empilhada %d\n", tamanhoP);
			}

			/* TESTE EMPILHA E DESEMPILHA */
			if(strcmp(fig, "pop") == 0)
			{
				fscanf(arqQry, "%d %d %lf %lf %lf", &pd, &i, &dx, &dy, &prop);

				// int id;
				// double x1;
				// double x2;
				// double y1;
				// double y2;
				
				// // printf("TIPO: %c\n", getTipo(vetPilha[pd]));
				// // pop(vetPilha[pd]);
				// id = getIdLinha(vetPilha[pd]);
				// printf("ID: %d\n", id);        
				// x1 = getX1Linha(vetPilha[pd]);
				// printf("X1: %lf\n", x1);
				// x2 = getX2Linha(vetPilha[pd]);
				// printf("X2: %lf\n", x2);
				// y1= getY1Linha(vetPilha[pd]);
				// printf("Y1: %lf\n", y1);
				// y2 = getY2Linha(vetPilha[pd]);
				// printf("Y2: %lf\n", y2);

				pop_Pilha(pd, i, dx, dy, prop, txtQry, vetPilha, listaCircle, listaRect, listaLinha, listaText);

				int tamanhoP = lengthP(vetPilha[pd]);
				printf("Tamanho pilha empilhada %d\n", tamanhoP);

			}

			// /*TESTAR AS FILAS */

			// if(strcmp(fig, "inf") == 0)
			// {
			// 	fscanf(arqQry,"%d %d", &fd, &i);
			// }

			// if(strcmp(fig, "rmf") == 0)
			// {
				
			// }

			// if(strcmp(fig, "ii") == 0){
			// 	fscanf(arqQry, "%d %d %d", ld, i, r);

			// 	insereInicioLista(List l, Node reg[], int ld, int i, int re);
				
			// }

			// if(strcmp(fig, "if") == 0){
			// 	fscanf(arqQry, "%d %d %d", ld, i, r);

			// 	insereFinalLista(List l, Node reg[], int ld, int i, int re);
			// }

			// if(strcmp(fig, "ia") == 0){

			// 	fscanf(arqQry, "%d %d %d %d", ld, i, ro, rd);

			// 	insereAntes();
			// }

			// if(strcmp(fig, "id") == 0){

			// 	fscanf(arqQry,"%d %d %d %d", ld, i, ro, rd);

			// 	insreDepois();
			// }

			// if(strcmp(fig, "da") == 0){
				
			// 	fscanf(arqQry,"%d %d", l, r);

			// 	removeAnterior();

			// }

			// if(strcmp(fig, "dd") == 0){
				
			// 	fscanf(arqQry,"%d %d");

			// 	removeDepois();
			// }

			// if(strcmp(fig, "dpl") == 0)
			// {

			// }






		


		}
		//desenha_Linha(saidaQry,x1,y1,x2,y2, "black");
		printf("passou direto");


		//Falta mudar aqui o draw precisa receber o FILE

		drawListCircle(listaCircle, svgQry);
		drawListRect(listaRect, svgQry);
		drawListText(listaText, svgQry);
		drawListLine(listaLinha, svgQry);
		saidaQry = fopen(svgQry, "a+");
		fprintf(saidaQry, "</svg>");
		fclose(saidaQry);
	}

}