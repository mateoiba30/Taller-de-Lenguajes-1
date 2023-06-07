#include <stdio.h>

int main(int argc, char * argv[]){

    if(argc==1)
        printf("Error, no se pasaron palabras\n");
    else
        for(int i=1; i<argc; i++)
            printf("%s ", argv[i]);

    return(0);
}
