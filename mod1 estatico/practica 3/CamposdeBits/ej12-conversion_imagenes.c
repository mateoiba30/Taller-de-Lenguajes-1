#include<stdio.h>

typedef struct{
    unsigned red :8;
    unsigned green :8;
    unsigned blue :8;
}RGB24;

typedef struct{
    unsigned red :5;
    unsigned green :6;
    unsigned blue :5;
}RGB16;

RGB24 mejorarImagen(RGB16);
RGB16 empeorarImagen(RGB24);


int main(){
    RGB16 img16;
    RGB24 img24;

    // img16.red=10;
    // img16.green=10;
    // img16.blue=10;  

    // img24=mejorarImagen(img16);
    // printf("nueva imagen: %d %d %d", img24.red, img24.green, img24.blue);

    img24.red=10;
    img24.green=10;
    img24.blue=10;  

    img16=empeorarImagen(img24);
    printf("nueva imagen: %d %d %d", img16.red, img16.green, img16.blue);

    return 0;
}

RGB24 mejorarImagen (RGB16 img16){
    RGB24 img24;

    img24.red=img16.red;
    img24.green=img16.green;
    img24.blue=img16.blue;

    return img24;
}

RGB16 empeorarImagen (RGB24 img24){
    RGB16 img16;

    img16.red=img24.red;
    img16.green=img24.green;
    img16.blue=img24.blue;

    return img16;
}