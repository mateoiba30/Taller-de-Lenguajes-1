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

void numtoTxt(int nro, char texto[]){
    char texto2[255]=" y ";
    char *especiales[16]={"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez", "once", "doce", "trece", "catorce", "quince"};
    char *decenas[9]={"diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};

    if(nro<16)
        strcpy(texto, especiales[nro]);
    else{
        strcpy(texto, decenas[nro/10 - 1]);//la pos cero tiene diez
        if((nro%10)!=0){
            strcat(texto, texto2);
            strcpy(texto2, especiales[nro%10]);
            strcat(texto, texto2);
        }

    }

}

int digitos(int nro){
    int contador=0;
    if(nro==0)
        return 1;
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
