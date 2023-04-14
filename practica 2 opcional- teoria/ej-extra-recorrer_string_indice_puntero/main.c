#include <stdio.h>
#include <stdlib.h>
#define CANT_DATOS 3

int main()

{
     int i, *datos, vector[3]={1,2,3};

     datos=vector;//asignarles valores reservados por medio de variables

   printf("inicio");
     printf("%d\n", datos[0]);

      printf(" impresion ");
     for(int j=0; j<CANT_DATOS; j++){
        printf("%d\t", *datos);
        datos++;
     }
     datos-=3;

     for (i=0; i<CANT_DATOS; i++){
        *(datos+i)= datos[i]/2;
    }

      printf(" impresion ");

    for(int j=0; j<CANT_DATOS; j++){
        printf("%d\t", *datos);
        datos++;
     }
     datos-=2;

    return 0;
}
