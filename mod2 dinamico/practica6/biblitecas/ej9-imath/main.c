#include <stdio.h>
#include "imath.h"

int main(){

    int n;

    int y=4;

    printf("Ingrese un numero a analizar (0 para finlaizar): ");
    scanf("%d", &n);

    while(n!=0){
        // if(multiplo(n, 2))
        //     printf("multiplo de %d\n", y);
        // if(divisor(n, 2))
        //     printf("divisor de %d\n", y);
        if( par(n) )
            printf("n^2 = %d\nn^3 = %d\n", cuadrado(n), cubo(n));
        else
            printf("n! = %d\n", factorial(n));

        printf("Ingrese otro numero: ");
        scanf("%d", &n);
    }

    return 0;
}