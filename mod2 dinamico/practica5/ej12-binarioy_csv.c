#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    long int dni;
    char apellido[50];
    char nombre[50];
    char trabajo[50];
    char correo[50];
    char ciudad[50];
    char pais[50];

}Persona;

typedef struct{
    long int dni;
    int pos;
}campo;

struct nodo{//DEBO PONERLE NOMBRE AL INICIO
    campo dato;
    struct nodo* sig;
};

typedef struct nodo nodo;
typedef nodo* lista;

void imprimirPersona(Persona pBuscada);
void cargarVector(campo[], lista, int);
int busquedaDicotomicaPos(campo[], int, long int);
int buscarPersonaLista(FILE *, lista, long int, Persona *, int );
void imprimirArchivo(FILE *binario);
void cargarBinario(FILE *, lista);
void inicializarLista(lista*);
void insertarOrdenadoDescendente(lista*, campo);
void imprimirLista(lista);
void liberarLista(lista*);

int main(){
    Persona pBuscada;
    lista l;
    campo p;
    FILE *personas, *binario;
    char aux2[100];//tiene que ser grande para poder leer cada renglon completo sin repetir
    int aux, diml=0;
    long int dni;

    binario=fopen("personas.idx", "wb+");//porque desp lo quiero leer
    if(binario==NULL){
        printf("Error en el archivo binario\n");
        return 1;
    }
    personas=fopen("personas.csv", "r");
    if(personas==NULL){
        printf("Error en el archivo csv\n");
        return 1;
    }
    inicializarLista(&l);

    //no leo un archivo binario, por ende no es necesario conocer como se cargaron los datos para saber el peso de cada persona y moverme de a personas
    fgets(aux2, 100, personas);//leo titulos, mandarle la cant de su tamanio

    p.pos=ftell(personas);
    while(fscanf(personas,"%d;", &aux)!=EOF){//id
        fscanf(personas,"%ld;", &p.dni);
        // printf("id: %d dni:%ld \n", aux, p.dni);
        fgets(aux2, 100, personas);//leo el resto
        
        insertarOrdenadoDescendente(&l, p);
        diml++;
        p.pos=ftell(personas);
    }

    // printf("eof: %d\n", aux); //da 5000 porque la ultima iteracion no le carga nada a aux
    // imprimirLista(l);
    cargarBinario(binario, l);
    // imprimirArchivo(binario);

    printf("Ingrese dni de la persona a buscar: ");
    scanf("%ld", &dni);
    if(buscarPersonaLista(personas, l, dni, &pBuscada, diml)==-1)
        printf("Persona no encontrada\n");
    else
        imprimirPersona(pBuscada);

    liberarLista(&l);
    fclose(binario);
    fclose(personas);
    return 0;
}

void imprimirPersona(Persona p){
    printf("id: %d\t", p.id);
    printf("dni: %ld\t", p.dni);
    printf("apellido: %s\t", p.apellido);
    printf("nombre: %s\t", p.nombre);
    printf("trabajo: %s\t", p.trabajo);
    printf("correo: %s\t", p.correo);
    printf("ciudad: %s\t", p.ciudad);
    printf("pais: %s\t", p.pais);
}

int buscarPersonaLista(FILE *personas, lista l, long int dni, Persona *p, int diml){//podría poner la diml dentro de la estructura tipo lista
//busco dicotomicamente el dni y me fijo la pos el el csv
    campo v[diml];
    int pos;
    cargarVector(v, l, diml);
    pos=busquedaDicotomicaPos(v, diml, dni);
    // printf("%d", pos);
    if(pos==-1)
        return -1;
    else{
        fseek(personas, pos, SEEK_SET);
        fscanf(personas,"%d;", &(*p).id);
        fscanf(personas,"%ld;", &p->dni);//ambas maneras equivalentes
        fscanf(personas,"%[^;];", p->apellido);
        fscanf(personas,"%[^;];", p->nombre);
        fscanf(personas,"%[^;];", p->trabajo);
        fscanf(personas,"%[^;];", p->correo);
        fscanf(personas,"%[^;];", p->ciudad);
        fscanf(personas,"%s", p->pais);//el ultimo quiero que lea hasta el salto de linea, no hasta ; porque sino me incluye el siguiente id

        fseek(personas, 0, SEEK_SET);//restauro pos inicial
    }

    return 0;
}

int busquedaDicotomicaPos(campo v[], int diml, long int dni){//que sea dicotomica no significa que sea recursiva
   int centro, inf=0, sup=diml-1;

   while(inf<=sup){
        centro=((sup-inf)/2)+inf;
        // printf("%ld\n", v[centro].dni);
        if(v[centro].dni==dni)
            return v[centro].pos;
        else {
            if(dni > v[centro].dni) //esta en orden descendente
                sup=centro-1;
            else
                inf=centro+1;
        }
   }
   return -1;
}

void cargarVector(campo v[], lista l, int diml){
    lista aux=l;
    for(int i=0; i<diml; i++){
        v[i]=aux->dato;
        aux=aux->sig;
    }
}

void imprimirArchivo(FILE *binario){
    int cont=0;
    campo p;
    while (fread(&p, sizeof(campo), 1, binario) ==1){//igual que preguntar por !=0
        printf("%ld\t%d\n", p.dni, p.pos);
        // cont++;
    }

    // printf("%d\n", cont);//por algun motivo hay 5034 datos, pero solo 5000 ids

    // campo p[5000]; //debería andar el imprimir todo de una, pero parece que no
    // fread(p, sizeof(campo), 5000, binario);
    // int i;
    // for (i=0; i<5000; i++){
    //     printf("%ld\t%d\n", p[i].dni, p[i].pos);
    // }

    fseek(binario, 0, SEEK_SET);//no olvidar
}

void cargarBinario(FILE *binario, lista l){
    lista aux=l;
    while(aux!=NULL){
        // fwrite(&aux->dato.dni, sizeof(long int), 1, binario);
        // fwrite(&aux->dato.pos, sizeof(int), 1, binario);
        fwrite(&aux->dato, sizeof(campo), 1, binario);//mejor de a estructuras
        aux=aux->sig;
    }
    fseek(binario, 0, SEEK_SET);//no olvidar
}

void insertarOrdenadoDescendente( lista* l, campo dato){
    lista nue, ant, act;
    nue=(lista)malloc(sizeof(nodo));//reservo mem
    nue->dato=dato;

    act=(*l);
    ant=(*l);

    while(act!=NULL && act->dato.dni > dato.dni){
        ant=act;
        act=act->sig;
    }

    nue->sig=act;

    if((*l)==act)
        (*l)=nue;
    else
        ant->sig =nue;

}

void inicializarLista(lista* l){
    (*l)=NULL;
}

void imprimirLista(lista l){
    lista aux=l;
        while(aux!=NULL){
            printf("%d, %d\n",aux->dato.dni, aux->dato.pos);
            aux=aux->sig;
    }

}

void liberarLista(lista* l){
    lista aux;
    while( (*l)){
        aux=(*l);
        (*l)=(*l)->sig;
        free(aux);
    }
}