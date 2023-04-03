#include <stdio.h>
#include <stdlib.h>

void tirar_dados(int *x, int *y){

    srand(time(NULL));
    *x=rand() %6 + 1;
    *y=rand() %6 + 1;

}

int main()        //fin 1 ganar, fin 2 perder, fin 0 seguir jugando
{
    int condicion,fin=0,x,y,jugada=0;
    printf("(presiona enter para tirar los dados) \n\n");

    getchar();//1er turno
    tirar_dados(&x, &y);
    printf("dado 1: %d \t dado 2: %d \n", x,y);
    condicion=x+y;

    if((x+y==7)||(x+y==11)){//me fijo si gana o pierde antes de empezar a iterar
        fin=2;
        printf("Ganaste por sacar una suma de 7 u 11 a la 1ra\n");}
    else
        if((x+y==2)||(x+y==12)){
            fin=1;
            printf("perdiste porque sumaste 2 o 12\n");}

    while(fin==0){//a repetir hasta perder o ganar  EN VEZ DE PREGUNTAR 1 VEZ AFUERA PODRÍA HABER USADO UN DO WHILE Y PREGUNTAR SIEMPRE ADENTRO
        getchar();//al usar getchar simplemente sigo apretando el enter, podría usar un scanf par que sirva cualquier tecla
        tirar_dados(&x, &y);
        printf("dado 1: %d \t dado 2: %d \n", x,y);

        if((x+y==2)||(x+y==12)){//me fijo si perde o gana
            fin=1;
            printf("perdiste porque sumaste 2 o 12\n");
        }
        else
            if(x+y==condicion){
                fin=2;
                printf("ganaste porque sumaste lo mismo que al inicio \n");
            }
    }
    return 0;
}
