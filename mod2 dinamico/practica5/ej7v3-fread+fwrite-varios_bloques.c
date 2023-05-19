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
    
    int caracts=0, pos=0, fin=0;
    while(!feof(f)){
        pos++;
        caracts++;
        aux=fgetc(f);//cuando leo me estoy moviendo!!

        if(caracts==1000){
            fread(buffer, sizeof(char), 1000, f);
            fwrite(buffer, sizeof(char), 1000, nuevo);
            caracts=0;
            fin=pos;
        }
    }
    fseek(f, pos+1000, SEEK_SET);//al finalizar me queda algo más chico que un bloque de mil caracteres que debo imprimir

    fread(buffer, sizeof(char), caracts, f);
    fwrite(buffer, sizeof(char), caracts, nuevo);

    fclose(f);
    fclose(nuevo);
    
    return 0;
}