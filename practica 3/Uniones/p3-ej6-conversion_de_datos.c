#include<stdio.h>
typedef struct{
    int dia;
    int mes;
    int anio;

}SFecha;

typedef union{
    SFecha fecha;
    long long int hack;//opicon de guardar 2022/12/31 como 20221231

}UFechaHack;

int compararFechas(SFecha f1, SFecha f2);

int main(){

    SFecha f1, f2;

    printf("Fecha 1 ");
    printf("dia 1 ");
    scanf("%d", &f1.dia);
    printf("mes 1 ");
    scanf("%d", &f1.mes);
    printf("anio 1 ");
    scanf("%d", &f1.anio);

    printf("Fecha 2 ");
    printf("dia 2 ");
    scanf("%d", &f2.dia);
    printf("mes 2 ");
    scanf("%d", &f2.mes);
    printf("anio 2 ");
    scanf("%d", &f2.anio);

    switch(compararFechas(f1,f2)){
        case -1: printf("La fecha 1 es la mayor "); break;
        case 0: printf("fechas iguales"); break;
        default: printf("la fecha 2 es la mayor"); break;
    }

    return 0;
}

int compararFechas(SFecha f1, SFecha f2){

    UFechaHack hack1, hack2;

    hack1.fecha=f1;//guardo como struct, cambio que deopende de la arquitectura de la computadora
    hack2.fecha=f2;

    if(hack1.hack<hack2.hack)//comparo como si toda una fecha sea un gran numero
        return 1;
    else if(hack1.hack==hack2.hack)
        return 0;

    return -1;
}