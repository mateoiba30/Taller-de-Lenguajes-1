#include <stdio.h>
#include <stdlib.h>
#define DIMF 20
#define NRO 15

void cargarVector(int[]);
float procesarPromedio(int[]);
float procesarMinimo(int[]);
int procesarPosMax(int[]);

int main()
{
    int pos_max;
    float vector[DIMF], prom, min;
    cargarVector(vector);
    prom=procesarPromedio(vector);
    min=procesarMinimo(vector);
    pos_max=procesarPosMax(vector);

    return 0;
}
void cargarVector(int vector[]){
    int i;
    for(i=0; i<DIMF; i++){
        vector[i]=(float)rand()/NRO;//para que haga un float
    }
}
float procesarPromedio(int vector[]){

    float prom=0;
    for (int i=0; i<DIMF; i++)
        prom+=vector[i];
    prom/=DIMF;
    return prom;
}
float procesarMinimo(int vector[]){

    float min=9999;
    for (int i=0; i<DIMF; i++){
        if (vector[i] < min)
            min=vector[i];
    }
    return min;
}

int procesarPosMax(int vector[]){

    float max=9999;
    int pos_max=-1;

    for (int i=0; i<DIMF; i++){
        if(vector[i]> max){
           max=vector[i];
           pos_max=i;
        }
    }
    return pos_max;
}
