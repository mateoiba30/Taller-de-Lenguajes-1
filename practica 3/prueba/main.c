#include <stdio.h>


typedef struct{
    float base;
    float altura;
}rectangulo;

void inicializarRectangulo(rectangulo *);//tiene que estar declarado el tipo rectangulo desde antes

int main(){
    rectangulo rec1;
    inicializarRectangulo(&rec1);
    return 0;
}

void inicializarRectangulo (rectangulo *rec){

    printf("Ingrese la altura: ");
    scanf("%f", &rec->base);
    printf("Ingrese la altura: ");
    scanf("%f", &rec->altura);//ambas opciones correctas
}
