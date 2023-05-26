#include <stdio.h>
#include <stdlib.h>
#define MAX 16
#define ABC 26

typedef struct{
    char palabra[MAX];
    float dificultad;
} Palabra;

void cargarBinario(FILE*, FILE*);
float obtenerDificultad(char [], int*);

int main(){
    FILE *texto, *binario;
    binario=fopen("personas.idx", "wb");
    if(binario==NULL){
        printf("Error en el archivo binario\n");
        return 1;
    }
    texto=fopen("palabras.txt", "r");
    if(texto==NULL){
        printf("Error en el archivo txt\n");
        return 1;
    }

    int aux;
    printf("dificultad de mateo: %f\n", obtenerDificultad("mateo", &aux));
    if(aux==1)
        printf("palabra con enie\n");
    // cargarBinario(binario, texto);

    fclose(binario);
    fclose(texto);
    return 0;
}

void cargarBinario(FILE*binario, FILE*texto){
    Palabra p;
    int problema=0;

    while(fscanf(texto, "%s", p.palabra)!=EOF){//scanf no incluye el \n pero corta en espacios (no es un problema en las palabras)
        p.dificultad=obtenerDificultad(p.palabra, &problema);
        if(problema==0)
            fwrite(&p, sizeof(Palabra), 1, binario);
    }
    fseek(binario, 0, SEEK_SET);
}

float obtenerDificultad(char palabra[], int *problema){
    float frecuencias[ABC]={12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.7, 6.25, 0.44, 0.01, 4.97, 3.15, 
                            6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.9, 0.02, 0.22, 0.9, 0.52};
    char cAct, aux='a';
    int i=0;
    float dificultad=0;

    cAct=palabra[i];
    while(cAct!='\0' && (*problema)==0){
        if(cAct=164)// 'ñ' en ascii extendido
            (*problema)=1;
        dificultad+=frecuencias[cAct-aux];

        i++;
        cAct=palabra[i];
    }

    return dificultad;
}