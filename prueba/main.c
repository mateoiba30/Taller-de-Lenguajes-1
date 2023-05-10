#include <stdio.h>
#include <stdlib.h>

void reservar(int*);

int main(){
int *vector;

// vector=malloc(4*sizeof(int));
// free(vector);
reservar(vector);
printf("%d", vector[3]);

free(vector);
return 0;
}

void reservar(int* vector){
    vector=malloc(4*sizeof(int));
}