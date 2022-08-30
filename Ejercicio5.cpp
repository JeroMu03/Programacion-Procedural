#include <stdio.h>
#include <string.h>
const int N=6;
const int M=4;
struct sala{
    char nom[20];
    int par;
};
void mena(int b[N][M], sala a[]){
    int i, j;
    
}
void men1(int b[N][M]){
    int i,j,men,turnmen;
    for(i=0;i<N;i++){
        men=b[i][0];
        for(j=1;j<M;j++){
            if(b[i][j]<men){
                men=b[i][j];
                turnmen=j;
            }
        }
        printf("El turno con menor asistencia para el area %d es: es %d con: %d asistentes",i+1,j+1,men);
    }
}
void may1(int b[N][M]){
    int i,j,may,turnmay;
    for(i=0;i<N;i++){
        may=b[i][0];
        for(j=1;j<M;j++){
            if(b[i][j]>may){
                may=b[i][j];
                turnmay=j;
            }
        }
        printf("El turno con mayor asistencia para el area %d es %d con: %d asistentes",i+1,j+1,may);
    }
}
void carga(sala a[],int b[N][M], int c[N][M]){
    int i,j,band=1,comp;
    char nombreb[20];
    while(band!=0){
        printf("\n Ingrese el nombre del area al que desea inscribirse: ");
        scanf("%s",&nombreb);
        while(comp=strcasecmp(nombreb,a[i].nom)!=0){
            i+=1;
        }
        if(comp==0){
            printf("\n Ingrese el turno al que desea inscribirse: ");
            scanf("%d",&j);
            if(c[i][j]>0){
                c[i][j]-=1;
                b[i][j]+=1;
                printf("\n Inscripcion exitosa!");
            }
            else{
                printf("\n No hay cupo");
            }
        }
        else{
            printf("\n El area no existe");
        }
        i=0;
        comp=100;
    }
    return;
}
void set(sala a[],int c[N][M]){
    int i,j;
    for(i=0; i<N; i++){
        printf("\n Ingrese el nombre del area tematica %d:",i+1);
        fflush(stdin);
        gets(a[i].nom);
        for(j=0; j<M; j++){
            printf("\n Ingrese el cupo del area para el turno %d: ",j+1);
            scanf("%d",c[i][j]);
        }
    }
    return;
}
void cero(int b[N][M]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            b[i][j]=0;
        }
    }
    return;
}
int menu(){
    int d;
    printf("\n Elija una opcion: \n");
    printf("1-Set \n");
    printf("2-Carga \n");
    printf("3-Conferencias con mayor y menor asistentes \n");
    printf("4-Menos inscriptos \n");
    printf("5-Promedio de inscriptos por area \n");
    printf("6-Area con cupo completo \n");
    printf("0-Salir \n");
    scanf("%d",&d);
    return d;
}
int main(){
    sala a[N];
    int b[N][M],c[N][M],op;
    cero(b);
    do{
        op=menu();
        switch(op){
            case 0: break;
            case 1:{
                set(a,c);
                break;
            }
            case 2:{
                carga(a,b,c);
                break;
            }
            case 3:{
                may1(b);
                men1(b);
                break;
            }
            case 4:{
                mena(b,a);
                break;
            }
            case 5:{
                men(a,b);
                break;
            }
            case 6:{
                nom(a,b);
                break;
            }
            case 7:{
                cup(a);
                break;
            }
        }
    }while(op!=0); 
}