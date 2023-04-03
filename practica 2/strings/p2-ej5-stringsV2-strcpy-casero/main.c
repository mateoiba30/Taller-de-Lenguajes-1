#include <stdio.h>
#include <stdlib.h>

void copiar(char*, char*);

int main()
{
    char *palabra1=NULL, *palabra2=NULL;
    palabra1=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap
    palabra2=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap

    printf("ingrese una palabra: \n");
    scanf("%255s", palabra1);
    getchar();
    copiar(palabra1, palabra2);
    printf("%s", palabra2);
    printf("%s", palabra1);
    getchar();

    return 0;
}

void copiar(char *palabra1, char *palabra2){
    char *aux, *aux2;

    aux=palabra1;//no quiero perder el puntero
    aux2=palabra2;//el uso de aux permite mantener la palabra1
    palabra2=palabra1;
    while(*aux != '\0'){
        *aux2=*aux;
        aux++;
        aux2++;
    }

}
