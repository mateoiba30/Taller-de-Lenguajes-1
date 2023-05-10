#include <stdio.h>
#define ALUMNOS 2

typedef struct{

    char calle[50];
    char ciudad[30];
    int cod_postal;
    char pais[40];
} direccion;

typedef struct{

    char apellido[50];
    char nombre[50];
    char legajo[8];
    float promedio;
    direccion domicilio;
    
} alu;//si o si declarada después de la estructura direccion

typedef alu alumno; // = typedef struct alu alumno;

void inicializarAlumno (alumno*);

int main(){

    alu vectorAlumnos[ALUMNOS];//puedo ponerle alu o alumno
    int i, pos_max;
    float max, prom_i;

    for(i=0; i<ALUMNOS; i++){
        inicializarAlumno(&vectorAlumnos[i]);//le mando la direccion, no el valor. no estoy mandando todo el vector
        prom_i=vectorAlumnos[i].promedio;
        if(prom_i>=max){
            max=prom_i;
            pos_max=i;
        }
    }
    printf("el alumno con mejor promedio es: %s %s", vectorAlumnos[pos_max].nombre, vectorAlumnos[pos_max].apellido);

    return 0;
}

void inicializarAlumno(alumno *a){
    printf("ingrese el apellido: ");
    fgets(a->apellido, 50, stdin);//para leer oraciones
    printf("ingrese el nombre: ");
    scanf("%s", (*a).nombre);//no pongo el & al inicio porque es un string
    printf("ingrese el legajo: ");
    scanf("%s", a->legajo);
    printf("ingrese el promedio: ");
    scanf("%f", &a->promedio);

    printf("---domicilio---\n");
    printf("ingrese la calle: ");
    scanf("%s", a->domicilio.calle);
    printf("ingrese la ciudad: ");
    scanf("%s", a->domicilio.ciudad);
    printf("ingrese el codigo postal: ");
    scanf("%d", &a->domicilio.cod_postal);
    printf("ingrese el pais: ");
    scanf("%s", a->domicilio.pais);
}