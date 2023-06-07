#include <stdio.h>
int main()
{
    int i, M[3][2]={{1,2},{3,4},{5,6}};

    // printf("2^5 = %d\n", 2^5);

    for (i=0; i<6; i++){
        printf("i:%d i/2:%d i mod 2:%d    ", i, i/2, i%2);
        printf(" %d \n", M[i/2][i%2]);
    }

    return 0;
}
