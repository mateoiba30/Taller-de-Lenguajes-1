#include <stdio.h>
#include <stdlib.h>
#define DIMF 20
#define NRO 15

void imprimirVecotr(float[]);
void cargarVector(float[]);
void procesarVector(float[], float*, float*, int*);
float procesarPromedio(float[]);
float procesarMinimo(float[]);
int procesarPosMax(float[]);

int main()
{
    srand(time(NULL));
    int pos_max;
    float vector[DIMF], prom, min;

    cargarVector(vector);
    imprimirVector(vector);

    procesarVector(vector, &prom, &min, &pos_max);
    printf("promedio: %2.2f \n minimo: %2.2f \n posicion maxima: %d", prom, min, pos_max);

    return 0;
}
void imprimirVector(float vector[]){
    int i;
    for(i=0; i< DIMF; i++)
        printf("%2.2f \n", vector[i]);
}
void cargarVector(float vector[]){
    int i;
    for(i=0; i<DIMF; i++){
        vector[i]=(float)rand()/NRO;//para que haga un float
    }
}
void procesarVector(float vector[], float *prom, float *min, int *pos_max){
    *prom=procesarPromedio(vector);
    *min=procesarMinimo(vector);
    (*pos_max)=procesarPosMax(vector);
}

float procesarPromedio(float vector[]){

    float prom=0;
    for (int i=0; i<DIMF; i++)
        prom+=vector[i];
    prom/=DIMF;
    return prom;
}
float procesarMinimo(float vector[]){

    float min=9999;
    for (int i=0; i<DIMF; i++){
        if (vector[i] < min)
            min=vector[i];
    }
    return min;
}

int procesarPosMax(float vector[]){

    float max=-999999;
    int pos_max=-1;

    for (int i=0; i<DIMF; i++){
        if(vector[i]>=max){
           max=vector[i];
           pos_max=i;
        }
    }
    return pos_max;
}
