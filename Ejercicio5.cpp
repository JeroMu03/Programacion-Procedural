#include <stdio.h>
const int N=5;
const int M=4;
void cien(int arre[N][M]){
    int i;
    int j, cont=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(arre[i][j]>100){
                cont++;
            }
        }
    }
    printf("\n Se ingresaron: %d mayores a 100", cont);
    return;
}
void prom(int arre[N][M]){
    int i, acum=0;
    for(i=0; i<N; i++){
        acum+=arre[i][3];
    }
    printf("\n El promedio de la columna 3 es de %d",acum/N);
}
void suma(int arre[N][M]){
    int i;
    int j, acum=0;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            acum+=arre[i][j];
        }
        printf("\n La suma de la fila: %d es: %d",i+1,acum);
        acum=0;
    }
    return;
}
void carga(int arre[N][M]){
    int i;
    int j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("\n Cargue un numero para la fila: %d y columna: %d: ",i+1,j+1);
            scanf("%d",&arre[i][j]);
        }
    }
    return;
}
main(){
    int arre[N][M];
    carga(arre);
    suma(arre);
    prom(arre);
    cien(arre);
}