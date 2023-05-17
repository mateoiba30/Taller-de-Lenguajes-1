#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    char dato[255];
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void imprimirLista(lista );
void inicializarLista(lista*);
void liberarLista(lista*);
void agregarInicio(lista*, char* );
void buscarPalabra(lista, char[], int*);


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

    lista l;
    inicializarLista(&l);

    // while (!feof(f)){//verifica si me pasé, entonces la última la lee 2 veces
    //     fscanf(f, "%s", palabra_act);//mejor que usar fgets porque pone bien el \0
    //     agregarInicio(&l,palabra_act);
    // } //debería eliminar el elemento repetido

    while (fscanf(f, "%s", palabra_act) == 1) {//Si un error de entrada ocurre antes de cualquier conversión, la función fscanf retorna EOf
        agregarInicio(&l, palabra_act);
    }
    // imprimirLista(l); //pa debuguear

    printf("Ingrese una palabra a buscar (ZZZ para finalizar): ");
    scanf("%s", palabra);
    if(strcmp(palabra,"ZZZ")==0)
        fin=1;
    while(fin==0){
        buscarPalabra(l,palabra,&encontre);
        if(encontre==1)
            printf("palabra encontrada\n");
        else
            printf("palabra NO encontrada\n");

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

    liberarLista(&l);
    fclose(f);
    return 0;
}
void buscarPalabra(lista l, char palabra[], int* encontre){
    lista act=l, aux, ant;//recorro con auxiliar para no perder el 1er puntero
    while(act!=NULL && (*encontre)==0){
        if(strcmp(palabra,act->dato)==0)
            (*encontre)=1;
        else{
            ant=act;
            act=act->sig;//sinó solo avanzo
        }
    }
}


void inicializarLista(lista* l){
    (*l)=NULL;
}

void agregarInicio(lista* l, char dato[]){
    lista act;
    act=(lista)malloc(sizeof(nodo));//reservo mem
    strcpy(act->dato,dato);//destino, fuente
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


void imprimirLista(lista l){
    lista aux=l;
        while(aux!=NULL){
            printf("%s, ",aux->dato);
            aux=aux->sig;
    }

}