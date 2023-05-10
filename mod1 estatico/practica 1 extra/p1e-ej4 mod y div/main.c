#include <stdio.h>
#include <stdlib.h>
int reducir(n){
    int rta=0;
    while(n>0){
        rta=rta+ n%10;
        n=n/10;
    }
    return rta;
}
int main()
{
    int n;
    printf("Ingrese un numero a reducir: ");
    scanf("%d", &n);
    while(n>=10){//puedo usar un bucle do while para que me muestre algo cuadno inserte cero
        n=reducir(n);
        printf("%d    -->   ", n);
    }

    return 0;
}
