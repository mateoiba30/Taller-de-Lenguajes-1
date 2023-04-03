#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BuscarMax(int*, char[], char[]);

int main()
{
    char palabra[255], pal_ganadora[255];
    int max=-9999;

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    while(strcmp(palabra,"FIN")){
        BuscarMax(&max, palabra, pal_ganadora);
        printf("Ingrese otra palabra: ");
        scanf("%s", palabra);
    }

    printf("La palabra ganadora es %s con %d caracteres\n", pal_ganadora, max);

    return 0;
}

void BuscarMax(int *max, char palabra[], char pal_ganadora[]){
    int longitud;
    longitud=strlen(palabra);

    if(longitud>=*max){
        *max=longitud;
        strcpy(pal_ganadora,palabra);
    }
}
