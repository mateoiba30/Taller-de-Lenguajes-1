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

    while (fread(&aux, sizeof(char), 1, binario) != 0)//no uso feof porque no me quiero pasar al contar los bytes
        cont++;

    // printf("el tamanio es de: %d bytes\n", sizeof(Tenistas));//=116 bytes
    printf("el tamanio es de: %d bytes\n", cont);//como tengo 2 tenistas su peso es de 232 bytes

    fclose(binario);
    return 0;
}

//otra forma:
// int tamanio(FILE *f) {
//     int t;//si se q va a ser grande el archivo puedo poner otro tipo en lugar de int

//     fseek(f, 0, SEEK_END);
//     t = ftell(f);
//     rewind(f);

//     return t;
// }

//tmb puedo restar el valor del puntero al final con el puntero al inicio (el inicio no vale cero)