#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct op{
    int num;
    float imp;
    int op;
};
struct nodo{
    op ope;
    struct nodo *sig;
};
typedef struct nodo *puntero;
void prome(FILE *ar,float &prom){
    op a;
    int cnt=0;
    rewind(ar);
    while(fread(&a,sizeof(a),1,ar)!=0){
        prom+=a.imp;
        cnt+=1;
    }
    prom=prom/cnt;
    return;
}
void liberar(puntero cb){
    puntero nv;
    while(cb!=NULL){
        nv=cb;
        cb=cb->sig;
        free(nv);
    }
    return;
}
void listar(FILE *ar){
    op c;
    rewind(ar);
    while(fread(&c,sizeof(c),1,ar)!=0){
        printf("\n Codigo op: %d,Importe: %f,tipo: %d",c.num,c.imp,c.op);
    } 
    return;
}
void carga(puntero cb,FILE *ar,op aux){
    if(cb!=NULL){
        if(cb->ope.op==2){
            aux.num=cb->ope.num;
            aux.imp=cb->ope.imp;
            aux.op=cb->ope.op;
            fwrite(&aux,sizeof(aux),1,ar);
        }
        carga(cb->sig,ar,aux);
    }
    else return;
}
void mayores(puntero cb,int may){
    if(cb!=NULL){
        if(cb->ope.imp==may && cb->ope.op==1){
            printf("\n num op: %d",cb->ope.num);
        }
        mayores(cb->sig,may);
    }
    else return;
}
void mayo(puntero cb, int &may){
    if(cb!=NULL){
        if(cb->ope.imp>may && cb->ope.op==1){
            may=cb->ope.imp;
        }
        mayo(cb->sig,may);
    }
    else return;
}
void insertar(puntero &cb){
    puntero nv;
    int ope;
    printf("\n Ingrese tipo de operacion:");
    scanf("%d",&ope);
    while(ope!=0){
        nv=(puntero)malloc(sizeof(struct nodo));
        nv->ope.op=ope;
        printf("\n Ingrese numero de operacion: ");
        scanf("%d",&nv->ope.num);
        printf("\n Ingrese el importe de la operacion:");
        scanf("%f",&nv->ope.imp);
        nv->sig=cb;
        cb=nv;
        printf("\n Ingrese tipo de operacion o 0 para terminar:");
        scanf("%d",&ope);
    }
    return;
}
void crear(puntero &cb){
    cb=NULL;
    return;
}
int main(){
    puntero cb;
    FILE *ar;
    int may=0;
    float prom=0;
    op aux;
    crear(cb);
    insertar(cb);
    mayo(cb,may);
    mayores(cb,may);
    if((ar=fopen("cajero.dat","w+"))==NULL){
        printf("Error");
    }
    else{
        carga(cb,ar,aux);
        listar(ar);
        liberar(cb);
        prome(ar,prom);
        printf("\n El importe promedio es de: %f",prom);

    }
}