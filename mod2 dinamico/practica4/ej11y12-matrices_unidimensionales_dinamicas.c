#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarMatriz(int*, int, int);
int* reservar(int, int);
void multiplos3(int*, int, int);
void imprimirMatrizPorColumnas(int*, int, int);
void imprimirMatrizPorFilas(int*, int, int);


int main(){
    int *matriz, c, f;

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &f);
    printf("Ingrese cantidad de columnas: ");
    scanf("%d", &c);
    matriz=reservar(c, f);

    inicializarMatriz(matriz, f, c);
    // for(int i=0; i<n; i++) //pa debuguear
    //     printf("%lf \t", vector[i]);

    multiplos3( matriz, f, c);
    printf("\nimpresion por columnas: \n");
    imprimirMatrizPorColumnas(matriz, f, c);
    printf("\nimpresion por filas: \n");
    imprimirMatrizPorFilas(matriz, f, c);
    free(matriz);//NO OLVIDAR!!!
    return 0;
}

void imprimirMatrizPorColumnas(int * matriz, int f, int c){
    for(int i=0; i<c; i++){
        for(int j=0; j<f; j++){
            printf("%d \t", matriz[j*f + i]);
        }
    }
}

void imprimirMatrizPorFilas(int * matriz, int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            printf("%d \t", matriz[i*c + j]);
        }
    }
}


void multiplos3(int* matriz, int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            if(matriz[i*c + j] % 3 ==0)
                printf("%d \t", matriz[i*c + j]);
        }
    }
}

void inicializarMatriz(int* matriz, int f, int c){
    int aux;
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            printf("fila %d  columna %d: ", (i+1), (j+1));
            scanf("%d", &aux);
            matriz[i*c + j]=aux;
        }
    }
}

int* reservar(int c, int f){
    int *matriz;
    matriz=(int*)malloc((f*c)*sizeof(int));//se guardan en celdas consecutivas
    return matriz;
}