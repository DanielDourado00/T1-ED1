#include "systemgeo.h"
#include "systempath.h"

/* ============================== ler informacoes das formas para salvar na lista ==============================*/

void ReadGeo(void *lista, void *parameters)
{
    int id;
    double x, x2, y, y2, r, h, w;                           // onde x e y sao as coordenadas da localização das formas, x2 e y2 sao as coordenadas do ponto final da linha, r é o raio do circulo, h e w sao a altura e largura do retangulo
    char corb[20], corp[20], tipo[2], cor[20], txto[20], a; // onde corb e corp sao as cores da borda e do preenchimento, tipo é o tipo da forma, cor é a cor da forma, txto é o texto da forma
    void *novaforma;
    void *List = lista;
    // ler o arquivo geo e salvar as informacoes na lista
    FILE *arqgeo = fopen(getgeofullpath(parameters), "r"); // abre o arquivo geo para leitura, onde "r" significa "read ou seja, leitura"
    if (arqgeo == NULL)                                    // verifica se o arquivo geo foi aberto
    {
        printf("Erro ao abrir o arquivo geo");
        exit(1);
    }
    while (!feof(arqgeo)) // enquanto nao chegar no final do arquivo geo
    {
        fscanf(arqgeo, "%s", tipo); // le o tipo da forma
        switch (tipo[0])
        {
        case 'c':                                                        // se for circulo
            fscanf(arqgeo, "%lf %lf %lf %s %s", &r, &x, &y, corb, corp); // le as informacoes do circulo
            novaforma = createCircle(r, x, y, corb, corp);               // cria uma nova forma do tipo circulo, vai para a ted de forma circular
            insert(List, novaforma);                                     // insere a nova forma na lista
            break;


/* comenetado o restante para debugar apenas usando a form circulo, vou verificar se esta sendo declarado corretamente o createCircle */



/*         case 'r':                                                                // se for retangulo
            fscanf(arqgeo, "%lf %lf %lf %lf %s %s", &w, &h, &x, &y, corb, corp); // le as informacoes do retangulo
            novaforma = createRectangle(w, h, x, y, corb, corp);                 // cria uma nova forma do tipo retangulo
            insert(List, novaforma);                                             // insere a nova forma na lista
            break;
        case 't':                                               // se for texto
            fscanf(arqgeo, "%lf %lf %s %s", &x, &y, cor, txto); // le as informacoes do texto
            novaforma = createText(x, y, cor, txto);            // cria uma nova forma do tipo texto
            insert(List, novaforma);                            // insere a nova forma na lista
            break;
        case 'l':                                                        // se for linha
            fscanf(arqgeo, "%lf %lf %lf %lf %s", &x, &y, &x2, &y2, cor); // le as informacoes da linha
            novaforma = createLine(x, y, x2, y2, cor);                   // cria uma nova forma do tipo linha
            insert(List, novaforma);                                     // insere a nova forma na lista
            break; */
        }
        strcpy(tipo, ""); // limpa a string tipo
    }
    fclose(arqgeo); // fecha o arquivo geo
}