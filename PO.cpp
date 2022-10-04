#include <stdio.h>
#include <malloc.h>
const int N=6;
struct obra{
    char nomb[20];
    int cnt;
};
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
void set(obra arre[N]){
    int i;
    for(i=0;i<N;i++){
        printf("\n Ingrese el nombre de la obra social:");
        fflush(stdin);
        gets(arre[i].nomb);
    }
    return;
}
void cereo (obra arre[N]){
    int i;
    for (i=0; i<N; i++){
        arre[i].cnt=0;
    }
    return;
}
void mostrar(obra arre[N], int i){
    if(i<N){
        printf("\n Los atendidos por la obra social %s son: %d",arre[i].nomb,arre[i].cnt);
        mostrar(arre,i+1);
    }
    else return;
}
void arreg(puntero cb, obra arre[N]){
    if(cb!=NULL){
        arre[cb->pac.cod-1].cnt+=1;
        arreg(cb->sig,arre);
    }
    else return;
}
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
int calc(puntero cb,int &at){
    if(cb!=NULL){
        if(cb->pac.sex=='F'&& cb->pac.edad>50){
            at+=1;
        }
        return 1+calc(cb->sig,at);
    }
    else{
        return 0;
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
        printf("\n Ingrese codigo:");
        scanf("%d",&nuevo->pac.cod);
        printf("\n Ingrese edad:");
        scanf("%d",&nuevo->pac.edad);
        printf("\n Ingrese sexo:");
        fflush(stdin);
        scanf("%c",&nuevo->pac.sex);
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
    int tot=0,at=0,dnib,ob,i=0;
    obra arre[N];
    crear(cb);
    inser(cb);
    recorre(cb);
    tot=calc(cb,at);
    printf("\n Total de atendidos: %d",tot);
    printf("\n Mujeres mas de 50: %d",at);
    printf("\n Ingrese DNI a buscar:");
    scanf("%d",&dnib);
    printf("\n Ingrese obra social a cambiar:");
    scanf("%d",&ob);
    busc(cb,dnib,ob);
    cereo(arre);
    set(arre);
    arreg(cb,arre);
    mostrar(arre,i);
}
