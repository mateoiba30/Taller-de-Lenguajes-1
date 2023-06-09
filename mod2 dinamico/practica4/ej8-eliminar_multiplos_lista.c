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
void invertirLista(lista, lista*);
void eliminarMultiplos(lista*, int);


int main(){

    int n=1;
    lista l;
    inicializarLista(&l);

    printf("para finalizar ingresar cero\n");
    printf("1er numero:");
    scanf("%d", &n); //no olvidar de leer
    while(n!=0){
        agregarFinal(&l, n);//primero agrego y desp comparo, para no agregar el cero

        printf("otro numero:");
        scanf("%d", &n); 
    }

    // printf("ingrese numero para eliminar multiplos: ");
    // scanf("%d", &n);
    // eliminarMultiplos(&l, n);
    
    imprimirLista(l);

    liberarLista(&l);
    return 0;
}

void eliminarMultiplos(lista *l, int n){
    lista act=(*l), aux, ant;//recorro con auxiliar para no perder el 1er puntero
    while(act!=NULL){
        if(act->dato % n ==0){//si hay q 
            aux=act;
            if(act==(*l))//no ol
                (*l)=(*l)->sig;
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

void invertirLista(lista l1, lista *l2){
    //l1 no es modificada, no pierdo el puntero porque mando copia
    while(l1!=NULL){
        agregarInicio(l2, l1->dato);
        l1=l1->sig;
    }

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