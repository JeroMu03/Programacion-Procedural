#include <stdio.h>
#include <malloc.h>
int N;
int M;
int O;
void mostrar2(int *&x){
    int i;
    for(i=0; i<O; i++){
        printf("\n impar %d",x[i]);
    }
    return;
}
int cimp(int *&p){
    int i,cont=0;
    for(i=0;i<N;i++){
        if(p[i]%2!=0){
            cont++;
        }
    }
    return cont;
}
void impa(int *&p,int *&x,int &O){
    int imp,i,j=0;
    imp=cimp(p);
    O=imp;
    x=(int*)malloc(imp*sizeof(int));
    for(i=0;i<N;i++){
        if(p[i]%2!=0){
            printf("\n aa %d",p[i]);
            x[j]=p[i];
            j++;
        }
    }
    return;
}
int producto(int *&p,int *&q,int i){
    if(i<N){
        return producto(p,q,i+1)+p[i]*q[i];
    }
    else{
        return 0;
    }
}
void mostrar(int *&p,int *&q){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n arreglo 1 %d",p[i]);
    }
    for(j=0;j<M;j++){
        printf("\n arreglo 2 %d",q[j]);
    }
    return;
}
void carga(int *&p,int *&q){
    int i,j;
    for(i=0;i<N;i++){
        printf("\n Ingrese numero arreglo 1 para %d ",i+1);
        scanf("%d",&p[i]);
    }
    for(j=0;j<M;j++){
        printf("\n Ingrese numero arreglo 2 para %d ",j+1);
        scanf("%d",&q[j]);
    }
    return;
}
void set(int *&p,int *&q,int &M,int &N){
    printf("\n Ingrese tamaño arreglo 1:");
    scanf("%d",&N);
    printf("\n Ingrese tamaño arreglo 2:");
    scanf("%d",&M);
    p=(int*)malloc(N*sizeof(int));
    q=(int*)malloc(M*sizeof(int));
    return;
}
int main(){
    int *p,*q,*x,i=0,produ,imp=0;
    set(p,q,M,N);
    carga(p,q);
    mostrar(p,q);
    produ=producto(p,q,i);
    printf("\n Producto; %d",produ);
    impa(p,x,O);
    mostrar2(x);   
}