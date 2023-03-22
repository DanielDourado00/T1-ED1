#include "systempath.h"

void *createParameters()
{
    all_paths *aux = calloc(1, sizeof(all_paths)); // aloca memoria para a struct all_paths e retorna o ponteiro para aux
    return aux;
}

typedef struct all_paths
{ // struct para guardar todos os paths

    char *pea;         // path de entrada de arquivos
    char *psa;         // path de saida de arquivos
    char *namegeo;     // nome do arquivo geo
    char *namegeoExt;  // nome do aruivo .geo sem extensao
    char *nameqry;     // nome do arquivo qry
    char *nameqryExt;  // nome do arquivo .qry sem extensao
    char *psageosvg;   // path de saida do arquivo geo.svg
    char *psaqrysvg;   // path de saida do arquivo qry.svg
    char *psaqrytxt;   // path de saida do arquivo qry.txt
    char *qryfullpath; // path completo do arquivo qry
    char *geofullpath; // path completo do arquivo geo
} all_paths;

char *VerifDiretorio(char *diretorio)
{ // verifica se o diretorio termina com /, se nao terminar, adiciona
    if (diretorio[strlen(diretorio) - 1] != '/')
    {
        strcat(diretorio, "/");
        return diretorio;
    }
    else
        return diretorio;
}
void freeparameters(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths / libera memoria alocada para cada path
    free(aux->pea);
    free(aux->psa);
    free(aux->namegeo);
    free(aux->namegeoExt);
    free(aux->nameqry);
    free(aux->nameqryExt);
    free(aux->psageosvg);
    free(aux->psaqrysvg);
    free(aux->qryfullpath);
    free(aux->geofullpath);
    free(parameters); // libera memoria alocada para a struct all_paths
}

void setgeofullpath(void *parameters, char *geofull)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->geofullpath = geofull;  // seta o path completo do arquivo geo
}

void setqryfullpath(void *parameters, char *qryfull)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->qryfullpath = qryfull;  // seta o path completo do arquivo qry
}

char *getqryfullpath(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->qryfullpath;     // retorna o path completo do arquivo qry
}

char *getgeofullpath(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->geofullpath;     // retorna o path completo do arquivo geo
}

void setpea(void *parameters, char *pea)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->pea = pea;              // seta o path de entrada de arquivos
}

void setpsa(void *parameters, char *psa)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->psa = psa;              // seta o path de saida de arquivos
}

void setnamegeo(void *parameters, char *namegeo)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->namegeo = namegeo;      // seta o nome do arquivo geo
}

void setnamegeoExt(void *parameters, char *namegeoExt)
{
    all_paths *aux = parameters;  // cast para all_paths
    aux->namegeoExt = namegeoExt; // seta o nome do arquivo geo sem extensao
}

void setnameqry(void *parameters, char *nameqry)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->nameqry = nameqry;      // seta o nome do arquivo qry
}

void setnameqryExt(void *parameters, char *nameqryExt)
{
    all_paths *aux = parameters;  // cast para all_paths
    aux->nameqryExt = nameqryExt; // seta o nome do arquivo qry sem extensao
}

void setpsageosvg(void *parameters, char *psageosvg)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->psageosvg = psageosvg;  // seta o path de saida do arquivo geo.svg
}

void setpsaqrytxt(void *parameters, char *psaqrytxt)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->psaqrytxt = psaqrytxt;  // seta o path de saida do arquivo qry.txt
}

char *getpea(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->pea;             // retorna o path de entrada de arquivos
}

char *getpsa(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->psa;             // retorna o path de saida de arquivos
}

char *getnamegeo(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->namegeo;         // retorna o nome do arquivo geo
}

char *getnamegeoExt(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->namegeoExt;      // retorna o nome do arquivo geo sem extensao
}

char *getnameqry(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->nameqry;         // retorna o nome do arquivo qry
}

char *getnameqryExt(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->nameqryExt;      // retorna o nome do arquivo qry sem extensao
}

char *getpsageosvg(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->psageosvg;       // retorna o path de saida do arquivo geo.svg
}

char *getpsaqrytxt(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->psaqrytxt;       // retorna o path de saida do arquivo qry.txt
}

/* prints para debug */

