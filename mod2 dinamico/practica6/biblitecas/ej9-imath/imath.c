#include <stdio.h>
#include "imath.h"//no olvidar

int potencia(int x, int y){
    for(int i=1; i<y; i++)
        x=x*x;
    return x;
}

int cuadrado(int x){
    return x*x;
}

int cubo(int x){
    return x*x*x;
}

int absoluto(int x){
    if(x<0)
        x=x*(-1);
    return x;
}

int factorial(int x){
    int fac=1;
    for(int i=2; i<=x; i++)
        fac=fac*i;
    return fac;
}

int sumatoria(int x){
    int suma=0;
    for(int i=0; i<=x; i++)
        suma+=i;
    return suma;
}

int multiplo(int x, int y){
    return !(x % y) ;
}

int divisor(int x, int y){
    return !(y % x);
}

int par(int x){
    return !(x % 2);
}

int impar(int x){
    return (x % 2);
}