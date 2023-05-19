#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMPARACIONES 8
enum {PROMEDIO, MINIMO, MAXIMO};

void escribirArchivo(FILE *, float [][COMPARACIONES], char [][255]);
void  calcularPromedio(float[][COMPARACIONES], int);
void leerDatos(FILE *, float[][COMPARACIONES], char[][255]);

int main(){
    FILE *f, *reporte;
    float mResultados[3][COMPARACIONES]={0};//datos a mostrar
    char inicio[COMPARACIONES][255];//si uso char * NO OLVIDAR DE RESERVAR MEMORIA!

    f = fopen("vinos.csv", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }
    leerDatos(f,mResultados, inicio);
    fclose(f);

    reporte = fopen("reporte_vinos.txt", "w");
    if (reporte == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    escribirArchivo(reporte, mResultados, inicio);
    fclose(reporte);
    
    return 0;
}

void escribirArchivo(FILE *reporte, float mResultados[][COMPARACIONES], char inicio[][255]){
    fprintf(reporte, "Atributo \t\t\t");
    for(int i=0; i<=COMPARACIONES; i++){
        fprintf(reporte, "|%s\t\t", inicio[i]);
    }
    fprintf(reporte, "\n");

    for(int j=PROMEDIO; j<=MAXIMO; j++){
        switch(j){
            case PROMEDIO: fprintf(reporte, "Promedio\t\t\t"); break;
            case MINIMO: fprintf(reporte,   "Minimo  \t\t\t"); break;
            case MAXIMO: fprintf(reporte,   "Maximo  \t\t\t"); break;
        }
        for(int k=0; k<COMPARACIONES; k++){
            fprintf(reporte, "%f\t\t\t", mResultados[j][k]);
        }
        fprintf(reporte, "\n");
    }

}

void  calcularPromedio(float mResultados[][COMPARACIONES], int cantElementos){
    for(int i=0; i<COMPARACIONES; i++){
        mResultados[PROMEDIO][i]=mResultados[PROMEDIO][i]/cantElementos;
    }

}

void leerDatos(FILE *f, float mResultados[][COMPARACIONES], char inicio[][255]){
    char aux[15];
    float vActual[COMPARACIONES];
    int cantElementos=0;
    int i;

    for(i=0; i<COMPARACIONES; i++){
        fscanf(f, "%[^;];", inicio[i]);// voy hasta el ;, y después lo desscarto
        // printf("inicio[%d] = %s\n", i, inicio[i]);//pa debuguear
    }
    fgets(aux, 5, f);//están las comparaciones que quiero y una mas
    
    while (!feof(f)){
        for(int i=0; i<COMPARACIONES; i++){//la 1er vez que entra al while, hay error en la 1er iteracion del for
            fscanf(f, "%f;", &vActual[i]);
        }
        fscanf(f, "%s", aux);//leo el tipo de vino

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