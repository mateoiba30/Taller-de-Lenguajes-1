#include <stdio.h>
#include <string.h>
#include "diccionario.h"

Dicc* crearDiccionario(){
    Dicc* l;
    l = (Dicc*)malloc(sizeof(Dicc));//debo reservar memoria para el puntero a la pila tambien
    (*l).l=NULL;
    (*l).tamanio=0;
    return l;
}

int agregarPalabraOrdenada( Dicc* l, char dato[]){
    lista ant, act;
    int agrego=0;
    act=(*l).l;
    ant=(*l).l;

    while(act!=NULL && strcmp(act->dato, dato)<0 ){
        ant=act;
        act=act->sig;
    }

    //ojo que puede llegar a ser null
    if(act==NULL || strcmp(act->dato, dato)!=0){//cuando ya no es menor puede ser igual, en ese caso no ingresar nada
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

// int existePalabra(Dicc sl, char palabra[]){
//     int encontre=0;
//     lista act=sl.l, ant;//recorro con auxiliar para no perder el 1er puntero
//     while(act!=NULL && encontre==0){
//         if(strcmp(palabra,act->dato)==0)
//             encontre=1;
//         else{
//             ant=act;
//             act=act->sig;//sinó solo avanzo
//         }
//     }
//     return encontre;
// }

int eliminarPalabra(Dicc sl, char palabra[]){
    int elimine=0;
    lista act=sl.l, aux, ant;//recorro con auxiliar para no perder el 1er puntero
    while(act!=NULL){
        if(strcmp(act->dato, palabra)){//si hay q 
            elimine=1;
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

    return elimine;
}

int cargarDesdeTxt(char nombre_txt[], Dicc* l){
    char palabra_act[MAX_LONG];
    FILE * f = fopen (nombre_txt, "r");
    if (f == NULL){
        printf ("Error\n");
        return 0;
    }

    while(fscanf(f, "%s", palabra_act)!=EOF){
        agregarPalabraOrdenada(l, palabra_act);
    }

    fclose(f);
    return 1;
}

int guardarEnTxt(char nombre_txt[], Dicc sl){
    FILE * f = fopen (nombre_txt, "w");
    if (f == NULL){
        printf ("Error\n");
        return 0;
    }

    lista act=sl.l;
    while(act!=NULL){
        fprintf(f, "%s\n", act->dato);
    }

    fclose(f);
    return 1;
}

void destruirDiccionario(Dicc *l){
    lista aux;//no perder el inicio de la lista para borrar

    for(int i=0; i<(*l).tamanio; i++){
        aux=(*l).l;
        (*l).l=(*l).l->sig;//siempre voy borrando el 1ro de la lista
        free(aux);
    }
}

void imprimirDicc(Dicc l){
    lista aux=l.l;
        for(int i=0; i<l.tamanio ; i++){
            printf("%s, ",aux->dato);
            aux=aux->sig;
        }

}

int tamanio(Dicc d){
    return d.tamanio;
}