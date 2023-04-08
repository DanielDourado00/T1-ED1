#include "circ.h"

/* Faltam colocar as informacoes nessecarias para o qry */

typedef struct circ
{
    char tipo;
    int id;
    double x;
    double y;
    double r;
    char corb[100];
    char corp[100];

    /* faltam colocar o restante das informacoes para fazer as operacoes com o qry */
} Circ;

/* fazer checkagem se a forma geometrica recebida é um CIRCULO */

bool checkCirc(void *bião)
{
    Circ *Circ = bião;  
    if (Circ->tipo == 'c')
    {
        return true;
    }
    else
    {
        return false;
    }
}


/* ===========================================inicio dos gets/=========================================== */
/* os gets vao ser usados para pegar as informacoes do circulo e fazer as operacoes com o qry, segue a ordem da struct circ */

char gettipoCirc(void *bião)
{                      // funcao para pegar o tipo do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->tipo; // retorna o tipo do circulo
}

int getidCirc(void *bião)
{                      // funcao para pegar o id do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->id;   // retorna o id do circulo
}

double getxCirc(void *bião)
{                      // funcao para pegar a coordenada x do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->x;    // retorna a coordenada x do circulo
}

double getyCirc(void *bião)
{                      // funcao para pegar a coordenada y do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->y;    // retorna a coordenada y do circulo
}

double getrCirc(void *bião)
{                      // funcao para pegar o raio do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->r;    // retorna o raio do circulo
}

char *getcorbCirc(void *bião)
{                      // funcao para pegar a cor da borda do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->corb; // retorna a cor da borda do circulo
}

char *getcorpCirc(void *bião)
{                      // funcao para pegar a cor de preenchimento do circulo
    Circ *Circ = bião; // cria um ponteiro para a struct circulo
    return Circ->corp; // retorna a cor de preenchimento do circulo
}

/* bião é o nome da forma geometrica, no caso o circulo, e Circ é o nome da struct, no caso Circ, ela sera usada para acessar os dados da struct circulo*/

/* ===========================================fim dos gets/=========================================== */

/* ===========================================inicio dos sets/=========================================== */
/* os sets vao ser usados para setar as informacoes do circulo e fazer as operacoes com o qry, segue a ordem da struct circ */

void settipoCirc(void *biao, char tipo)
{                      // funcao para setar o tipo do biao
    Circ *Circ = biao; // cria um ponteiro para a struct biao
    Circ->tipo = tipo; // seta o tipo do biao
}

void setidCirc(void *biao, int id)
{                      // funcao para setar o id do biao
    Circ *Circ = biao; // cria um ponteiro para a struct biao
    Circ->id = id;     // seta o id do biao
}

void setxCirc(void *biao, double x)
{                      // funcao para setar a coordenada x do biao
    Circ *Circ = biao; // cria um ponteiro para a struct biao
    Circ->x = x;       // seta a coordenada x do biao
}

void setyCirc(void *biao, double y)
{                      // funcao para setar a coordenada y do biao
    Circ *Circ = biao; // cria um ponteiro para a struct biao
    Circ->y = y;       // seta a coordenada y do biao
}

void setrCirc(void *biao, double r)
{                      // funcao para setar o raio do biao
    Circ *Circ = biao; // cria um ponteiro para a struct biao
    Circ->r = r;       // seta o raio do biao
}

void setcorbCirc(void *biao, char *corb)
{                             // funcao para setar a cor da borda do biao
    Circ *Circ = biao;        // cria um ponteiro para a struct biao
    strcpy(Circ->corb, corb); // seta a cor da borda do biao
}

void setcorpCirc(void *biao, char *corp)
{                             // funcao para setar a cor de preenchimento do biao
    Circ *Circ = biao;        // cria um ponteiro para a struct biao
    strcpy(Circ->corp, corp); // seta a cor de preenchimento do biao
}

/* ===========================================fim dos sets/=========================================== */

/*==========================================funcao para criar circulo e dar free==========================================*/

void* createCircle (int id, double x, double y, double r, char *corb, char *corp){         // funcao para criar um circulo e setar as informacoes, as informacoes sao passadas por parametro e a funcao retorna um ponteiro para a struct circulo, armazenando as informacoes do circulo na struct
    Circ *circulo = calloc(1, sizeof(Circ));                                                // aloca espaço para a struct circulo
    settipoCirc(circulo, 'c');                                                            // seta o tipo do circulo
    setidCirc(circulo, id);                                                              // seta o id do circulo
    setxCirc(circulo, x);                                                                // seta a coordenada x do circulo
    setyCirc(circulo, y);                                                                // seta a coordenada y do circulo
    setrCirc(circulo, r);                                                                // seta o raio do circulo
    setcorbCirc(circulo, corb);                                                          // seta a cor da borda do circulo
    setcorpCirc(circulo, corp);                                                          // seta a cor de preenchimento do circulo
    return circulo;                                                                         // retorna o circulo
}

void* memoriacirc(){                            //callocdata
    Circ *circulo = calloc(1, sizeof(Circ));                                                // aloca espaço para a struct circulo
    return circulo;
}

void freeCircle (void *biao){                                                               // funcao para dar free no circulo
    Circ *forma = biao;                                                                      // cria um ponteiro para a struct circulo
    free(forma);                                                                             // da free no circulo
}


