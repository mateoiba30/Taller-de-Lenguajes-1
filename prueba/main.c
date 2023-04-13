#include <stdio.h>
#define CANTREC 2

typedef struct{
    float base;
    float altura;
}rectangulo;

void inicializarRectangulo(rectangulo *);//tiene que estar declarado el tipo rectangulo desde antes

float calcularArea(rectangulo);

int main(){

    // printf("%d", !(3-3));
    rectangulo vectorRec[CANTREC];
    int i, pos_min=0;
    float area_i, min=9999;

    for(i=0; i<CANTREC; i++){
        inicializarRectangulo(&vectorRec[i]);
        area_i=calcularArea(vectorRec[i]);
        if(area_i < min){
            min=area_i;
            pos_min=i;
        }

    }

    printf("El menor rectangulo es el numero %d", pos_min+1);
    return 0;
}

void inicializarRectangulo (rectangulo *rec){

    printf("Ingrese la altura: ");
    scanf("%f", &rec->base);
    printf("Ingrese la altura: ");
    scanf("%f", &(*rec).altura);//ambas opciones correctas
}

float calcularArea(rectangulo rec){
    return rec.altura * rec.base;
}
