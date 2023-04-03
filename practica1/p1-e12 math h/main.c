#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i=1;i<=10;i++){
        printf(" NUMERO %d \n",i);
        printf("raiz cuadrada: %.3f \n", sqrt(i));
        //printf("raiz: %.0f \n", pow(i,1.0/2)); --> NO FUNCIONA
        printf("cuadrado: %.0f \n", pow(i,2));
        printf("cubo: %.0f \n", pow(i,3));

        printf(" ------------------ \n");
    }

    return 0;
}
