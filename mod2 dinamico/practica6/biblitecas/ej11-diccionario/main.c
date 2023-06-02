#include <stdio.h>
#include <string.h>
#include "diccionario.h"

int main(){
    Dicc * d= crearDiccionario();//HACER EL CREAR QUE DEVUELVA ALGO, SINO SE COMPLICA

    if(agregarPalabraOrdenada( d, "mateo")==0)
        printf("error al agregar palabra\n");
    else
        printf("palabra agregada\n");

    printf("Tamanio: %d\n", tamanio(*d));

    imprimirDicc(*d);
    // printf("Tamanio: %d\n", tamanio(*d));


    // if(agregarPalabraOrdenada( d, "matias")==0)
    //     printf("error al agregar palabra\n");

    // printf("tamanio: %d\n", d->tamanio);

    // // if(existePalabra(*d, "mateo")==1)
    // //     printf("la palabra existe en el diccionario\n");

    // if(eliminarPalabra(*d, "matias")==0)
    //     printf("error al eliminar palabra\n");

    // printf("tamanio: %d\n", d->tamanio);
    
    
    // // if(existePalabra(*d, "matias")==1)
    // //     printf("la palabra existe en el diccionario\n");

    return 0;
}