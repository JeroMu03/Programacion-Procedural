#include <stdio.h>
#include <string.h>
const int N=3;
struct pro{
    int cod;
    char nom[20];
    float pre;
    int stock;
    int vend;
};
void total(pro a[]){
    int i;
    for(i=0; i<N; i++){
        printf("\n Para el articulo: %s, el monto total obtenido por las ventas es: %f",a[i].nom, a[i].pre*a[i].vend);
    }
    return;
}
void mostrar(pro a[]){
    int i;
    for(i=0; i<3; i++){
        printf("\n Los 20 productos quedaron con mas stock son: %s",a[i].nom);
    }
    return;
}
void ord(pro a[]){
    int k,i,cota;
    pro aux;
    cota=N-1;
    k=1;
    while(k!=-1){
        k=-1;
        for(i=0;i<cota;i++){
            if(a[i].stock<a[i+1].stock){
                aux=a[i];
                a[i]=a[i+1];
                a[i+1]=aux;
                k=i;
            }
        }
        cota=k;
    }
    return;
}
int stock(pro a[],int &nul){
    int i,cntnul=0,cntpre=0;
    for(i=0;i<N;i++){
        if(a[i].stock==0){
            cntnul+=1;
        }
        if(a[i].pre>7000){
            cntpre+=0;
        }
    }
    nul=cntnul;
    return cntpre;
}
void carga(pro a[]){
    int i=0,comp,vend;
    char busq[20], fin[20]="FIN";
    printf("\n Ingrese el nombre del producto: ");
    fflush(stdin);
    gets(busq);
    while(strcasecmp(busq,fin)!=0){
        while(comp=strcasecmp(busq,a[i].nom)!=0){
            i+=1;
        }
        if(comp==0){
            printf("\n Ingrese las unidades vendidas: ");
            scanf("%d",&vend);
            a[i].stock=a[i].stock-vend;
            a[i].vend+=vend;
        }
        else{
            printf("\n El producto no se encontro");
        }
        i=0;
        comp=100;
        printf("\n Ingrese el nombre de otro producto o FIN para terminar: ");
        fflush(stdin);
        gets(busq);
    }
    return;
}
void set(pro a[]){
    int i;
    for(i=0;i<N;i++){
        printf("\n Ingrese nombre del producto: ");
        fflush(stdin);
        gets(a[i].nom);
        printf("\n Ingrese codigo para el producto: ");
        scanf("%d",&a[i].cod);
        printf("\n Ingrese precio unitario del producto: ");
        scanf("%d",&a[i].pre);
        printf("\n Ingrese stock del producto: ");
        scanf("%d",&a[i].stock);
    }
    return;
}
int menu(){
    int d;
    printf("\n Elija una opcion: \n");
    printf("1-Set \n");
    printf("2-Carga \n");
    printf("3-Stock nulo y precio mayor a 7000 \n");
    printf("4-Articulos mayor stock \n");
    printf("5-Monto total \n");\
    printf("0-Salir \n");
    scanf("%d",&d);
    return d;
}
void cereo(pro a[]){
    int i;
    for(i=0; i<N; i++){
        a[i].cod=0;
        a[i].stock=0;
    }
    return;
}
int main(){
    pro a[N];
    int op,nul,pre;
    cereo(a);
    do{
        op=menu();
        switch(op){
            case 0: break;
            case 1:{
                set(a);
                break;
            }
            case 2:{
                carga(a);
                break;
            }
            case 3:{
                pre=stock(a,nul);
                printf("\n La cantidad de productos con stock nulo es de: %d",nul);
                printf("\n La cantidad de productos con el precio mayor a 7000 es de: %d",pre);
                break;
            }
            case 4:{
                ord(a);
                mostrar(a);
                break;
            }
            case 5:{
                total(a);
                break;
            }
        }
    }
    while(op!=0);
}