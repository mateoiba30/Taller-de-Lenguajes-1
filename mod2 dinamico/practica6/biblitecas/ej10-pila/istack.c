#include <stdio.h>
#include "istack.h"

//s=1erDato -> 2doDato -> ... -> ultimoDatoADesapilar
struct nodo{
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* stack;

stack* a_create(){
    stack * s;
    (*s)=NULL;
    return s;
}

int s_push (stack * s, int x){//como agregar al inicio
    stack act;
    act=(stack)malloc(sizeof(nodo));
    act->dato=x;
    act->sig=(*s);
    (*s)=act;

    return x;
}

int s_pop(stack * s){//como eliminar 1er elemento
    stack aux;
    int desapilado;
    aux=(*s);
    (*s)=(*s)->sig;
    desapilado=aux->dato;
    free(aux);
    return desapilado;
}

int s_top(stack s){//devuelve dato del 1er elemento
    return s->dato;
}

int s_empty(stack s) {
    if(s==NULL)
        return 1;
    return 0;
}

int s_length(stack s){
    if(s==NULL)
        return 0;

    int tamanio=0;
    stack aux=s;

    while(aux->sig!=NULL){
        aux=aux->sig;
        tamanio++;
    }

    return tamanio;

}