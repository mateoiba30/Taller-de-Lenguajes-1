#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include <stdlib.h>//para malloc
#define MAX_LONG 100

struct nodo{
    char dato[MAX_LONG];
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

typedef struct{
    lista l;
    int tamanio;
} Dicc;

//prototipos de diccionario.c
Dicc* crearDiccionario();//ANDA
int agregarPalabraOrdenada( Dicc*, char[]);//ANDA
int existePalabra(Dicc, char[]);//ANDA
int eliminarPalabra(Dicc*, char[]);//ANDA
int cargarDesdeTxt(char [], Dicc*);
int guardarEnTxt(char[], Dicc);
void destruirDiccionario(Dicc *);
void imprimirDicc(Dicc);//ANDA
int tamanio(Dicc);//ANDA

#endif