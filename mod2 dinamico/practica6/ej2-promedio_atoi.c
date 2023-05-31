#include <stdio.h>
#include <stdlib.h>
#define CANT 4

int verDigs(char *);
int pasarANum(int, char *);

int main (int argc, char * argv[]) {
    float promedio=0;
    int digs;

    if(argc!=CANT+1)
        printf("se deben pasar 4 parametros\n");
    else{
        for(int i=1; i<CANT+1; i++){//empezar en 1!!!
            digs=verDigs(argv[i]);
            printf("%d  ", atoi(argv[i]));//atoi funciona igual que las 2 funciones que hice !!!
            promedio+=pasarANum(digs, argv[i]);
        }
        printf("promedi: %f\n", promedio/CANT);
    }
    return 0;
}

int verDigs(char * string){
    int digs=0, i=0;
    while(string[i]!='\0'){
        digs++;
        i++;
    }
    return digs;
}

int pasarANum(int digs, char * string){
    int mult=1, i=0, num=0;
    char aux='0';

    for(int j=0; j<digs-1; j++)//si tengo 2 digs, mult 1ro vale 10
        mult=mult*10;

    while(string[i]!='\0'){
        num+= (string[i]-aux)*mult;
        mult=mult/10;
        i++;
    }

    return num;
    
}