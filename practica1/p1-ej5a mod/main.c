#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i=1; i<=50; i++){
        if(i % 5==0){
            printf("%d \n",i);
        }
    }
    return 0;
}
