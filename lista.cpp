#include <stdio.h>
#include <malloc.h>
struct nodo{
    int nro;
    struct nodo *sig;
};
typedef struct nodo * puntero;
void recorre(puntero cb){
    while(cb!=NULL){
        printf("\n %d",cb->nro);
        cb=cb->sig;
    }
}
void insertar(puntero &cb){
    int dato;
    puntero nuevo;
    printf("\n Ingrese valor:");
    scanf("%d",&dato);
    while(dato!=0){
        nuevo=(puntero)malloc(sizeof(puntero));
        nuevo-> nro=dato;
        nuevo->sig=cb;
        cb=nuevo;
        printf("\n Ingrese nuevo valor:");
        scanf("%d",&dato);
    }
}
void crear(puntero &cb){
    cb=NULL;
}
int main(){
    puntero cb;
    crear(cb);
    insertar(cb);
    recorre(cb);
}