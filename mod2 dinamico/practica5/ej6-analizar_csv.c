#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COMPARACIONES 8
#define RENGLON_MAX 300
typedef enum {PROMEDIO, MINIMO, MAXIMO};

void  calcularPromedio(float[][MAXIMO+1], int);

int main(){
    FILE *f, *reporte;
    int cantElementos=0;
    char aux[RENGLON_MAX], inicio[RENGLON_MAX];

    float mResultados[MAXIMO+1][COMPARACIONES]={0};//datos a mostrar
    float vActual[COMPARACIONES];

    f = fopen("vinos.csv", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }

    fgets(inicio, RENGLON_MAX, f);//descarto el primer renglon
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

    reporte = fopen("reporte_vinos.txt", "w");
    if (reporte == NULL){
        printf ("Error en reporte\n");
        return 1;
    }



    fclose(reporte);
    fclose(f);
    return 0;
}

void  calcularPromedio(float mResultados[][MAXIMO+1], int cantElementos){
    for(int i=0; i<COMPARACIONES; i++){
        mResultados[PROMEDIO][i]=mResultados[PROMEDIO][i]/cantElementos;
    }

}