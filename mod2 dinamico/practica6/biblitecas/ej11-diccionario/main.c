#include <stdio.h>
#include <string.h>
#include "diccionario.h"

int main(){
    Dicc * d= crearDiccionario();//HACER EL CREAR QUE DEVUELVA ALGO, SINO SE COMPLICA

    imprimirDicc(*d);
    cargarDesdeTxt("DICCIONARIO.txt", d);
    imprimirDicc(*d);
    

    return 0;
}