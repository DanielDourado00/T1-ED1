#ifndef SYSTEMPATH_H
#define SYSTEMPATH_H

#include "biblioteca.h"
#include "parameters.h"


/* Vai ler os pareametros, é necessario colocar no systempath.h e linkar na main para que a main acesse o systempath.c */
int readParam(int argc, char **argv, void *parameters);

typedef void* Path;          // será usado no .c path para alocar memoria.
Path createParameters();    // vai para parameters.c
void printarpath(Path parameters); //funcao para printar o path
char* getpath(Path parameters); //funcao para pegar o path
void freeParameters(Path parameters); //

/* sets e gets na ordem do systempath.c */
void setgeofullpath(void *parameters, char *geofull);
void setqryfullpath(void *parameters, char *qryfull);

char *getqryfullpath(void *parameters);
char *getgeofullpath(void *parameters);

void setpea(void *parameters, char *pea);
void setpsa(void *parameters, char *psa);
void setnamegeo(void *parameters, char *namegeo);
void setnamegeoExt(void *parameters, char *namegeoExt);
void setnameqry(void *parameters, char *nameqry);
void setnameqryExt(void *parameters, char *nameqryExt);
void setpsageosvg(void *parameters, char *psageosvg);
void setpsaqrytxt(void *parameters, char *psaqrytxt);

char *getpea(void *parameters);
char *getpsa(void *parameters);
char *getnamegeo(void *parameters);
char *getnamegeoExt(void *parameters);
char *getnameqry(void *parameters);
char *getnameqryExt(void *parameters);
char *getpsageosvg(void *parameters);
char *getpsaqrytxt(void *parameters);

/* print debug */
void printPath(void *parameters);

/* diretorios */
char *VerifDiretorio(char *diretorio);

#endif