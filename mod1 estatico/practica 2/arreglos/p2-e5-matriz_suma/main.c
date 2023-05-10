#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 5
#include <time.h>

void cargarMatriz(int[M][N]);
void imprimirMatriz(int[M][N]);

int main()
{
    srand(time(NULL));
    int matrizA [M][N],matrizB [M][N], matrizC [M][N];

    cargarMatriz(matrizA);
    cargarMatriz(matrizB);

    imprimirMatriz(matrizA);
    printf("\n");
    imprimirMatriz(matrizB);

    sumarMatrices(matrizA, matrizB, matrizC);
    printf("----------------------------\n");
    imprimirMatriz(matrizC);

}

void sumarMatrices(int matrizA [M][N], int matrizB [M][N], int matrizC [M][N]){
    int i, j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            matrizC[i][j]=matrizA[i][j]+matrizB[i][j];
        }
    }
}

void cargarMatriz(int matriz[M][N]){
    int i, j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            matriz[i][j]=rand()/1000;//para achicar los numeros
        }
    }
}

void imprimirMatriz(int matriz[M][N]){
    int i, j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}
