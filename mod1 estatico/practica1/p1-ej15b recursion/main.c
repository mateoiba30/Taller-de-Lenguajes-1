#include <stdio.h>
#include <stdlib.h>
int factorial(int n){

    if(n==0)
        n=1;
    else
        n=n * factorial(n-1);

    return n;
}
int main()
{
    int n;
    printf("Ingrese un numero para calcular su facotrial: \n");
    scanf("%d", &n);
    printf("el factorial de %d es= %d \n", n, factorial(n));
    return 0;
}
