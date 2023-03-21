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
    char *psaqrytxt;   // path de saida do arquivo qry.txt
    char *psaqeytxt;   // path de saida do arquivo qry.txt
    char *qryfullpath; // path completo do arquivo qry
    char *geofullpath; // path completo do arquivo geo
} all_paths;

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
    free(aux->psaqeytxt);
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