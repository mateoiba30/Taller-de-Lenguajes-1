#include <stdio.h>
#include <stdlib.h>
int factorial(int numero) {  //PUEDO ESCRIBIR LA FUNCION DIRECTAMENTE ARRIBA
    if (numero ==0)
        return 1;
    else//puedo sacar el else
      return numero * factorial(numero-1); // Restar 1
}

int main()
{
    int n;
    printf("ingrese un numero: ");
    scanf("%d", &n);
    printf("El factorial de %d es: %d \n",n,factorial(n));
    getchar();

    return 0;
}


