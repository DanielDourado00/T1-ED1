#include "svg.h"
#include "lista.h"
#include "systempath.h"
#include "systemgeo.h"
#include "circ.h"
#include "retangulo.h"
#include "linha.h"
#include "txto.h"

typedef void *Posic;

void printSvg(void *list, char *arquivo)
{

    int id;
    double x, x2, y, y2, r, h, w;
    char *corb;
    char *corp;
    char *cor;
    char *txto;
    char *a;

    void *auxform;
    void *no;
    printf("conteudo de arquivo: %s\n", (char *)arquivo);

    FILE *svg = fopen(arquivo, "w"); // abre o arquivo svg para escrita, onde "w" significa "write ou seja, escrita"
    if (svg == NULL)
    {
        printf("\nErro ao abrir o arquivo svg\n");
        exit(EXIT_FAILURE);
    }

    fprintf(svg, "<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n"); // escreve no arquivo svg a primeira linha
    printf("Arquivo svg aberto com sucesso\n\n");

    for (no = getFirstLst(list); no; no = getNextLst(list, no))
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
        case 'r':
            auxform = getLst(list, no);
            id = getRetanguloId(auxform);
            x = getRetanguloX(auxform);
            y = getRetanguloY(auxform);
            w = getRetanguloW(auxform);
            h = getRetanguloH(auxform);
            corb = getRetanguloCorb(auxform);
            corp = getRetanguloCorp(auxform);
            fprintf(svg, "<rect id=\"%d\" x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" />\n", id, x, y, w, h, corb, corp);
            fflush(svg);
            break;
        case 'l':
            auxform = getLst(list, no);
            id = getLinhaId(auxform);
            x = getLinhaX1(auxform);
            x2 = getLinhaX2(auxform);
            y = getLinhaY1(auxform);
            y2 = getLinhaY2(auxform);
            cor = getLinhaCor(auxform);
            fprintf(svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"1\" />\n", id, x, y, x2, y2, cor);
            fflush(svg);
            break;
        case 't':
            printf("\n\t\tCUZINHO IGNORANTE DEBUGADOR DE MERDA\n");
            auxform = getLst(list, no);
            id = getTxtId(auxform);
            printf("id: %d\n", id);
            x = getTxtX(auxform);
            printf("x: %lf\n", x);
            y = getTxtY(auxform);
            printf("y: %lf\n", y);
            corb = getTxtCorb(auxform);
            printf("corb: %s\n", corb);
            corp = getTxtCorp(auxform);
            printf("corp: %s\n", corp);
            a = getTxtA(auxform);
            printf("a: %s\n", a);
            txto = getTxtTxto(auxform);
            printf("txto: %s\n", txto);
            fprintf(svg, "<text id=\"%d\" x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"1\" fill=\"%s\" text-anchor=\"%s\">%s</text>\n", id, x, y, corb, corp, a, txto);
            fflush(svg);
            break;
        }
    }
    fprintf(svg, "</svg>\n");
    fclose(svg);
}