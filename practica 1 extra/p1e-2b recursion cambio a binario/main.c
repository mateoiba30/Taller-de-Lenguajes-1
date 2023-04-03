#include <stdio.h>
#include <stdlib.h>

/*
void decimal_a_binario(int n, int x){
    if(x==0){
        if(n>=pow(2,0))
            printf("1");
        else
            printf("0");
        }
    else{
        x--;

        if(n>=pow(2,x)){
            printf("1");
            decimal_a_binario(n-pow(2,x), x);
        }
        else{
            printf("0");
            decimal_a_binario(n-pow(2,x), x);
        }
    }
}
*/

void decimal_a_binario(int n){
    int aux;
    if(n<=0)// PUEDO PONER N==0
        return;
        //printf("0"); LO MEJOR ES HACER RETURN PARA QUE NO IMPRIMA UN CERO DEMÁS
    else{
        aux=n;
        n=n/2;
        decimal_a_binario(n);
        printf("%d", aux%2);}

        /*
        otra forma de haxcer el else:

        decimal_a_binario(n/2);
        printf("%d", n%2);}
        */
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
