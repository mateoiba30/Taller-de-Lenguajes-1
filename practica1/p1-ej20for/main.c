#include <stdio.h>
#include <stdlib.h>
void damePar(int n){
    for(int i=0; i<2*n; i=i+2){
        printf("%d \t", i);
    }
}
int main()
{
    int n;
    printf("ingrese la cantidad de pares a  imprimir: ");
    scanf("%d", &n);
    printf("\n");
    damePar(n);

    return 0;
}
