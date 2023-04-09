#include "biblioteca.h"
#ifndef RETANGULO_H
#define RETANGULO_H

/* sets */
void setRetangulotipo(void *bião, char tipo);
void seRetanguloId(void *bião, int id);
void setRetanguloX(void *bião, double x);
void setRetanguloY(void *bião, double y);
void setRetanguloW(void *bião, double w);
void setRetanguloH(void *bião, double h);
void setRetanguloCorb(void *bião, char *corb);
void setRetanguloCorp(void *bião, char *corp);

/* gets */

char getRetanguloTipo(void *bião);
int getRetanguloId(void *bião);
double getRetanguloX(void *bião);
double getRetanguloY(void *bião);
double getRetanguloW(void *bião);
double getRetanguloH(void *bião);
char* getRetanguloCorb(void *bião);
char* getRetanguloCorp(void *bião);

/* criacao de retangulo */
void* createRetangulo(int id, double x, double y, double w, double h, char *corb, char *corp);

/* checkagem */
bool checkRetangulo(void *bião);

/* free */

void freeRetangulo(void *bião);



#endif