
#include "diccionario.h"
void mensaje();

int main(){
    mensaje();
    Dicc * d= crearDiccionario();//HACER EL CREAR QUE DEVUELVA ALGO, SINO SE COMPLICA

    imprimirDicc(*d);
    cargarDesdeTxt("DICCIONARIO.txt", d);
    imprimirDicc(*d);
    

    return 0;
}