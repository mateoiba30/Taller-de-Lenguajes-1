#include <stdio.h>
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

    c=fgetc(f);
    while (!feof(f)){
        // fscanf(f, "%s", linea);
        // printf("%s\n", linea); //PONE SALTO DE LINEA EXTRA EN CADA BLANCO

        // fgets(linea,LONG,f);
        // puts(linea); //PONE 1 SALTO EXTRA ENTRE RENGLONES

        printf("%c", c);//no hacer printf("%c", fgetc(f)); porque puede llegar a fallar imprimiendo el end of file
        c=fgetc(f);
        // fprintf(stdout, "%c", fgetc(f)); //otra solucion que anda perfecto
    }

    fclose(f);
    return 0;
}