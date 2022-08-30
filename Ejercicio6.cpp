#include <stdio.h>
#include <string.h>
const int N=6;
const int M=8;
void super(float arre[N][M],float prome){
    int i,j;
    float acum=0;
    for(j=0;j<M; j++){
        for(i=0;i<N; i++){
            acum+=arre[i][j];
        }
        if(acum>prome){
            printf("El departamento: %d, supera el promedio con un importe de: %f",j+1,acum);
        }
        acum=0;
    }
}
float prom(float arre[N][M]){
    int i,j;
    float acum=0;
    for(i=0;i<N; i++){
        for(j=0;j<M;j++){
            acum+=arre[i][j];
        }
    }
    acum=acum/(N*M);
    printf("\n El promedio de ventas del supermercado es: %f",acum);
    return acum;
}
int menor(float arre[N][M]){
    int i,j,mesmen;
    float menor=arre[0][0];
    for(i=1;i<N;i++){
        for(j=1;j<M;j++){
            if(arre[i][j]<menor){
                menor=arre[i][j];
                mesmen=j;
            }
        }
    }
    return j;
}
void carga(float arre[N][M]){
    int i,j,carg=1;
    float vent;
    while(carg!=0){
        printf("\n Ingrese el mes de la venta del 1 al 6: ");
        scanf("%d",&i);
        printf("\n Ingrese el departamento de la venta del 1 al 8: ");
        scanf("%d",&j);
        printf("\n Ingrese el importe de la venta: ");
        scanf("%d",&vent);
        arre[i][j]+=vent;
        printf("\n Ingrese 0 para terminar la carga o otro numero para continuar: ");
        scanf("%d",&carg);
    }
}
int menu(){
    int d;
    printf("\n Elija una opcion: \n");
    printf("1-Carga \n");
    printf("2-Mostrar menor importe de venta \n");
    printf("3-Promedio de venta \n");
    printf("4-Departamentos que superan la venta promedio \n");
    printf("0-Salir \n");
    scanf("%d",&d);
    return d;
}
void cero(float arre[N][M]){
    int i, j;
    for(i=0; i<N; i++){
        for(j=0;j<M;j++){
            arre[i][j]=0;
        }
    }
    return;
}
int main(){
    float arre[N][M],prome;
    int op,men;
    cero(arre);
    do{
        op=menu();
        switch(op){
            case 0: break;
            case 1:{
                carga(arre);
                break;
            }
            case 2:{
                men=menor(arre);
                printf("El mes con menor importe de venta es: %d",men);
                break;
            }
            case 3:{
                prome=prom(arre);
                break;
            }
            case 4:{
                super(arre,prome);
                break;
            }
        }
    }while(op!=0);
}