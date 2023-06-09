#include <stdio.h>
#include <stdlib.h>

#define CANTTENISTAS 20
typedef struct{
    char nombre[50];
    char apellido[50];
    int edad;
    int cantTitulos;
    int ranking;
    int fortuna;


}Tenistas;

void informarMejorRanking(FILE *, int);
void cargarTenistas(Tenistas [], int, FILE *);
void leerTenistas(Tenistas [], int);

int main(){
    FILE *binario;
    Tenistas vectorTenistas[CANTTENISTAS];

    leerTenistas(vectorTenistas, CANTTENISTAS);

    binario= fopen("tenistas.dat", "wb");
    if(binario==NULL){
        printf("Error en el archivo binario al escribir\n");
        return 1;
    }
    cargarTenistas(vectorTenistas, CANTTENISTAS, binario);
    fclose(binario);

    binario= fopen("tenistas.dat", "rb");
    if(binario==NULL){
        printf("Error en el archivo binario al leer\n");
        return 1;
    }
    informarMejorRanking(binario, CANTTENISTAS);
    fclose(binario);

}

void informarMejorRanking(FILE *binario, int diml){
    int mejorRank=9999, posMR=0, i, maxTitulos=-1;
    Tenistas tenistaAct, mejorTenistaRank, mejorTenistaTitulos;

    for(i=0; i<diml; i++){//podría haber hecho: while (fread(&tenistaActual, sizeof(Tenistas), 1, binario) != 0)
        fread(&tenistaAct, sizeof(Tenistas), 1, binario);
        if(tenistaAct.ranking<mejorRank){
            mejorRank=tenistaAct.ranking;
            // posMR=i; lo podría usar en lugar de guardar el mejor tenista en este if
            mejorTenistaRank=tenistaAct;
        }
        if(tenistaAct.cantTitulos>maxTitulos){
            maxTitulos=tenistaAct.cantTitulos;
            mejorTenistaTitulos=tenistaAct;
        }
    }
    // fseek(binario, (posMR)*sizeof(Tenistas), SEEK_SET); //en lugar de usar la pos conviene moverme de a estructuras, pero esto tmb funciona
    // fread(&mejorTenista, sizeof(Tenistas), 1, binario);
    printf("jugador con mejor ranking: %s %s\n", mejorTenistaRank.nombre, mejorTenistaRank.apellido);
    printf("jugador con mas titulos es: %s %s\n", mejorTenistaTitulos.nombre, mejorTenistaTitulos.apellido);


}

void cargarTenistas(Tenistas v[], int diml, FILE *binario){
    for(int i=0; i<diml; i++){
        fwrite(&v[i], sizeof(Tenistas), 1, binario);//manejarme de a estructuras
    }
}

void leerTenistas(Tenistas v[], int diml){
    for(int i=0; i<diml; i++){
        printf("\n\ntenista %d\n", i+1);

        printf("\nnombre: ");
        scanf("%s", v[i].nombre);

        printf("\napellido: ");
        scanf("%s", v[i].apellido);

        printf("\nedad: ");
        scanf("%d", &v[i].edad);
        
        printf("\ncantidad de titulos: ");
        scanf("%d", &v[i].cantTitulos);
        
        printf("\nranking mundial: ");
        scanf("%d", &v[i].ranking);

        printf("\nfortuna:");
        scanf("%d", &v[i].fortuna);
    }
}