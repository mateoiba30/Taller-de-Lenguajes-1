#include <stdio.h>
#include <stdlib.h>//para usar malloc, realloc, etc -> NO OLVIDAR

int* cargarDivisores(int, int*, int);

int main(){
    int* divisores=NULL, n, diml=0;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    divisores=cargarDivisores(n, divisores, diml);

    for(int i=0; i<diml; i++)
        printf("%d \t", divisores[i]);

    free(divisores);

    return 0;
}

int* cargarDivisores(int n, int* divisores, int diml){
    for(int i=1; i<=n; i++){//iniciar en 1 para no dividir por cero

        if(n % i ==0){//es divisor
            diml++;
            divisores = (int*) realloc(divisores, diml * sizeof(int));
            divisores[diml-1]=i;//cargo divisor en la ultima pos
        }
    }
    return divisores;
}