void printPath(void *parameters)
{
    /* printas para debugar e ver o que cada variavel esta recebendo para conferir se n tem vazamento de memoria */

    printf("\n\nDiretorio base de entrada (pea): %s)", getpea(parameters));
    printf("\n\nDiretorio base de saida (psa): %s)", getpsa(parameters));

    printf("\n==========PRINTS PARA GEO DEBUG==========\n");
    printf("\nNome do arquivo geo: %s", getnamegeo(parameters));
    printf("\nNome do arquivo geo sem extensao: %s", getnamegeoExt(parameters));
    printf("\nPath completo do arquivo geo: %s", getgeofullpath(parameters));

    printf("\n==========PRINTS DE DEBUGAR QRY==========\n");
    printf("\nDiretorio completo do arquivo qry: %s", getqryfullpath(parameters));
    printf("\nNome do arquivo qry: %s", getnameqry(parameters));
    printf("\nNome do arquivo qry sem extensao: %s", getnameqryExt(parameters));

    printf("\n==========PRINTS PARA DEBUGAR O SVG==========\n");
    printf("\nPath de saida do arquivo geo.svg (psageosvg): %s", getpsageosvg(parameters));
    printf("\nPath de saida do arquivo qry.txt (psaqrytxt): %s", getpsaqrytxt(parameters));
    printf("\nPath de saida do arquivo qry.svg (psageosvg): %s", getpsageosvg(parameters));
}

/*

 receber parametros e fazer a verificacao entre -f -q -o -e

-e path Diretório-base de entrada ($DIR_ENTRADA)
-f arq.geo Arquivo com a descrição da cidade. Este arquivo deve estar sob o diretório $DIR_ENTRADA.
-o path  Diretório-base de saída ($DIR_SAIDA)
-q arqcons.qry  Arquivo com consultas. Este arquivo deve estar sob o diretório $DIR_ENTRADA.

*/

