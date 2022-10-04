#include <stdio.h>
#include <malloc.h>
struct pa{
    char nom[20];
    char sex;
    int edad;
    int dni;
    int cod;
};
struct nodo{
    pa pac;
    struct nodo *sig;
};
typedef struct nodo *puntero;
void busc(puntero cb,int dnib,int ob){
    if(cb==NULL){
        printf("\n El paciente no esta en la lista");
    }
    else{
        if(cb->pac.dni==dnib){
            cb->pac.cod=ob;
        }
        else{
            busc(cb->sig,dnib,ob);
        }
    }
}
void calc(puntero cb, int &tot,int &at){
    if(cb!=NULL){
        if(cb->pac.sex=='F'&& cb->pac.edad>50){
            at+=1;
        }
        calc(cb->sig,tot,at);
        tot+=1;
    }
    else{
        return;
    }
}
void recorre(puntero cb){
    while(cb!=NULL){
        printf("\n Nombre: %s",cb->pac.nom);
        printf("\n DNI: %d",cb->pac.dni);
        printf("\n Edad: %d",cb->pac.edad);
        printf("\n Sexo: %c",cb->pac.sex);
        printf("\n Codigo: %d",cb->pac.cod);
        cb=cb->sig;
    }
}
void inser(puntero &cb){
    int band=1;
    puntero nuevo;
    while(band!=0){
        nuevo=(puntero)malloc(sizeof(struct nodo));
        printf("\n Ingrese nombre del paciente:");
        fflush(stdin);
        gets(nuevo->pac.nom);
        printf("\n Ingrese DNI:");
        scanf("%d",&nuevo->pac.dni);
        printf("\n Ingrese edad:");
        scanf("%d",&nuevo->pac.edad);
        printf("\n Ingrese sexo:");
        fflush(stdin);
        scanf("%c",&nuevo->pac.sex);
        printf("\n Ingrese codigo:");
        scanf("%d",&nuevo->pac.cod);
        nuevo->sig=cb;
        cb=nuevo;
        printf("\n Ingrese 0 para terminar o otro num para seguir:");
        scanf("%d",&band);
    }
    return;
}
void crear(puntero &cb){
    cb=NULL;
}
int main(){
    puntero cb;
    int tot=0,at=0,dnib,ob;
    crear(cb);
    inser(cb);
    recorre(cb);
    calc(cb,tot,at);
    printf("\n Total de atendidos: %d",tot);
    printf("\n Mujeres mas de 50: %d",at);
    printf("\n Ingrese DNI a buscar:");
    scanf("%d",&dnib);
    printf("\n Ingrese obra social a cambiar:");
    scanf("%d",&ob);
    busc(cb,dnib,ob);
}
