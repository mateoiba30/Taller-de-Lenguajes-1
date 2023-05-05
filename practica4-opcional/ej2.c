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
void insertarOrdenadoDescendente( lista*, int);
void insertarOrdenadoAscendente(lista*, int);
void liberarLista(lista*);

int main(){

    int n;
    lista l, pares, impares;
    inicializarLista(&l);
    inicializarLista(&pares);
    inicializarLista(&impares);


    printf("ingrese un numero (0 para finalizar): ");
    scanf("%d", &n);
    while(n!=0){
        insertarOrdenadoAscendente(&l, n);
        if(n % 2==0)
            agregarInicio(&pares, n);
        else
            agregarInicio(&impares, n);

        printf("ingrese otro numero: ");
        scanf("%d", &n);

    }

    printf("\nlista final de tamanio %d: \n", tamanio(l));
    imprimirLista(l);
    printf("\nlista pares de tamanio %d: \n", tamanio(pares));
    imprimirLista(pares);
    printf("\nlista impares de tamanio %d: \n", tamanio(impares));
    imprimirLista(impares);


    liberarLista(&l);
    liberarLista(&pares);
    liberarLista(&impares);

    return 0;
}

void insertarOrdenadoDescendente( lista* l, int dato){
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

void insertarOrdenadoAscendente( lista* l, int dato){
    lista nue, ant, act;
    nue=(lista)malloc(sizeof(nodo));//reservo mem
    nue->dato=dato;

    act=(*l);
    ant=(*l);

    while(act!=NULL && act->dato > dato){
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
    lista aux=(l);
    int cont=0;
    while(aux!=NULL){
        aux=aux->sig;
        cont++;
    }

    return cont;
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