#include <stdio.h>
#include <stdlib.h>
#define M 10

void contarDigitos(int[], int);
void imprimirContadores(int[]);

int main()
{
    int contadores [M]={0}, n;//para cada digito del 0 al 9 veo cuantas veces se repite, y queda inicializado

    printf("Ingrese un numero para analizar:");
    scanf("%d", &n);
    contarDigitos(contadores, n);
    imprimirContadores(contadores);

}

void contarDigitos(int contadores[M], int n){
    while(n>0){
        contadores[n%10]++;
        n/=10;
    }
}

void imprimirContadores(int contadores[M]){
    int i;
    for(i=0; i<M; i++){
        printf("repeticiones del %d: %d \n", i, contadores[i]);
    }
}

