#include <stdio.h>

int main(){
    FILE *f;
    int cod;
    float monto=0, act;
    char c;

    f = fopen("apuestas.txt", "r");
    if (f == NULL){
        printf ("Error\n");
        return 1;
    }

    while (!feof(f)){
        fscanf(f,"%d|%f;",&cod, &act);//puedo leerlo todo de una
        printf("%f\n",act);
        monto+=act;
    }


    printf("El monto es de: %f\n",monto);

    fclose(f);
    return 0;
}