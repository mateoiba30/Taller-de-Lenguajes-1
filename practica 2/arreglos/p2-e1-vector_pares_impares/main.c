#include <stdio.h>
#include <stdlib.h>
#define NROS 50
#include <time.h>

void cargarVectores(int []);
void contarParesImpares(int[], int*, int*);

int main()
{
    int vector[NROS], cont_imp=0, cont_p=0;
    srand(time(NULL));
    cargarVector(vector);
    contarParesImpares(vector, &cont_imp, &cont_p);
    printf("La cantidad de impares es de= %d \t y la de pares= %d \n", cont_imp, cont_p);

    return 0;
}

void cargarVector(int vector[]){
    int i;
    for(i=0; i<NROS; i++){
        vector[i]=rand();
    }
}

void contarParesImpares(int vector[], int *cont_imp, int *cont_p){
    int i;
    for(i=0; i<NROS; i++){
        if(vector[i] % 2)
           // *cont_p= *cont_p+1;
            (*cont_p)++;
        else
            *cont_imp=*cont_imp+1;
    }
}
