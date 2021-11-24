#include "parametros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* arrumaBarra(char* path) {
    int end=strlen(path);
    printf("END: %d\n", end);
    if (path[end-1] != '/') {
        strcat(path,"/");
    }
    return path;
}

char* recebePath(int argc, char *argv[], char *path) {
    int i = 1;
    while (i<argc) {
        if (strcmp("-e", argv[i]) == 0) {
            path = (char *)malloc((strlen(argv[i+1]) + 2)*sizeof(char));
            
            strcpy(path,argv[i+1]);
            printf("-e %s", path);
            path = arrumaBarra(path);
            printf("-e %s", path);
            return path;

        }
        i++;
    }
    path = (char *)malloc(3*sizeof(char));
    strcpy(path, "./");
    return path;
}

char* recebeGeo(int argc, char *argv[], char *geo) {
    int i = 1;
    while (i<argc) {
        if (strcmp("-f", argv[i]) == 0) {
            geo = (char *)malloc((strlen(argv[i+1]) + 1)*sizeof(char));
            strcpy(geo,argv[i+1]);
        }
        printf("GEO PORRA: %s\n", geo);
        i++;
    }
    return geo;
}

char* recebeQry(int argc, char *argv[], char *qry) {
    int i = 1;
    while (i<argc) {
        if (strcmp("-q", argv[i]) == 0) {
            qry = (char *)malloc((strlen(argv[i+1]) + 1)*sizeof(char));
            strcpy(qry,argv[i+1]);
            return qry;
        }
        i++;
    }
    return NULL;
}

char* recebeDest(int argc, char *argv[], char *dest) {
    int i = 1;
    while (i<argc) {
        if (strcmp("-o", argv[i]) == 0) {
            dest = (char *)malloc((strlen(argv[i+1]) + 2)*sizeof(char));
            strcpy(dest,argv[i+1]);
        }
        i++;
    }
    if(dest != NULL){
        dest = arrumaBarra(dest);
        return dest;
    }
    
}
