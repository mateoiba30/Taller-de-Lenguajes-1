#include <stdlib.h>
#include <stdio.h>
#define MAX_SINONIMOS 10
#define TAM_PALABRA 50

typedef struct{
    char palabra [TAM_PALABRA+1];
    char cant_sinonimos;
    char sinonimos [MAX_SINONIMOS][TAM_PALABRA +1];
} sinonimos_t;

int main(){

    char *p; char c; char s[10];

    // c="z";
    p=s+5;