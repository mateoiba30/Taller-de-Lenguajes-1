#include <stdio.h>
#include <stdlib.h>
// #include <time.h> //para probar codigo elijo pseudoaleatoriamiente

#define BOMBAS 10
#define LADOS 8
#define CHAR_BOMBA 229//EB
#define CHAR_OCULTA 177//B1
#define CHAR_BANDERA 16

// i es fila
//j es para columna
//1 para verdadero

typedef enum  {sup1, sup2, sup3, izq, der, pos1, pos2, pos3 } enumCasillasVecinas;
// 0 1 2
// 3 x 4
// 5 6 7

typedef struct{//HACERLOS CAMPOS DE BITS?
    int tieneBandera;
    int esBomba;
    int bombasVecinas;
    int esVisible;

}casilla;

typedef struct{
    int fila;
    int columna;

}punto2D;

void impirmirPrueba(casilla[][LADOS]);
void inicializarTablero(casilla[][LADOS], punto2D[]);
void contarBombasVecinas(casilla[][LADOS]);

void imprimirPosBombas(punto2D[]);
void elegirBombas(punto2D[], int *);
int buscarPunto(punto2D, punto2D[], int);

int main(){

    // srand(time(NULL));  //para probar codigo elijo pseudoaleatoriamiente
    casilla tablero[LADOS][LADOS];
    int dimlBombas=0;//diml es cuantos voy cargando
    punto2D posBombas[BOMBAS];

    elegirBombas(posBombas, &dimlBombas);
    // imprimirPosBombas(posBombas);
    inicializarTablero(tablero, posBombas);
    contarBombasVecinas(tablero);//para contar las bombas vecinas, 1ro deboi haber cargado quienes eran bombas
    // impirmirPrueba(tablero);

    return 0;
}

void contarBombasVecinas(casilla tablero[][LADOS]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){
            if(j<LADOS-1)
                tablero[i][j].bombasVecinas+=tablero[i][j+1].esBomba;
            if(j>0)
                tablero[i][j].bombasVecinas+=tablero[i][j-1].esBomba;

            if(i>0){
                tablero[i][j].bombasVecinas+=tablero[i-1][j].esBomba;//nop poner else porque debo comparar todos los casos
                if(j>0)
                    tablero[i][j].bombasVecinas+=tablero[i-1][j-1].esBomba;
                if(j<LADOS-1)
                    tablero[i][j].bombasVecinas+=tablero[i-1][j+1].esBomba;
            }
            if(i<LADOS -1){
                tablero[i][j].bombasVecinas+=tablero[i+1][j].esBomba;
                if(j>0)
                    tablero[i][j].bombasVecinas+=tablero[i+1][j-1].esBomba;
                if(j<LADOS-1)
                    tablero[i][j].bombasVecinas+=tablero[i+1][j+1].esBomba;
            }
        }
    }
}

void impirmirPrueba(casilla tablero[][LADOS]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esBomba)
                printf("%c \t", CHAR_BOMBA);
            else
                printf("%d \t", tablero[i][j].bombasVecinas);
        }
        printf("\n \n");
    }
}

void inicializarTablero(casilla tablero[][LADOS], punto2D posBombas[]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){

            punto2D nuevoPunto;
            nuevoPunto.fila=i;
            nuevoPunto.columna=j;
            if(buscarPunto(nuevoPunto, posBombas, BOMBAS)==1)//1 si encuentra al punto como bomba
                tablero[i][j].esBomba=1;
            else
                tablero[i][j].esBomba=0;

            tablero[i][j].tieneBandera=0;
            tablero[i][j].esVisible=0;
            tablero[i][j].bombasVecinas=0;
            
        }
    }
}

void imprimirPosBombas(punto2D posBombas[]){
    for(int i=0; i<BOMBAS; i++){
        printf(" bomba %d \t fila %d | columna %d \n", (i+1), posBombas[i].fila, posBombas[i].columna);
    }
}

void elegirBombas(punto2D posBombas[], int *dimlBombas){//no poner bombas entre los corchetes porque lo tendría que poner tmb en el prototipo y es a fin de cuentas innecesario
    punto2D nuevoPunto;
    for(int i=0; i<BOMBAS; i++){// <= para cargar todas las bombas
        nuevoPunto.fila=rand()%(LADOS);
        nuevoPunto.columna=rand()%(LADOS);
        if( buscarPunto(nuevoPunto, posBombas, (*dimlBombas)) == 0){
            (*dimlBombas)++;
            posBombas[(*dimlBombas)-1]=nuevoPunto;//cargo al final, diml representa la cant de elementos
        }
        else
            i--;//repito paso

    }
}

int buscarPunto(punto2D nuevoPunto, punto2D posBombas[], int dimlBombas){
    int i=0, encontre=0;
    while(i<=dimlBombas && encontre==0){
        if(posBombas[i].columna == nuevoPunto.columna && posBombas[i].fila==nuevoPunto.fila)
            encontre=1;
        i++;//no olvidar de avanzar
    }
    return encontre;
}
