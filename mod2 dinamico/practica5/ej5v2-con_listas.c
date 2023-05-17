#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    char *dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void inicializarLista(lista*);
void liberarLista(lista*);
void agregarInicio(lista*, int );

int main(){
    FILE *f;
    int cod, fin=0, encontre=0;
    char palabra[255], palabra_act[255];

    f = fopen("diccionario.txt", "w+");
    if (f == NULL){
        printf ("Error\n");
        return 1;
    }
    fprintf(f,"mateo\njuan\npepe\n");
    fseek(f, 0, SEEK_SET);//suando escribo me mueve el puntero del archivo
    
    printf("Ingrese una palabra a buscar (ZZZ para finalizar): ");
    scanf("%s", palabra);
    if(strcmp(palabra,"ZZZ")==0)
        fin=1;

    lista l;
    inicializarLista(&l);

    while (!feof(f)){
        fscanf(f, "%s", palabra_act);//mejor que usar fgets porque pone bien el \0
        agregarInicio(&l,palabra_act);
    }

    while(fin==0){
        
        if(encontre==1)
            printf("palabra encontrada\n");
        else
            printf("palabra NO encontrada\n");

        fseek(f, 0, SEEK_SET); // Volver al principio del archivo porque leer me mueve el puntero
        encontre=0;
        printf("Ingrese otra palabra a buscar (ZZZ para finalizar): ");
        scanf("%s", palabra);
        if(strcmp(palabra,"ZZZ")==0)
            fin=1;
    }
    if(encontre==1)
        printf("palabra encontrada\n");
    else
        printf("palabra NO encontrada\n");

    liberarLista(l);
    fclose(f);
    return 0;
}

void inicializarLista(lista* l){
    (*l)=NULL;
}

void agregarInicio(lista* l, int dato){
    lista act;
    act=(lista)malloc(sizeof(nodo));//reservo mem
    act->dato=dato;
    act->sig=(*l);
    (*l)=act;

}

void liberarLista(lista* l){
    lista aux;
    while( (*l)){
        aux=(*l);
        (*l)=(*l)->sig;
        free(aux);
    }
}