#include "txto.h"

typedef struct texto{
    char tipo;
    int id;
   // int fSize;
    double x;
    double y;
    char corp[20];
    char corb[20];
    char a[3];
    char txto[100];
/*     char fFamily[20]; */
    /*char fWeight[20]; */

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
printf("\nconteudo de a cuzinho na funcao settxtA: %s\n", Tex->a);
}

void setTxtCorp(void *biao, char *Tcorp){
    Texto *Tex = biao;
    strcpy(Tex->corp, Tcorp);
    printf("\nconteudo de corp cuzinho na funcao settxtCorp: %s\n", Tex->corp);
}

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
    printf("\nconteudo de a cuzinho na funcao creatxt: %s\n", a);
    printf("\nconteudo de corp cuzinho na funcao creatxt: %s\n", corp);
    setTxtId(Tex, id);
    //setTxtFsize(Tex, fSize);
    setTxtTipo(Tex, 't');
    setTxtX(Tex, x);
    setTxtY(Tex, y);
    setTxtCorb(Tex, corb);
    setTxtCorp(Tex, corp);
    setTxtA(Tex, a);
    setTxtTxto(Tex, txto);
/*     setfFamily(Tex, fFamily);
    setfWeight(Tex, fWeight); */
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

/* typedef struct ts{
    char tipo;
    char fFamily[20];
    char fWeight[20];
    int fSize;
} Ts; */

/* void setTxtFsize(void *biao, int Tfs){
    Texto *Tex = biao;
    Tex->fSize = Tfs;
} */

/* void setfFamily(void *biao, char *Tff){
    Texto *Tex = biao;
    strcpy(Tex->fFamily, Tff);
}

void setfWeight(void *biao, char *Tfw){
    Texto *Tex = biao;
    strcpy(Tex->fWeight, Tfw);
} */

/* char* getTxtfFamily(void *biao){
    Texto *Tex = biao;
    return Tex->fFamily;
}

char* getTxtfWeight(void *biao){
    Texto *Tex = biao;
    return Tex->fWeight;} */

/* int getTxtFsize(void *biao){
    Texto *Tex = biao;
    return Tex->fSize;
} */

/* bool checkTs(void *bião){
    Ts *Tex = bião;
    if(strcmp(Tex->tipo, "ts") == 0){
        return true;
    }
    return false;
} */





