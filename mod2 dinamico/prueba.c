#include <stdlib.h>
#include <stdio.h>
#define TOKENCONCAT(a, b) a##b
#define aux "

int main(){

    int *mU, **mB, m[5][5]={0};

    mU=malloc(5*5*sizeof(int));

    mB=malloc(sizeof(void*)*5);
    for(int i=0; i<5; i++){
        mB[i]=malloc(sizeof(int)*5);
    }

    //1er elemento
    printf("%d %d %d\n", mU[0], mB[0][0], m[0][0]);

    int i=4,  j=6;
    printf("%d %d %d\n", mU[i*5 + j], mB[i][j], m[i][j]);

    // char * OK="hola";

    // printf("%s %s %s", TOKENCONCAT(TOKENCONCAT(aux,K), TOKENCONCAT(O,aux)));   
    return 0;
}