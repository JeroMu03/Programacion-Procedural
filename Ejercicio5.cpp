#include <stdio.h>
#include <malloc.h>
struct nodo{
    int nro;
    struct nodo *sig;
};
typedef struct nodo * puntero;
void insertar(puntero &cb){
    int dato,band=1;
    puntero nuevo;
    while(band!=0){
        printf("\n Ingrese valor:");
        scanf("%d",&dato);
        if(dato>0){
            nuevo=(puntero)malloc(sizeof(struct nodo));
            nuevo->nro=dato;
            nuevo->sig=cb;
            cb=nuevo;
        }
        else{
            printf("\n Ingrese numeros positivos:");
        }
    printf("\n Ingrese 0 para terminar la carga o cq numero para continuar:");
    scanf("%d",&band);
    }
    return;
}
int main(){
    puntero cabeza;
    insertar(cabeza);
}