#include <stdio.h>
#include <stdlib.h>
#define CANT_DATOS 3

int main()
{
     int i, *datos;

     *datos=1;
     datos++;
     *datos=2;
     datos++;
     *datos=3;
     datos-=2;

     printf("%d\n", datos[0]);

     for(int j=0; j<CANT_DATOS; j++){
        printf("%d\t", *datos);
        datos++;
     }
     datos-=2;

     for (i=0; i<CANT_DATOS; i++){
        *(datos+i)= datos[i]/2;
    }

    for(int j=0; j<CANT_DATOS; j++){
        printf("%d\t", *datos);
        datos++;
     }
     datos-=2;

    return 0;
}
