#include <stdio.h>
#include <stdlib.h>
#define LONG 300
int main(){
    FILE *f;
    char linea[LONG], c;
    // Abrir el archivo

    f = fopen("prueba.txt", "r");
    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
    }
    while (!feof(f)){
        // fscanf(f, "%s", linea);
        // printf("%s\n", linea); //PONE SALTO DE LINEA EXTRA EN CADA BLANCO

        // fgets(linea,LONG,f);
        // puts(linea); //PONE 1 SALTO EXTRA ENTRE RENGLONES

        printf("%c", fgetc(f));//anda perfecto
        // fprintf(stdout, "%c", fgetc(f)); //otra solucion que anda perfecto
    }

    fclose(f);
    return 0;
}