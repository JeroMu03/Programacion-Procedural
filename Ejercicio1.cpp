#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int N=4;
void mostrar(int arre[]){
    int i;
    for(i=0; i<N; i++){
        printf("\n %d",arre[i]);
    }
    return;
}
void leer(int arre[]){
    int i,busc;
    printf("\n Ingrese el numero a buscar:");
    scanf("%d",&busc);
    for(i=0; i<N; i++){
        if(busc==arre[i]){
            printf("\n El numero ingresado se encuentra en la posicion: %d",i+1);
        }
    }
    return;
}
int sum(int arre[], int &impar){
    int i,sp=0,si=0;
    for(i=0;i<N;i++){
        if(i%2==0){
            sp+=arre[i];
        }
        else{
            si+=arre[i];
        }
    }
    si*=impar;
    return sp;
}
bool nums(int arre[]){
    int i,mayor=0,menor=0;
    bool cond;
    for(i=0;i<N;i++){
        if(arre[i]>0){
            mayor=+1;
        }
        if(arre[i]<0){
            menor=+1;
        }
    }
    if(mayor>menor){
        cond=true;
    }
    if(mayor==menor){
        cond=false;
    }
    return cond;
}
void carga(int arre[]){
    int i;
    for(i=0;i<N;i++){
        arre[i]=rand();
    }
    return;
}
int main(){
    srand(time(NULL));
    int arre[N],par,impar;
    bool cond;
    printf("\n Resto de 2 es: %d",3%2);
    carga(arre);
    mostrar(arre);
    cond=nums(arre);
    if(cond==true){
        printf("\n La cantidad de numeros mayores a cero es mayor a la cantidad de numeros menores");
    }
    else{
        printf("\n La cantidad de numeros mayores es igual a la cantidad de numeros menores");
    }
    par=sum(arre,impar);
    printf("\n La suma de los numeros es par: %d",par);
    printf("\n La suma de los numeros impar es: %d", impar);
    leer(arre);
}
