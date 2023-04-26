#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarVector(int*, int);
int* reservar(int);
int buscarMax(int*, int);

int main(){

    srand(time(NULL));
    int n, max, *vector;

    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &n);

    vector=reservar(n);
    inicializarVector(vector, n);
    max=buscarMax(vector, n);

    printf("El numero maximo es: %d", max);

    free(vector);//NO OLVIDAR!!!

    return 0;
}

void inicializarVector(int* vector, int n){
    for(int i=0; i<n; i++){
        vector[i]=rand();
    }
}

int* reservar(int n){
    int *vector;
    vector=(int*)malloc(n*sizeof(int));
    return vector;
}

int buscarMax(int*vector, int n){
    int max=-999;
    for(int i=0; i<n; i++){
        if(vector[i]>max)
            max=vector[i];
    }
    return max;
}