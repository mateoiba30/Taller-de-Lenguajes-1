#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculopi(){
    int a;
    double pi=3;
    register int i;

    for(i=1; i<=100; i++){
        a=2*i;
        pi=pi + (double)(pow(-1,i+1)*4) / (a*(a+1)*(a+2));
    }

    return pi;
}
int main()
{
    printf("aproximacion de PI: %.16Lf \n", calculopi());
    return 0;
}
//anda con float o con double, CUAL ES MEJOR??
