#include "svg.h"

void printSvg(void *list, void *arquivo)
{

    int id;
    char *corb, *corp, *cor, *txto;
    double x, x2, y, y2, r, h, w;

    void *forma;
    void *no;
    printf("conteudo de arquivo: %s\n", (char *)arquivo);
    
    FILE *svg = fopen(arquivo, "w");                                // abre o arquivo svg para escrita, onde "w" significa "write ou seja, escrita"
    if (svg == NULL)
    {
        printf("\nErro ao abrir o arquivo svg\n");
        exit(EXIT_FAILURE);
    }
    printf("Arquivo svg aberto com sucesso\n\n");                                  // abre o arquivo svg para escrita, onde "w" significa "write ou seja, escrita"
    fprintf(svg, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n");   // escreve no arquivo svg a primeira linha
}