int readParam(int argc, char **argv, void *parameters)
{
    // setar tudo como falso
    bool read_pea = false, read_psa = false, read_geo = false, read_qry = false; // flags para verificar se os parametros foram passados sendo pea = -e, psa = -o, geo = -f, qry = -q

    char *normPath;
    int len;

    int opt;
    while ((opt = getopt(argc, argv, "e:f:o:q:")) != -1) // se caso algum dos parametros que entrrar forem -e -f -o -q 
    {
        switch (opt)
        {
        case 'e':                                                                   // -e path Diretório-base de entrada ($DIR_ENTRADA)
            char *pea = calloc(strlen(optarg) + 1, sizeof(char));                   // aloca o tamanho do pea
            strcpy(pea, optarg);
            len = strlen(pea);                                                      // pega o tamanho do pea
            normPath = "";
            normalizePath(pea, normPath, len);                                      // envia para a funcao normalizePath para normalizar o path do parameters.c
            setpea(parameters, normPath);                                           // seta o pea

        case 'f':                                                                   // -f arq.geo. Este arquivo deve estar sob o diretório $DIR_ENTRADA.
            char *namegeo = calloc(strlen(optarg) + 1, sizeof(char));
            char *namegeoExt = calloc(strlen(optarg) + 1, sizeof(char));
            char *ext = ".geo";
            if (!getpea(parameters))                                                // se o pea nao foi passado, seta o pea como "./"
            {
                char *pea = calloc(4 + 1, sizeof(char)); // seria 3 mas tem que colocar o \0
                strcpy(pea, "./");
                setpea(parameters, pea);
            }
            read_geo = true;
            strcpy(namegeo, optarg);

            char *getgeofullpath = calloc(strlen(getpea(parameters)) + strlen(namegeo) + 1, sizeof(char));

            joinFilePath(getpea(parameters), namegeo, getgeofullpath, len);
            strcpy(namegeoExt, namegeo);             // copia o nome do arquivo geo para o nome do arquivo geo sem extensao
            if (namegeo[strlen(namegeo) - 4] == '.') // verifica se o nome do arquivo geo tem extensao
            {
                namegeoExt[strlen(namegeoExt) - 4] = '\0'; // se tiver, remove a extensao sendo namegeoExt = nome do arquivo geo sem extensao
                joinAll(getpea(parameters), namegeo, ext, getgeofullpath, len);

                setnamegeo(parameters, namegeo);            // envia o nome do arquivo geo para a tad parameters
                setnamegeoExt(parameters, namegeoExt);      // envia o nome do arquivo geo sem extensao para a tad parameters
                setgeofullpath(parameters, getgeofullpath); // envia o path completo do arquivo geo para a tad parameters
                break;
            }
        case 'o':                                                 // -o path  Diretório-base de saída ($DIR_SAIDA)
            char *psa = calloc(strlen(optarg) + 2, sizeof(char)); // aloca memoria para o path de saida
            strcpy(psa, optarg);                                  // copia o path de saida para a variavel psa
            read_psa = true;                                      // seta a flag de path de saida como verdadeira
            normalizePath(psa, normPath, len);                    // normaliza o path de saida para ser usada na tad parameters
            setpsa(parameters, psa);                              // seta o path de saida
            break;

        case 'q':                                                        // -q arqcons.qry  Arquivo com consultas. Este arquivo deve estar sob o diretório $DIR_ENTRADA.
            char *nameqry = calloc(strlen(optarg) + 1, sizeof(char));    // aloca memoria para o nome do arquivo qry
            char *nameqryExt = calloc(strlen(optarg) + 1, sizeof(char)); // aloca memoria para o nome do arquivo qry sem extensao
            if (!getpea(parameters))
            {
                char *pea = calloc(4 + 1, sizeof(char)); // seria 3 mas tem que colocar o \0
                strcpy(pea, "./");
                setpea(parameters, pea);
            }
            read_qry = true;
            strcpy(nameqry, optarg);                                                                    // copia o nome do arquivo qry para o nome do arquivo qry com extensao
            char *qryfullpath = calloc(strlen(getpea(parameters)) + strlen(nameqry) + 1, sizeof(char)); // aloca memoria para o path completo do arquivo qry

            joinFilePath(getpea(parameters), nameqry, qryfullpath, len); // junta o path de entrada com o nome do arquivo qry para formar o path completo do arquivo qry
            while (nameqry, '/')                                         // verifica se o nome do arquivo qry tem barra
            {
                nameqry = strrchr(nameqry, '/') + 1; // se tiver, pega o nome do arquivo qry sem a barra, a funcao strrchr retorna o ultimo caractere da string, lendo ele de tras pra frente
                strcpy(nameqryExt, nameqry);         // copia o nome do arquivo qry sem a barra para o nome do arquivo qry sem extensao
            }
            if (nameqry[strlen(nameqry) - 4] == '.') // verifica se o nome do arquivo qry tem extensao
            {
                nameqryExt[strlen(nameqryExt) - 4] = '\0'; // se tiver, remove a extensao sendo nameqryExt = nome do arquivo qry sem extensao
                setnameqry(parameters, nameqry);           // envia o nome do arquivo qry para a tad parameters
                setnameqryExt(parameters, nameqryExt);     // envia o nome do arquivo qry sem extensao para a tad parameters
                setqryfullpath(parameters, qryfullpath);   // envia o path completo do arquivo qry para a tad parameters
                break;
            }
        default:
            printf("Parametro invalido");
            return -1;
        }
    }

    if (read_geo && read_psa)
    {                                                                                                               // verifica se os parametros do geo.svg  a saida foram passados
        char *psageosvg = calloc(strlen(getpsa(parameters)) + strlen(getnamegeoExt(parameters)) + 5, sizeof(char)); // aloca memoria para o path do geo.svg
        strcpy(psageosvg, getpsa(parameters));                                                                      // copia o path de saida para o path do geo.svg
        VerifDiretorio(psageosvg);                                                                                  // verifica se o diretorio existe, se nao existir, cria
        strcat(psageosvg, getnamegeoExt(parameters));
        strcat(psageosvg, ".svg");           // concatena o nome do arquivo geo sem extensao com o path do geo.svg
        setpsageosvg(parameters, psageosvg); // envia o path do geo.svg para a tad parameters
    }
    else if (!read_geo || !read_psa)
    {
        printf("Parametros invalidos");
        return -1;
    }

    if (!read_qry || !read_psa)
    {
        printf("Parametros invalidos");
        return -1;
    }
    if (read_qry && read_psa) // verifica se os parametros do qry.svg e da saida foram passados
    {
        char *psaqrysvg = calloc(strlen(getpsa(parameters)) + strlen(getnameqryExt(parameters)) + 5, sizeof(char)); // aloca memoria para o path do qry.svg
        char *psaqrytxt = calloc(strlen(getpsa(parameters)) + strlen(getnameqryExt(parameters)) + 5, sizeof(char)); // aloca memoria para o path do qry.txt
        strcpy(psaqrysvg, getpsa(parameters));                                                                      // copia o path de saida para o path do qry.svg
        VerifDiretorio(psaqrysvg);                                                                                  // verifica se o diretorio existe, se nao existir, cria
        strcat(psaqrysvg, getnameqryExt(parameters));                                                               // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        strcat(psaqrysvg, "_");                                                                                     // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        strcat(psaqrysvg, getnameqry(parameters));                                                                  // concatena o nome do arquivo qry sem extensao com o path do qry.svg

        if (psaqrysvg[strlen(psaqrysvg) - 4] == '.') // verifica se o nome do arquivo qry tem extensao

            psaqrysvg[strlen(psaqrysvg) - 4] = '\0'; // se tiver, remove a extensao sendo nameqryExt = nome do arquivo qry sem extensao
        setpsaqrysvg(parameters, psaqrysvg);         // envia o path do qry.svg para a tad parameters

        strcpy(psaqrytxt, psaqrysvg);        // copia o path de saida para o path do qry.txt
        strcat(psaqrytxt, ".txt");           // concatena o nome do arquivo qry sem extensao com o path do qry.txt
        strcat(psaqrysvg, ".svg");           // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        setpsageosvg(parameters, psaqrysvg); // envia o path do geo.svg para a tad parameters
        setpsaqrytxt(parameters, psaqrytxt); // envia o path do qry.txt para a tad parameters
    }
    return 0;
}