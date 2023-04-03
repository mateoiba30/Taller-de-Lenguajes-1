#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f=0;

    printf("Ingrese una cantidad de kilometros: ");
    scanf("%f", &f);
    f=f/1.61;

    printf("El equivalente en millas es de: %.2f", f);

    return 0;
}
