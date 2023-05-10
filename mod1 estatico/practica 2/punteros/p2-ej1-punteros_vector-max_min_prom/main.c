#include <stdio.h>
#include <stdlib.h>

void procesarArreglo(int[], int*, int*, float*, int );

int main()
{
    int max, min, dimf=5;
    float prom=0;
    int vector[dimf];

    min=9999;
    max=-9999;
    prom=0;

    vector[0] = 80;
    vector[1] = 20;
    vector[2] = 30;
    vector[3] = 40;
    vector[4] = 40;

    procesarArreglo(vector, &max, &min, &prom, dimf);
    printf("maximo: %d   minimo: %d   promedio: %2.2f", max, min, prom);

    return 0;
}

void procesarArreglo(int vector[], int *max, int *min, float *prom, int dimf){

    *prom=0;
    *min=vector[0];
    *max=vector[0];
    for (int i=0; i<dimf; i++){
        *prom+=vector[i];

        if(vector[i]> *max)
           *max=vector[i];
        else if (vector[i] < *min)
            *min=vector[i];
    }
    *prom/=dimf;
}
