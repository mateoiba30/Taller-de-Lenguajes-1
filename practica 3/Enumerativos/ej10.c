#include <stdio.h>
typedef enum { 
    Bluetooth=128,
    Wifi=64,
    GPS=32,
    Datos=16,
    Frontal=8,
    Trasera=4,
    Linterna=2,
    Vibrar=1} Telefono;//SOLO PUEDEN SER CARACTERES

int activarModulo(int, char*[]);
int desactivarModulo(int, char*[]);
void verBits(int);

int main(){
    int tel1=0;
    char* mods[]={"Vibrar","Linterna","Trasera", "Frontal",  "Datos","GPS", "Wifi", "Bluetooth"   };

    tel1=activarModulo(tel1, mods);
    tel1=desactivarModulo(tel1, mods);
    printf("telefono: %d", tel1);

    return 0;
}

// int invertirModulos(int tel){

// }

int desactivarModulo(int tel, char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a desactivar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i+1, mods[i]);
    }
    scanf("%d", &x);
    mascara= 1;
    mascara <<= x;//situamos la mascara en el bit deseado

    // switch(x){
    //     case 0: tel-=Vibrar;
    //     case 1: tel-=Linterna;
    //     case 2: tel-=Trasera;
    //     case 3: tel-=Frontal;
    //     case 4: tel-=Datos;
    //     case 5: tel-=GPS;
    //     case 6: tel-=Wifi;
    //     case 7: tel-=Bluetooth;     
    // }    
    
    verBits(tel);
    verBits(mascara);
    tel ^= mascara;
    printf("XOR-------------\n");
    verBits(tel);

    return tel;

}

int activarModulo(int tel, char* mods[]){
    int i, x, mascara;
    // char *mod;

    printf("Ingrese numero de modulo a activar: \n");
    for(i=0; i<8; i++){
        printf(" %d para %s \n", i, mods[i]);
    }
    scanf("%d", &x);
    // printf("%d", x);

    // switch(x){
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
    verBits(tel);
    verBits(mascara);
    tel |= mascara;
    printf("OR-------------\n");
    verBits(tel);

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