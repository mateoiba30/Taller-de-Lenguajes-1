#include <stdio.h>
#include "istack.h"

struct nodo{
    int dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* stack;

int main(){

    stack* s;
    s=s_create();
    int n;

    printf("Ingrese un numero a apilar (0 para finalizar): \n");
    scanf("%d", &n);

    while(n!=0){
        s_push(s, n);

        printf("Ingrese otro numero\n");
        scanf("%d", &n);
    }

    printf("tamanio de la pila: %d", s_length((*s)) );

    return 0;
}