#include <stdio.h>
#include <stdlib.h>
# define cant_paises 4

int main()
{
    int i, cont_especies=0;
    struct{
        int codigo, cant_especies;
    } pais;

    for(i=1; i<=cant_paises; i++){
        printf("PAIS %d \n", i);
        printf("codigo: ");
        scanf("%d", &pais.codigo);
        printf("cantidad de especies: ");
        scanf("%d", &pais.cant_especies);
        printf("\n\n");

        if(pais.cant_especies>=40)
            cont_especies++;
    }
    printf("\n\n");
    printf("el porcentaje de paises con mas de 40 especies es de: %.3f", ((float)cont_especies/cant_paises)*100 );

    return 0;
}
