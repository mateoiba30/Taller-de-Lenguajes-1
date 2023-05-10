#include <stdio.h>
#include <stdlib.h>

int copiar(char*);

int main()
{
    char *palabra1=NULL;
    palabra1=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap

    printf("ingrese una palabra: \n");
    scanf("%255s", palabra1);
    getchar();
    printf("la longitud de la palabra es de %d", longitud(palabra1));
    getchar();

    return 0;
}

int longitud(char *palabra1){
    char *aux;
    int cont=0;

    aux=palabra1;//no quiero perder el puntero
    while(*aux != '\0'){
        aux++;
        cont++;
    }
    return cont;
}
