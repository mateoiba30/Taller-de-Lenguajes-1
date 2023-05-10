#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarVector(float*, int);
float* reservar(int);
float buscarProm(float*, int);

int main(){

    srand(time(NULL));
    int n;
    float prom, *vector;

    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &n);

    vector=reservar(n);
    inicializarVector(vector, n);
    prom=buscarProm(vector, n);

    printf("El numero promedio es: %.4f", prom);

    free(vector);

    return 0;
}

void inicializarVector(float* vector, int n){
    for(int i=0; i<n; i++){
        vector[i]=(float)rand()/15;
    }
}

float* reservar(int n){
    float *vector;
    vector=(float*)malloc(n*sizeof(float));
    return vector;
}

float buscarProm(float*vector, int n){
    float prom=0;
    for(int i=0; i<n; i++){
        prom+=vector[i];
    }
    prom/=n;
    return prom;
}