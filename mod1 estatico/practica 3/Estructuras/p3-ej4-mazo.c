#include <stdio.h>
#include <string.h>
#include <time.h>
#define CANT 50

typedef struct{//!!!!!!!!!!!!!!!!!!
    char palo[6];//podría haberlo hecho de integer, de 1 a 4, y defino constantes donde si la carta vale 1, al mostrarla mando el valor de ORO (que vale "oro")
    int numero;

}carta;

void cargarMazo(carta[], int);

void imprimirMazo(carta[], int);

void barajarMazo(carta[], int);

carta elegirCarta (carta[], int);

void imprimirCarta(carta);

int main(){

    srand(time(NULL));
    carta mazo[CANT];

    cargarMazo(mazo, CANT);
    barajarMazo(mazo, CANT);
    imprimirMazo(mazo, CANT);
    printf("carta random ");
    imprimirCarta(elegirCarta(mazo, CANT));
    return 0;
}

void cargarMazo(carta mazo[], int cant){

    char *palos[4]={"oro", "copa", "basto", "espada"};//posiciones de 0 a 3
    int i, x;

    for(i=0; i<cant; i++){
        x=i%4;//x vale 0, 1, 2 o 3
        strcpy(mazo[i].palo, palos[x]);
        x=i%12;//x va de cero a 11
        x++;
        mazo[i].numero=x;
    }
}

void imprimirMazo(carta mazo[], int cant){
    int i;

    for(i=0; i<cant; i++){
        printf("%d de %s \n", mazo[i].numero, mazo[i].palo);
    }
}

void barajarMazo(carta mazo[], int cant){
    carta carta1, carta2;
    int i, x;

    for(i=0; i<cant; i++){
        x=rand()%cant;//x tiene un valor random de 0 a 49, al igual que las posiciones del mazo
        carta2=mazo[x];
        carta1=mazo[i];
        mazo[i]=carta2;
        mazo[x]=carta1;//intercambio las cartas
    }
}

carta elegirCarta (carta mazo[], int cant){
    int x;
    x=rand()%cant;
    return mazo[x];
}

void imprimirCarta(carta car){
    printf("-> %d de %s", car.numero, car.palo);
}