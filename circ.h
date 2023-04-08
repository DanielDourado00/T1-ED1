#ifndef CIRC_H
#define CIRC_H

#include "biblioteca.h"

bool checkCirc(void *bião);

/* inicio das declaracoes gets da tad circulo */
char gettipoCirc(void *bião);
int getidCirc(void *bião);
double getxCirc(void *bião);
double getyCirc(void *bião);
double getrCirc(void *bião);
char* getcorbCirc(void *bião);
char* getcorpCirc(void *bião);

/* inicio das declaracoes sets da tad circulo */
void settipoCirc(void *bião, char tipo);
void setidCirc(void *bião, int id);
void setxCirc(void *bião, double x);
void setyCirc(void *bião, double y);
void setrCirc(void *bião, double r);
void setcorbCirc(void *bião, char *corb);
void setcorpCirc(void *bião, char *corp);

/* criacao de circulo */
/* tamanho da memoria */
/* limpeza dele */
void* createCircle (int id, double x, double y, double r, char *corb, char *corp);
void* memoriacirc();
void freeCircle (void *biao);

#endif