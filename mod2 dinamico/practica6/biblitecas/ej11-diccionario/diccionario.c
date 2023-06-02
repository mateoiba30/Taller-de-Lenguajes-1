#include <stdio.h>
#include <string.h>
#include "diccionario.h"

void crearDiccionario(Slista* l){
    (*l).l=NULL;
    (*l).tamanio=0;
}

void agregarPalabra( Slista* l, int dato){
    (*l).tamanio++;
    lista ant, act;
    int agrego=0;

    act=(*l).l;
    ant=(*l).l;

    while(act!=NULL && act->dato < dato){
        ant=act;
        act=act->sig;
    }
    if(strcmp(act->dato, dato)!=0){//cuando ya no es menor puede ser igual, en ese caso no ingresar nada
        agrego=1;
        lista nue;
        nue=(lista)malloc(sizeof(nodo));//reservo mem
        strcpy(nue->dato, dato); 
        (*l).tamanio++;

        nue->sig=act;

        if((*l).l==act)
            (*l).l=nue;
        else
            ant->sig =nue;
    }

    return agrego;
}

int existePalabra(Slista sl, char palabra[]){
    int encontre=0;
    lista act=sl.l, ant;//recorro con auxiliar para no perder el 1er puntero
    while(act!=NULL && encontre==0){
        if(strcmp(palabra,act->dato)==0)
            encontre=1;
        else{
            ant=act;
            act=act->sig;//sinó solo avanzo
        }
    }
    return encontre;
}

int eliminarPalabra(Slista sl, char palabra[]){
    lista act=sl.l, aux, ant;//recorro con auxiliar para no perder el 1er puntero
    while(act!=NULL){
        if(strcmp(act->dato, palabra)){//si hay q 
            aux=act;
            if(act==sl.l)//no ol
                sl.l=sl.l->sig;
            else
                ant->sig=act->sig;
            
            aux=act->sig;
            free(act);
            act=aux;
        }
        else{
            ant=act;
            act=act->sig;//sinó solo avanzo
        }
    }
}