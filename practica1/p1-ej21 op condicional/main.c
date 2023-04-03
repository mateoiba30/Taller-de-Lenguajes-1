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
 return (N%2 ? N : N+j);  //N%2 siempre va a ser verdadera mas alla del N
 //siempre devuelve el valor de N para N>0 o N par. debido a que  esos casos el resto de N/2 es cero, y cero se toma por falso
}
