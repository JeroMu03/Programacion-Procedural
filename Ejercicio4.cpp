#include <stdio.h>
const int N=6;
void encue(int arre[],int inf, int sup,int &may9,int &men5){
    if(inf!=sup){
        if(arre[inf]<5000){
            men5+=1;
        }
        if (arre[inf]>9000){
            may9+=1;
        }
        encue(arre,inf+1,sup,may9,men5);
    }
    else{
        return;
    }
}
void suma(int arre[],int inf, int sup, int max){
    if(inf!=sup){
        max+=arre[inf];
        suma(arre,inf+1,sup,max);
    }
    else{
        printf("\n El total de encuestas es de %d",max);
        return;
    }
}
void mayor(int arre[],int inf, int sup,int max,int cod){
    if(inf!=sup){
        if(arre[inf]>max){
            max=arre[inf];
            cod=inf;
        }
        mayor(arre,inf+1,sup,max,cod);
    }
    else{
        printf("\n El codigo mas elegido es: %d",cod+1);
        return;
    }
}
void menos(int arre[],int inf, int sup){
    if(inf!=sup){
        if(arre[inf]<4000){
            printf("\n El codigo %d fue elegido por menos de 4000",inf+1);
        }
        menos(arre,inf+1,sup);
    }
    else{
        return;
    }
}
void carga(int arre[],int inf,int sup) {
    if(inf!=sup){
        printf("\n Ingrese el numero de encuestados del codigo: %d \n",inf+1);
        scanf("%d",arre+inf);
        carga(arre,inf+1,sup);
    }
    else{
        printf("\n Arreglo cargado");
        return;
    }
}
int main(){
    int arre[N],sup=N,inf=0,max=0,cod,may9=0,men5=0;
    printf("\n Carga de los encuestados \n");
    carga(arre,inf,sup);
    menos(arre, inf,sup);
    mayor(arre,inf,sup,max,cod);
    suma(arre,inf,sup,max);
    encue(arre,inf,sup,may9,men5);
    printf("\n La cantidad de codigos con menos de 5000 encuestados es de: %d",men5);
    printf("\n La cantidad de codigos con mas de 9000 encuestados es de: %d",may9);
}