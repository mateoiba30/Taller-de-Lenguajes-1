#include <stdio.h>

int main(){
    FILE *f;
    int c, min=0, may=0, dig=0;

    f = fopen("prueba.txt", "r");
    if (f == NULL){
        printf ("Error\n");
        return 1;
    }
    while (!feof(f)){
        c=fgetc(f);
        if (c>='a' && c<='z')
            min++;
        if (c>='A' && c<='Z')
            may++;
        if( c>='0' && c<='9')
            dig++;
    }

    printf("mayusculas: %d \nminusculas: %d \ndigitos: %d \n", may, min, dig);

    fclose(f);
    return 0;
}