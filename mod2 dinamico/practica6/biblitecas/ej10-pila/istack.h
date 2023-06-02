#ifndef istack_included
#define istack_included

#include <stdlib.h>//para malloc

struct nodo{
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* stack;

typedef struct{
    stack pila;
    int tamanio;
} Sstack;

Sstack* s_create();
int s_push (Sstack *, int);
int s_pop(Sstack *);
int s_top(stack);
int s_empty(stack);
int s_length(Sstack);
void imprimirStack(Sstack);

#endif
