#include<stdio.h>

typedef struct{
    //si no pongo unsigned, el bit más significativo lo toma como singo !!!
    unsigned int segundos : 4;//elegí perder su presicion para tener más horas
    unsigned int minutos : 6;//= 2^6 = 64
    unsigned int horas : 8;//ELIJO LOS BITS !!!
}Horario;

int main(){
//int -> 4 bytes = 32 bits
//16 bits = 2 bytes
    int s,m,h;
    Horario hora;

    printf("ingrese los segundos:\n ");
    scanf("%d", &s);
    printf("ingrese los minutos:\n ");
    scanf("%d", &m);
    printf("ingrese la hora:\n ");
    scanf("%d", &h);

    hora.segundos=s;
    hora.minutos=m;
    hora.horas=h;

    printf("La hora es->  %d:%d:%d \n", hora.horas, hora.minutos, hora.segundos);
    return 0;
}