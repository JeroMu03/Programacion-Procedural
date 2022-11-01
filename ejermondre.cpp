#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct su{
    int nr;
    int con;
    char dep[20];
};
struct nodo1{
    su cl;
    struct nodo1 *sig;
};
struct nodo{
    su cl;
    struct nodo *sig;
};
typedef struct nodo *puntero;
typedef struct nodo1 *puntero1;
void lisin(puntero1 cbs){
    if(cbs!=NULL){
        printf("\n No recibe \n Numero cuenta: %d \n Consumo: %d \n Departamento: %s",cbs->cl.nr,cbs->cl.con,cbs->cl.dep);
        lisin(cbs->sig);
    }
    else{
        return;
    }
}
void lisub(puntero cb){
    if(cb!=NULL){
        printf("\n Recibe \n Numero cuenta: %d \n Consumo: %d \n Departamento: %s",cb->cl.nr,cb->cl.con,cb->cl.dep);
        lisub(cb->sig);
    }
    else{
        return;
    }
}
void carga(puntero &cb, puntero1 &cbs,FILE *us){
    puntero nv;
    puntero1 nv1;
    su c;
    fseek(us,0,SEEK_SET);
    while(fread(&c,sizeof(c),1,us)){
        if(c.con<100){
            nv=(puntero)malloc(sizeof(struct nodo));
            nv->cl=c;
            nv->sig=cb;
            cb=nv;
        }
        else{
            nv1=(puntero1)malloc(sizeof(struct nodo1));
            nv1->cl=c;
            nv1->sig=cbs;
            cbs=nv1;
        }
    }
    return;
}
void crear(puntero &cb,puntero1 &cbs){
    cb=NULL;
    cbs=NULL;
    return;
}
void listarar(FILE *us){
    su c;
    while(fread(&c,sizeof(c),1,us)){
        printf("\n Numero cuenta: %d \n Consumo: %d \n Departamento: %s",c.nr,c.con,c.dep);
    }
    return;
}
void cargaus(FILE *us){
    su usu;
    printf("\n Ingrese numero de cuenta:");
    scanf("%d",&usu.nr);
    while(usu.nr!=0){
        printf("\n Ingrese el consumo: ");
        scanf("%d",&usu.con);
        printf("\n Ingrese departamento:");
        fflush(stdin);
        gets(usu.dep);
        fwrite(&usu,sizeof(usu),1,us);
        printf("\n Ingrese numero de cuenta o 0 para terminar:");
        scanf("%d",&usu.nr);
    }
    return;
}
int main(){
    puntero cb;
    puntero1 cbs;
    FILE *us;
    if((us=fopen("us.dat","r+"))==NULL){
        if((us=fopen("us.dat","w+"))==NULL){
            printf("\n Hay error");
        }
        else{
            cargaus(us);
        }
    }
    crear(cb,cbs);
    carga(cb,cbs,us);
    lisub(cb);
    lisin(cbs);
}