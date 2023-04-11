#include <stdio.h>
typedef enum { IZQUIERDA, CENTRO_H, DERECHA } AlineacionHorizontal;
typedef enum { ARRIBA=1, CENTRO_V, ABAJO } AlineacionVertical;
typedef enum { DOS=2, CERO=0, UNO, MENOS_UNO=-1, OTRO } Numeros;//SE PUEDEN NUMERO NEGATIVOS!!
typedef enum { LET_A = 'A', LET_B, LET_Z = 'Z' } Letras;//SOLO PUEDEN SER CARACTERES

int main(){

    // printf("%d ", IZQUIERDA);
    // printf("%d ", CENTRO_H);
    // printf("%d ", DERECHA);

    // printf("%d ", ARRIBA);
    // printf("%d ", CENTRO_V);
    // printf("%d ", ABAJO);

    // printf("%d ", DOS);
    // printf("%d ", CERO);
    // printf("%d ", UNO);
    // printf("%d ", MENOS_UNO);
    // printf("%d ", OTRO);

    printf("%c ", LET_A);
    printf("%c ", LET_B);
    printf("%c ", LET_Z);

    return 0;
}