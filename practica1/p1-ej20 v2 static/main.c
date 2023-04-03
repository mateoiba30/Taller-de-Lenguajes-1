#include <stdio.h>
#include <stdlib.h>
int damePar(){
    static int par=-2;
    par+=2;

    return par;
}
int main()
{
    int n, i;
    printf("ingrese la cantidad de pares a  imprimir: ");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
        printf("%d,\t", damePar());

    return 0;
}
