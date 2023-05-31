#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CIRCULOS 10
#define AREA_CIRCULO(r) 3.14*(r)*(r)

int main(){

    srand(time(NULL));
    for(int i=0; i<CIRCULOS; i++){
        int x=rand()%50;
        // float area= AREA_CIRCULO(x);
        printf("%d) radio %d   area: %d\n", i+1, x, (int)AREA_CIRCULO(x));//no castea bien a las macros, debo ponerle un '(int)' adelante para que lo lea como yo quiera
    }//tmb puedo leer a la aera como flotante

    return 0;
}