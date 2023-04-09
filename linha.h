#include "biblioteca.h"
#ifndef LINHA_H
#define LINHA_H

bool checkLinha(void *bião);

/* inicio dos gets */

char getLinhaTipo(void *bião);
int getLinhaId(void *bião);
double getLinhaX1(void *bião);
double getLinhaX2(void *bião);
double getLinhaY1(void *bião);
double getLinhaY2(void *bião);
char* getLinhaCor(void *bião);

/* sets */
void setLinhaTipo(void *bião, char tipo);
void setLinhaId(void *bião, int id);
void setLinhaX1(void *bião, double x1);
void setLinhaX2(void *bião, double x2);
void setLinhaY1(void *bião, double y1);
void setLinhaY2(void *bião, double y2);
void setLinhaCor(void *bião, char *cor);

/* criar linha tam memoria e frees */
void *createLinha(int id, double x1, double y1, double x2, double y2, char *cor);
void freeLinha(void *bião);
#endif