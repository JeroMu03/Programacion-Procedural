#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct as{
    char nom[20];
    int ed;
};
void prome(FILE *archi,float &prom){
    as c;
    int cont=0;
    rewind(archi);
    fread(&c,sizeof(c),1,archi);
    while(feof(archi)==0){
        prom+=c.ed;
        cont+=1;
        fread(&c,sizeof(c),1,archi);
    }
    prom=prom/cont;
    return;
}
void may40(FILE *archi){
    as c;
    rewind(archi);
    fread(&c,sizeof(c),1,archi);
    while(feof(archi)==0){
        if(c.ed>40){
            printf("\n Nombre: %s, Edad: %d",c.nom,c.ed);
        }
        fread(&c,sizeof(c),1,archi);
    }
    return;
}
void cargar(FILE *archi){
    as c;
    printf("\n Ingrese el nombre del asistente:");
    fflush(stdin);
    gets(c.nom);
    while(strcmp(c.nom,"FIN")){
        printf("\n Ingrese edad del asistente:");
        scanf("%d",&c.ed);
        fwrite(&c,sizeof(c),1,archi);
        printf("\n Ingrese el nombre del alumno o FIN para termiar:");
        fflush(stdin);
        gets(c.nom);
    }
    return;
}
int main(){
    FILE *archi;
    float prom=0;
    if((archi=fopen("Asistentes.dat","w+"))==NULL){
        printf("hay error1 \n");
    }
    else{
        cargar(archi);
        may40(archi);
        prome(archi,prom);
        printf("\n La edad promedio es de: %f",prom);
        fclose(archi);
    }
}