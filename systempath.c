#include "systempath.h"


/* verificar todos os metodos de entrada de arquivo pois apenas o   
./ted -e ./testes -f t001.geo -o ./alunos/aluno1/o/ -q ./q1.qry 
esta funcionando */

typedef struct all_paths
{ // struct para guardar todos os paths

    char *pea;          // path de entrada de arquivos
    char *psa;          // path de saida de arquivos
    char *peageo;      // nome do arquivo geo (.geo sob p diretorio pea)


    char *geofullpath;  // path completo do arquivo geo
    char *peageoExt;   // nome do aruivo .geo sem extensao (peageo)

    char *peaqry;  // path completo do arquivo qry
    char *nameqryExt;   // nome do arquivo .qry sem extensao
    char *nameqry;      // nome do arquivo qry (pea qry)


    char *psageosvg;    // path de saida do arquivo geo.svg
    char *psageoqrysvg; // path de saida do arquivo qry.svg
    char *psageoqrytxt; // path de saida do arquivo qry.txt
} all_paths;

void *createParameters()
{
    all_paths *aux = calloc(1, sizeof(all_paths)); // aloca memoria para a struct all_paths e retorna o ponteiro para aux
    return aux;
}

char *VerifDiretorio(char *diretorio)
{ // verifica se o diretorio termina com /, se nao terminar, adiciona
    if (diretorio[strlen(diretorio) - 1] != '/')
    {
        strcat(diretorio, "/");

    }
        return diretorio;
}
/* fazer funcao para verificar ponto usando . usando reverse */

void freeparameters(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths / libera memoria alocada para cada path
    free(aux->pea);
    free(aux->psa);
    free(aux->peageo);
    free(aux->peageoExt);
    free(aux->nameqry);
    free(aux->nameqryExt);
    free(aux->psageosvg);
    free(aux->psageoqrysvg);
    free(aux->peaqry);
    free(aux->geofullpath);
    free(parameters); // libera memoria alocada para a struct all_paths
}

void setgeofullpath(void *parameters, char *geofull)
{
    all_paths *aux = (all_paths *)parameters; // cast para all_paths
    aux->geofullpath = geofull;               // seta o path completo do arquivo geo
}

void setpeaqry(void *parameters, char *peaqry)
{
    all_paths *aux = (all_paths *)parameters; // cast para all_paths
    aux->peaqry = peaqry;           // seta o path completo do arquivo qry
}

char *getpeaqry(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->peaqry;     // retorna o path completo do arquivo qry
}

char *getgeofullpath(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->geofullpath;     // retorna o path completo do arquivo geo
}

void setpea(void *parameters, char *pea)
{
    all_paths *aux = (all_paths *)parameters; // cast para all_paths
    aux->pea = pea;                           // seta o path de entrada de arquivos
}

void setpsa(void *parameters, char *psa)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->psa = psa;              // seta o path de saida de arquivos
}

void setpeageo(void *parameters, char *peageo)
{
    all_paths *aux = parameters; // cast para all_paths
    aux->peageo = peageo;      // seta o nome do arquivo geo
}

