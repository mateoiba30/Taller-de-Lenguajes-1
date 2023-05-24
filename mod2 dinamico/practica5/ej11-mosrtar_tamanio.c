#include <stdio.h>
#include <stdlib.h>
// typedef struct
// {
//     char nombre[50];
//     char apellido[50];
//     int edad;
//     int cantTitulos;
//     int ranking;
//     int fortuna;

// } Tenistas;

int main(){
    FILE *binario;
    char aux;
    int cont=0;

    binario = fopen("tenistas.dat", "rb");
    if (binario == NULL){
        printf("Error en el archivo binario\n");
        return 1;
    }

    while (fread(&aux, sizeof(char), 1, binario) != 0)
        cont++;

    // printf("el tamanio es de: %d bytes\n", sizeof(Tenistas));//=116 bytes
    printf("el tamanio es de: %d bytes\n", cont);//como tengo 2 tenistas su peso es de 232 bytes

    fclose(binario);
    return 0;
}