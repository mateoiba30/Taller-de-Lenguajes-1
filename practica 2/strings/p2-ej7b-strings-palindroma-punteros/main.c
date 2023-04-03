#include <stdio.h>
#include <stdlib.h>

int palindroma(char*);
int Longitud(char*);

int main()
{
    char *palabra1=NULL;
    palabra1=(char*)malloc(256*sizeof(char));//reserva 256 caracteres en la heap

    printf("ingrese una palabra en minusculas: \n");
    scanf("%255s", palabra1);
    getchar();

    if(palindroma(palabra1)==1)
        printf("es palindroma");
    else
        printf("NO es palindroma");
    return 0;
}

int palindroma(char *palabra1){//devuelve 0 si no es palindroma
    char *aux, *aux2;
    int result=0, longitud, i=0, j=0;

    longitud=Longitud(palabra1);
    aux=palabra1;//no quiero perder el puntero
    aux2=aux+longitud-1;

    while((aux[i]==aux2[i])&&(aux[j] < longitud/2 - 1)){// no es necesario poner *aux <=longitud/2 - 1  porque no es necesario que analice el caracter del medio en caso que la palabra tenga cantidad de caracts impar
        i++;
        j--;//voy retrocediendo en lo q apunta aux 2. no es una pos negativa porque aux2 no es un vector
    }

    if(*aux==*aux2)
        result=1;

    return result;
}

int Longitud(char *palabra1){
    char *aux;
    int cont=0;

    aux=palabra1;//no quiero perder el puntero
    while(*aux != '\0'){
        aux++;
        cont++;
    }
    return cont;
}
