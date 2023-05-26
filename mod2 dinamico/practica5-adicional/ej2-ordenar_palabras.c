#include <stdio.h>
#include <stdlib.h>
#define MAX 16

typedef struct{
    char palabra[MAX];
    float dificultad;
} Palabra;

struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    Palabra dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void cargarLista(FILE *, lista *, int*);
void inicializarLista(lista*);
void insertarOrdenadoDescendente(lista*, Palabra);
void imprimirLista(lista);
void liberarLista(lista*);

int main(){
    FILE *binario;
    binario=fopen("palabrasDificultad.txt", "rb");//archivo ya cargado
    if(binario==NULL){
        printf("Error en el archivo binario\n");
        return 1;
    }

    lista l;
    int diml=0;
    inicializarLista(&l);
    cargarLista(binario, &l, &diml);
    imprimirLista(l);

    liberarLista(&l);
    fclose(binario);
    return 0;
}

void cargarLista(FILE *binario, lista *l, int* diml){
    Palabra p;

    while(fread(&p, sizeof(Palabra), 1, binario)!=0){
        insertarOrdenadoDescendente(l, p);
        (*diml)++;
    }
}

void insertarOrdenadoDescendente( lista* l, Palabra dato){
    lista nue, ant, act;
    nue=(lista)malloc(sizeof(nodo));//reservo mem
    nue->dato=dato;

    act=(*l);
    ant=(*l);

    while(act!=NULL && act->dato.dificultad > dato.dificultad){
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

void imprimirLista(lista l){
    lista aux=l;
        while(aux!=NULL){
            printf("%s, %f\n",aux->dato.palabra, aux->dato.dificultad);
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