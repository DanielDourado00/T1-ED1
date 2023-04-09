#include "linha.h"

typedef struct line{
    char tipo;
    int id;
    double x1;
    double y1;
    double x2;
    double y2;
    char cor[100];
    /* variaveis para o qry */
} Line;

/* ===========================================inicio dos sets/=========================================== */
/* os sets vao ser usados para setar as informacoes da linha e fazer as operacoes com o qry, segue a ordem da struct line */
void setLinhaTipo(void *biao, char tipo){
    Line *Line = biao;
    Line->tipo = tipo;
}

void setLinhaId(void *biao, int id){
    Line *Line = biao;
    Line->id = id;
}

void setLinhaX1(void *biao, double x1){
    Line *Line = biao;
    Line->x1 = x1;
}

void setLinhaX2(void *biao, double x2){
    Line *Line = biao;
    Line->x2 = x2;
}

void setLinhaY1(void *biao, double y1){
    Line *Line = biao;
    Line->y1 = y1;
}

void setLinhaY2(void *biao, double y2){
    Line *Line = biao;
    Line->y2 = y2;
}

void setLinhaCor(void *biao, char *cor){
    Line *Line = biao;
    strcpy(Line->cor, cor);
}

/* gets */

char getLinhaTipo(void *biao){
    Line *Line = biao;
    return Line->tipo;
}

int getLinhaId(void *biao){
    Line *Line = biao;
    return Line->id;
}

double getLinhaX1(void *biao){
    Line *Line = biao;
    return Line->x1;
}

double getLinhaX2(void *biao){
    Line *Line = biao;
    return Line->x2;
}

double getLinhaY1(void *biao){
    Line *Line = biao;
    return Line->y1;
}

double getLinhaY2(void *biao){
    Line *Line = biao;
    return Line->y2;
}

char *getLinhaCor(void *biao){
    Line *Line = biao;
    return Line->cor;
}

/* ===========================================fim dos sets/=========================================== */

bool checkLinha(void *bião){
    Line *Line = bião;
    if(Line->tipo == 'l' || Line->tipo == 'L'){
        return true;
    }
    return false;
}
/* alocar memoria e cirar linha */

void *createLinha(int id, double x1, double y1, double x2, double y2, char *cor){
    Line *line = calloc(1, sizeof(Line));
    setLinhaTipo(line, 'l');
    setLinhaId(line, id);
    setLinhaX1(line, x1);
    setLinhaX2(line, x2);
    setLinhaY1(line, y1);
    setLinhaY2(line, y2);
    setLinhaCor(line, cor);
    return line;
}

void freeLinha(void *biao){
    Line *Line = biao;
    free(Line);
}
