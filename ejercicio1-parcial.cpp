#include <stdio.h>
#include <malloc.h>
#include <string.h>
int N=6;
struct ob{
    char nom[20];
    int cnt;
};
struct pac{
    char nom[20];
    int dni;
    int cod;
    int ed;
    char sex;
};
struct nodo{
    pac pa;
    struct nodo *sig;
};
typedef struct nodo *puntero;
void mostrar(ob arre[]){
    int i;
    for(i=0;i<N;i++){
        printf("\n Nombre obra social: %s",arre[i].nom);
        printf("\n Cnt obra social: %s",arre[i].nom);
    }
    return;
}
void obra(puntero cb,ob arre[]){
    if(cb!=NULL){
        arre[cb->pa.cod-1].cnt+=1;
        obra(cb->sig,arre);
    }
    else{
        arre[cb->pa.cod-1].cnt+=1;
        return;
    }
}
void dni(puntero &cb,int d){
    if(cb!=NULL){
        if(cb->pa.dni==d){
            cb->pa.dni=d;
            return;
        }
        dni(cb->sig,d);
    }
    else{
        if(cb->pa.dni==d){
            cb->pa.dni=d;
        }
        else printf("\n No se encontro");
    return; 
    }
}
int recur(puntero cb,int tot,int &muj){
    if(cb!=NULL){
        tot+=1;
        if(cb->pa.ed>50 && cb->pa.sex=='F'){
            muj+=1;
        }
        recur(cb->sig, tot,muj);
    }
    else{
        tot+=1;
        if(cb->pa.ed>50 && cb->pa.sex=='F'){
            muj+=1;
        }
        return;
    }
}
void nom(ob arre[]){
    int i;
    for(i=0;i<N;i++){
        printf("\n Cargue nombre obra social %d: ",i+1);
        fflush(stdin);
        gets(arre[i].nom);
    }
    return;
}
void ins(puntero &cb){
    int codi;
    puntero nv;
    printf("\n Ingrese codigo de obra social del paciente y 0 para terminar:");
    scanf("%d",&codi);
    while(codi!=0){
        nv=(puntero)malloc(sizeof(struct nodo));
        nv->pa.cod=codi;
        printf("\n Ingrese nombre del paciente: ");
        fflush(stdin);
        gets(nv->pa.nom);
        printf("\n Ingrese DNI del paciente: ");
        scanf("%d",&nv->pa.dni);
        printf("\n Ingrese la edad del paciente: ");
        scanf("%d",&nv->pa.ed);
        printf("\n Ingrese el sexo del paciente: ");
        fflush(stdin);
        scanf("%c",nv->pa.sex);
        nv->sig=cb;
        cb=nv;
        printf("\n Ingrese codigo de obra social del paciente y 0 para terminar:");
        scanf("%d",&codi);
    }
    return;
}
void crea(puntero &cb){
    cb=NULL;
    return;
}
void cero(ob arre[]){
    int i;
    for(i=0;i<N;i++){
        arre[i].cnt=0;
    }
    return;
}
int main(){
    int tot=0,muj=0,d;
    ob arre[N];
    puntero cb;
    cero(arre);
    crea(cb);
    ins(cb);
    tot=recur(cb,tot,muj);
    printf("\n Ingrese DNI a buscar: ");
    scanf("%d",d);
    dni(cb,d);
}