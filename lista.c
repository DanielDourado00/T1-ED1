#include "biblioteca.h"
#include "lista.h"

typedef struct Lista Wlista; // Lista  duplamente encadeada onde Wlista é um apelido para struct Lista
typedef struct Posic Wposic; // Posic da lista onde Wposic é um apelido para struct Posic

typedef struct Iterador Witerador; // Iterador da lista
typedef struct Clausura Wclausura; // Clausura da lista

/* Lista duplamente encadeda */

struct iterador                     // serve para percorrer a lista e passar um parametro para a funcao
{
    Wposic *posic;
    Wlista *lista;
};

struct clausura                 // serve para percorrer a lista e passar um parametro para a funcao
{
    void *info;
};

struct Posic
{ // Posic
    Item *info;
    Wposic *prox;
    Wposic *ant;
} posic;

struct Lista
{
    Wposic *inicio; // inicio da lista (head)
    Wposic *fim;    // fim da lista (tail)
    int tamanho;    // tamanho da lista
    int capacidade; // capacidade da lista
} lista;

/* alocar memoria usando calloc */
Lista createLst(int capacidade)
{
    Wlista *L = (Wlista *)calloc(1, sizeof(Wlista)); // com calloc eu n preciso inicializar os valores da struct com NULL
    L->capacidade = capacidade;
    L->tamanho = 0;
    L->inicio = NULL;
    L->fim = NULL;
    return L;
}

/** Retorna o numero de elementos da lista. */
int lengthLst(Lista L)
{                                // retorna o tamanho da lista
    Wlista *lista = (Wlista *)L; // converte o tipo Lisat para Wlista
    return lista->tamanho;       // retorna o tamanho da lista
}

/** Retorna verdadeiro se a lista L estiver vazia */
bool isEmptyLst(Lista L)
{                                // retorna true se a lista estiver vazia
    Wlista *lista = (Wlista *)L; // converte o tipo Lisat para Wlista
    if (lista->tamanho == 0)     // se o tamanho da lista for igual a 0, retorna true
        return true;
    else
        return false;
}

/** Retorna verdadeiro se a lista L estiver cheia. Ou seja, se a lista
   tiver sido criada com uma capacidade máxima e lenght(L) == maxLength(L). */
bool isFullLst(Lista L)
{
    Wlista *lista = (Wlista *)L; // converte o tipo Lisat para Wlista
    if (lista->tamanho == lista->capacidade)
        return true;
    else
        return false;
}

/**  Insere o item info no final da lista L. O comprimento da
lista e' acrescido de 1 elemento.
Retorna um indicador para o elemento acrescentado; ou NIL, se a lista estiver
cheia */
Posic insertLst(Lista L, Item info)
{
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic->info = info;                                  // atribui o valor de info para a posic
    if (lista->tamanho == 0)
    {
        lista->inicio = posic;
        lista->fim = posic;
        lista->tamanho++;
        return posic;
    }
    else
    {
        lista->fim->prox = posic;
        posic->ant = lista->fim;
        lista->fim = posic;
        lista->tamanho++;
        return posic;
    }
}

Item popLst(Lista L)
{                                                        // remove o primeiro elemento da lista
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic = lista->inicio;                               // atribui o valor de inicio para a posic
    lista->inicio = posic->prox;                         // atribui o valor de prox para inicio
    lista->tamanho--;                                    // decrementa o tamanho da lista
    return posic->info;                                  // retorna o valor de info
}

/** Remove o elemento da lista L indicado por p.  p deve indicar um elemento existente em L. O comprimento da lista e' diminuido de 1 elemento. */
void removeLst(Lista L, Posic p)
{
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic = p;                                           // atribui o valor de p para a posic
    if (posic == lista->inicio)
    {                                // se a posic for igual ao inicio da lista
        lista->inicio = posic->prox; // atribui o valor de prox para inicio
        lista->tamanho--;            // decrementa o tamanho da lista
    }
    else if (posic == lista->fim)
    {                            // se a posic for igual ao fim da lista
        lista->fim = posic->ant; // atribui o valor de ant para fim
        lista->tamanho--;        // decrementa o tamanho da lista
    }
    else
    {                                   // se a posic for igual a qualquer posic da lista
        posic->ant->prox = posic->prox; // atribui o valor de prox para ant->prox
        posic->prox->ant = posic->ant;  // atribui o valor de ant para prox->ant
        lista->tamanho--;               // decrementa o tamanho da lista
    }
}

