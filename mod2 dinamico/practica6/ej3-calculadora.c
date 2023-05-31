#include <stdio.h>
#include <stdlib.h>
#define CANT 4

int main (int argc, char * argv[]) {

    if(argc!=CANT)
        printf("se deben pasar 3 parametros ('x' 'y' 'op')\n");
    else{

        int j=0, terminar=0;
        float res;

        while( argv[3][j]!='\0')
            j++;

        if(j>1)
            terminar=1;
        else{
            int x, y;
            char op=argv[3][0];
            x=atoi( argv[1] );
            y=atoi( argv[2] );

            switch(op){
                case '+': res=x+y; break;
                case '.': res=x*y; break;
                case '/': res=(float)x/y; break; 
                case '-': res=x-y; break;
                default: terminar=1; break;
            }
        }

        if(terminar==0)
            printf("el resultado es de %f\n", res);
        else
            printf("el operador no es reconocido\n");

    }
    return 0;
}