#include <stdio.h>
#include <string.h>
#define CANTREC 2

typedef struct{
    float base;
    float altura;
}rectangulo;

void inicializarRectangulo(rectangulo *);//tiene que estar declarado el tipo rectangulo desde antes

float calcularArea(rectangulo);

struct LED{
    unsigned char LED1 :1;
    unsigned char LED2 :1;
    unsigned char LED3 :1;
    unsigned char LED4 :1;
    unsigned char resto :4;//para no guardar basura mejor guardar ceros

};

int main(){

    // int numero=7, binario=3;
    // if(numero & binario ==1 )//si es verdadera, al menos coinciden en 1 bit a nivel binario
    //     printf("coinciden en algo");
    // else
    //     printf("NO coinciden en algo");

        //si es true, si 7&3!=0, si 7 y 3 son distintos, imprime algo diferente a cero
    // printf("%d", 7&&7);
    //si es false 7&3=0, por lo cual 7 y 3 son iguales, imprimiría cero
   

    // #define CAR 5
    // enum meses {ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC};

    // enum meses m1;
    // char vector[CAR]={0};

    // for(int i=ENE; i<CAR; i++){
    //     printf("valor del mes %d = %d \n", i, vector[i]);
    // }

    // struct LED status;

    // status.LED1=1;
    // status.LED2=1;
    // status.LED3=1;
    // status.LED4=1;
    // status.resto=0;


    // unsigned char *byte;
    // byte= (unsigned char*)&status;
    // printf("Estado del led: %s", byte);

    // int x=10;
    // printf("%x \n", x);
    // typedef struct {
    //     int edad;
    //     char nombre[23];
    // }persona;

    // persona *vector[2], p1={18,"Mateo"}, p2={19, "Stefano"}, *v2;
    // vector[0]=&p1;
    // vector[1]=&p2;
    // printf("nombre 1: %s \n", (*vector[0]).nombre);
    // printf("nombre 2: %s \n", (*(*(vector+1))).nombre);
    // // *(vector-1);//modifico de vuelta a lo que apunta
    // printf("nombre 1: %s\n", vector[0]->nombre);
    // printf("nombre 2: %s\n", (*(vector+1))->nombre);

    // printf("nombre 1: %s\n", vector[0]->nombre);

    // char *vector[2]={"Mateo", "Stefano"}, *v2;

    // v2=vector[0];//ambos son punteros a char
    
    // printf("nombre 1: %s \n", v2[0]);
    // printf("nombre 2: %s \n", (*(v2+0)));

    // // *(vector-1);//modifico de vuelta a lo que apunta
    // printf("nombre 1: %s\n", (&v2[0]));
    // printf("nombre 2: %s\n", (v2+0));



    // char pal[]={"hola"};
    // char *varias_p[4]={"hola", "como", "estas", "?"};
    // printf("%d", strcmp(pal, varias_p[0]));

    // // printf("%s", varias_p[0]);
    // char caractere='x';
    // char *palabra="hola2";
    // varias_p[0]=palabra;
    // printf("%s fin ", varias_p[0]);


    // void *voidP;
    // float f=5.5;
    // voidP=&f;
    // printf("%f", *(float*)voidP);

    // // printf("%d", !(3-3));
    // rectangulo vectorRec[CANTREC];
    // int i, pos_min=0;
    // float area_i, min=9999;

    // for(i=0; i<CANTREC; i++){
    //     inicializarRectangulo(&vectorRec[i]);
    //     area_i=calcularArea(vectorRec[i]);
    //     if(area_i < min){
    //         min=area_i;
    //         pos_min=i;
    //     }

    // }

    // printf("El menor rectangulo es el numero %d", pos_min+1);
    return 0;
}

void inicializarRectangulo (rectangulo *rec){
    #define CAR 5
    printf("Ingrese la altura: ");
    scanf("%f", &rec->base);
    printf("Ingrese la altura: ");
    scanf("%f", &(*rec).altura);//ambas opciones correctas
}

float calcularArea(rectangulo rec){
    return rec.altura * rec.base;
}
