#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SQUAREOF(x) (x)*(x)//poner muchos parentesis para que funcione bien

int main() {
 int xin=3;
 printf("\nxin=%i",xin);
 printf("\nSQUAREOF(xin)=%i", SQUAREOF(xin));
 printf("\nSQUAREOF(xin+4)=%i", SQUAREOF(xin+4));
 printf("\nSQUAREOF(xin+xin)=%i", SQUAREOF(xin+xin));
}