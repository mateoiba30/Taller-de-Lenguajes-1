#include<stdio.h>
#define LONG 50

typedef union{
    long long int DNI;
    char pasaporte[LONG];

}Uidentificacion;

typedef struct{
    char apellido[LONG];
    char nombre[LONG];
    char legajo[LONG];
    Uidentificacion identificacion;

}Sestudiante;

void cargarEstudiante( Sestudiante *, int, int*);

void imprimirEstudiante(Sestudiante, int, int);

int main(){
    Sestudiante est;
    int dni;

    cargarEstudiante(&est, LONG, &dni);
    imprimirEstudiante(est, LONG, dni);

    return 0;
}

void cargarEstudiante(Sestudiante *est, int lon, int *dni){//otra forma de cargar es generando la estructura dentro
    printf("ingrese apellido:");
    scanf("%s", est->apellido);
    printf("ingrese nombre: ");
    scanf("%s", est->nombre);
    printf("ingrese legajo: ");
    scanf("%s", est->legajo);
    printf("ingrese cero si tiene dni: ");
    scanf("%d", dni);// como cargo un puntero: &(*dni) = dni
    if(*dni==0){//if dni==0
        printf("ingrese DNI:");
        scanf("%lld", &(est->identificacion.DNI) );//lleva '&' porque no es un char
    }
    else{
        printf("ingrese pasaporte: ");
        scanf("%s", est->identificacion.pasaporte);
    }

}
void imprimirEstudiante(Sestudiante est, int lon, int dni){
    printf("apellido: %s", est.apellido);
    printf(" nombre: %s", est.nombre);
    printf(" legajo: %s", est.legajo);
    // printf("dni: %d", dni);
    if(dni==0)//if dni==0
        printf(" DNI: %lld", est.identificacion.DNI);//el printf nunca necesita el '&'
    else
        printf(" pasaporte: %s", est.identificacion.pasaporte);

}