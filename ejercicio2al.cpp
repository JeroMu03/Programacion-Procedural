#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct all{
    char nom[20];
    int nr;
    char re;
};
void listar(FILE *archi){
    all c;
    rewind(archi);
    while(fread(&c,sizeof(c),1,archi)!=0){
        printf("\n Nombre del alumno: %s,Registro del alumno: %d,Resultado: %c",c.nom,c.nr,c.re);
    } 
    return;
}
void carga(FILE *archi){
    all c;
    printf("\n Ingrese nombre del alumno: ");
    fflush(stdin);
    gets(c.nom);
    while(strcmp(c.nom,"FIN")){
        printf("\n Ingrese numero de registro: ");
        scanf("%d",&c.nr);
        printf("\n Aprobo o reprobo: ");
        fflush(stdin);
        scanf("%c",&c.re);
        fwrite(&c,sizeof(c),1,archi);
        printf("\n Ingrese nombre alumno o termine con FIN: ");
        fflush(stdin);
        gets(c.nom);
    }
    return;
}
int main(){
    FILE *archi;
    if((archi=fopen("alumnosAL.dat","w+"))==NULL){
        printf("error \n");
    }
    else{
        carga(archi);
        listar(archi);
        fclose(archi);
    }
}