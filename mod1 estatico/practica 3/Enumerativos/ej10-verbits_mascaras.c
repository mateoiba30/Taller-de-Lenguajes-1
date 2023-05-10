#include <stdio.h>
typedef enum { 
    Bluetooth=128,
    Wifi=64,
    GPS=32,
    Datos=16,
    Frontal=8,
    Trasera=4,
    Linterna=2,
    Vibrar=1
    } Telefono;//SOLO PUEDEN SER CARACTERES

int activarModulo(Telefono, char*[]);
int desactivarModulo(Telefono, char*[]);
int invertirModulo(Telefono, char*[]);
int verEncendido(Telefono, char*[]);//tmb pueden devolver Telefono


void verBits(int);

int main(){
    // int tel1=0;
    Telefono tel1;
    char* mods[]={"Vibrar","Linterna","Trasera", "Frontal",  "Datos","GPS", "Wifi", "Bluetooth"   };

    tel1=activarModulo(tel1, mods);
    tel1=desactivarModulo(tel1, mods);
    tel1=invertirModulo(tel1, mods);
    printf("telefono: %d \n", tel1);
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
    mascara= 1;
    mascara <<= x;//situamos la mascara en el bit deseado
    
    if(tel & mascara)//si no da cero, está prendido
        rta=1;
    else
        rta=0;
    
    return rta;
}

int invertirModulo(Telefono tel,char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a invertir: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    mascara= 1;
    mascara <<= x;//situamos la mascara en el bit deseado
    tel ^= mascara;//XOR devuelve 1 si hay 1 único 1

    return tel;
}

int desactivarModulo(Telefono tel, char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a desactivar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    mascara= 1;
    mascara <<= x;//situamos la mascara en el bit deseado

    // switch(x){ //ESTA BIEN ESTA OPCION
    //     case 0: tel-=Vibrar;
    //     case 1: tel-=Linterna;
    //     case 2: tel-=Trasera;
    //     case 3: tel-=Frontal;
    //     case 4: tel-=Datos;
    //     case 5: tel-=GPS;
    //     case 6: tel-=Wifi;
    //     case 7: tel-=Bluetooth;     
    // }    
    
    // verBits(tel);
    // verBits(mascara);

    //debería usar un NOR, pero no hay en C, así 1 1° me fijo si está prendido
    if(tel & mascara)//si da 1 es porque está prendida
        tel ^= mascara;
    // printf("XOR-------------\n");
    // verBits(tel);

    return tel;

}

int activarModulo(Telefono tel, char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a activar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    // printf("%d", x);

    // switch(x){ //ESTA BIEN ESTA OPCION
    //     case 0: tel+=Vibrar;
    //     case 1: tel+=Linterna;
    //     case 2: tel+=Trasera;
    //     case 3: tel+=Frontal;
    //     case 4: tel+=Datos;
    //     case 5: tel+=GPS;
    //     case 6: tel+=Wifi;
    //     case 7: tel+=Bluetooth;     
    // }

    mascara= 1;
    mascara <<= x;
    // verBits(tel);
    // verBits(mascara);
    tel |= mascara;//si estaba prendido lo dejo prendido con el OR
    // printf("OR-------------\n");
    // verBits(tel);

    return tel;

}

void verBits(int numero){
    int i, mascara=1, aux;
    mascara <<= 7; // 10000000

    for (i=0; i<8; i++){
        aux= numero & mascara; //no lo puedo poner directo en la comparacion!!
        if( aux !=0 )//coincide el bit
            printf("1");
        else 
        printf("0");
        mascara >>= 1;
    }

    printf("\n");
}