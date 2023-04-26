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
void liberarLista(lista*);


int main(){

    int n=1;
    lista l, l2;
    inicializarLista(&l);
    inicializarLista(&l2);

    printf("para finalizar ingresar cero\n");
    while(n!=0){
        printf("numero: \n");
        scanf("%d", &n);
        agregarFinal(&l, n);
    }

    invertirLista(l, &l2);
    
    imprimirLista(l);
    printf("%d", tamanio(l));

    imprimirLista(l2);
    printf("%d", tamanio(l2));

    liberarLista(&l);
    liberarLista(&l2);
    return 0;
}

void invertirLista()

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