#include <stdio.h>
// #include <unistd.h> //sirve para hacer delays en microsegundos
#include <stdlib.h>
#ifdef _WIN32
#include<windows.h>
#endif
#include <time.h> //para probar codigo elijo pseudoaleatoriamiente

#define BOMBAS 10
#define LADOS 8
#define CHAR_BOMBA 162
#define CHAR_OCULTA 177//B1
#define CHAR_BANDERA 16

// i es fila
//j es para columna
//1 para verdadero

typedef enum {CORRECTO, PERDER, COLUMNA_INV, FILA_INV, ACCION_INV, CASILLA_REP, GANAR, TIENE_BANDERA, YA_EXCAVADA} estados;

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

//JUGAR
void excavarRecursivo(casilla[][LADOS], int, int);
void realizarJugada(casilla[][LADOS], punto2D[], int*, estados*, int*);
void inicioJuego(casilla[][LADOS], punto2D[]);
void revelarBombas(casilla[][LADOS]);

//PANTALLA
void limpiar_pantalla();
void imprimirTitulo();
void mostrarTablero(casilla[][LADOS], int);
void revelarTablero(casilla[][LADOS]);
void imprimirPosBombas(punto2D[]);

//INICIALIZAR
void inicializarTablero(casilla[][LADOS], punto2D[]);
void contarBombasVecinas(casilla[][LADOS]);
void elegirBombas(punto2D[], int *);
int buscarPunto(punto2D, punto2D[], int);

int main(){

    srand(time(NULL));  //para probar codigo elijo pseudoaleatoriamiente
    casilla tablero[LADOS][LADOS];
    int dimlBombas=0;//diml es cuantos voy cargando
    punto2D posBombas[BOMBAS];

    elegirBombas(posBombas, &dimlBombas);
    inicializarTablero(tablero, posBombas);
    contarBombasVecinas(tablero);//para contar las bombas vecinas, 1ro deboi haber cargado quienes eran bombas
    inicioJuego(tablero, posBombas);

    return 0;
}

void excavarRecursivo(casilla tablero[][LADOS], int i, int j){

    for(int k=i-1; k<=i+1; k++){
        for(int l=j-1; l<=j+1; l++){

            if(k<LADOS && k>=0 && l<LADOS && l>=0 && tablero[k][l].esVisible==0){//CHEQUEO LOS HERMANOS EXTERIORES ESTEN EN CONDICIONES PARA MANDARLOS
                tablero[k][l].esVisible=1;
                if(tablero[k][l].bombasVecinas==0)      //!(k==i && l==j) es como preguntar si es visible
                    excavarRecursivo(tablero, k, l);
            }

        }
    }
}


void realizarJugada(casilla tablero[][LADOS], punto2D posBombas[], int* cantBombasAcertadas, estados *estado, int* contadorBanderas){
    int fila, accion;
    *estado=CORRECTO;
    char columna;

    // usleep(1000000); // pa debuguear

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
    scanf(" %c", &columna);//PONER UN ESPACIO ANTES DE %C Y LUEGO GETCHAR PARA ELER SIN ERRORES!!!
    getchar();

    // printf("%x %x %x \n", accion, fila, columna_char); // pa debuguear
    columna-='A';//paso de caracter a numero

    if(accion==EXCAVAR){
        if(tablero[fila][columna].esBomba)
            (*estado)=PERDER;
        else{
            if(tablero[fila][columna].esVisible)
                *estado=CASILLA_REP;
            else{
                if(tablero[fila][columna].tieneBandera){//si tiene bandera y quiero excavar, le saco la bandera
                    *estado=TIENE_BANDERA;
                    return;
                }
                tablero[fila][columna].esVisible=1;
                if(tablero[fila][columna].bombasVecinas==0)
                    excavarRecursivo(tablero, fila, columna);
            }
        }
    }
    else{//poner bandera
        if(tablero[fila][columna].esVisible){//si ya excavé, no puedo poner bandera
                *estado=CASILLA_REP;
        }
        else{
            if(tablero[fila][columna].tieneBandera){
                tablero[fila][columna].tieneBandera=0;
                (*contadorBanderas)--;
            }
            else{
                tablero[fila][columna].tieneBandera=1;
                (*contadorBanderas)++;
            }
            if(tablero[fila][columna].esBomba){
                if(tablero[fila][columna].tieneBandera)
                    (*cantBombasAcertadas)++;
                else
                    (*cantBombasAcertadas)--;
            }
            if(*cantBombasAcertadas==BOMBAS && *contadorBanderas==BOMBAS)//para ganar no hay que poner banderas demás, sinó re fácil
                *estado=GANAR;
        }
    }
}

