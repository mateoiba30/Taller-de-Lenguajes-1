#include <stdio.h>
#include <stdlib.h>
int invertir(int);

int main()
{
    int n;
    printf("ingrese un numero a invertir: ");
    scanf("%d",&n);

    printf("invertido es: ");
    invertir(n);

    return 0;
}

int invertir(n){
    while(n>0){
        printf("%d", n%10);
        n=n/10; //la division normal es la division entera, como DIV

    }


return 0;
}
