#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct li{
    char nom[20];
    char aut[20];
    int cnt;
    int cod;
};
void agregar(FILE *ar){
    return;
}
void buscaraut(FILE *ar){
    li c;
    char au[20];
    int cnt=0;
    printf("\n Ingrese autor:");
    fflush(stdin);
    gets(au);
    fseek(ar,0,SEEK_SET);
    while(fread(&c,sizeof(c),1,ar)){
        if(strcmp(c.aut,au)==0){
            fseek(ar,sizeof(c),SEEK_CUR);
            printf("\n Libro del autor: %s",c.nom);
            cnt+=1;
        }
    }
    if(cnt==0){
        printf("\n El autor no tiene libros.");
    }
    return;
}
void buscart(FILE *ar){
    li c;
    char tit[20];
    int b;
    printf("\n Ingrese titulo del libro:");
    fflush(stdin);
    gets(tit);
    while(strcmp(tit,"FIN")){
        b=0;
        fseek(ar,0,SEEK_SET);
        while((b==0) && fread(&c,sizeof(c),1,ar)){
            if(strcmp(c.nom,tit)==0){
                b=1;
            }
        }
        if(b==1){
            fseek(ar,sizeof(c),SEEK_CUR);
            printf("\n El autor del libro es: %s",c.aut);
        }
        else{
            printf("\n El libro no existe");
        }
        strcpy(tit,"FIN");
    }
    return;
}
void buscar(FILE *ar){
    li c;
    int cd,b;
    printf("\n Ingrese el codigo del libro al buscar:");
    scanf("%d",&cd);
    while(cd!=0){
        b=0;
        fseek(ar,0,SEEK_SET);
        while((b==0)&&fread(&c,sizeof(c),1,ar)){
            if(c.cod==cd){
                printf("\n este es el codigo ing %d y el leido: %d \n",cd,c.cod);
                b=1;
            }
        }
        if(b==1){
            fseek(ar,sizeof(c),SEEK_CUR);
            printf("\n Nombre: %s \n Autor: %s \n Stock: %d",c.nom,c.aut,c.cnt);
        }
        else{
            printf("\n El libro no existe");
        }
        cd=0;
    }
    return;
}
void cargar(FILE *ar){
    li c;
    printf("\n Ingrese codigo del libro o 0 para terminar: ");
    scanf("%d",&c.cod);
    while(c.cod!=0){
        printf("\n Ingrese nombre del libro:");
        fflush(stdin);
        gets(c.nom);
        printf("\n Ingrese autor del libro:");
        fflush(stdin);
        gets(c.aut);
        printf("\n Ingrese cantidad del libro:");
        scanf("%d",&c.cnt);
        fwrite(&c,sizeof(c),1,ar);
        printf("\n Ingrese el codigo del libro o 0 para terminar:");
        scanf("%d",&c.cod);
    }
    return;
}
typedef struct nodo *puntero;
int main(){
    FILE *ar;
    if((ar=fopen("TITULOS.dat","w+"))==NULL){
        printf("\n error");
    }
    else{
        cargar(ar);
        buscar(ar);
        buscart(ar);
        buscaraut(ar);
        agregar(ar);
    }
}