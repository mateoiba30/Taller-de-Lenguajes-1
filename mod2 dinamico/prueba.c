#include <stdlib.h>
#include <stdio.h>
#define F 5
#define C 4
int main(){

    int *mU;
    int i=2,  j=1;

    mU=malloc(F*C*sizeof(int));

    mU[i*C+j]=7;


    printf("%d\n", mU[i*C+j]);
 
    return 0;
}