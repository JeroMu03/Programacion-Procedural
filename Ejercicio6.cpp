#include <stdio.h>
const int N=2;
const int M=2;
void prom(int arre[N][M]){
    int i,area, acum=0;
    printf("Ingrese el numero de area que desea saber la cantidad promedio: ");
    scanf("%d",&area);
    area=area-1;
    for(i=0;i<area;i++){
        acum+=arre[i][area];
    }
    printf("La cantidad promedio de inscriptos en esa area es de: %d", acum/N);
    return;
}
void cnt(int arre[N][M]){
    int i;
    int j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf("\n La cantidad de inscriptos en el turno: %d, en el area: %d, son: %d",i+1,j+1,arre[i][j]);
        }
    }
    return;
}
void carga(int arre[N][M]){
    int i,j,band=1;
    while(band==1){
        printf("\n Ingrese el turno del alumno: ");
        scanf("%d",&i);
        printf("\n Ingrese el area del alumno: ");
        scanf("%d",&j);
        arre[i-1][j-1]+=1;
        printf("\n Ingrese 1 para cargar otro alumno y cualquier numero para terminar: ");
        scanf("%d",&band);
    }
    return;
}
void set(int arre[N][M]){
    int i;
    int j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            arre[i][j]=0;
        }
    }
    return;
}
main(){
    int arre[N][M];
    set(arre);
    carga(arre);
    cnt(arre);
    prom(arre);
}