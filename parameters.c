#include "parameters.h"

/* typedef struct parameters {
    char* diretorioEntrada; // -e <diretorio de entrada>
    char* nomeGeo;          // -f <nome do arquivo .geo
    char* diretoriosaida;   // -o <diretorio de saida>
}parameters;

Parameters createParameters(){                                              //Cria um tipo abstrato de dados
    parameters* parametros = (parameters*) malloc(sizeof(parameters));      //Aloca memoria para o tipo abstrato de dados

    if (parametros == NULL){                                                //Verifica se a memoria foi alocada
        printf("Erro ao alocar memoria para a tad parametros /n FINALIZANDO PROGRAMA");
        exit(1);
    }
    parametros -> diretorioEntrada = NULL;                                  //Inicializa os campos da tad
    parametros -> nomeGeo = NULL;
    parametros -> diretoriosaida = NULL;

    return parametros;
} */

typedef struct Path
{                           // Cria um tad
    char *diretorioEntrada; // -e <diretorio de entrada>
    char *nomeGeo;          // -f <nome do arquivo .geo
    char *diretoriosaida;   // -o <diretorio de saida>
} Path;

Path createParameters()
{                                                    // Cria um tipo abstrato de dados
    Path *parametros = (Path *)malloc(sizeof(Path)); // Aloca memoria para minha tad parametros que é do tipo Path ou seja um ponteiro para Path(void), retorna qualquer coisa para minha memoria.
    if (parametros == NULL)
    { // Verifica se a memoria foi alocada

        printf("Erro ao alocar memoria para a tad parametros /n FINALIZANDO PROGRAMA");
        exit(1); // Finaliza o programa
    }

    // limpar lixo dos ponteiro alocados
    parametros->diretorioEntrada = NULL; // Inicializa os campos da tad
    parametros->nomeGeo = NULL;          // Inicializa os campos da tad
    parametros->diretoriosaida = NULL;   // Inicializa os campos da tad
}

void splitPath(char *fullPath, char *path, int lenPath, char *nomeArq, int lenNomeArq, char *extArq, int lenExtArq)
{
    char *barra = strrchr(fullPath, '/'); // Pega o ultimo caractere '/' da string
    char *ponto = strrchr(fullPath, '.'); // Pega o ultimo caractere '.' da string
    if (barra != NULL)                    // Verifica se a string tem uma barra
    {
        strncpy(path, fullPath, fullPath - barra); // Copia a string ate a barra
        path[fullPath - barra] = '\0';             // Adiciona um caractere nulo no final da string
        char *pathENome;                           // Cria uma string para armazenar o nome do arquivo
        strcpy(pathENome, barra + 1);              // Copia a string a partir da barra
        nomeArq = strtok(pathENome, ".");          // Separa a string em duas, a partir do ponto
        strcpy(extArq, ponto + 1);                 // Copia a string a partir do ponto
    }
    else if (ponto != NULL) // Verifica se a string tem um ponto
    {
        strncpy(nomeArq, fullPath, fullPath - ponto); // Copia a string ate o ponto
        nomeArq[fullPath - ponto] = '\0';             // Adiciona um caractere nulo no final da string
        strcpy(extArq, ponto + 1);                    // Copia a string a partir do ponto
        strcpy(path, "");                             // Copia uma string vazia para o path
    }
    else
    {
        strcpy(nomeArq, fullPath); // Copia a string para o nome do arquivo
        strcpy(extArq, "");        // Copia uma string vazia para a extensao do arquivo
        strcpy(path, "");          // Copia uma string vazia para o path
    }
}

void joinFilePath(char *path, char *fileName, char *fullPath, int lenFullPath)
{

    strcat(path, fileName);
    strcat(fullPath, path);
}

void joinAll(char *path, char *fileName, char *ext, char *fullPath, int lenfullPath)
{
    strcat(fullPath, path);
    strcat(fullPath, "/");
    strcat(fullPath, fileName);
    strcat(fullPath, ext);
}

void getFileName(char *fullPath, char *fileName, char *lenFileName)
{

    char *ponto = strrchr(fullPath, '/');

    if (ponto == NULL)
    {
        strcpy(fileName, fullPath);
        return;
    }
    else
    {
        strcpy(fileName, ponto + 1);
        return;
    }
}

void getPath(char *fullPath, char *path, int lenPath)
{
    path = realloc(path, sizeof(char) * (strlen(fullPath) + 1));            //Alocando memoria para path
    strcpy(path, fullPath);                                                 //copiando o conteudo de fullPath para path
    if (strrchr(path, '/') != NULL)                                         //Verifica se a string tem uma barra
    {
        *(strrchr(path, '/') + 1) = '\0';                                   //Se tiver, coloca um caractere nulo no final da string
    }
    else
    {
        strcpy(path, "");                                                   //Se não tiver, copia uma string vazia para o path
    }   
}

void normalizePath(char *path, char *normPath, int lenNormPath)
{

    int ult = strlen(path) - 1; // Pega o tamanho da string
    if (path[ult] == '/')
    {                    // Verifica se o ultimo caractere é uma barra
        normPath = path; // Se for, copia a string para a string normalizada
        return;
    }
    else
    {
        normPath = path;
         *(path + strlen( path )-1)  = '\0';// se tem "/" retira
    }
}
