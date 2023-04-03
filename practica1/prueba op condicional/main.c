#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main()

{   extern int princesita;

    int j=56,N=8;
    static int c=0;
    c++;
    printf("%d\n", c);

    j++;
    printf("%d \n", (N%2 ? N : N+j));
    return 0; //N%2 siempre va a ser verdadera mas alla del N
 //siempre devuelve el valor de N para N>0 o N impar. debido a que  esos casos el resto de N/2 es cero, y cero se toma por falso
}
