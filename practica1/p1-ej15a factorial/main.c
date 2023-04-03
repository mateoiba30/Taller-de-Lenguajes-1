#include <stdio.h>
#include <stdlib.h>
int factorial(int);

int main()
{
    int n;
    printf("ingrese un numero: ");
    scanf("%d", &n);
    printf("El factorial de %d es: %d \n",n,factorial(n));

    return 0;
}

int factorial(n){

    int fact=n;
    while(n>1){
        n--;
        fact=fact*n;
    }

return fact;
}
