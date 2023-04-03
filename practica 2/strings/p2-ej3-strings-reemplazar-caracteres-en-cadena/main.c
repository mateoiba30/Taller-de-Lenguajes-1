#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modificarString(char*, char, char);

int main()
{
    char *palabra=NULL, a, b;
    palabra=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap

    printf("ingrese una palabra: ");
    scanf("%255s", palabra);//maximo leo 255 caracteres, lo que puedo usar de los 256 reervados
    getchar();

    printf("ingrese el caracter a buscar\n");
    scanf("%c", &a);
    getchar();
    printf("ingrese el caracter por el cual reemplazarlo\n");
    scanf("%c", &b);
    getchar();

    modificarString(palabra, a, b);
    printf("nueva cadena: %s", palabra);

    return 0;
}

void modificarString(char *palabra, char a, char b){
    char *aux;
    aux=palabra;//no quiero perder el puntero
    while(*aux != '\0'){
        if(*aux == a)
            *aux=b;
        aux++;
    }
}
