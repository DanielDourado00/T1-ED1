 #include "systemgeo.h"
#include "systempath.h"
#include "lista.h"
#include "circ.h"
#include "retangulo.h"
#include "linha.h"
#include "txto.h"

/* ============================== ler informacoes das formas para salvar na lista ==============================*/

void ReadGeo(void *lista, void *parameters)
{
    int id;
    int fSize;
    double x, x2, y, y2, r, h, w;                               // onde x e y sao as coordenadas da localização das formas, x2 e y2 sao as coordenadas do ponto final da linha, r é o raio do circulo, h e w sao a altura e largura do retangulo
    char tipo[5], corb[20], corp[20], cor[20], txto[100], a[3]; // onde corb e corp sao as cores da borda e do preenchimento, tipo é o tipo da forma, cor é a cor da forma, txto é o texto da forma
    char fFamily[10], fWeight[5];
    void *novaforma;
    /*    void *newstyletext; */
    void *geo;

    geo = getgeofullpath(parameters); // ler o arquivo geo e salvar as informacoes na lista

    // ler o arquivo geo e salvar as informacoes na lista
    printf("lendo arquivo .geo: %s\n\n", (char *)geo);

    FILE *peageo = fopen(geo, "r"); // abre o arquivo geo para leitura, onde "r" significa "read ou seja, leitura"

    if (peageo == NULL) // verifica se o arquivo geo foi aberto
    {
        printf("\nErro ao abrir o arquivo geo\n"); // o erro se da quando o arquivo geo nao existe
        exit(EXIT_FAILURE);
    }
    printf("Arquivo geo aberto com sucesso\n\n");

    while (!feof(peageo)) // enquanto nao chegar no final do arquivo geo
    {
        fscanf(peageo, "%s", tipo); // le o tipo da forma
        if (!strcmp(tipo, "c"))     // se o tipo de forma for circulo
        {
            fscanf(peageo, "%d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp); // le as informacoes do circulo
            novaforma = createCircle(id, x, y, r, corb, corp);                   // cria o circulo
                                                                                 // novaforma = createNode(novaforma); // cria um no para o circulo
            insertLst(lista, novaforma);                                         // insere o no na lista
        }
        else if (!strcmp(tipo, "r")) // se o tipo de forma for retangulo
        {
            fscanf(peageo, "%d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp); // le as informacoes do retangulo
            novaforma = createRetangulo(id, x, y, w, h, corb, corp);                     // cria o retangulo                                                                           /*             novaforma = createNode(novaforma); // cria um no para o retangulo                                                                               */
            insertLst(lista, novaforma);                                                 // insere o no na lista
        }
        else if (!strcmp(tipo, "l"))
        {
            fscanf(peageo, "%d %lf %lf %lf %lf %s", &id, &x, &y, &x2, &y2, cor); // le as informacoes da linha
            novaforma = createLinha(id, x, y, x2, y2, cor);                      // cria a linha
            insertLst(lista, novaforma);                                         /*             novaforma = createNode(novaforma); // cria um no para a linha                                                                               */
        }
        else if (!strcmp(tipo, "ts"))
        {
            fscanf(peageo, "%s %s %d", fFamily, fWeight, &fSize); // le as informacoes do texto
            printf("\n\t fFamily: %s\n\t fWeight: %s\n\t fSize: %d\n", fFamily, fWeight, fSize);
            novaforma = createTs(fFamily, fWeight, fSize); // cria o texto
            insertLst(lista, novaforma);                   // insere o no na lista
        }
        else if (!strcmp(tipo, "t"))
        {
            fscanf(peageo, "%d %lf %lf %s %s %s %s", &id, &x, &y, corb, corp, a, txto); // le as informacoes do texto
                                                                                                                           /*             printf("\nid: %d\n x: %lf\n y: %lf\n corb: %s\n corp: %s\n a: %s\n txto: %s\n fFamily: %s\n fWeight: %s\n fSize: %d\n", id, x, y, corb, corp, a, txto, fFamily, fWeight, fSize);
                                                                                                                            */
            novaforma = createTxt(id, x, y, corp, corb, a, txto);                                 // cria o texto
            insertLst(lista, novaforma);                                                                                   // insere o no na lista
        }

        strcpy(tipo, " "); // limpa a variavel tipo
    }
    fclose(peageo); // fecha o arquivo geo
}

/* ============================== ler informacoes das formas para salvar na lista ==============================*/
/* ========================================checkforms========================================*/
char checkForm(void *forma)
{
    void *aux = forma;
    if (checkCirc(aux) == true)
    {
        return 'c';
    }
    else if (checkRetangulo(aux) == true)
    {
        return 'r';
    }
    else if (checkLinha(aux) == true)
    {
        return 'l';
    }
    else if (checkTxt(aux) == true)
    {   
        return 't';
    }
    else
    {
        return 's';
    }
}


/* =======================================deleteforms=======================================*/
void deleteForm(void *forma)
{
    void *aux = forma;
    freeCircle(aux);
    freeRetangulo(aux);
    freeLinha(aux);
    freeTxt(aux);
}