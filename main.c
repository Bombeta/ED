#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "StartSvg.h"
#include "ret.h"
#include "circulo.h"
#include "lista.h"
#include "texto.h"
#include "funcoes.h"
/*#include "parametros.h"*/

/** ta funcionando PORRA  LISTA TA O FINO falta implementar o .qry**/

int main(int argc, char const *argv[])
{
	int i = 1;

	char *DirIn = NULL; 	/* -e >> Diretório base de entrada */
	char *DirTwo = NULL;		/* Gambira 	*/
	char *arqGeo = NULL;  		/* -f >> Arquivo com descrição da cidade arq.geo */
	char *arqCons = NULL;	/* -q >> Arquivo com consultas arqcons.qry */
	char *DirOut = NULL; 	/* -o >> Diretŕio base de saída */

	char *DirGeo = NULL; 	/* Vai ser usado para abrir o arquivo Concatenado DirIn + arqGeo */
	char *DirQry = NULL;	/* Vai ser usado para abrir o arquivo Concatenado DirOut + arqCons  ?????*/
	char *semGeo = NULL;
	char *nomeSvg = NULL;
	char *nomeTxt = NULL;
	char *outSvg = NULL;
	char *outTxt = NULL;
	char fig;
	char cons[5];			/* tamanho do comando o? --- delf */ 
	int l;

	int c;		/* retorno de strcmp para string de .qry */
	char lixo;

	int id;
	int xd;
	char dirGeo[3] = "./";
	char nx[3] = "nx";
	int tam = 1000;				/* tamanho do vetor comando nx */

	double r, x, y, w, h;
	char fill[10];
	char border[10];
	char txto;

	//int numero;


	/* FILE openGeo; */
	FILE *arq; 

	/* FILE SVG */
	FILE *arqSvg;

	/* FILE openQry */
	FILE *qry;

	/*FILE txt */
	FILE *txt;

	

	DirIn = recebeEntrada(argc,argv, DirIn);
	printf("SAIDA: %s\n", DirIn);
	DirTwo = recebeEntrada(argc, argv, DirTwo);
	printf("SAIDA-2: %s\n",DirTwo);
	arqGeo = recebeGeo(argc, argv, arqGeo);
	printf("SAIDA-3: %s\n",arqGeo);
	arqCons = recebeCons(argc, argv, arqCons);
	printf("SAIDA-4: %s\n", arqCons);
	DirOut = recebeDiretorioSaida(argc, argv, DirOut);
	printf("SAIDA: 5: %s\n", DirOut);

	semGeo = tiraGeo(arqGeo);
	nomeSvg = concatena(semGeo, ".svg");
	nomeTxt = concatena(semGeo, ".txt");

	
	/* Arquivos -e (DirIn) e -q (arqCons) são OPCIONAIS */

	if(DirIn != NULL){

		DirGeo = concatena(DirIn, arqGeo); 
	}
	if(DirIn == NULL) {
		DirGeo = aloca_tamanho(strlen(arqGeo)+2);
		strcpy(DirGeo,arqGeo);

		strncat(dirGeo,DirGeo,strlen(DirGeo)); 

				
	}
	

	if(arqCons == NULL)
	{
		free(arqCons);	
	}

	if(arqCons != NULL){

		if(DirTwo != NULL){

			DirQry = concatena(DirTwo, arqCons); 
		

		}else {
			DirQry = aloca_tamanho(strlen(arqCons));
			strcpy(DirQry,arqCons);
			
		}

	}



	/*criando as saidas dos arquivos Txt e svg */
	if(DirOut != NULL)
	{	
		l = strlen(DirOut);
		l = l + strlen(nomeSvg);
		outSvg = aloca_tamanho(l);
		l = strlen(DirOut) + strlen(nomeTxt);
		outTxt = aloca_tamanho(l);
		outSvg = concatena(DirOut, nomeSvg);		
		outTxt = concatena(DirOut, nomeTxt);		
	}

	// arq = abreFileGeo(arq,DirGeo);
	// arqSvg = abreFileSvg(arqSvg,outSvg);

	readFile(arq, DirGeo, arqSvg, outSvg);

	/*arq = fopen(DirGeo, "r");*/
	
	// arqSvg = fopen(outSvg, "w");

	// if(arqSvg == NULL)
	// {
	// 	printf("Arquivo SVG não foi criado!\n");
	// 	exit(0);
	// } 

	// cria_SVG(arqSvg);

	// readFile(arq, arqSvg);	

	
	// if(arq == NULL)
	// {	
	// 	printf("ERRO! O arquivo GEO não foi aberto\n");	
	// }
	// else
	// {	

	// 	fgets(nx,3,arq);

	// 	if(strncmp(nx,"nx",2) == 0)
	// 	{
	// 		fscanf(arq,"%d", &tam);
	// 		printf("O tamanho do vetor eh: %d\n",tam);

	// 	}


		

	// 	while((fscanf(arq,"%c", &fig))!=EOF)
	// 	{	

	// 		printf("\n%c\n", fig);

	// 		if(fig=='c')
	// 		{	
				

	// 			fscanf(arq, "%d %lf %lf %lf %s %s\n", &id, &r, &x, &y, fill, border);
				
	// 			/*Adiciona um circulo a lista */
	// 			cria_Circulo(lista, id, x, y, r, fill, border);

	// 			arqSvg = fopen(outSvg,"a");

	// 			desenha_Circulo(arqSvg, lista);		

				
	// 			fclose(arqSvg);

				
				
	// 		}

			
	// 		if(fig=='r')
	// 		{
	// 			fscanf(arq, "%d %lf %lf %lf %lf %s %s\n", &id, &x, &y, &w, &h, fill, border);
				
	// 			/*Adiciona um retangulo a lista */
	// 			cria_Retangulo(lista, id, x, y, w, h, fill, border); 

	// 			arqSvg = fopen(outSvg, "a+"); 

	// 			desenha_Retangulo(arqSvg, lista); 	
				
				
				
	// 			fclose(arqSvg);

			
			
	// 		}
			
	// 		/*Veriricar Valgrind linha 314*/
	// 		if(fig=='t')
	// 		{
	// 			fscanf(arq, "%d %lf %lf %s %s\n", &id, &x, &y, fill, border);
				
	// 			cria_Texto(lista, id, x, y, fill, border);		
				
	// 			arqSvg = fopen(outSvg, "a+");
		
	// 			desenha_Texto(arqSvg, lista, arq);				
				

	// 			fclose(arqSvg);

				

	// 		}

			
			
	// 	}

	// 	/*exibir_Lista(l);*/
	// }

	/************ ATÉ AQUI FUNCIONA - SVG CRIADO******************/


	// /*FILE open qry */
	// if(DirQry != NULL){
		
	// 	qry = fopen(DirQry, "r");
	// }
	// //printf("AQUIII: %s\n", DirTwo);

	// txt = fopen(outTxt, "w");
	

	// if(qry == NULL)
	// {
	// 	printf("ERRO! O arquivo não foi aberto\n");	
	// 	printf("arqCons:	%s\n",arqCons);
	// }else
	// {
	// 	while((fscanf(qry,"%s", cons)) != EOF)
	// 	{
			
	// 		if(strcmp(cons, "o?") == 0)
	// 		{
	// 			int r;
	// 			int k;
	// 			int contC = 0;
	// 			int contR = 0;

	// 			fscanf(qry, "%d %d", &id , &xd);
	// 			arqSvg = fopen(outSvg, "a");

	// 			/*qual forma geométrica eh  */

	// 			/*Procura id em Circulo*/
	// 			for(i=0;i<lista->nroC;i++)
	// 			{
	// 				if(id == lista->C[i].id || xd == lista->C[i].id)
	// 				{
	// 					contC = contC + 1;
	// 				}
	// 			}

	// 			/* As duas figuras são circulos */
	// 			if(contC == 2)
	// 			{
	// 				//printf("dois circulos: i: %d j: %d\n",id, xd);
	// 				r = overlapCircle(lista, id, xd, arqSvg);

	// 				if(r == 0)
	// 				{
	// 					txt = fopen("txt.txt", "a+");
	// 					fprintf(txt,"%d: circulo %d: circulo NAO\n",id, xd);
	// 					fclose(txt);
	// 				}

	// 				if(r == 1)
	// 				{
	// 					txt = fopen("txt.txt", "a+");
	// 					fprintf(txt,"%d: circulo %d: circulo SIM\n",id, xd);
	// 					fclose(txt);
	// 				}
							
	// 			}

	// 			/*Procura id no Retangulo */
	// 			for(i=0;i<lista->nroR;i++)
	// 			{
	// 				if(id == lista->R[i].id || xd == lista->R[i].id)
	// 				{
	// 					contR = contR + 1;
	// 				}
	// 			}

	// 			/*As duas figuras são Retangulos */
	// 			if(contR == 2)
	// 			{
	// 				r = overlapRect(lista, id, xd, arqSvg);

	// 				if(r == 0)
	// 				{
	// 					txt = fopen(outTxt, "a+");
	// 					fprintf(txt,"%d: retangulo %d: retangulo NAO\n",id, xd);
	// 					fclose(txt);
	// 				}

	// 				if(r == 1)
	// 				{
	// 					txt = fopen(outTxt, "a+");
	// 					fprintf(txt,"%d: retangulo %d: retangulo SIM\n",id, xd);
	// 					fclose(txt);
	// 				}
	// 			}

	// 			/* ids j e k estão em C ou R */
	// 			if(contR == 1 && contC == 1)
	// 			{
	// 				/*Para id ser o circulo e xd no retangulo */
	// 				for(i=0;i<lista->nroC;i++)
	// 				{
	// 					if(id == lista->C[i].id)
	// 					{
	// 						r = overlapCircleRect(lista, id, xd, arqSvg);
	// 						if(r == 0)
	// 						{
	// 							txt = fopen(outTxt, "a+");
	// 							fprintf(txt,"%d: circulo %d: circulo NAO\n",id, xd);
	// 							fclose(txt);
	// 						}

	// 						if(r == 1)
	// 						{
	// 							txt = fopen(outTxt, "a+");
	// 							fprintf(txt,"%d: circulo %d: circulo SIM\n",id, xd);
	// 							fclose(txt);
	// 						}
	// 					}

	// 				}

	// 				/*Para id ser no retangulo  e xd no circulo*/
	// 				for(i=0;i<lista->nroR;i++)
	// 				{
	// 					if(id == lista->R[i].id)
	// 					{	
	// 						r = overlapCircleRect(lista, xd, id, arqSvg);

	// 						if(r == 0)
	// 						{
	// 							txt = fopen(outTxt, "a+");
	// 							fprintf(txt,"%d: circulo %d: circulo NAO\n",id, xd);
	// 							fclose(txt);
	// 						}

	// 						if(r == 1)
	// 						{
	// 							txt = fopen(outTxt, "a+");
	// 							fprintf(txt,"%d: circulo %d: circulo SIM\n",id, xd);
	// 							fclose(txt);
	// 						}
	// 						//printf("retangulo i %d:\n", id);
	// 						//printf("circulo j: %d\n", xd);
	// 					}
	// 				}

	// 			}

	// 			contR = 0;
	// 			contC = 0;

	// 			fclose(arqSvg);

	// 		}

	// 		if((strcmp(cons, "i?") == 0))
	// 		{
	// 			fscanf(qry, "%d %lf %lf", &id, &x, &y);
				
	// 		}

	// 		if((strcmp(cons, "pnt") == 0))
	// 		{
	// 			fscanf(qry, "%d %s %s", &id, border, fill);

	// 			txt = fopen(outTxt, "a");

	// 			mudar_cor(lista, id, fill, border);

	// 			fclose(txt);
				
	// 		}

	// 		if((strcmp(cons, "pnt*") == 0))
	// 		{
	// 			/*printf("pnt*\n"); */
	// 			fscanf(qry, "%d %d %s %s", &id, &xd, border, fill);

	// 			txt = fopen(outTxt, "a");

	// 			mudar_cor_2(lista, id, xd, fill, border); 

	// 			fclose(txt);
				
	// 		}

	// 		if((strcmp(cons, "delf") == 0))
	// 		{


	// 			//printf("delf %d\n", id); 

	// 			fscanf(qry, "%d", &id);

	// 			txt = fopen(outTxt, "a");

	// 			fprintf(txt, "delf %d\n", id);
				

	// 			remove_Lista(lista, id);

	// 			fclose(txt);

	// 		}

	// 		if((strcmp(cons, "delf*") == 0))
	// 		{
	// 			/*printf("delf*\n"); */
	// 			fscanf(qry, "%d %d", &id, &xd);

	// 			txt = fopen(outTxt, "a");

	// 			fprintf(txt, "delf* %d %d", id, xd);

	// 			remove_Lista_2(l, id, xd); 

	// 			fclose(txt);

				

	// 		}
	// 	}


	// 	fclose(arqSvg);
	// 	//exibir_Lista(lista);

		
	// } 




	

	
	//fclose(arqSvg);
	
	
	free(outTxt);
	free(outSvg);
	free(nomeTxt);
	free(nomeSvg);
	free(DirIn);
	free(DirTwo);
	free(arqGeo);
	free(arqCons);
	free(DirOut);
	free(DirGeo);
	free(DirQry);

	//fclose(arq);
	/*fclose(qry); */
	

	
	return(0);
}
