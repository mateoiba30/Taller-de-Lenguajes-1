#include <stdio.h>

typedef struct{
    float x;
    float y;
    float z;
}pun3D;

typedef pun3D punto3D;

int main(){

    printf("el tamanio de un pun3D es de %d bytes \n", sizeof(pun3D));//cada float pesa 4 bytes
    printf("el tamanio de un punto3D es de %d bytes \n", sizeof(punto3D));//cada float pesa 4 bytes

    punto3D vectorPuntos[4];
    printf("el tamanio de un vector de 4 punto3D es de %d bytes \n", sizeof(vectorPuntos));//cada float pesa 4 bytes
    //su tamanio es de 4 elementos punto3D
    return 0;
}