#include <stdio.h>
typedef struct { //campos de bits usados para aumetnar la legibilidad, no eficientes
    unsigned int Bluetooth:1;
    unsigned int Wifi:1;
    unsigned int GPS:1;
    unsigned int Datos:1;
    unsigned int Frontal:1;
    unsigned int Trasera:1;
    unsigned int Linterna:1;
    unsigned int Vibrar:1;
}Telefono;//podría hacer una union donde pueda usar telefono o un entero que guarde un solo número que representen los estados
//cuando activo o descativo lo hago como el ej 10, y para ver si está encendido pregunto: if tel.Bluetooth ==1 por ejemplo

void activarModulo(Telefono*, char*[]);
void desactivarModulo(Telefono*, char*[]);
void invertirModulo(Telefono*, char*[]);
int verEncendido(Telefono, char*[]);

int main(){
    Telefono tel1;
    char* mods[]={"Vibrar","Linterna","Trasera", "Frontal",  "Datos","GPS", "Wifi", "Bluetooth"   };

    activarModulo(&tel1, mods);
    desactivarModulo(&tel1, mods);
    invertirModulo(&tel1, mods);
    if( verEncendido(tel1, mods)==1)
        printf("encendido \n");
    else
        printf("apagado \n");

    return 0;
}


int verEncendido(Telefono tel,char* mods[]){
    int i, x, mascara, rta;
    // char *mod;

    printf("Ingrese numero de modulo a chequear: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    switch(x){
        case 7: rta=tel.Bluetooth; break;
        case 6: rta=tel.Wifi; break;
        case 5: rta=tel.GPS; break;
        case 4: rta=tel.Datos; break;
        case 3: rta=tel.Frontal; break;
        case 2: rta=tel.Trasera; break;
        case 1: rta=tel.Linterna; break;
        default: rta=tel.Vibrar; break;
    }

    return rta;
}

void invertirModulo(Telefono *tel,char* mods[]){
    int i, x, mascara;

    printf("Ingrese numero de modulo a invertir: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);

    switch(x){//XOR 1 invierte el valor
        case 7: tel->Bluetooth ^= 1; break;
        case 6: tel->Wifi^= 1; break;
        case 5: tel->GPS^= 1; break;
        case 4: tel->Datos^= 1; break;
        case 3: tel->Frontal^= 1; break;
        case 2: tel->Trasera^= 1; break;
        case 1: tel->Linterna^= 1; break;
        default: tel->Vibrar^= 1; break;
    }
}

void desactivarModulo(Telefono *tel, char* mods[]){
    int i, x, mascara;

    printf("Ingrese numero de modulo a desactivar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);

    switch(x){//les mando cero pa desactivar
        case 7: tel->Bluetooth =0; break;
        case 6: tel->Wifi=0; break;
        case 5: tel->GPS=0; break;
        case 4: tel->Datos=0; break;
        case 3: tel->Frontal=0; break;
        case 2: tel->Trasera=0; break;
        case 1: tel->Linterna=0; break;
        default: tel->Vibrar=0; break;
    }


}

void activarModulo(Telefono *tel, char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a activar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    switch(x){//les mando 1 pa activar
        case 7: tel->Bluetooth =1; break;
        case 6: tel->Wifi=1; break;
        case 5: tel->GPS=1; break;
        case 4: tel->Datos=1; break;
        case 3: tel->Frontal=1; break;
        case 2: tel->Trasera=1; break;
        case 1: tel->Linterna=1; break;
        default: tel->Vibrar=1; break;
    }

}

// void verBits(int numero){
//     int i, mascara=1, aux;
//     mascara <<= 7; // 10000000

//     for (i=0; i<8; i++){
//         aux= numero & mascara; //no lo puedo poner directo en la comparacion!!
//         if( aux !=0 )//coincide el bit
//             printf("1");
//         else 
//         printf("0");
//         mascara >>= 1;
//     }

//     printf("\n");
// }


