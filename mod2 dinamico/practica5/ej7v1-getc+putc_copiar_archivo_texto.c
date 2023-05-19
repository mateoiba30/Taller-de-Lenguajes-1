#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *f, *nuevo;
    char aux;

    f = fopen("vinos.csv", "r");
    if (f == NULL){
        printf ("Error en vinos\n");
        return 1;
    }

    nuevo = fopen("nuevo.txt", "w");
    if (nuevo == NULL){
        printf ("Error en reporte\n");
        return 1;
    }
    
    aux=fgetc(f);
    while(!feof(f)){
        // fprintf(nuevo, "%c", aux); //anda igual de bien
        fputc(aux, nuevo);
        aux=fgetc(f);
    }
    //siempre leer, y desp preguntar si llegué al final para no imprimir el end of file !!

    fclose(f);
    fclose(nuevo);
    
    return 0;
}