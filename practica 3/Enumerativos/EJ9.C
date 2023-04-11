#include <stdio.h>
typedef enum { Domingo, Lunes, Martes, Miercoles, Jueves, Viernes, Sabado} Semana;//SOLO PUEDEN SER CARACTERES

int main(){
    int i=0;
  char *semana[] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

    printf("Los dias de la semana son: ");
    for (Semana j = Domingo; i <= Sabado; i++)
        printf("%s ", semana[i]);

    for(i=Domingo; i<=Sabado; i++)
        switch(i){
            case Domingo: printf("Domingo "); break;
            case Lunes: printf("Lunes "); break;
            case Martes: printf("Martes "); break;
            case Miercoles: printf("Miercoles "); break;
            case Jueves: printf("Jueves "); break;
            case Viernes: printf("Viernes "); break;
            default: printf("Sabado "); break;
        }
    



    return 0;
}