void setpeageoExt(void *parameters, char *peageoExt)
{
    all_paths *aux = parameters;  // cast para all_paths
    aux->peageoExt = peageoExt; // seta o nome do arquivo geo sem extensao
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

void setpsageoqrysvg(void *parameters, char *psageoqrysvg)
{
    all_paths *aux = parameters;      // cast para all_paths
    aux->psageoqrysvg = psageoqrysvg; // seta o path de saida do arquivo geo.svg
}

void setpsageoqrytxt(void *parameters, char *psageoqrytxt)
{
    all_paths *aux = parameters;      // cast para all_paths
    aux->psageoqrytxt = psageoqrytxt; // seta o path de saida do arquivo qry.txt
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

char *getpeageo(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->peageo;         // retorna o nome do arquivo geo
}

char *getpeageoExt(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->peageoExt;      // retorna o nome do arquivo geo sem extensao
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

char *getpsageoqrytxt(void *parameters)
{
    all_paths *aux = parameters; // cast para all_paths
    return aux->psageoqrytxt;    // retorna o path de saida do arquivo qry.txt
}

/* prints para debug */

void printPath(void *parameters)
{
    printf("\n\nDiretorio base de entrada (pea): %s)", getpea(parameters));
    printf("\n\nDiretorio base de saida (psa): %s)", getpsa(parameters));

    printf("\n==========PRINTS PARA GEO DEBUG==========\n");
    printf("\nNome do arquivo geo: %s", getpeageo(parameters));
    printf("\nNome do arquivo geo sem extensao: %s", getpeageoExt(parameters));
    printf("\nPath completo do arquivo geo: %s", getgeofullpath(parameters));

    printf("\n==========PRINTS DE DEBUGAR QRY==========\n");
    printf("\nDiretorio completo do arquivo qry: %s", getpeaqry(parameters));
    printf("\nNome do arquivo qry: %s", getnameqry(parameters));
    printf("\nNome do arquivo qry sem extensao: %s", getnameqryExt(parameters));

    printf("\n==========PRINTS PARA DEBUGAR O SVG==========\n");
    printf("\nPath de saida do arquivo geo.svg (psageosvg): %s", getpsageosvg(parameters));
    printf("\nPath de saida do arquivo qry.txt (psageoqrytxt): %s", getpsageoqrytxt(parameters));
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
    bool read_psa = false;
    bool read_geo = false;
    bool read_qry = false;
    // flags para verificar se os parametros foram passados sendo pea = -e, psa = -o, geo = -f, qry = -q

    char *normPath;
    int len;

    int opt;
    while ((opt = getopt(argc, argv, "e:f:o:q:")) != -1) // se caso algum dos parametros que entrrar forem -e -f -o -q, o getopt vai retornar o valor do parametro
    {
        switch (opt)
        {
        case 'e':                                                 // -e path Diretório-base de entrada ($DIR_ENTRADA)
            char *pea = calloc(strlen(optarg) + 1, sizeof(char)); // aloca o tamanho do pea
            strcpy(pea, optarg);
            len = strlen(pea);                 // pega o tamanho do pea
            normPath = "";                     // seta o normPath como vazio
            normalizePath(pea, normPath, len); // envia para a funcao normalizePath para normalizar o path do parameters.c
            setpea(parameters, pea);           // seta o pea
/*             printf("conteudo de pea na tad systempath linha 233: %s\n\n", pea);
 */            break;

        case 'f':                                                        // -f arq.geo. Este arquivo deve estar sob o diretório $DIR_ENTRADA.
            char *peageo = calloc(strlen(optarg) + 1, sizeof(char));    // aloca o tamanho do peageo
            char *peageoExt = calloc(strlen(optarg) + 1, sizeof(char)); // aloca o tamanho do peageoExt (sem extensao)
            char *ext = ".geo";                                          // extensao do geo
            if (!getpea(parameters))                                     // se o pea nao foi passado, seta o pea como "./"
            {
                char *pea = calloc(3, sizeof(char)); // seria 3 mas tem que colocar o \0
                strcpy(pea, "./");
                setpea(parameters, pea);
            }
            read_geo = true;
            strcpy(peageo, optarg);

            char *geofullpath = calloc(strlen(peageo) + strlen(getpea(parameters)) + 2, sizeof(char));

            joinFilePath(getpea(parameters), peageo, geofullpath, len);
            strcpy(peageoExt, peageo); // copia o nome do arquivo geo para o nome do arquivo geo sem extensao

            // printf("conteudo de peageoExt na tad systempath linha 254: %s\n\n", peageoExt);

            if (peageoExt[strlen(peageoExt) - 4] == '.')     // verifica se o nome do arquivo geo tem extensao  //strchr() function.
                *(peageoExt + strlen(peageoExt) - 4) = '\0'; // se tiver, retira a extensao do nome do arquivo geo sem extensao e coloca o \0 no final
            joinAll(getpea(parameters), peageoExt, ext, geofullpath, len);

            setpeageo(parameters, peageo);         // envia o nome do arquivo geo para a tad parameters
            setpeageoExt(parameters, peageoExt);   // envia o nome do arquivo geo sem extensao para a tad parameters
            setgeofullpath(parameters, geofullpath); // envia o path completo do arquivo geo para a tad parameters
/*             printf("conteudo de peageo (com extensao) na tad systempath linha 254: %s\n\n", peageo);
            printf("conteudo de peageoExt (sem extensao) na tad systempath linha 254: %s\n\n", peageoExt);
 */            break;

        case 'o':                                                 // -o path  Diretório-base de saída ($DIR_SAIDA)
            char *psa = calloc(strlen(optarg) + 1, sizeof(char)); // aloca memoria para o path de saida
            strcpy(psa, optarg);                                  // copia o path de saida para a variavel psa
            read_psa = true;                                      // seta a flag de path de saida como verdadeira
            normalizePath(psa, normPath, len);                    // normaliza o path de saida para ser usada na tad parameters
            setpsa(parameters, psa);                              // seta o path de saida
/*             printf("conteudo de psa na tad systempath linha 258: %s\n\n", psa);
 */            break;

        case 'q':                                                        // -q arqcons.qry  Arquivo com consultas. Este arquivo deve estar sob o diretório $DIR_ENTRADA.
            char *nameqry = calloc(strlen(optarg) + 1, sizeof(char));    // aloca memoria para o nome do arquivo qry
            char *nameqryExt = calloc(strlen(optarg) + 1, sizeof(char)); // aloca memoria para o nome do arquivo qry sem extensao
            char *extt = ".qry";                                          // extensao do qry
            if (!getpea(parameters))
            {
                char *pea = calloc(3, sizeof(char)); // seria 3 mas tem que colocar o \0
                strcpy(pea, "./");
                setpea(parameters, pea);
            }

            read_qry = true;

            strcpy(nameqry, optarg);                                                                    // copia o nome do arquivo qry para o nome do arquivo qry com extensao
            char *peaqry = calloc(strlen(nameqry) + strlen(getpea(parameters)) + 2, sizeof(char)); // aloca memoria para o path completo do arquivo qry

            joinFilePath(getpea(parameters), nameqry, peaqry, len); // junta o path de entrada com o nome do arquivo qry para formar o path completo do arquivo qry
            strcpy(nameqryExt, nameqry);                                 // copia o nome do arquivo qry para o nome do arquivo qry sem extensao
/*             printf("conteudo de name qry: %s, conteudo de peaqry: %s, conteudo de len: %d\n", nameqry, peaqry, len);
 */

        /* usar strrchr para verificar a aparição de barra e salvar o conteudo que está apos a barra */
        
            if (nameqryExt[strlen(nameqryExt) - 4] == '.')     // verifica se o nome do arquivo qry tem extensao
                *(nameqryExt + strlen(nameqryExt) - 4) = '\0'; // se tiver, remove a extensao sendo nameqryExt = nome do arquivo qry sem extensao

            joinAll(getpea(parameters), nameqryExt, extt, peaqry, len); // junta o path de entrada com o nome do arquivo qry sem extensao e a extensao para formar o path completo do arquivo qry
           
            setnameqryExt(parameters, nameqryExt);      // envia o nome do arquivo qry para a tad parameters
            setnameqry(parameters, nameqry);      // envia o nome do arquivo qry sem extensao para a tad parameters
            setpeaqry(parameters, peaqry); // envia o path completo do arquivo qry para a tad parameters
           
           
            //printf("conteudo de nameqry (com extensao) na tad systempath linha 254: %s\n\n", nameqry);
            //printf("conteudo de nameqryExt (sem extensao) na tad systempath linha 254: %s\n\n", nameqryExt);           
            break;

        default:
            //printf("Parametro invalido");
            return -1;
        }
    }

    if (!read_geo || !read_psa)
    {
        //printf("Parametros invalidos, sem dir de saida ou n lendo o .geo");
        return -1;
    }

    if (read_geo && read_psa)
    {                                                                                                               // verifica se os parametros do geo.svg  a saida foram passados
        char *psageosvg = calloc(strlen(getpsa(parameters)) + strlen(getpeageoExt(parameters)) + 6, sizeof(char)); // aloca memoria para o path do geo.svg
        strcpy(psageosvg, getpsa(parameters));                                                                      // copia o path de saida para o path do geo.svg
        VerifDiretorio(psageosvg);                                                                                  // verifica se o diretorio existe, se nao existir, cria
        strcat(psageosvg, getpeageoExt(parameters));
        strcat(psageosvg, ".svg"); // concatena o nome do arquivo geo sem extensao com o path do geo.svg
/*         printf("\nconteudo de psageosvg: %s\n\n ", psageosvg);
 */        setpsageosvg(parameters, psageosvg); // envia o path do geo.svg para a tad parameters
/*         printf("\n\n bião debugs\n\n"); */
    }

    if (!read_qry || !read_psa)
    {
        printf("Parametros invalidos ao ler o qry e o dir de saida");
        return -1;
    }

    if (read_qry && read_psa) // verifica se os parametros do qry.txt e da saida foram passados
    {

       // printf("\ncuzinho curioso debugador no read_qry read_psa\n");
        char *psageoqrysvg = calloc(strlen(getpsa(parameters)) + strlen(getnameqryExt(parameters)) + strlen(getnameqry(parameters)) + 7, sizeof(char)); // aloca memoria para o path do qry.svg
        char *psageoqrytxt = calloc(strlen(getpsa(parameters)) + strlen(getnameqryExt(parameters)) + strlen(getnameqry(parameters)) + 7, sizeof(char)); // aloca memoria para o path do qry.txt
        strcpy(psageoqrysvg, getpsa(parameters));                                                                                                       // copia o path de saida para o path do qry.svg
        VerifDiretorio(psageoqrysvg);                                                                                                                   // verifica se o diretorio existe, se nao existir, cria
        strcat(psageoqrysvg, getnameqryExt(parameters));                                                                                                // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        strcat(psageoqrysvg, "_");                                                                                                                      // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        strcat(psageoqrysvg, getnameqry(parameters));                                                                                                   // concatena o nome do arquivo qry sem extensao com o path do qry.svg

        if (psageoqrysvg[strlen(psageoqrysvg) - 4] == '.') // verifica se o nome do arquivo qry tem extensao
            psageoqrysvg[strlen(psageoqrysvg) - 4] = '\0'; // se tiver, remove a extensao sendo nameqryExt = nome do arquivo qry sem extensao           // envia o path do qry.svg para a tad parameters

        strcpy(psageoqrytxt, psageoqrysvg); // copia o path de saida para o path do qry.txt
        strcat(psageoqrysvg, ".svg");       // concatena o nome do arquivo qry sem extensao com o path do qry.txt
        strcat(psageoqrytxt, ".txt");       // concatena o nome do arquivo qry sem extensao com o path do qry.svg
        //printf("\nconteudo de psageoqrytxt: %s\n\n ", psageoqrytxt);
        //printf("\nconteudo de psageoqrysvg: %s\n\n ", psageoqrysvg);
        setpsageoqrysvg(parameters, psageoqrysvg); // envia o path do geo.svg para a tad parameters
        setpsageoqrytxt(parameters, psageoqrytxt); // envia o path do qry.txt para a tad parameters
/*         printf("\n\n bião debugs qry\n\n"); */
    }
    return 0;
}
