#include <stdio.h>
#include <stdlib.h>


struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;
typedef struct{
    lista l;
    int cont;
}SLista;//tmb puedo haecr algo de este estilo

void inicializarLista(SLista*);
void eliminarTodo(SLista*);
void agregarInicio(SLista*, int );
void agregarFinal(SLista*, int );
int tamanio(SLista);
void imprimirLista(SLista);
void insertarOrdenado( SLista*, int);
void liberarLista(SLista*);

int main(){

    int n;
    SLista l1;
    inicializarLista(&l1);

    for(int i=0; i<5; i++){
        printf("ingrese un numero: ");
        scanf("%d", &n);
        agregarFinal(&l1, n);
    }

    insertarOrdenado(&l1, 6);
    printf("nueva lista: ");
    imprimirLista(l1);
  
    printf("tamanio: %d \n",  tamanio(l1)); 
    liberarLista(&l1);
    return 0;
}

void insertarOrdenado( SLista* l, int dato){
    (*l).cont++;
    lista nue, ant, act;
    nue=(lista)malloc(sizeof(nodo));//reservo mem
    nue->dato=dato;

    act=(*l).l;
    ant=(*l).l;

    while(act!=NULL && act->dato < dato){
        ant=act;
        act=act->sig;
    }

    nue->sig=act;

    if((*l).l==act)
        (*l).l=nue;
    else
        ant->sig =nue;

}

void inicializarLista(SLista* l){
    (*l).l=NULL;
    (*l).cont=0;
}

void eliminarTodo(SLista* l){
    lista aux;//no perder el inicio de la lista para borrar

    for(int i=0; i<(*l).cont; i++){
        aux=(*l).l;
        (*l).l=(*l).l->sig;//siempre voy borrando el 1ro de la lista
        free(aux);

    }

}

void agregarInicio(SLista* l, int dato){
    (*l).cont++;
    lista act;
    act=(lista)malloc(sizeof(nodo));//reservo mem
    act->dato=dato;
    act->sig=(*l).l;
    (*l).l=act;

}

void agregarFinal(SLista* l, int dato){
    (*l).cont++;
    lista act, aux=(*l).l;
    act=(lista)malloc(sizeof(nodo));
    act->dato=dato;
    act->sig=NULL;

    if((*l).l==NULL){
        (*l).l=act;
    }
    else{
    while(aux->sig!=NULL){
        aux=aux->sig;
    }
    aux->sig=act;
    }

}

int tamanio(SLista l){
    return l.cont;
}

void imprimirLista(SLista l){
    lista aux=l.l;
        for(int i=0; i<l.cont; i++){
            printf("%d, ",aux->dato);
            aux=aux->sig;
    }

}

void liberarLista(SLista* l){
    lista aux;
    for(int i=0; i<(*l).cont; i++){
        aux=(*l).l;
        (*l).l=(*l).l->sig;
        free(aux);
    }
    (*l).cont=0;
}