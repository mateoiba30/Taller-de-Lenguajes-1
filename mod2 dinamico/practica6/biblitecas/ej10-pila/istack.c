#include <stdio.h>
#include "istack.h"

//s=1erDato -> 2doDato -> ... -> ultimoDatoADesapilar
Sstack* s_create(){
    Sstack * s;
    s = (Sstack*)malloc(sizeof(Sstack));//debo reservar memoria para el puntero a la pila tambien
    (*s).pila=NULL;
    (*s).tamanio=0;
    return s;
}

int s_push (Sstack * s, int x){//como agregar al inicio
    stack act;
    act=(stack)malloc(sizeof(nodo));
    act->dato=x;
    act->sig=(*s).pila;
    (*s).pila=act;
    (*s).tamanio++;

    return x;
}

int s_pop(Sstack * s){//como eliminar 1er elemento
    stack aux;
    int desapilado;
    aux=(*s).pila;
    (*s).pila=(*s).pila->sig;
    desapilado=aux->dato;
    free(aux);
    (*s).tamanio--;

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

int s_length(Sstack s){
    return s.tamanio;

}

void imprimirStack(Sstack s){
    stack aux=s.pila;
        for(int i=0; i<s_length(s) ; i++){
            printf("%d, ",aux->dato);
            aux=aux->sig;
        }
    // printf("hola\n");//pa debuguear
}
