#include <stdio.h>
#include "istack.h"

int main(){

    Sstack* s;
    s=s_create();
    int n;

    printf("Ingrese un numero a apilar (0 para finalizar): \n");
    scanf("%d", &n);

    while(n!=0){
        s_push(s, n);
        printf("Elemento en el tope: %d\n", s_top((*s).pila));
        
        printf("Ingrese otro numero\n");
        scanf("%d", &n);
    }

    imprimirStack((*s));
    printf("tamanio de la pila: %d\n", s_length((*s)) );

    while(!s_empty((*s).pila))
        s_pop(s);
    printf("tamanio despues de desapilar: %d\n", s_length((*s)));
    imprimirStack((*s));

    return 0;
}