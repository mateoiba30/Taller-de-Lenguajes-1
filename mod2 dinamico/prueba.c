#include <stdio.h>
#define MACRO(x) x=1

int main(){
    printf("%d", 6);

    #ifdef MACRO
        printf("macro definida\n");
        printf("chau\n");
    #endif
}

