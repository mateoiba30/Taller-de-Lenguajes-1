#include<stdio.h>
#include <stdlib.h>

void calcularMinMay(char*, int*, int*);
void leerPalabra(char*);
char* reservar(int);


int main(){

    int n, min=0, may=0;
    char *vector;

    vector=reservar(100);
    
    for(int i=0; i<10; i++){
        min=0;
        may=0;
        leerPalabra(vector);
        calcularMinMay(vector, &min, &may);
        printf("palabra %d minusculas: %d mayusculas: %d \n", i+1, min, may);
    }

    free(vector);

    return 0;
}

void calcularMinMay(char*vector, int* min, int*may){

    int i=0;
    while(vector[i]!='\0'){

        if(vector[i]>='A' && vector[i]<='Z')
            *may=*may+1;
        if(vector[i]>='a' && vector[i]<='z')
            *min=*min+1;

        i++;
    }
}

void leerPalabra( char*vector){
    printf("ingrese una palabra: ");
    gets(vector);
}

char* reservar(int n){
    char *vector;
    vector=(char*)malloc(n*sizeof(char));
    return vector;
}
