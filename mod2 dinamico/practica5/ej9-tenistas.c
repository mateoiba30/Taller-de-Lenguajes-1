#include <stdio.h>

#define CANTTENISTAS 2
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
    Tenistas vectorTenistas[CANTTENISTAS];
    leerTenistas(vectorTenistas, CANTTENISTAS);

    FILE *binario= fopen("tenistas.dat", "wb");
    if(binario==NULL){
        printf("Error en el archivo binario\n");
        return 1;
    }

    cargarTenistas(vectorTenistas, CANTTENISTAS, binario);

    informarMejorRanking(binario, CANTTENISTAS);

}

void informarMejorRanking(FILE *binario, int diml){
    int aux, rankAct, mejorRank=9999, posMR=0, i;
    char nombreMR[50], apellidoMR[50];
    for(i=0; i<diml; i++){
        fread(&aux, sizeof(int), 4, binario);
        fread(&rankAct, sizeof(int), 1, binario);
        if(rankAct<mejorRank){
            mejorRank=rankAct;
            posMR=i;
        }
    }
    fseek(binario, (i-4)*sizeof(int), SEEK_SET);
    fread(nombreMR, sizeof(int), 1, binario);
    fread(apellidoMR, sizeof(int), 1, binario);

    printf("jugador con mejor ranking: %s %s\n", nombreMR, apellidoMR);

}

void cargarTenistas(Tenistas v[], int diml, FILE *binario){
    char aux[2]=" ";
    for(int i=0; i<diml; i++){
        fwrite(v[i].nombre, sizeof(int), 1, binario);
        fwrite(v[i].apellido, sizeof(int), 1, binario);
        fwrite(&v[i].edad, sizeof(int), 1, binario);
        fwrite(&v[i].cantTitulos, sizeof(int), 1, binario);
        fwrite(&v[i].ranking, sizeof(int), 1, binario);
        fwrite(&v[i].fortuna, sizeof(int), 1, binario);
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