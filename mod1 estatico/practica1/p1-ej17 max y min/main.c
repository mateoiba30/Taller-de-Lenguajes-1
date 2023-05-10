#include <stdio.h>
#include <stdlib.h>
void ingresar_flotantes(int n, float * max, float * min){
    float x;

    for(int i=1; i<=n; i++){
        printf("ingrese el flotante %d:\n",i);
        scanf("%f", &x);
        if(x>=*max)
            *max=x;
        else
            if(x<=*min)
                *min=x;
    }
}
int main()
{
    int n;
    float max=-9999, min=9999;

    printf("Ingrese la cantidad de flotantes a ingresar: ");
    scanf("%d", &n);
    ingresar_flotantes(n,&max,&min);
    printf("el maximo es: %f \t el minimo es: %f\n",max,min);

    return 0;

}
