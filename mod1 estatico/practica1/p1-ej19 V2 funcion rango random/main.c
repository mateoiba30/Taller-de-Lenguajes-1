#include <stdio.h>
#include <stdlib.h>
int preguntas(int calificacion){
    srand(time(NULL));//para que cada vez diga distintas preguntas

    int x,y,rta,aux=-1;
    for(int i=1; i<=4; i++){
        printf("PREGUNTA %d: \n",i);
        x=rand()%101;
        y=rand()%101;
        rta=x+y;
        printf("%d + %d = ",x,y);
        scanf("%d",&aux);
        if(aux==rta)
            calificacion++;
    }

    return calificacion;
}
int main()
{
    int calificacion=0;
    calificacion=preguntas(calificacion);

    switch(calificacion){
  //      case 0: printf("E"); break;
        case 1: printf("D"); break;
        case 2: printf("C"); break;
        case 3: printf("B"); break;
        case 4: printf("A"); break;
        default: printf("E");break;//hace una comparacion menos con esto

    }
}
