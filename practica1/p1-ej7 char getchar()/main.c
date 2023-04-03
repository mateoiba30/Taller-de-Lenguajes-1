
#include <stdio.h>
int main(){
 char a, b;
 printf("Ingrese el primer caracter:\n");
 scanf("%c", &a);
 getchar();
 printf("Se leyo el caracter: %c\n", a);
 //scanf("%c", &b); (esto tmb funciona)

 printf("Ingrese el segundo caracter:\n");
 scanf("%c", &b);
 printf("Se leyo el caracter: %c\n", b);
 return 0;
}
