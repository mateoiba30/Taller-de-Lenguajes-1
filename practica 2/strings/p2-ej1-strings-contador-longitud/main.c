#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra[255];
    int cont_5=0;

    printf("Ingrese una palabra: (hasta ingresar 'ZZZ') ");
    scanf("%s", palabra);
    while(strcmp(palabra,"ZZZ")){
        if(strlen(palabra)==5)
            cont_5++;
        printf("Ingrese otra palabra: ");
        scanf("%s", palabra);
    }

    printf("La cantidad de palabras con 5 digitos es de= %d\n", cont_5);

    return 0;
}
