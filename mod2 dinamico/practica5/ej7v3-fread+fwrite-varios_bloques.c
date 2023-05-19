#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f, *nuevo;
    char buffer[1000], aux;

    f = fopen("vinos.csv", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }

    nuevo = fopen("nuevoo.txt", "w");
    if (nuevo == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    
    int cant=0;

    cant=fread(buffer, sizeof(char), 1000, f);//devuelve la cant de caracteres que pudo eler correctamente
    while(cant>0){
        fwrite(buffer, sizeof(char), cant, nuevo);
        cant=fread(buffer, sizeof(char), 1000, f);
    }

    fclose(f);
    fclose(nuevo);
    
    return 0;
}