#include "systemgeo.h"
#include "systempath.h"
#include "lista.h"
#include "circ.h"

/* ============================== ler informacoes das formas para salvar na lista ==============================*/

void ReadGeo(void *lista, void *parameters)
{
    int id;
    double x, x2, y, y2, r, h, w;                            // onde x e y sao as coordenadas da localização das formas, x2 e y2 sao as coordenadas do ponto final da linha, r é o raio do circulo, h e w sao a altura e largura do retangulo
    char tipo[2], corb[20], corp[20], cor[20], txto[200], a[1]; // onde corb e corp sao as cores da borda e do preenchimento, tipo é o tipo da forma, cor é a cor da forma, txto é o texto da forma
    void *novaforma;
    void *novoNo;
    void *geo;
    
    geo = getgeofullpath(parameters); // ler o arquivo geo e salvar as informacoes na lista

    // ler o arquivo geo e salvar as informacoes na lista
    printf("lendo arquivo .geo:%s\n\n", (char*)geo);


    FILE *peageo = fopen(geo, "r"); // abre o arquivo geo para leitura, onde "r" significa "read ou seja, leitura"


    if (peageo == NULL)                                    // verifica se o arquivo geo foi aberto
    {
        printf("\nErro ao abrir o arquivo geo\n"); //o erro se da quando o arquivo geo nao existe
        exit(EXIT_FAILURE);
    }
    while (!feof(peageo)) // enquanto nao chegar no final do arquivo geo
    {

    }
    fclose(peageo); // fecha o arquivo geo

}