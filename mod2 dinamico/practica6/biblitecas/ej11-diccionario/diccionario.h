#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <stdlib.h>//para malloc
#define MAX_LONG 100

struct nodo{
    char dato[50];
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

typedef struct{
    lista l;
    int tamanio;
} Slista;

//prototipos de diccionario.c

#endif