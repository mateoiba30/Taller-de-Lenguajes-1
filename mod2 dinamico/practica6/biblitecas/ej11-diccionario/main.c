#include <stdio.h>
#include <string.h>
#include "diccionario.h"

int main(){
    Dicc * d= crearDiccionario();//HACER EL CREAR QUE DEVUELVA ALGO, SINO SE COMPLICA

    agregarPalabraOrdenada(d, "matias");
    imprimirDicc(*d);
    
    if(existePalabra(*d, "matia")==1)
        printf("la palabra existe en el diccionario\n");
    else
        printf("la palabra NO existe en el diccionario\n");


    return 0;
}