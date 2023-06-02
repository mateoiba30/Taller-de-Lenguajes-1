#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG 0
#define CANT 1000

int buscarEntero(int, int []);

int main(){
    srand(time(NULL));
    int vector[CANT], n, aux;

    for(int i=0; i<CANT; i++)
        vector[i]=rand()%100;

    printf("Ingrese el entero a buscar: ");
    scanf("%d", &n);

    aux=buscarEntero(n, vector);
    if(aux==-1)
        printf("Entero no encontrado\n");
    else
        printf("Entero en la posicion: %d\n", aux);
        
    return 0;
}

int buscarEntero(int n, int v[]){
    int i=0;

    while(i<CANT && v[i]!=n)
        i++;
    
    #if DEBUG
        printf("accesos a arreglo: %d\n", i);
    #endif
    
    if(i<CANT)
        return i;
    else
        return -1;
}