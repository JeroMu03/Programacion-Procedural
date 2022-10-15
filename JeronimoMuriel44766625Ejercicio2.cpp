//Jeronimo Muriel
//44766626
//E014-31-E010-43
//TUPW-LCC
#include <stdio.h>
#include <malloc.h>
struct nodo{
    int cod;
    float pre;
    struct nodo *sig;
};
typedef struct nodo *puntero;
void mayor(puntero cb, int &caro,float may){
    if(cb!=NULL){
        if(cb->pre>may){
            may=cb->pre;
            caro=cb->cod;
        }
        mayor(cb->sig,caro,may);
    }
    else{
        return;
    }
}
void mostrar(puntero cb){
    if(cb!=NULL){
        printf("\n Codigo: %d",cb->cod);
        printf("\n Precio: %f",cb->pre);
        mostrar(cb->sig);
    }
    else{
        return;
    }
}
void carga(puntero &cb){
    int band=1;
    puntero n;
    while(band!=0){
        n=(puntero)malloc(sizeof(struct nodo));
        printf("Ingrese codigo del producto:");
        scanf("%d",&n->cod);
        printf("Ingrese precio del producto:");
        scanf("%f",&n->pre);
        n->sig=cb;
        cb=n;
        printf("Ingrese 0 para terminar o cq otro numero para continuar:");
        scanf("%d",&band);
    }
    return;
}
void crear(puntero &cb){
    cb=NULL;
    return;
}
int main(){
    puntero cb;
    int caro;
    float may=0;
    crear(cb);
    carga(cb);
    mostrar(cb);
    mayor(cb,caro,may);
    printf("\n El codigo del producto mas caro es: %d",caro);
}