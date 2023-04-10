#include "biblioteca.h"
#ifndef TXTO_H
#define TXTO_H

bool checkTxt(void *bião);

/* inicio das declaracoes gets da tad texto */
char getTxtTipo(void *bião);
int getTxtId(void *bião);
double getTxtX(void *bião);
double getTxtY(void *bião);
char* getTxtA(void *bião);
char* getTxtCorp(void *bião);
char* getTxtCorb(void *bião);
char* getTxtTxto(void *bião);

/* inicio dos sets */

void setTxtTipo(void *bião, char Ttipo);
void setTxtId(void *bião, int Tid);
void setTxtX(void *bião, double Tx);
void setTxtY(void *bião, double Ty);
void setTxtA(void *bião, char *Ta);
void setTxtCorp(void *bião, char *Tcorp);
void setTxtCorb(void *bião, char *Tcorb);
void setTxtTxto(void *bião, char *Ttxto);

void* createTxt(int id, double x, double y, char *a, char *corp, char *corb, char *txto);

void freeTxt(void *biao);


#endif