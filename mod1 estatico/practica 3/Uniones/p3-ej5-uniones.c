#include <stdio.h>

typedef struct{
    float x;
    float y;
    float ancho;
    float alto;
}ventana1;

typedef struct{
    float x;
    float y;
}pun2D;

typedef struct{
    pun2D xy1;
    pun2D xy2;
}ventana2;

typedef struct{
    pun2D xy;
    pun2D anch_alt;
}ventana3;

typedef union{

    ventana1 v1;
    ventana2 v2;//ventana 2 y 3 podrían ser como un vector de puntos
    ventana3 v3;
}union_ventanas;

int main(){

    union_ventanas ventana;

    return 0;
}