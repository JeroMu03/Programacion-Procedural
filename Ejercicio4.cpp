#include <stdio.h>
#include <string.h>
const int N=2;
const int M=3;
struct pro{
    float pre;
    int cnt;
};
struct prove
{
    char nom[20];
    int num;
    int cntp;
};
void infp(prove p[M], int c){
    int i=0;
    char nombre[20];
    int bande=1;
    int enc=100;
    while(bande==1){
        printf("\n Ingrese nombre a buscar: ");
        fflush(stdin);
        gets(nombre);
        while (enc!=0 && i<c){
            enc=strcmp(nombre,p[i].nom);
            printf("%s",p[i].nom);
            i+=1;
        }
        printf("%s",p[i].nom);
        if(enc==0){
            printf("\n El proveedor de nombre: %s se encontro", nombre);
            printf("\n El numero es de proveedor es: %d y la cantidad de compras realizadas son: %d",p[i].num,p[i].cntp);
        }
        else{
            printf("\n No se encontro el proveedor");
        }
        printf("\n Ingrese 1 para continuar buscando y cualquier otro numero para termina: ");
        scanf("%d",&bande);
    }
    return;
}
void mostrar(prove p[M],int c){
    int i;
    for(i=0; i<c; i++){
        printf("\n Nombre: %s",p[i].nom);
    }
}
void ord(prove p[M],int c){
    int i,cota,k=1;
    prove aux;
    cota=c-1;
    while(k!=-1){
        k=-1;
        for(i=0;i<cota; i++){
            if(p[i].nom<p[i+1].nom){
                aux=p[i+1];
                p[i+1]=p[i];
                p[i]=aux;
                k=i;
            }
        }
    cota=k;
    }
    return;
}
int proveedores(prove b[M], prove p[M]){
    int i, c=0;
    for(i=0; i<M; i++){
        printf("\n %d este es cantidad de compras",b[i].cntp);
        if(b[i].cntp>1){
            p[c]=b[i];
            printf("%s",p[c].nom);
            c+=1;
        }
    }
    return (c);  
}
void dinero(pro a[N]){
    int i;
    float nashe;
    for(i=0;i<N;i++){
        nashe=a[i].pre*a[i].cnt;
        printf("\n El dinero invertido en el producto:  %d es de %f ",i+1,nashe);
    }
}
void carga(pro a[N],prove b[M]){
    int i,j, band=1, com;
    while (band==1){
        printf("\n Ingrese numero del proovedor: ");
        scanf("%d",&i);
        if(i==1021){
            i=i-1001;
        }
        else{
            i=i-1000;
        }
        printf("\n %d este es el i",i);
        printf("\n Ingrese codigo del producto: ");
        scanf("%d",&j);
        j=j-1;
        printf("\n Ingrese cantidad comprada del producto: ");
        scanf("%d",&com);
        a[j].cnt+=com;
        b[i].cntp+=1;
        printf("\n Ingrese 1 para nueva carga y otro numero para salir de la carga: ");
        scanf("%d",&band);
    }
    return;
}
void set(pro a[N], prove b[M]){
    int i;
    for(i=0; i<N; i++){
        printf("\n Ingrese el precio del producto %d :", i+1);
        scanf("%f", &a[i].pre);
        a[i].cnt = 0;
    }
    for(i=0; i<M; i++){
        b[i].cntp = 0;
        printf("\n Ingrese el nombre del proveedor : ");
        fflush(stdin);
        gets(b[i].nom);
        printf("\n Ingrese el codigo del proveedor : ");
        scanf("%d",&b[i].num);
    }
    return;
}
main(){
    pro a[50];
    prove b[M];
    prove p[M];
    int c;
    set(a,b);
    carga(a,b);
    dinero(a);
    c=proveedores(b,p);
    ord(p,c);
    mostrar(p,c);
    infp(p,c);
}
