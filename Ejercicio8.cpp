#include <stdio.h>
#include <string.h>
const int N=12;
const int M=8;
void superprom(int ven[N][M],float prom){
    int mes,dep;
    printf("\n Ingrese mes de la venta: ");
    scanf("%d",&mes);
    printf("\n Ingrese departamento de la venta: ");
    scanf("%d",&dep);
    if(ven[mes-1][dep-1]>prom){
        printf("\n El importe supera el promedio");
    }
    else{
        printf("\n El importe no supera el promedio");
    }
    return;
}
float promedio(int ven[N][M]){
    int i,j,acum;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            acum+=ven[i][j];
        }
    }
    acum=acum/(N*M);
    printf("\n El promedio de ventas es: %f",acum);
    return acum;
}
int menos(int ven[N][M]){
    int i,busq,menor,c;
    printf("\n Ingrese el mes que desea buscar: ");
    scanf("%d",&busq);
    menor=ven[busq-1][0];
    for(i=1;i<M;i++){
        if(ven[busq-1][i]<menor){
            menor=ven[busq-1][i];
            c=i;
        }
    }
    return c;
}
void cerear(int ven[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            ven[i][j]=0;
        }
    }
    return;
}
void carga(int ven[N][M]){
    int mes,dep,imp;
    cerear(ven);
    printf("\n Ingrese el departamento de la venta: ");
    scanf("%d",&dep);
    printf("\n Ingrese el mes de la venta: ");
    scanf("%d",&mes);
    while(mes!=0){
        printf("\n Ingrese el importe de la venta: ");
        scanf("%d",&imp);
        ven[mes-1][dep-1]+=imp;
        printf("\n Ingrese el departamento de la venta: ");
        scanf("%d",&dep);
        printf("\n Ingrese el mes de la venta o 0 para terminar la carga: ");
        scanf("%d",&mes);
    }
    return;   
}
int main(){
    int ven[N][M],depmen;
    float prom;
    carga(ven);
    depmen=menos(ven);
    printf("\n El departamento que menos vendio es: %d",depmen+1);
    prom=promedio(ven);
    superprom(ven,prom);
}