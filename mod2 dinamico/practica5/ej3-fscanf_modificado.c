#include <stdio.h>

int main(){
    FILE *f;
    int precipitacion, maxp=-1, maxd=0;
    char c;

    f = fopen("precipitaciones.txt", "r");
    if (f == NULL){
        printf ("Error\n");
        return 1;
    }

    for(int i=1; i<=31; i++){
        fscanf(f,"%d-",&precipitacion);//lee todo hasta el guion y no lo guarda (ya lo lee al caracter)
        // printf("%d ", precipitacion);
        if(precipitacion>maxp){
            maxp=precipitacion;
            maxd=i;
        }
    }

    printf("El maximo dia fue: %d\n",maxd);

    fclose(f);
    return 0;
}