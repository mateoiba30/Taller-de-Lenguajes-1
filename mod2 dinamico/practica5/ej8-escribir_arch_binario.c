#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    char aux;
    FILE *texto, *binario;
    char buffer[1];
    // aux='0'; //creo que no era necesario al final

    texto = fopen("numeros.txt", "w");
    if (texto == NULL){
        printf ("Error en texto\n");
        return 1;
    }

    binario = fopen("binario.dat", "wb");
    if (binario == NULL){
        printf ("Error en binario\n");
        return 1;
    }

    for(int i=0; i<10; i++){
        printf("Ingrese el numero %d: ", i+1);
        scanf("%d", &n);
    //  n=n+aux;//para guardar el valor en caracter del numero, creo que no lo piden

        // fputc(n, texto);//recordar que hay varias maneras, puedo por ej usar fprintf
        fprintf(texto, "%d", n);
        buffer[0]=n;
        fwrite(buffer, sizeof(int), 1, binario);//en luigar del buffer tmb puedo mandar la dir de n: &n 
    }   

    fclose(texto);
    fclose(binario);
    return 0;
}