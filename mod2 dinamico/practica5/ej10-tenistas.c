#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CANTTENISTAS 2
typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int cantTitulos;
    int ranking;
    int fortuna;

} Tenistas;

int actualizarTenista(FILE *, char[], char[], int);
void informarMejorRanking(FILE *, int);
void cargarTenistas(Tenistas[], int, FILE *);
void leerTenistas(Tenistas[], int);

int main()
{
    int nuevoRanking;
    char nombre[50], apellido[50];
    FILE *binario;
    Tenistas vectorTenistas[CANTTENISTAS];

    leerTenistas(vectorTenistas, CANTTENISTAS);
    binario = fopen("tenistas.dat", "wb+"); // el segundo campo estaba con rb+, por ende si solo usamos ese ej iria con wb+
    if (binario == NULL)
    {
        printf("Error en el archivo binario\n");
        return 1;
    }
    cargarTenistas(vectorTenistas, CANTTENISTAS, binario);

    // informarMejorRanking(binario, CANTTENISTAS);

    printf("Ingrese nombre del tenista a actualizar: ");
    scanf("%s", nombre);
    printf("Ingrese apellido del tenista a actualizar: ");
    scanf("%s", apellido);
    printf("Ingrese nuevo ranking del tenista a actualizar: ");
    scanf("%d", &nuevoRanking);
    if (actualizarTenista(binario, nombre, apellido, nuevoRanking) == 1)
        printf("Tenista actualizado\n");
    else
        printf("Tenista NO actualizado\n");

    fseek(binario, 0, SEEK_SET);//no olvidar
    informarMejorRanking(binario, CANTTENISTAS);

    fclose(binario);
    return 0;
}

int actualizarTenista(FILE *binario, char nombre[], char apellido[], int nuevoRanking)
{
    // el file ya se cargo, hay que volver a 0 para recorrerlo
    fseek(binario, 0, SEEK_SET);
    Tenistas tenistaActual;
    int seguir = 1, comparacion = 1, posTenista = 0;

    while (seguir == 1 && fread(&tenistaActual, sizeof(Tenistas), 1, binario) != 0)
    {
        if (strcmp(tenistaActual.nombre, nombre) == 0 && strcmp(tenistaActual.apellido, apellido) == 0) // vale cero si son iguales
            seguir = 0;
        else
            posTenista++;
    }
    if (seguir == 0)
    { // si encontro el dato modifico. donde me encuentro parado retrocedo un int para ir a ranking

        // fseek(binario, -sizeof(Tenistas), SEEK_SET); // podría siempre aumentar la pos y al salir restar en sizeof
        fseek(binario, posTenista * sizeof(Tenistas), SEEK_SET); // asi no funcionaria porque nos estamos desplazando desde la posicion actual una cantidad de bytes especifica con el posTenista y nos vamos a la mierda
        tenistaActual.ranking = nuevoRanking;
        fwrite(&tenistaActual, sizeof(Tenistas), 1, binario); // sobreescribo datos
        return 1;
    }
    return 0;
}

void informarMejorRanking(FILE *binario, int diml){
    int mejorRank = 9999, posMR = 0, i, maxTitulos = -1;
    Tenistas tenistaAct, mejorTenistaRank, mejorTenistaTitulos;

    for (i = 0; i < diml; i++)
    {
        fread(&tenistaAct, sizeof(Tenistas), 1, binario);
        if (tenistaAct.ranking < mejorRank)
        {
            mejorRank = tenistaAct.ranking;
            mejorTenistaRank = tenistaAct;
        }
        if (tenistaAct.cantTitulos > maxTitulos)
        {
            maxTitulos = tenistaAct.cantTitulos;
            mejorTenistaTitulos = tenistaAct;
        }
    }
    printf("jugador con mejor ranking: %s %s\n", mejorTenistaRank.nombre, mejorTenistaRank.apellido);
    printf("jugador con mas titulos es: %s %s\n", mejorTenistaTitulos.nombre, mejorTenistaTitulos.apellido);
}

void cargarTenistas(Tenistas v[], int diml, FILE *binario){
    for (int i = 0; i < diml; i++){
        fwrite(&v[i], sizeof(Tenistas), 1, binario); // manejarme de a estructuras
    }
}

void leerTenistas(Tenistas v[], int diml)
{
    for (int i = 0; i < diml; i++)
    {
        printf("\n\ntenista %d\n", i + 1);

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