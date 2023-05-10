#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void decimal_a_binario(int n){
    int b=0, x=16;
    while (x>=0){
        if(n>=pow(2,x)){
            printf("1");
            n=n-pow(2,x);}
        else
            printf("0");
        x--;
    }
}
int main()
{
    int n;

    printf("Ingrese un numero natural: \n");
    scanf("%d", &n);

    printf("su representacion en binario es: \n");
    decimal_a_binario(n);
    return 0;
}
//3 2^0 2^1 2^2
