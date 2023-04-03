#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char c;

    printf("ingrese el entero a: \n");
    scanf("%d", &a);
     printf("ingrese el entero b: \n");
    scanf("%d", &b);
    getchar();
    printf("ingrese el operador (+, -, /, x): \n");
    scanf("%c", &c);

    switch(c){
case '+': printf(" %d %c %d = %d",a,c,b,a+b);break;
case '-': printf(" %d %c %d = %d",a,c,b,a-b);break;
case '/':printf(" %d %c %d = %.2f",a,c,b,(float)a/b);break;
case 'x':printf(" %d %c %d = %d",a,c,b,a*b);break;
    default:printf("simbolo equivocado");break;

//tmb puedo anidar ifs.
    }
    return 0;
}
