#include "biblioteca.h"
#ifndef TXTO_H
#define TXTO_H

bool checkTxt(void *bião);
/* bool checkTs(void *bião); */

/* inicio das declaracoes gets da tad texto */
char getTxtTipo(void *bião);
int getTxtId(void *bião);
double getTxtX(void *bião);
double getTxtY(void *bião);
char* getTxtA(void *bião);
char* getTxtCorp(void *bião);
char* getTxtCorb(void *bião);
char* getTxtTxto(void *bião);

/* gets ts*/
int getTxtfSize(void *biao);
char* getTxtfFamily(void *biao);
char* getTxtfWeight(void *biao);

/* inicio dos sets */

void setTxtTipo(void *bião, char Ttipo);
void setTxtId(void *bião, int Tid);
void setTxtX(void *bião, double Tx);
void setTxtY(void *bião, double Ty);
void setTxtA(void *bião, char *Ta);
void setTxtCorp(void *bião, char *Tcorp);
void setTxtCorb(void *bião, char *Tcorb);
void setTxtTxto(void *bião, char *Ttxto);

/* set ts */
void setTxtFsize(void *biao, int Tfs);
void setfFamily(void *biao, char *Tff);
void setfWeight(void *biao, char *Tfw);


//void* createTxt(int id, int fSize, double x, double y, char *corb, char *corp, char *a, char *txto, char *fFamily, char *fWeight){


void* createTxt(int id, double x, double y, char *corp, char *corb, char *a, char *txto);
void freeTxt(void *biao);

/* Ts */
void * createTs(char *fFamily, char *fWeight, int fSize);
void freeTs(void *biao);
bool checkTs(void *biao);
int printstruct();

#endif