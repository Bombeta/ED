#ifndef STRING_H
#define STRING_H

FILE* abreFileGeo(FILE *arq, char *DirGeo); 
// FILE* abreFileSvg(FILE *arqSvg, char *outSvg);

void readFile(FILE *arq, FILE *qry, char *DirGeo, char* DirQry, FILE*arqSvg);


#endif