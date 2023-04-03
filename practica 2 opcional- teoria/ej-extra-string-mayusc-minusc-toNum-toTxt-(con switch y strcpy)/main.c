#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void numtoTxt(int, char[]);
int digitos(int);
void numToStr(int, char[]);
void upperStr(char[]);
void lowerStr(char[]);

int main()
{
    //minusculas entre 97 y 122
    //mayusculas entre 65 y 90
    srand(time(NULL));

    int nro;
    char palabra[255], cadena[11], texto[255];

    printf("ingrese una palabra: \n");
    scanf("%s", palabra);

    upperStr(palabra);
    printf("la palabra en mayusculas es: %s\n", palabra);
    lowerStr(palabra);
    printf("la palabra en minusculas es: %s\n", palabra);

    printf("Ingrese un numero entero entre 0 y 99: \n");
    scanf("%d", &nro);
    numToStr(nro, cadena);
    printf("el texto del numero es: %s\n", cadena);
    numtoTxt(nro, texto);
    printf("el numero en palabras es: %s ", texto);
    return 0;
}

void especiales(char texto[],int nro){
    switch(nro){
        case 1: strcpy(texto,"uno"); break;
        case 2: strcpy(texto,"dos"); break;
        case 3: strcpy(texto,"tres"); break;
        case 4: strcpy(texto,"cuatro"); break;
        case 5: strcpy(texto,"cinco"); break;
        case 6: strcpy(texto,"seis"); break;
        case 7: strcpy(texto,"siete"); break;
        case 8: strcpy(texto,"ocho"); break;
        case 9: strcpy(texto,"nueve"); break;
        case 10: strcpy(texto,"diez"); break;
        case 11: strcpy(texto,"once"); break;
        case 12: strcpy(texto,"doce"); break;
        case 13: strcpy(texto,"trece"); break;
        case 14: strcpy(texto,"catorce"); break;
        case 15: strcpy(texto,"quince"); break;
    }
}

void decenas(char texto[], int nro){
    switch(nro){
        case 1: strcpy(texto,"diez"); break;
        case 2: strcpy(texto,"veinte"); break;
        case 3: strcpy(texto,"treinta"); break;
        case 4: strcpy(texto,"cuarenta"); break;
        case 5: strcpy(texto,"cincuenta"); break;
        case 6: strcpy(texto,"sesenta"); break;
        case 7: strcpy(texto,"setenta"); break;
        case 8: strcpy(texto,"ochenta"); break;
        case 9: strcpy(texto,"noventa"); break;
    }
}

void numtoTxt(int nro, char texto[]){
    char texto2[255];

    if(nro<16)
        especiales(texto, nro);
    else{
        decenas(texto, nro/10);
        if((nro%10)!=0){
            strcpy(texto2," y ");
            strcat(texto, texto2);
            especiales(texto2, nro%10);
            strcat(texto, texto2);
        }

    }

}

int digitos(int nro){
    int contador=0;

    while(nro>0){
        nro/=10;
        contador++;
    }
    return contador;
}
void numToStr (int nro, char cadena[]){
    int i=0, caracts;

    caracts=digitos(nro);

    cadena[caracts]='\0';
    for(i=caracts-1 ;i>=0; i-- ){
        cadena[i]=nro%10 + 48;//el problema
        nro/=10;
    }

}

void upperStr(char palabra[]){
    int i=0;
    while(palabra[i]!='\0'){
        if((palabra[i]>96)&&(palabra[i]<123))//modifico solo las minusculas
            palabra[i]=palabra[i]-32;
        i++;
    }
}

void lowerStr(char palabra[]){
    int i=0;
    while(palabra[i]!='\0'){
        if((palabra[i]>64)&&(palabra[i]<91))
            palabra[i]=palabra[i]+32;
        i++;
    }
}
