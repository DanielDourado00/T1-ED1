#include "biblioteca.h"
#include "lista.h"
#include "circ.h"
#include "systemgeo.h"
#include "systempath.h"
#include "retangulo.h"
#include "linha.h"
#include "txto.h"

typedef struct Lista Plist;
typedef struct Posic Pposic;
typedef struct Item Pitem;
typedef struct Iterador Piterador;
typedef struct Clausura Pclausura;

//lista dinamica duplamente encadeada
struct Lista        // estrutura da lista dinamica duplamente encadeada
{
    Pposic *first;
    Pposic *last;
    int length;
    int max_length;
};

struct Posic
{
    Pitem *info;        // informacao do elemento da lista 
    Pposic *next;       // ponteiro para o proximo elemento da lista
    Pposic *prev;       // ponteiro para o elemento anterior da lista
};                      // estrutura da posicao da lista dinamica duplamente encadeada

 struct Item
{
    void *info;
} ;                      // estrutura do item da lista dinamica duplamente encadeada

struct Iterador {
    Lista *L;
    Posic *pos;
    bool *reverso;
};

Lista createLst(int capacidade)         // cria uma lista dinamica duplamente encadeada
{
    Plist *L = (Plist *) malloc(sizeof(Plist));

    L->first = NIL;
    L->last = NIL;
    L->length = 0;
    L->max_length = capacidade;
    return L;
}

int lengthLst(Lista L)
{
    Plist *list = (Plist *) L;
    return list->length;
}

int maxLengthLst(Lista L)
{
    Plist *list = (Plist *) L;
    return list->max_length;
    printf("\ncomprimento maximo: %d\n", list->max_length);
}

bool isEmptyLst(Lista L)
{
    Plist *list = (Plist *) L;
   if (list->length > 0){
         return false; 
   }
   return true;
}

bool isFullLst(Lista L){
    Plist *list = (Plist *) L;
    return (list->length == list->max_length);
    printf("lista cheia\n");

}

Posic insertLst(Lista L, Item info)
{
    Plist *list = (Plist *) L;
    Pposic *new = (Pposic *) calloc(1, sizeof(Pposic));
    new->info = info;
    new->next = NIL;
    new->prev = NIL;
    if (list->length == 0)
    {
        list->first = new;
        list->last = new;
    }
    else
    {
        list->last->next = new;
        new->prev = list->last;
        list->last = new;
    }
    list->length++;
    printf("comprimento: %d\n", list->length);
    return new;
    printf("inseriu\n");
}

Item popLst(Lista L)
{
    Plist *list = (Plist *) L;
    Pposic *aux = list->first;
    Item info = aux->info;
    list->first = aux->next;
    list->first->prev = NIL;
    free(aux);
    list->length--;
    return info;
}

void removeLst(Lista L, Posic p)
{
    Plist *list = (Plist *) L;
    Pposic *posic = (Pposic *) p;
    if (posic->prev == NULL)
    {
        list->first = posic->next;
    }
    else
    {
        posic->prev->next = posic->next;
    }
    if (posic->next == NULL)
    {
        list->last = posic->prev;
    }
    else
    {
        posic->next->prev = posic->prev;
    }
    free(posic);
    list->length--;
}

Item getLst(Lista L, Posic p)
{
    Plist *list = (Plist *) L;
    if (isEmptyLst(list)){
        return NIL;
    }
    Pposic *posic = (Pposic *) p;
    return posic->info;
}

Posic insertBefore(Lista L, Posic p, Item info)
{
    Plist *list = (Plist *) L;
    Pposic *posic = (Pposic *) p;
    Pposic *new = (Pposic *) calloc(1, sizeof(Pposic));
    new->info = info;
    new->next = posic;
    new->prev = posic->prev;
    if (posic->prev == NULL)
    {
        list->first = new;
    }
    else
    {
        posic->prev->next = new;
    }
    posic->prev = new;
    list->length++;
    return new;
}

Posic insertAfterLst(Lista L, Posic p, Item info)
{
    Plist *list = (Plist *) L;
    Pposic *posic = (Pposic *) p;
    Pposic *new = calloc(1, sizeof(Pposic));
    new->info = info;
    new->next = posic->next;
    new->prev = posic;
    if (posic->next == NULL)
    {
        list->last = new;
    }
    else
    {
        posic->next->prev = new;
    }
    posic->next = new;
    list->length++;
    return new;
}

Posic getFirstLst(Lista L)
{
    Plist *list = (Plist *) L;
    if (list->length == 0) {
        return NIL;
    }
    return list->first;
}

