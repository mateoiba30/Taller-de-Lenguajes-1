#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(){
int *matrizUni, **matrizBid, matrizEst[3][3]={{1,2,3}, {4,5,6}, {7,8,9}};

matrizBid=malloc(3*sizeof(int*));
for(int h=0; h<3; h++){
    matrizBid[h]=malloc(3*sizeof(int));
}

for(int i=0; i<3; i++){
    memcpy(matrizBid[i], matrizEst[i], 5*sizeof(int));
}

for(int j=0; j<3; j++){
    for(int k=0; k<3; k++)
        printf("%d\n", matrizBid[j][k]);
}

// matrizUni=malloc(3*3*sizeof(int));
// memcpy(matrizUni, matrizEst, 3*3*sizeof(int));


// for(int k=0; k<3; k++){
//     for(int l=0; l<3; l++)
//     printf("%d\n", matrizUni[k*3+l]);
// }


return 0;
}