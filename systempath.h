#ifndef SYSTEMPATH_H
#define SYSTEMPATH_H

#include "biblioteca.h"
#include "parameters.h"


/* Vai ler os pareametros, é necessario colocar no systempath.h e linkar na main para que a main acesse o systempath.c */
int readParam(int argc, char **argv, void *parameters);


void* createParameters();    // vai para parameters.c
char* getpath(void* parameters); //funcao para pegar o path
void freeParameters(void* parameters); //

/* sets e gets na ordem do systempath.c */
void setgeofullpath(void *parameters, char *geofull);
void setpeaqry(void *parameters, char *qryfull);

char *getpeaqry(void *parameters);
char *getgeofullpath(void *parameters);

void setpea(void *parameters, char *pea);
void setpsa(void *parameters, char *psa);
void setpeageo(void *parameters, char *peageo);
void setpeageoExt(void *parameters, char *peageoExt);
void setnameqry(void *parameters, char *nameqry);
void setnameqryExt(void *parameters, char *nameqryExt);
void setpsageosvg(void *parameters, char *psageosvg);
void setpsaqrytxt(void *parameters, char *psaqrytxt);


char *getpea(void *parameters);
char *getpsa(void *parameters);
char *getpeageo(void *parameters);
char *getpeageoExt(void *parameters);
char *getnameqry(void *parameters);
char *getnameqryExt(void *parameters);
char *getpsageosvg(void *parameters);
char *getpsaqrytxt(void *parameters);

/* print debug */
void printPath(void *parameters);
/* diretorios */
char *VerifDiretorio(char *diretorio);

#endif