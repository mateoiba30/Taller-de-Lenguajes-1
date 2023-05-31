#include <stdio.h>
#include <stdlib.h>
#define size 25

void imprimir(int * v, int x){//no puedo poner  void imprimir(int * v, int size){   porque donde encuentra 'size' lo reemplaza por un 25
    int i;
    for (i=0; i<x; i++){
        printf("v[%d]= %d", i, v[i]);
    }
}

int main(){
    int v[size];
    imprimir(v, size);

    return 0;
}
