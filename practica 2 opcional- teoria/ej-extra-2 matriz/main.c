#include <stdio.h>
#include <stdlib.h>
#define CLI 5
#define TITU 4
void cargarCliente(int, int [][TITU], char *[]);

int main()
{
    int matriz[CLI][TITU];
    char *titulos[TITU]={"atencion", "calidad", "justicia", "ambiente"};
    float prom=0;

    for(int i=0; i<CLI; i++){
        printf("Cliente %d\n", i+1);
        getchar();
        cargarCliente(i, matriz,titulos);//le mando a cargar los titulos del vector del cliente
    }
    for(int i=0; i<TITU; i++){
        prom=0;
        for(int j=0; j<CLI; j++){
            prom+=matriz[j][i];
        }
        printf("Promedio %s = %2.2f \n", titulos[i], prom/CLI);

    }

    return 0;
}
void cargarCliente(int i, int matriz[][TITU], char *titulos[]){
    printf("Califique entre 1 y 10 los siguientes aspectos \n");
    getchar();
    for(int j=0; j<TITU; j++){
        printf("%s: \n", titulos[j]);
        scanf("%d", &matriz[i][j]);
    }

}
