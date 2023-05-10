#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarVector(double*, int);
double* reservar(int);
double promedio(double*, int);

int main(){
    int n;
    double *vector;

    printf("Ingrese el tamanio del vector: ");
    scanf("%d", &n);

    vector=reservar(n);
    inicializarVector(vector, n);
    // for(int i=0; i<n; i++) //pa debuguear
    //     printf("%lf \t", vector[i]);

    printf("El numero promedio es: %lf", promedio(vector, n));

    free(vector);//NO OLVIDAR!!!
    return 0;
}

void inicializarVector(double* vector, int n){
    double aux;
    for(int i=0; i<n; i++){
        printf("numero %d: ", (i+1));
        scanf("%lf", &aux);
        vector[i]=aux;
    }
}

double* reservar(int n){
    double *vector;
    vector=(double*)malloc(n*sizeof(double));
    return vector;
}

double promedio(double*vector, int n){
    double promedio=0;
    for(int i=0; i<n; i++)
        promedio+=vector[i];
    promedio/=n;
    printf("%lf ", promedio);
    return promedio;
}