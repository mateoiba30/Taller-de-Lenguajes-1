#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int finCaracter(char[]);

int main()
{
    char palabra[255];
    int cont=0;

    printf("Ingrese una palabra: (hasta ingresar 'ZZZ') ");
    scanf("%s", palabra);
    while(strcmp(palabra,"ZZZ")){
        if(finCaracter(palabra))
            cont++;
        printf("Ingrese otra palabra: ");
        scanf("%s", palabra);
    }

    printf("La cantidad de palabras terminadas en 'o' es de= %d\n", cont);

    return 0;
}

int finCaracter(char palabra[]){
    int result=1;
    int longitud=strlen(palabra);
    if (palabra[longitud-1]=='o')
        result=0;
    return result;

}
