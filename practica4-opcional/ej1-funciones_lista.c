#include <stdio.h>
#include <stdlib.h>


struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void inicializarLista(lista*);
void eliminarTodo(lista*);
void agregarInicio(lista*, int );
void agregarFinal(lista*, int );
int tamanio(lista);
void imprimirLista(lista);
void insertarOrdenado( lista*, int);
void liberarLista(lista*);

int main(){

    int n;
    lista l;
    inicializarLista(&l);

    for(int i=0; i<5; i++){
        printf("ingrese un numero: ");
        scanf("%d", &n);
        agregarFinal(&l, n);
    }

    insertarOrdenado(&l, 6);
    printf("nueva lista: ");
    imprimirLista(l);
  
    printf("tamanio: %d \n",  tamanio(l)); 
    liberarLista(&l);
    return 0;
}

void insertarOrdenado( lista* l, int dato){
    lista nue, ant, act;
    nue=(lista)malloc(sizeof(nodo));//reservo mem
    nue->dato=dato;

    act=(*l);
    ant=(*l);

    while(act!=NULL && act->dato < dato){
        ant=act;
        act=act->sig;
    }

    nue->sig=act;

    if((*l)==act)
        (*l)=nue;
    else
        ant->sig =nue;

}

void inicializarLista(lista* l){
    (*l)=NULL;
}

void eliminarTodo(lista* l){
    lista aux;//no perder el inicio de la lista para borrar

    while((*l)!=NULL){
        aux=(*l);
        (*l)=(*l)->sig;//siempre voy borrando el 1ro de la lista
        free(aux);

    }

}

void agregarInicio(lista* l, int dato){
    lista act;
    act=(lista)malloc(sizeof(nodo));//reservo mem
    act->dato=dato;
    act->sig=(*l);
    (*l)=act;

}

void agregarFinal(lista* l, int dato){
    lista act, aux=(*l);
    act=(lista)malloc(sizeof(nodo));
    act->dato=dato;
    act->sig=NULL;

    if((*l)==NULL){
        (*l)=act;
    }
    else{
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    aux->sig=act;
    }

}

int tamanio(lista l){
    return sizeof(l);
}

void imprimirLista(lista l){
    lista aux=l;
        while(aux!=NULL){
            printf("%d, ",aux->dato);
            aux=aux->sig;
    }

}

void liberarLista(lista* l){
    lista aux;
    while( (*l)){
        aux=(*l);
        (*l)=(*l)->sig;
        free(aux);
    }
}