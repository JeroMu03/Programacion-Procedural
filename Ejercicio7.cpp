#include <stdio.h>
int const F=2;
int const M=3;
void vend(int farm[F][M]){
    int cod,i,mayor,codmayor;
    printf("\n Ingrese el codigo de farmacia: ");
    scanf("%d",&cod);
    mayor=farm[cod-1][0];
    for(i=1;i<M;i++)
    {
        if(farm[cod-1][i]>mayor){
            mayor=farm[cod-1][i];
            codmayor=i;
        }
    }
    printf("\n El medicamento mas vendido en la farmacia: %d, es el numero: %d:",cod,codmayor+100);
    return;
}
void total(int farm[F][M]){
    int i,j,acum=0;
    for(j=0;j<M;j++){
        printf("\n estoy en la columna %d",j);
        for(i=0;i<F;i++){
            printf("\n estoy en la fila %d",i);
            acum += farm[j][i];
            printf("\n contenido acum %d",acum);
        }
        printf("\n El total vendido para el medicamento %d es de: %d",j+100,acum);
        acum=0;
    }
    return;
}
void cerear(int farm[F][M]){
    int i,j;
    for(i=0;i<F;i++){
        for(j=0;j<M;j++){
            farm[i][j]=0;
        }
    }
    return;
}
void carga(int farm[F][M]){
    int i,cod=100,cnt;
    cerear(farm);
    printf("\n Ingrese el codigo de medicamento para la farmacia %d: ", i+1);
    scanf("%d",&cod);
    for(i=0;i<F;i++){
        while(cod!=0){
            printf("\n Ingrese las unidades vendidas del medicamento: ");
            scanf("%d",&cnt);
            farm[i][cod-100]+=cnt;
            printf("\n esto se guarda rey: %d",farm[i][cod-100]);
            printf("\n Ingrese el codigo de medicamento para la farmacia %d: ", i+1);
            scanf("%d",&cod);
        }
        cod=100;
    }
    return;
}
main(){
    int farm[F][M];
    carga(farm);
    total(farm);
    vend(farm);
}