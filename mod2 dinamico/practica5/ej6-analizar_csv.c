#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMPARACIONES 8
enum {PROMEDIO, MINIMO, MAXIMO};

void escribirArchivo(FILE *, float [][COMPARACIONES], char *[]);
void  calcularPromedio(float[][COMPARACIONES], int);
void recibirDatos(FILE *, float[][COMPARACIONES], char*[]);

int main(){
    FILE *f, *reporte;
    float mResultados[3][COMPARACIONES]={0};//datos a mostrar
    char * inicio[COMPARACIONES];
    f = fopen("vinos.csv", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }
    // recibirDatos(f,mResultados, inicio);

    reporte = fopen("reporte_vinos.txt", "w");
    if (reporte == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    escribirArchivo(reporte, mResultados, inicio);

    fclose(reporte);
    fclose(f);
    return 0;
}

void escribirArchivo(FILE *reporte, float mResultados[][COMPARACIONES], char * inicio[]){
    fprintf(reporte, "Atributo \t");
    for(int i=PROMEDIO; i<=MAXIMO; i++){
        fprintf(reporte, "%s\t", inicio[i]);
    }

    for(int j=0; j<3; j++){
        switch(j){
            case PROMEDIO: fprintf(reporte, "Promedio\t"); break;
            case MINIMO: fprintf(reporte, "Minimo\t"); break;
            case MAXIMO: fprintf(reporte, "Maximo\t"); break;
        }
        for(int k=0; k<COMPARACIONES; k++){
            fprintf(reporte, "%f\t", mResultados[j][k]);
        }
        fprintf(reporte, "\n");
    }

}

void  calcularPromedio(float mResultados[][COMPARACIONES], int cantElementos){
    for(int i=0; i<COMPARACIONES; i++){
        mResultados[PROMEDIO][i]=mResultados[PROMEDIO][i]/cantElementos;
    }

}

void recibirDatos(FILE *f, float mResultados[][COMPARACIONES], char * inicio[]){
    char aux[15];
    float vActual[COMPARACIONES];
    int cantElementos=0;

    for(int i=0; i<COMPARACIONES; i++)
        fscanf(f, "%s;", inicio[i]);
    
    while (!feof(f)){
        for(int i=0; i<COMPARACIONES; i++)
            fscanf(f, "%f;", vActual[i]);
        fgets(aux, 15, f);//leo el tipo de vino

        for(int j=0; j<COMPARACIONES; j++){
            if(vActual[j]>mResultados[MAXIMO][j])
                mResultados[MAXIMO][j]=vActual[j];

            if(vActual[j]<mResultados[MINIMO][j])
                mResultados[MINIMO][j]=vActual[j];

            mResultados[PROMEDIO][j]+=vActual[j];
            cantElementos++;
        }

    }
    calcularPromedio(mResultados, cantElementos);

}