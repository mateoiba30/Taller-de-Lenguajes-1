#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include<windows.h>
#endif
// #include <time.h> //para probar codigo elijo pseudoaleatoriamiente

#define BOMBAS 10
#define LADOS 8
#define CHAR_BOMBA 229//EB
#define CHAR_OCULTA 177//B1
#define CHAR_BANDERA 16

// i es fila
//j es para columna
//1 para verdadero

typedef enum {CORRECTO, PERDER, COLUMNA_INV, FILA_INV, ACCION_INV, CASILLA_REP} estados;

typedef enum {EXCAVAR, BANDERA} acciones;

typedef enum {A, B, C, D, E, F, G, H} columnas;

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

void realizarJugada(casilla[][LADOS], punto2D[], int*, estados*);
void inicioJuego(casilla[][LADOS], punto2D[]);
void visualizarBombas(casilla[][LADOS]);

void limpiar_pantalla();
void imprimirTitulo();
void mostrarTablero(casilla[][LADOS]);

void revelarTablero(casilla[][LADOS]);
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
    inicializarTablero(tablero, posBombas);
    contarBombasVecinas(tablero);//para contar las bombas vecinas, 1ro deboi haber cargado quienes eran bombas
    inicioJuego(tablero, posBombas);

    return 0;
}

void realizarJugada(casilla tablero[][LADOS], punto2D posBombas[], int* cantBombasAcertadas, estados *estado){
    int fila, columna, accion;
    *estado=CORRECTO;
    char columna_char;

    printf("accion ->");
    scanf("%d",&accion);

    if(accion!=0 && accion!=1){
        *estado=ACCION_INV;
        return;
    }

    printf("fila   ->");
    scanf("%d",&fila);

    if(fila>=LADOS || fila <0){
        *estado=FILA_INV;
        return;
    }

    printf("columna->");
    scanf(" %c", &columna_char);//PONER UN ESPACIO ANTES DE %C Y LUEGO GETCHAR PARA ELER SIN ERRORES!!!
    getchar();

    switch(columna_char){
        case 'A':columna=A; break;
        case 'B':columna=B; break;
        case 'C':columna=C; break;
        case 'D':columna=D; break;
        case 'E':columna=E; break;
        case 'F':columna=F; break;
        case 'G':columna=G; break;
        case 'H':columna=H; break;
        default: (*estado)=COLUMNA_INV; return; break;
    }

    if(accion==EXCAVAR){
        if(tablero[fila][columna].esBomba)
            (*estado)=PERDER;
        else{
            if(tablero[fila][columna].esVisible)
                *estado=CASILLA_REP;           
            else
                tablero[fila][columna].esVisible=1; 
        }
    }
    else{
        tablero[fila][columna].tieneBandera^=1;//cambio el estado con XOR
        if(tablero[fila][columna].esBomba)
            if(tablero[fila][columna].tieneBandera)
                (*cantBombasAcertadas)++;
            else    
                (*cantBombasAcertadas)--;
    }
}

void inicioJuego(casilla tablero[][LADOS], punto2D posBombas[]){
    int cantBombasAcertadas=0, perder=0, equivocado;
    estados estado=CORRECTO;
    while(cantBombasAcertadas!=BOMBAS && estado!=PERDER){
        mostrarTablero(tablero);
        switch(estado){
            case CASILLA_REP: printf("CASILLA REPETIDA\n"); break;//muestro desp de actualizar
            case FILA_INV: printf("FILA INVALIDA\n"); break;
            case COLUMNA_INV: printf("COLUMNA INVALIDA\n"); break;
            case ACCION_INV: printf("accion invalida\n"); break;
        }
        realizarJugada(tablero, posBombas, &cantBombasAcertadas, &estado);
    }
        visualizarBombas(tablero);
        mostrarTablero(tablero);
    if(cantBombasAcertadas==BOMBAS)
        printf("FELICITACIONES, GANASTE !!!\n ");
    else
        printf(" PERDISTE, FIN DEL JUEGO \n");

}

void visualizarBombas(casilla tablero[][LADOS]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esBomba)
                tablero[i][j].esVisible=1;
        }
    }
}

void limpiar_pantalla(){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void imprimirTitulo(){
    printf("--------------------\n");
    printf("|    BUSCA MINAS   |\n");
    printf("--------------------\n");
    printf("0 para excavar, 1 para poner/sacar bandera\n\n");

}

void mostrarTablero(casilla tablero[][LADOS]){
    limpiar_pantalla();
    imprimirTitulo();

    printf("\tA\tB\tC\tD\tE\tF\tG\tH\n\n");
    for(int i=0; i<LADOS; i++){
        printf("%d\t", i);
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esVisible){
                if(tablero[i][j].esBomba)
                    revelarTablero(tablero);
                else
                    printf("%d \t", tablero[i][j].bombasVecinas);
            }
            else{
                if(tablero[i][j].tieneBandera)
                    printf("%c \t", CHAR_BANDERA);
                else
                    printf("%c \t", CHAR_OCULTA);
            }           
        }
        printf("\n\n\n");
    }
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

void revelarTablero(casilla tablero[][LADOS]){
    limpiar_pantalla();
    imprimirTitulo();
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
