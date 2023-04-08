#include "svg.h"
#include "circ.h"
#include "lista.h"
#include "parameters.h"
#include "systempath.h"
#include "systemgeo.h"

void printSvg(void *list, char *arquivo)
{

    int id;
    char *corb, *corp, *cor, *txto;
    double x, x2, y, y2, r, h, w;

    void *auxform;
    void *no;
    printf("conteudo de arquivo: %s\n", (char *)arquivo);

    FILE *svg = fopen(arquivo, "w"); // abre o arquivo svg para escrita, onde "w" significa "write ou seja, escrita"
    if (svg == NULL)
    {
        printf("\nErro ao abrir o arquivo svg\n");
        exit(EXIT_FAILURE);
    }
    printf("Arquivo svg aberto com sucesso\n\n");                                 // abre o arquivo svg para escrita, onde "w" significa "write ou seja, escrita"
    fprintf(svg, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n"); // escreve no arquivo svg a primeira linha

    for (no == getFirstLst(list); no; no = getNextLst(list, no))
    {                                   // percorre a lista
        auxform = getLst(list, no);     // pega o elemento da lista
        char tipo = checkForm(auxform); // pega o tipo do elemento da lista (c, r, t, etc)

        switch (tipo)
        {
        case 'c':
            auxform = getLst(list, no);
            id = getidCirc(auxform);
            x = getxCirc(auxform);
            y = getyCirc(auxform);
            r = getrCirc(auxform);
            corb = getcorbCirc(auxform);
            corp = getcorpCirc(auxform);
            fprintf(svg, "<circle id=\"%d\" cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill-opacity=\"0.7\" fill=\"%s\" />\n", id, x, y, r, corb, corp);
            fflush(svg);
            break;
        }
    }
    fprintf(svg, "</svg>\n");
    fclose(svg);
}
