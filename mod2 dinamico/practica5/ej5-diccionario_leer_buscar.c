#include <stdio.h>
#include <string.h>

int main(){
    FILE *f;
    int cod, fin=0, encontre=0;
    char palabra[255], palabra_act[255];

    f = fopen("diccionario.txt", "w+");
    if (f == NULL){
        printf ("Error\n");
        return 1;
    }
    fprintf(f,"mateo\njuan\npepe\n");
    fseek(f, 0, SEEK_SET);//suando escribo me mueve el puntero del archivo
    
    printf("Ingrese una palabra a buscar (ZZZ para finalizar): ");
    scanf("%s", palabra);
    if(strcmp(palabra,"ZZZ")==0)
        fin=1;

    while(fin==0){
        while (!feof(f)){
            //fgets lee hasta un cambio de linea
            //si quiero leer hasta cierta condicion puedo usar fscanf con un caracter de escape
            // fgets(palabra_act,255,f);//el archivo va a lo último
            // palabra_act[strcspn(palabra_act, "\n")] = '\0'; // Elimiar el carácter de nueva línea
            //fgets lee el \n y lo incluye !

            fscanf(f, "%s", palabra_act);//mejor que usar fgets porque pone bien el \0
            if(strcmp(palabra_act,palabra)==0){
                encontre=1;
            }
        }

        
        if(encontre==1)
            printf("palabra encontrada\n");
        else
            printf("palabra NO encontrada\n");

        fseek(f, 0, SEEK_SET); // Volver al principio del archivo porque leer me mueve el puntero
        encontre=0;
        printf("Ingrese otra palabra a buscar (ZZZ para finalizar): ");
        scanf("%s", palabra);
        if(strcmp(palabra,"ZZZ")==0)
            fin=1;
    }
    if(encontre==1)
        printf("palabra encontrada\n");
    else
        printf("palabra NO encontrada\n");

    fclose(f);
    return 0;
}