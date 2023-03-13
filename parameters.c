#include "parameters.h"


struct dir {
    char* diretorioEntrada;
    char* nomeGeo;
    char* bedGeo;
    char* nomeQry;
    char* diretorioSaida;
}direto;

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq) {
    char* barra = strrchr(fullPath, '/');
    char* ponto = strrchr(fullPath, '.');
    if (barra != NULL)
    {
        strncpy(path, fullPath, fullPath - barra);
        path[fullPath - barra] = '\0';
        char* pathENome;
        strcpy(pathENome, barra + 1);
        nomeArq = strtok(pathENome, ".");
        strcpy(extArq, ponto + 1);
    }
    else if (ponto != NULL)
    {
        strncpy(nomeArq, fullPath, fullPath - ponto);
        nomeArq[fullPath - ponto] = '\0';
        strcpy(extArq, ponto + 1);
        strcpy(path, "");
    }
    else
    {
        strcpy(nomeArq, fullPath);
        strcpy(extArq, "");
        strcpy(path, "");
    }
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath){

strcat(path,fileName);
strcat(fullPath,path);

}


void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenfullPath){
strcat (fullPath, path);
strcat (fullPath, "/");
strcat (fullPath, fileName);
strcat (fullPath, ext);

}

void getFileName(char *fullPath, char *fileName, char *lenFileName){

char* ponto = strrchr(fullPath, '/');

if (ponto == NULL){
   strcpy(fileName, fullPath);
}else{
   strcpy(fileName, ponto+1);
}
}


void getPath(char *fullPath, char *path, int lenPath){


char* ponto = strrchr(fullPath, '/');
if (ponto == NULL){
    strcpy(path, " ");
}
else{
   path = strtok (fullPath, ponto-1);
}
}


void normalizePath(char *path, char *normPath, int lenNormPath){

int ult = strlen(path)-1;
if (path[ult] == '/')
      path[ult] = '\0';

// char* aux = strrchr(path , '/');
}


