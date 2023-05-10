#include <stdio.h>
int incremento(int);

int main(){
 float i;
 for(i=6; i>0.5; i/=2)
 printf("i=%5.1f j=%5d \n", i, incremento(i));
 return 0;
}
int incremento(int N){//N toma el valor entero de i
 static int j=0;//que sea estatico significa que no borra nunca su contnido, aunque muera la funcion
 j++;//con cada bucle va incrementando
 return (N%2 ? N : N+j);  //N%2 siempre va a ser verdadera cuando le madno un par. SI recibe 1,5 trunca a 1, si recibe 0,7 trunca a cero el N
//solo la última rep es falsa al mandar 0,8 N=0; 0%2 = 0 = falso; devulve N+j = 0 +4
}
