#include "retangulo.h"



typedef struct retangulo
{
    char tipo;
    int id;
    double x;
    double y;
    double w;
    double h;
    char corb[100];
    char corp[100];
}rect;

/* sets */
void setRetangulotipo(void *bião, char tipo){ //biao é sdata
    rect *retangulo = bião;
    retangulo->tipo = tipo;
}

void seRetanguloId(void *bião, int id){
    rect *retangulo = bião;
    retangulo->id = id;
}

void setRetanguloX(void *bião, double x){
    rect *retangulo = bião;
    retangulo->x = x;
}

void setRetanguloY(void *bião, double y){
    rect *retangulo = bião;
    retangulo->y = y;
}

void setRetanguloW(void *bião, double w){
    rect *retangulo = bião;
    retangulo->w = w;
}

void setRetanguloH(void *bião, double h){
    rect *retangulo = bião;
    retangulo->h = h;
}

void setRetanguloCorb(void *bião, char *corb){
    rect *retangulo = bião;
    strcpy(retangulo->corb, corb);
}

void setRetanguloCorp(void *bião, char *corp){
    rect *retangulo = bião;
    strcpy(retangulo->corp, corp);
}

/* gets */

char getRetanguloTipo(void *bião){
    rect *retangulo = bião;
    return retangulo->tipo;
}

int getRetanguloId(void *bião){
    rect *retangulo = bião;
    return retangulo->id;
}

double getRetanguloX(void *bião){
    rect *retangulo = bião;
    return retangulo->x;
}

double getRetanguloY(void *bião){
    rect *retangulo = bião;
    return retangulo->y;
}

double getRetanguloW(void *bião){
    rect *retangulo = bião;
    return retangulo->w;
}

double getRetanguloH(void *bião){
    rect *retangulo = bião;
    return retangulo->h;
}

char* getRetanguloCorb(void *bião){
    rect *retangulo = bião;
    return retangulo->corb;
}

char* getRetanguloCorp(void *bião){
    rect *retangulo = bião;
    return retangulo->corp;
}

bool checkRetangulo(void *bião){
    rect *retangulo = bião;
    if(retangulo->tipo == 'r' || retangulo->tipo == 'R'){
        return true;
    }
    else{
        return false;
    }
}

/* criar retangulo memoria */
void* createRetangulo(int id, double x, double y, double w, double h, char *corb, char *corp){
    rect *retangulo = (rect*)calloc(1, sizeof(rect));
    setRetangulotipo(retangulo, 'r');
    seRetanguloId(retangulo, id);
    setRetanguloX(retangulo, x);
    setRetanguloY(retangulo, y);
    setRetanguloW(retangulo, w);
    setRetanguloH(retangulo, h);
    setRetanguloCorb(retangulo, corb);
    setRetanguloCorp(retangulo, corp);
    return retangulo;
}

/* checkagem */


/* free */

void freeRetangulo(void *bião){
    rect *retangulo = bião;
    free(retangulo);
}