Posic getNextLst(Lista L, Posic p) {
    Plist *list = (Plist *) L;
    Pposic *posic = (Pposic *) p;

    // Verifica se p está dentro dos limites da lista L
    if (posic == NULL || posic->next == NULL) {
        return NIL;
    }
    // Retorna a posição seguinte a p
    return posic->next;
}


Posic getLastLst(Lista L)
{
    Plist *list = (Plist *) L;
    if (isEmptyLst(list)){
        return NIL;
    }
    return list->last;
}

Posic getPreviousLst(Lista L, Posic p)
{
    Pposic *posic = (Pposic *) p;
    
    if (posic->prev == NULL) { // p é o primeiro elemento da lista
        return NIL;
    } else { // p não é o primeiro elemento da lista
        return posic->prev;
    }
}

void killLst(Lista L)
{
    Plist *list = (Plist *) L;
    Pposic *aux = list->first;
    while (aux != NULL)
    {
        list->first = aux->next;
        free(aux);
        aux = list->first;
    }
    free(list);
}

/* iteradores */

/* Iterador createIterador(Lista L, bool reverso) {                        // cria iterador
    Plist *list = (Plist *) L;                                          // converte lista para Plist
    Piterador *iterador = (Piterador *) calloc(1, sizeof(Piterador));   // aloca memória para iterador
    iterador->pos = list->first;                                        // pos aponta para o primeiro elemento da lista
    iterador->reverso = reverso;                                        // define se o iterador será reverso ou não
    return iterador;                                                    // retorna iterador
}

bool isIteratorEmpty(Lista L, Iterador it){
    Plist *list = (Plist *) L;                      // converte lista para Plist
    Piterador *iterador = (Piterador *) it;         // converte iterador para Piterador
    if (iterador->pos == NULL){                     // verifica se o iterador está no fim da lista
        return true;                                // retorna true se estiver no fim da lista
    }
    return false;                                   // retorna false se não estiver no fim da lista
}

/* Item getIteratorNext(Lista L, Iterador it){
    Plist *list = (Plist *) L;                      // converte lista para Plist
    Piterador *iterador = (Piterador *) it;         // converte iterador para Piterador
    if (iterador->pos == NULL){                     // verifica se o iterador está no fim da lista
        return NIL;                                 // retorna NIL se estiver no fim da lista
    }
    Item info = iterador->pos->info;                // pega o item da posição atual do iterador
    if (iterador->reverso == false){                // verifica se o iterador é reverso
        iterador->pos = iterador->pos->next;        // se não for, avança para a próxima posição
    } else {                                        // se for
        iterador->pos = iterador->pos->prev;        // retrocede para a posição anterior
    }
    return info;                                    // retorna o item da posição atual do iterador
} */

/* void killIterator(Lista L, Iterador it){
    Plist *list = (Plist *) L;                      // converte lista para Plist
    Piterador *iterador = (Piterador *) it;         // converte iterador para Piterador
    free(iterador);                                 // libera memória do iterador
}

/* funções auxiliares */

/* Lista map(Lista L, Apply f) {                               // cria uma nova lista com os itens de L aplicados a f
    Lista nova = createLst(L);                              // cria uma nova lista
    Iterador it = createIterador(L, false);                 // cria um iterador para a lista L
    while (!isIteratorEmpty(L, it)) {                       // enquanto o iterador não estiver no fim da lista
        Item item = getIteratorNext(L, it);                 // pega o item da posição atual do iterador
        insertAfterLst(nova, getLastLst(nova), f(item));    // insere o item aplicado a f na nova lista
    }
    killIterator(L, it);                                    // libera memória do iterador
    return nova;                                            // retorna a nova lista
}

Lista filter(Lista L, Check f){
    Lista nova = createLst(L);                              // cria uma nova lista
    Iterador it = createIterador(L, false);                 // cria um iterador para a lista L
    while (!isIteratorEmpty(L, it)) {                       // enquanto o iterador não estiver no fim da lista
        Item item = getIteratorNext(L, it);                 // pega o item da posição atual do iterador
        if (f(item) == true){                               // verifica se o item passa no teste de f
            insertAfterLst(nova, getLastLst(nova), item);   // insere o item na nova lista
        }
    }
    killIterator(L, it);                                    // libera memória do iterador
    return nova;                                            // retorna a nova lista
}

void fold(Lista L, ApplyClosure f, Clausura c){
    Iterador it = createIterador(L, false);                 // cria um iterador para a lista L
    while (!isIteratorEmpty(L, it)) {                       // enquanto o iterador não estiver no fim da lista
        Item item = getIteratorNext(L, it);                 // pega o item da posição atual do iterador
        f(item, c);                                         // aplica a função f ao item e a clausura
    }
    killIterator(L, it);                                    // libera memória do iterador
} */ 