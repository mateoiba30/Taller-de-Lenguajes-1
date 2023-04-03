#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIMF 5

void cargarVector(int[]);
void imprimirVector(int[]);

int main()
{
    int vector[DIMF];
    srand(time(NULL));

    cargarVector(vector);
    imprimirVector(vector);

    return 0;
}

void cargarVector(int vector[]){
    int i;
    for(i=0; i<DIMF; i++){
        vector[i]=rand();
    }
}

void imprimirVector(int vector[]){
    int i;
    for(i=0; i<DIMF; i++){
        printf("%d \n", vector[i]);

    }
}
