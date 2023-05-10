#include<stdio.h>
#include <stdlib.h>

int** reservar(int, int);
void inicializarMatriz(int**, int, int);
void multiplos3(int**, int, int);
int** liberarMatriz(int**, int, int);
void inicializarMatriz(int**, int, int);
void imprimirMatrizPorColumnas(int **, int, int);
void imprimirMatrizPorFilas(int **, int, int);

int main(){
    int **matriz, c, f;//arreglo de filas | int** filas | int* columnas | int dato

    printf("Ingrese cantidad de filas: ");
    scanf("%d", &f);
    printf("Ingrese cantidad de columnas: ");
    scanf("%d", &c);
    matriz=reservar(c, f);

    inicializarMatriz(matriz,f,c);

    multiplos3(matriz, f, c);
    
    matriz=liberarMatriz(matriz, f, c); 
    // printf("%d", matriz[10][10]); //no imprime nada porque ya liberé
    return 0;
}

void imprimirMatrizPorColumnas(int ** matriz, int f, int c){
    for(int i=0; i<c; i++){
        for(int j=0; j<f; j++){
            printf("%d \t", matriz[j][i]);
        }
    }
}

void imprimirMatrizPorFilas(int ** matriz, int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            printf("%d \t", matriz[i][j]);
        }
    }
}

void inicializarMatriz(int** matriz, int f, int c){
    int aux;
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            printf("fila %d  columna %d: ", (i+1), (j+1));
            scanf("%d", &aux);
            matriz[i][j]=aux;
        }
    }
}

int** liberarMatriz(int** matriz, int f, int c){
    for(int i=0; i<f; i++)
        free(matriz[i]);//libero cada fila
    free(matriz);//libero vector de filas | no liberarlo primero, ni tampoco liberarlo solo a él

    return matriz;
}

void multiplos3(int** matriz, int f, int c){
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            if(matriz[i][j] % 3 ==0)
                printf("%d \t", matriz[i][j]);
        }
    }
}

int** reservar( int c, int f){
    int **matriz;
    matriz=(int**)malloc((f)*sizeof(int*));//reservo arreglos de columnas, por tantas filas tenga
    for(int i=0; i<f; i++){//para cada fila voy reservando
        matriz[i]=(int*)malloc(c*sizeof(int));//cada fila es del largo de cantidad de columnas
        //PONER MATRIZ[I]
    }
    return matriz;
}