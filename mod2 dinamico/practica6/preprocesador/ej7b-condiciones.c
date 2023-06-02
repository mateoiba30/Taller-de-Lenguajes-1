#include <stdio.h>
#include <stdlib.h>
// #define DEBUG 0
int main(){
    int x= 15;

    while (x<50){
        #if DEBUG //no pregunta si está definido, pregunta si es verdadero, pero es cero (F)
            printf("x= %d", x);
            y= y+1;
        #endif
            x++;
    }

    printf("%d", x);
    
    return 0;
}