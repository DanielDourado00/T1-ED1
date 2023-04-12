#include "txto.h"

typedef struct texto{
    char tipo;
    int id;
/*     int fSize; */
    double x;
    double y;
    char corp[20];
    char corb[20];
    char a[3];
    char txto[100];
/*     char fFamily[20];
    char fWeight[20]; */

} Texto;




/* ===========================================inicio dos sets/=========================================== */
/* os sets vao ser usados para setar as informacoes da linha e fazer as operacoes com o qry, segue a ordem da struct line */
void setTxtTipo(void *biao, char Ttipo){
    Texto *Tex = biao;
    Tex->tipo = Ttipo;
}

void setTxtId(void *biao, int Tid){
    Texto *Tex = biao;
    Tex->id = Tid;
}


void setTxtX(void *biao, double Tx){
    Texto *Texto = biao;
    Texto->x = Tx;
}

void setTxtY(void *biao, double Ty){
    Texto *Tex = biao;
    Tex->y = Ty;
}

void setTxtA(void *biao, char *Ta){
    Texto *Tex = biao;
    strcpy(Tex->a, Ta);
/* printf("\nconteudo de a cuzinho na funcao settxtA: %s\n", Tex->a);
 */}

void setTxtCorp(void *biao, char *Tcorp){
    Texto *Tex = biao;
    strcpy(Tex->corp, Tcorp);
/*     printf("\nconteudo de corp cuzinho na funcao settxtCorp: %s\n", Tex->corp);
 */}

void setTxtCorb(void *biao, char *Tcorb){
    Texto *Tex = biao;
    strcpy(Tex->corb, Tcorb);
}

void setTxtTxto(void *biao, char *Ttxto){
    Texto *Tex = biao;
    strcpy(Tex->txto, Ttxto);
}


/* gets */

char getTxtTipo(void *biao){
    Texto *Tex = biao;
    return Tex->tipo;
}

int getTxtId(void *biao){
    Texto *Tex = biao;
    return Tex->id;
}


double getTxtX(void *biao){
    Texto *Tex = biao;
    return Tex->x;
}

double getTxtY(void *biao){
    Texto *Tex = biao;
    return Tex->y;
}

char* getTxtA(void *biao){
    Texto *Tex = biao;
    return Tex->a;
}

char* getTxtCorp(void *biao){
    Texto *Tex = biao;
    return Tex->corp;
}

char* getTxtCorb(void *biao){
    Texto *Tex = biao;
    return Tex->corb;
}

char* getTxtTxto(void *biao){
    Texto *Tex = biao;
    return Tex->txto;
}

bool checkTxt(void *bião){
    Texto *Tex = bião;
    if(Tex->tipo == 't' || Tex->tipo == 'T'){
        return true;
    }
    return false;
}


void* createTxt(int id, double x, double y, char *corp, char *corb, char *a, char *txto){
    Texto *Tex = calloc(1, sizeof(Texto));
/*     printf("\nconteudo de a cuzinho na funcao creatxt: %s\n", a);
    printf("\nconteudo de corp cuzinho na funcao creatxt: %s\n", corp); */
    setTxtId(Tex, id);
    setTxtTipo(Tex, 't');
    setTxtX(Tex, x);
    setTxtY(Tex, y);
    setTxtCorb(Tex, corb);
    setTxtCorp(Tex, corp);
    setTxtA(Tex, a);
    setTxtTxto(Tex, txto);
    /* sets do ts */
/*     setfFamily(Tex, fFamily);
    setfWeight(Tex, fWeight);
    setTxtFsize(Tex, fSize); */
    return Tex;
}

/*  */


/* ===========================================fim dos sets/=========================================== */
/* free */
void freeTxt(void *biao){
    Texto *Tex = biao;
    free(Tex);
}


/* ===================================================TS===================================================*/

typedef struct ts{
    char tipo;
    char fFamily[20];
    char fWeight[20];
    int fSize;
} Ts;

void * createTs(char *fFamily, char *fWeight, int fSize){
    Ts *ts = calloc(1, sizeof(Ts));
    setfFamily(ts, fFamily);
    printf("\n\t\tconteudo de fFamily  na funcao creatxt: %s\n", fFamily);
    printf("\n\t\tao ser setado, para para struct e é chamado no svg pelo get\n");

    setfWeight(ts, fWeight);
    setTxtFsize(ts, fSize);
    ts->tipo = 's';
    return ts;
}

/* sets do ts */

void setTxtFsize(void *biao, int Tfs){
    Ts *Texs = biao;
    Texs->fSize = Tfs;
    printf("\nconteudo de fSize cuzinho na funcao settxtFsize: %d\n", Texs->fSize);
}

void setfFamily(void *biao, char *Tff){
    Ts *Texs = biao;
    strcpy(Texs->fFamily, Tff);
    printf("\nconteudo de fFamily cuzinho na funcao settxtFfamily: %s\n", Texs->fFamily);
}

void setfWeight(void *biao, char *Tfw){
    Ts *Texs = biao;
    strcpy(Texs->fWeight, Tfw);
    printf("\nconteudo de fWeight cuzinho na funcao settxtFweight: %s\n", Texs->fWeight);
}

/* gets do ts */

char* getTxtfFamily(void *biao){
    Ts *Texs = biao;
    return Texs->fFamily;
}


char* getTxtfWeight(void *biao){
    Ts *Texs = biao;
    return Texs->fWeight;}

int getTxtfSize(void *biao){
    Ts *Texs = biao;
    return Texs->fSize;
}

/* free */
void freeTs(void *biao){
    Ts *ts = biao;
    free(ts);
}

/* check */
bool checkTs(void *biao){
    Ts *ts = biao;
    if(ts->tipo == 's'){
        return true;
        printf("\n\ttrue checkTs\n");
    }
    return false;
}
/* ===================================================TS===================================================*/
