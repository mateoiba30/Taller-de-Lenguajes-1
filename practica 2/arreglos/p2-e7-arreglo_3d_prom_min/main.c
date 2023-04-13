#include <stdio.h>
#include <stdlib.h>
#define ANIOS 10
#define MESES 12
#define DIAS 30
#include <time.h>

int buscarMenorPromAnios(float []);
void informarMesesMinimos(int[]);
void verMinimo(int*, float*, float, int);
void recorrerPrecipitaciones(float[][MESES][DIAS], int[], float[]);
void cargarPrecipitaciones(float [][MESES][DIAS]);
void imprimirPrecipitaciones(float [][MESES][DIAS]);

int main()
{
    srand(time(NULL));

    float prom_anios[ANIOS]={0},precipitaciones [ANIOS][MESES][DIAS]={0};;//en cada anio guarda el prom de precipitaciones //inicializamos en cero
    int min_mes_anios[ANIOS]={0};//en cada a�o guarda el minimo mes

    cargarPrecipitaciones(precipitaciones);
 //   imprimirPrecipitaciones(precipitaciones);
    recorrerPrecipitaciones(precipitaciones, min_mes_anios, prom_anios);
    informarMesesMinimos(min_mes_anios);
    printf("El anio con menor promedio de precipitaciones fue: %d", buscarMenorPromAnios(prom_anios));

    return 0;
}

int buscarMenorPromAnios(float prom_anios[]){
    int i, posMin=-1;
    float min_prom=99999;
    for(i=0; i<ANIOS; i++){
        verMinimo(&posMin, &min_prom, prom_anios[i], i);
    }
    return (posMin+1);//para que enero sea la pos 1 y no la pos 0
}

void informarMesesMinimos( int min_mes_anios[]){
    int i;
    for(i=0; i<ANIOS; i++){
        printf("En el anio %d el mes con menor precipitaciones fue: %d\n", i+1, min_mes_anios[i]);
    }
}

void verMinimo(int *posMin, float *valorMin, float contPos, int Pos){
    if(contPos<= (*valorMin)){
        (*valorMin)=contPos;
        (*posMin)=Pos;
    }
}

void recorrerPrecipitaciones (float precipitaciones[][MESES][DIAS], int min_mes_anios[], float prom_anio[]){
    int i, j, k, posMinPresMes=-1;
    float contPresMes=0, contPresAnio=0,minPresMes=99999;

    for(i=0; i<ANIOS; i++){
        contPresAnio=0;

        for(j=0; j<MESES; j++){
            contPresMes=0;
            minPresMes=9999;
            posMinPresMes=-1;

            for(k=0; k<DIAS; k++){
                contPresMes+=precipitaciones[i][j][k];

            }
            verMinimo(&posMinPresMes, &minPresMes, contPresMes, j);
            contPresAnio+=contPresMes;
        }
       // printf("%d\n", posMinPresMes+1); //LO USE PARA CHEQUEAR DATOS
        prom_anio[i]=contPresAnio/MESES;
        //printf("promedio del anio %d = %f \n", i+1, prom_anio[i]); LO USE PARA CHEQUEAR DATOS
        min_mes_anios[i]=posMinPresMes+1;//ahora 1 corresponde a Enero, y no el cero

    }
}

void cargarPrecipitaciones(float precipitaciones[][MESES][DIAS]){
    int i, j, k;
    for(i=0; i<ANIOS; i++){
        for(j=0; j<MESES; j++){
            for(k=0; k<DIAS; k++){
                precipitaciones[i][j][k]=(float)rand()/150;//para hacer nros float
            }
        }
    }
}

void imprimirPrecipitaciones(float precipitaciones[][MESES][DIAS]){
    int i, j, k;
    for(i=0; i<ANIOS; i++){
        for(j=0; j<MESES; j++){
            for(k=0; k<DIAS; k++){
                printf("fecha: %d / %d / %d = %2.2f \n", (k+1), (j+1), (i+1), precipitaciones[i][j][k]);
            }
        }
    }
}
