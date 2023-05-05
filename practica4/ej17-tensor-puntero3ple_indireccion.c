#include <stdio.h>
#include <stdlib.h>
#define N 10

int*** crearTensor(int t){
    int i,j;
    int*** a;
    a = (int***) calloc(t,sizeof(int**));//es un arreglo dinamico que tiene 10 punteros a direcciones
    for (i=0; i<t; i++){
        a[i] = (int**) calloc(t, sizeof(int*));//para cada posicion del arreglo, reserva memoria para apuntar a 1 direccion
        for (j=0; j<t; j++){
            a[i][j] = (int*) calloc(t, sizeof(int));//al puntero que es apuntando por el elemento del vector le reservo espacio, este es quien apunta al valor que necesito
        }
    }
    return a;//lo devuelve modificado
}

int main(){
    int*** e;
    e = crearTensor(N);

    return 0;
}