void inicioJuego(casilla tablero[][LADOS], punto2D posBombas[]){
    int cantBombasAcertadas=0, perder=0, equivocado, contadorBanderas=0;
    estados estado=CORRECTO;
    while(estado!=GANAR && estado!=PERDER){//si una no se cumple, termino
        mostrarTablero(tablero, contadorBanderas);
        switch(estado){
            case CASILLA_REP: printf("CASILLA REPETIDA\n"); break;//muestro desp de actualizar
            case FILA_INV: printf("FILA INVALIDA\n"); break;
            case COLUMNA_INV: printf("COLUMNA INVALIDA\n"); break;
            case ACCION_INV: printf("ACCION INVALIDA\n"); break;
            case TIENE_BANDERA: printf("CASILLA CON BANDERA\n"); break;
        }
        realizarJugada(tablero, posBombas, &cantBombasAcertadas, &estado, &contadorBanderas);
    }

    revelarBombas(tablero);
    if(estado==GANAR)
        printf("FELICITACIONES, GANASTE !!!\n ");
    else//PERDER
        printf(" PERDISTE, FIN DEL JUEGO \n");

}

void revelarBombas(casilla tablero[][LADOS]){
    limpiar_pantalla();
    imprimirTitulo();

    printf("\t\tA\tB\tC\tD\tE\tF\tG\tH\n\n");
    printf("\t----------------------------------------------------------------------\n\t|\n\t|\n");
    for(int i=0; i<LADOS; i++){
        printf("%d\t|\t", i);
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esVisible || tablero[i][j].esBomba){
                if(tablero[i][j].esBomba)
                    printf("%c \t", CHAR_BOMBA);
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
        printf("\n\t|\n\t|\n");
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
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t|    BUSCA MINAS   |\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t0 para excavar, 1 para poner/sacar bandera\n\n\n\n");

}

void mostrarTablero(casilla tablero[][LADOS], int contadorBanderas){
    limpiar_pantalla();
    imprimirTitulo();

    printf("\t\tA\tB\tC\tD\tE\tF\tG\tH\n\n");
    printf("\t----------------------------------------------------------------------\n\t|\n\t|\n");
    for(int i=0; i<LADOS; i++){
        printf("%d\t|\t", i);
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esVisible){
                if(tablero[i][j].esBomba)
                    printf("%c \t", CHAR_BOMBA);
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
        printf("\n\t|\n\t|\n");
    }
    printf("\nBanderas colocadas: %d\n", contadorBanderas);
}

void contarBombasVecinas(casilla tablero[][LADOS]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){//recorro todo tablero

            for(int k=i-1; k<=i+1; k++){
                for(int l=j-1; l<=j+1; l++){
                    if(k<LADOS && k>=0 && l<LADOS && l>=0){//CHEQUEO LOS HERMANOS EXTERIORES ESTEN EN CONDICIONES PARA MANDARLOS
                        tablero[i][j].bombasVecinas+=tablero[k][l].esBomba;
                    }
                }
            }

        }
    }
}

void revelarTablero(casilla tablero[][LADOS]){
    for(int i=0; i<LADOS; i++){
        for(int j=0; j<LADOS; j++){
            if(tablero[i][j].esBomba)
                tablero[i][j].esVisible=1;
        }
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
