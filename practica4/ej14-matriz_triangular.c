#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int** reservarTriangularInferior(int);
void inicializarMatrizTriangularInferior(int**, int);
void imprimirMatrizTriangularInferior(int **, int);
int** liberarMatrizTriangularInferior(int**, int);

int main(){
    int **matriz, f;//arreglo de filas | int** filas | int* columnas | int dato
    srand(time(NULL));

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &f);
    matriz=reservarTriangularInferior(f);

    inicializarMatrizTriangularInferior(matriz, f);

    imprimirMatrizTriangularInferior(matriz, f);

    matriz=liberarMatrizTriangularInferior(matriz, f);
    return 0;
}

int** liberarMatrizTriangularInferior(int** matriz, int f){
    for(int i=0; i<f; i++)
        free(matriz[i]);//libero cada fila
    free(matriz);//libero vector de filas | no liberarlo primero, ni tampoco liberarlo solo a él

    return matriz;
}

void imprimirMatrizTriangularInferior(int ** matriz, int f){
    int contador=1;//cant de elementos inicia en 1
    for(int i=0; i<f; i++){
        for(int j=0; j<contador; j++){
            printf("%d \t", matriz[i][j]);
        }
        printf("\n");
        contador++;
    }
}

int** reservarTriangularInferior(int f){
    int **matriz, contador=1;//cant de elementos inicia en 1
    matriz=(int**)malloc((f)*sizeof(int*));//reservo arreglos de columnas, por tantas filas tenga
    for(int i=0; i<f; i++){//para cada fila voy reservando
        matriz[i]=(int*)malloc(contador*sizeof(int));//voy reservando cada vez más columnas
        contador++;
    }
    return matriz;
}

void inicializarMatrizTriangularInferior(int** matriz, int f){
    int contador=1;//cant de elementos inicia en 1
    for(int i=0; i<f; i++){
        printf("contador=%d \n", contador);
        for(int j=0; j<contador; j++){
            matriz[i][j]= (rand() % 21);
        }
        contador++;
    }
}