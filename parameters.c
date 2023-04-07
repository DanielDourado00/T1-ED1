#include "parameters.h"
#include "systempath.h"
#include "systemgeo.h"

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{

    if (strchr(fullPath, '/'))
    { // se tiver barra (completo)
        path = realloc(path, strlen(fullPath));
        strcpy(path, fullPath);
        if (strchr(path, '.'))
        {
            path[strlen(path) - 4] = '\0';
        }
        nomeArq = strrchr(fullPath, '/') + 1;
        if (strchr(nomeArq, '.'))
        {
            extArq = strrchr(nomeArq, '.');
            nomeArq[strlen(nomeArq) - 4] = '\0';
        }
        else
        {
            extArq = "";
        }
        return;
    }
    else
    { // se nao tiver barra (so o nome)
        path = "";
        if (strchr(fullPath, '.'))
        {
            nomeArq = fullPath;
            nomeArq[strlen(nomeArq) - 4] = '\0';
            extArq = strrchr(fullPath, '.');
        }
        else
        {
            nomeArq = fullPath;
            extArq = "";
        }
        return;
    }
    return;
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath){
    
    if(strchr(path, '/')){ //se tiver barra (completo)
    strcpy(fullPath, path);
    strcat(fullPath, "/");
    strcat(fullPath, fileName);
    return;
    }   else{ //se nao tiver barra (so o nome)
        strcpy(fullPath, fileName);
        return;
    }
    //printf("\n\nconteudo do fullpath na tad parameters.c, funcao joinFilePath linha 58: %s \n\n", fullPath);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenfullPath)
{

    strcpy(fullPath, path);

    if (fullPath[strlen(fullPath) - 1] != '/')
    { // coloca barra se nao tiver
        strcat(fullPath, "/");
    }
    strcat(fullPath, fileName);
    strcat(fullPath, ext);
    //printf("\n\nconteudo do fullpath na tad parameters.c, funcao joinAll linha 61: %s \n\n", fullPath);
}

void getFileName(char *fullPath, char *fileName, char *lenFileName)
{
    if (strchr(fullPath, '/'))
    { // se tiver barra (completo)
        fileName = strrchr(fullPath, '/') + 1;
        return;
    }
    else
    { // se nao tiver barra (so o nome)
        fileName = fullPath;
        return;
    }
    printf("\n\nconteudo de fileName do parameters.c: %s \n\n", fileName);
}

void getPath(char *fullPath, char *path, int lenPath)
{
    path = realloc(path, strlen(fullPath));
    strcpy(path, fullPath);

    if (strchr(path, '/'))
    {
        *(strrchr(path, '/') + 1) = '\0'; // tira o nome do arquivo
    }
    else
        path = "";
    printf("\n\n conteudo de path do parameters.c: %s \n\n", path);
}

void normalizePath(char *path, char *normPath, int lenNormPath){
    
    if (path[strlen(path)-1] != '/'){ //se não tem "/" retorna
      normPath = path;
      return;
    }
    else{
    normPath = path;
    *(path + strlen( path )-1)  = '\0';// se tem "/" retira
    return;
    }
    printf("\n\nconteudo de normPath do parameters.c: %s \n\n", normPath);
}
