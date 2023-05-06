#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOMBAS 10
#define LADOS 8

typedef struct{
    int fila;
    int columna;

}punto2D;

void elegirBombas(punto2D[], int *);
int buscarPunto(punto2D, punto2D[], int);
void imprimirPosBombas(punto2D[]);

int main(){
    print("hola");
    srand(time(NULL));
    int tablero[LADOS][LADOS], dimlBombas=-1;//diml es cuantos voy cargando
    punto2D posBombas[BOMBAS];
    elegirBombas(posBombas, &dimlBombas);

    imprimirPosBombas(posBombas);

    return 0;
}

void imprimirPosBombas(punto2D posBombas[]){
    for(int i=0; i<BOMBAS; i++){
        printf(" bomba %d /t fila %d | columna %d \n", (i+1), posBombas[i].fila, posBombas[i].columna);
    }
}

void elegirBombas(punto2D posBombas[], int *dimlBombas){//no poner bombas entre los corchetes porque lo tendría que poner tmb en el prototipo y es a fin de cuentas innecesario
    punto2D nuevoPunto;
    for(int i=0; i<BOMBAS; i++){
        nuevoPunto.fila=rand()%(LADOS +1);
        nuevoPunto.columna=rand()%(LADOS +1);
        if( buscarPunto(nuevoPunto, posBombas, (*dimlBombas)) == 0){
            (*dimlBombas)++;
            posBombas[(*dimlBombas)]=nuevoPunto;
        }
        else
            i--;//repito paso

    }
}

int buscarPunto(punto2D nuevoPunto, punto2D posBombas[], int dimlBombas){
    int i=0, encontre=0;
    while(i<dimlBombas && encontre==0){
        if(posBombas[i].columna == nuevoPunto.columna && posBombas[i].fila==nuevoPunto.fila)
            encontre=1;
    }
    return encontre;
}
