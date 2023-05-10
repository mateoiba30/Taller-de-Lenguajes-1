#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    srand(time(NULL));//para que siempre siga randoms distintos

    for (int i=1; i<=15; i++){
        x=rand();
        printf("numero %d: %d \n",i,x);
    }

    return 0;
}
