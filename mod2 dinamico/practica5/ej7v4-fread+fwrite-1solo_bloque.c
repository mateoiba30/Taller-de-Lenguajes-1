#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f, *nuevo;
    char buffer[1000], aux;

    f = fopen("apuestas.txt", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }

    nuevo = fopen("nuevoo.txt", "w");
    if (nuevo == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    
    int caracts=0;
    while(!feof(f)){
        caracts++;
        aux=fgetc(f);
    }
    caracts--;//elimino el endoffile
    fseek(f, 0, SEEK_SET);//al finalizar me queda algo más chico que un bloque de mil caracteres que debo imprimir
    fread(buffer, sizeof(char), caracts, f);
    fwrite(buffer, sizeof(char), caracts, nuevo);

    fclose(f);
    fclose(nuevo);
    
    return 0;
}