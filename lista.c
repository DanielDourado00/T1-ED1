#include "biblioteca.h"
#include "lista.h"

typedef struct Lista Wlista; // Lista  duplamente encadeada onde Wlista é um apelido para struct Lista
typedef struct Posic Wposic; // Posic da lista onde Wposic é um apelido para struct Posic
typedef struct Item;         // Item da lista

typedef struct Iterador Witerador; // Iterador da lista
typedef struct Clausura Wclausura; // Clausura da lista

/* Lista duplamente encadeda */

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
