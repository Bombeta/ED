#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "StartSvg.h"
#include "funcoes.h"

/* Erro valgrind linhas 234 231 e 130 */

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
	// char nx[3] = "nx";
	// int tam = 1000;				/* tamanho do vetor comando nx */

	// double r, x, y, w, h;
	// char fill[10];
	// char border[10];
	// char txto;




	/* FILE openGeo; */
	FILE *arq; 

	/* FILE SVG */
	FILE *arqSvg;

	/* FILE openQry */
	FILE *qry;

	/*FILE txt */
	FILE *txt;


	DirIn = recebeEntrada(argc,argv, DirIn);
	// printf("SAIDA: %s\n", DirIn);
	// DirTwo = recebeEntrada(argc, argv, DirTwo);
	// printf("SAIDA-2: %s\n",DirTwo);
	arqGeo = recebeGeo(argc, argv, arqGeo);
	// printf("SAIDA-3: %s\n",arqGeo);
	arqCons = recebeCons(argc, argv, arqCons);
	// printf("SAIDA-4: %s\n", arqCons);
	DirOut = recebeDiretorioSaida(argc, argv, DirOut);
	// printf("SAIDA: 5: %s\n", DirOut);

	// semGeo = tiraGeo(arqGeo);
	// nomeSvg = concatena(semGeo, ".svg");
	// nomeTxt = concatena(semGeo, ".txt");

	/*Tirando o .geo */
	// printf("\nArqGeo: %s\n", arqGeo);
	semGeo = tiraGeo(arqGeo);
	// printf("\nSem Geo: %s\n", semGeo);

	char string[100];
	
	// strcpy(string,semGeo);
	// for (i=0; string[i] != '\0'; i++)
	// 	printf ("Caractere %d: %c\n", i, string[i]);
   

	int l_svg = 0;
	l_svg = strlen(semGeo) + 5;
	// printf("\nTamanho semgEO %d\n", l_svg);
	nomeSvg = aloca_tamanho(l_svg, nomeSvg);
	nomeSvg = concatena(semGeo, ".svg");
	// printf("nomeSvg: %s\n", nomeSvg);
	// nomeTxt = concatena(semGeo, ".txt");

	/* FILE *openGeo; */
		
	// if(DirIn != NULL){
	// 	DirGeo = concatena(DirIn, semGeo);
	// }
	// }else{
	// 	int l = 2;
	// 	l = l + strlen(arqGeo);
	// 	printf("l de arqGeo: %d\n", l);
	// 	printf("l + 1 = %d", l);
	// 	DirGeo = aloca_tamanho(l,str);
	// 	strcpy(DirGeo,arqGeo);
				
	// }

	

	// DirIn = recebeEntrada(argc,argv, DirIn);
	// printf("SAIDA: %s\n", DirIn);
	// DirTwo = recebeEntrada(argc, argv, DirTwo);
	// printf("SAIDA-2: %s\n",DirTwo);
	// arqGeo = recebeGeo(argc, argv, arqGeo);
	// printf("SAIDA-3: %s\n",arqGeo);
	// arqCons = recebeCons(argc, argv, arqCons);
	// printf("SAIDA-4: %s\n", arqCons);
	// DirOut = recebeDiretorioSaida(argc, argv, DirOut);
	// printf("SAIDA: 5: %s\n", DirOut);

	// semGeo = tiraGeo(arqGeo);
	// nomeSvg = concatena(semGeo, ".svg");
	// nomeTxt = concatena(semGeo, ".txt");

	
	/* Arquivos -e (DirIn) e -q (arqCons) são OPCIONAIS */

	if(DirIn != NULL){

		DirGeo = concatena(DirIn, arqGeo);
		// printf("DirGeo: %s\n", DirGeo);
	}
	if(DirIn == NULL) {
		/* Para arquivo Geo */
		int l = 0;
		l = strlen(arqGeo);
		DirGeo = aloca_tamanho(l, DirGeo);
		strcpy(DirGeo,arqGeo);

		/* coloca o "./" caso n tenha o nome do arquivo de entrada */
		strncat(dirGeo,DirGeo,strlen(DirGeo)); 

		if(arqCons != NULL){
			int l = 0;
			l = strlen(arqCons);
			DirQry = aloca_tamanho(l, DirQry);
			strcpy(DirQry,arqCons);

			/* coloca o "./" caso n tenha o nome do arquivo de entrada */

			strncat(dirGeo,DirQry,strlen(DirQry));
		}
				
	}
	

	if(arqCons == NULL)
	{
		free(arqCons);	
	}

	/* Verificar oque é isso */

	// if(arqCons != NULL){

	// 	if(DirTwo != NULL){

	// 		DirQry = concatena(DirTwo, arqCons); 
		

	// 	}else {
	// 		int l = 0;
	// 		l = strlen(arqCons);
	// 		char *str;
	// 		DirQry = aloca_tamanho(l, str);
	// 		strcpy(DirQry,arqCons);
			
			
	// 	}

	// }



	/*criando as saidas dos arquivos Txt e svg */
	if(DirOut != NULL)
	{
		int l1 = 0;
		int l2 = 0;
		int l3 = 0;

		l1 = strlen(DirOut) + 2;
		// printf("\nl de DirOut: %d\n", l1);

		l2 = strlen(nomeSvg) + 2;
		// printf("\nl de nome Svg: %d\n", l2);

		l3 = l1 + l2;
		// printf("\nl DirOut + nome Svg: %d\n", l3);

		aloca_tamanho(l3, outSvg);
		
		// l = l + strlen(nomeTxt);		
		// outTxt = aloca_tamanho(l, str);
			
		outSvg = concatena(DirOut, nomeSvg);		
		//outTxt = concatena(DirOut, nomeTxt);
		
	}

	arq = abreFileGeo(arq,DirGeo);
	//qry = abreFileGeo(qry,DirQry);
	// arqSvg = abreFileSvg(arqSvg,outSvg);

	//printf("arqSvg = %s", arqSvg);

	readFile(arq, qry, DirGeo, DirQry, arqSvg);


	//fclose(arq);
	//fclose(arqSvg);
	//fclose(qry);
	//fclose(txt);
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

	return(0);
}
