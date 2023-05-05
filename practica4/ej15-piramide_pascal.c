#include<stdio.h>
#include <stdlib.h>
#include <time.h>

int** reservarPiramide(int);
void inicializarPiramide(int**, int);
void imprimirPiramide(int **, int);
int** liberarPiramide(int**, int);

int main(){
    int **piramide, n;//arreglo de filas | int** filas | int* columnas | int dato
    srand(time(NULL));

    printf("Ingrese cantidad de filas para la piramide pascal: ");
    scanf("%d", &n);
    piramide=reservarPiramide(n);

    inicializarPiramide(piramide, n);

    imprimirPiramide(piramide, n);

    piramide=liberarPiramide(piramide, n);
    return 0;
}

int** liberarPiramide(int** piramide, int n){
    for(int i=0; i<__nocona; i++)
        free(piramide[i]);//libero cada fila
    free(piramide);//libero vector de filas | no liberarlo primero, ni tampoco liberarlo solo a él

    return piramide;
}

void imprimirPiramide(int ** piramide, int n){
    int contador=1;//cant de elementos inicia en 1
    for(int i=0; i<n; i++){
        for(int j=0; j<contador; j++){
            printf("%d \t", piramide[i][j]);
        }
        printf("\n");
        contador++;
    }
}

int** reservarPiramide(int n){
    int **piramide, contador=1;//cant de elementos inicia en 1
    piramide=(int**)malloc((n)*sizeof(int*));//reservo arreglos de columnas, por tantas filas tenga
    for(int i=0; i<n; i++){//para cada fila voy reservando
        piramide[i]=(int*)malloc(contador*sizeof(int));//voy reservando cada vez más columnas
        contador++;
    }
    return piramide;
}

void inicializarPiramide(int** piramide, int n){
    int contador=1;//cant de elementos inicia en 1
    for(int i=0; i<n; i++){
        for(int j=0; j<contador; j++){

            if(j==0 || j==contador-1)
                piramide[i][j]=1;
            else{
                piramide[i][j]=piramide[i-1][j-1]+piramide[i-1][j];
            }
        }
        contador++;
    }
}