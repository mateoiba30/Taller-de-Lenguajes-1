#include <stdio.h>
#include <stdlib.h>
int* f ();
int main(){
 int * ptr = NULL;
 ptr=f();
 if (ptr == NULL)
 printf("ptr es NULL\n");
 else
 printf("ptr no es NULL\n");
 return 0;
}
int* f () {
 int * p;
 p = (int *) malloc(10*sizeof(int));
 return p;//hay que retornar el puntero que tiene memoria reservada
}