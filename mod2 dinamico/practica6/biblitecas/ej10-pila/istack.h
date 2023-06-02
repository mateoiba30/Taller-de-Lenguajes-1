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
int s_push (stack *, int);
int s_pop(stack *);
int s_top(stack);
int s_empty(stack);
int s_length(stack);
void imprimirStack(stack);

#endif
