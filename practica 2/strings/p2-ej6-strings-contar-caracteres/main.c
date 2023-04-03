#include <stdio.h>
#include <stdlib.h>

int contar(char*, char);

int main()
{
    char *palabra1=NULL, car;
    palabra1=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap

    printf("ingrese una palabra en minusculas: \n");
    scanf("%255s", palabra1);
    getchar();
    printf("ingrese un caracter a buscar: \n");
    scanf("%c", &car);
    getchar();

    printf("La cantidad de veces que aparece %c en la %s es de= %d", car, palabra1, contar(palabra1,car));
    return 0;
}

int contar(char *palabra1, char car){
    char *aux;
    int cont=0;

    aux=palabra1;//no quiero perder el puntero
    while(*aux != '\0'){
        if(*aux==car)
            cont++;
        aux++;
    }

    return cont;
}