Item getLst(Lista L, Posic p)
{                                                        // retorna o valor de info
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic = p;                                           // atribui o valor de p para a posic
    return posic->info;                                  // retorna o valor de info
}


Posic insertBefore(Lista L,Posic p, Item info){           // insere um elemento antes de uma posic
    Wlista *lista = (Wlista *)L;                          // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic));  // aloca memoria para a posic
    Wposic *posic2 = (Wposic *)calloc(3, sizeof(Wposic)); // aloca memoria para a posic2
    posic = p;                                            // atribui o valor de p para a posic
    posic2->info = info;                                  // atribui o valor de info para a posic2
    if (posic == lista->inicio){                          // se a posic for igual ao inicio da lista, ou seja ela vai ser o novo inicio
        lista->inicio->ant = posic2;
        posic2->prox = lista->inicio;
        lista->inicio = posic2;
        lista->tamanho++;
        return posic2;
    }
    else{                                                   // se a posic for igual a qualquer posic da lista
        posic->ant->prox = posic2;                          // atribui o valor de posic2 para ant->prox
        posic2->ant = posic->ant;                           // atribui o valor de ant para posic2->ant
        posic->ant = posic2;                                // atribui o valor de posic2 para ant
        posic2->prox = posic;                               // atribui o valor de posic para posic2->prox
        lista->tamanho++;                                   // incrementa o tamanho da lista
        return posic2;
    }
}


Posic insertAfterLst(Lista L, Posic p, Item info)
{
    Wlista *lista = (Wlista *)L;                          // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic));  // aloca memoria para a posic
    Wposic *posic2 = (Wposic *)calloc(3, sizeof(Wposic)); // aloca memoria para a posic2
    posic = p;                                            // atribui o valor de p para a posic
    posic2->info = info;                                  // atribui o valor de info para a posic2
    if (posic == lista->fim){                             // se a posic for igual ao fim da lista, ou seja ela vai ser o novo fim
        lista->fim->prox = posic2;
        posic2->ant = lista->fim;
        lista->fim = posic2;
        lista->tamanho++;
        return posic2;
    }
    else{                                                   // se a posic for igual a qualquer posic da lista, ou seja ela vai ser uma posic no meio da lista
        posic2->prox = posic->prox;
        posic2->ant = posic;
        posic->prox->ant = posic2;
        posic->prox = posic2;
        lista->tamanho++;
        return posic2;  
    }
}

/** Retorna o indicador do primeiro elemento de L. Se
length(L)=0, retorna NIL. */
Posic getFirstLst(Lista L){
    Wlista *lista = (Wlista *)L; // converte o tipo Lisat para Wlista
    return lista->inicio;
}

/** Retorna o indicador do elemento de L seguinte ao elemento
indicado por p. Se p for o ultimo elemento da lista, retorna NIL.
p deve indicar um elemento existente em L.*/
Posic getNextLst(Lista L,Posic p){
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic = p;                                           // atribui o valor de p para a posic
    return posic->prox;
}


Posic getLastLst(Lista L){                    // retorna o valor de fim
    Wlista *lista = (Wlista *)L;              // converte o tipo Lisat para Wlista
    return lista->fim;

}
/** Retorna o indicador do elemento de L anterior ao elemento
indicado por p. Se p for o primeiro elemento da lista, retorna NIL.
p deve indicar um elemento existente em L. */
Posic getPreviousLst(Lista L,Posic p){
    Wlista *lista = (Wlista *)L;                         // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof(Wposic)); // aloca memoria para a posic
    posic = p;                                           // atribui o valor de p para a posic
    return posic->ant;
}

/** Libera toda memoria alocada pela lista. */
void killLst(Lista L){                                     // libera a memoria de inicio
    Wlista *lista = (Wlista *)L;                           // converte o tipo Lisat para Wlista
    Wposic *posic = (Wposic *)calloc(2, sizeof (Wposic));  // aloca memoria para a posic
    posic = lista->inicio;                                 // atribui o valor de inicio para a posic
    while (posic != NULL){                                 // enquanto a posic for diferente de NULL
        lista->inicio = posic->prox;                       //atribui o valor de prox para inicio
        free(posic);                                       // libera a memoria de posic
        posic = lista->inicio;                             // atribui o valor de inicio para a posic
    }
}
/**
   Retorna um iterador sobre a lista L. 
   O iterador "anda" do inicio ate' o fim, caso reverso for falso;
   do fim para o inicio, se reverso for verdadeiro.
 */
/* Iterador createIterador(Lista L, bool reverso){

} */