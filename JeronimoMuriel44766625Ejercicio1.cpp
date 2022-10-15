//Jeronimo Muriel
//44766626
//E014-31-E010-43
//TUPW-LCC
#include <stdio.h>
#include <malloc.h>
int N;
struct as{
    char nom[20];
    int ed;
};
void mosyed(as *&p){
    int i;
    float acum=0;
    for(i=0;i<N;i++){
        printf("\n El nombre del asistente %d es: %s",i+1,p[i].nom);
        acum+=p[i].ed;
    }
    printf("\n La edad promedio es de: %f",acum/N);
    return;
}
void carga(as *&p){
    int i;
    for(i=0;i<N;i++){
        printf("\n Ingrese el nombre del asistente %d:",i+1);
        fflush(stdin);
        gets(p[i].nom);
        printf("\n Ingrese la edad:");
        scanf("%d",&p[i].ed);
    }
    return;
}
void cnt(as *&p){
    printf("\n Ingrese la cantidad de asistentes:");
    scanf("%d",&N);
    p=(as*)malloc(N*sizeof(as));
    return;
}
int main(){
    as *p;
    cnt(p);
    carga(p);
    mosyed(p);
    free(p);
}