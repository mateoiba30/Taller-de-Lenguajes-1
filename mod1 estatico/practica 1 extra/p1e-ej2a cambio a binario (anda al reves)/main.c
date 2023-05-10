#include <stdio.h>
#include <stdlib.h>
int decimal_a_binario(int n){
    int b=0;
    while (n>0){
        printf("%d",(n % 2));
        n=n/2;
    }
    return b;
}
int main()
{
    int n;

    printf("Ingrese un numero natural: \n");
    scanf("%d", &n);
    decimal_a_binario(n);

    return 0;
}
