#include <stdio.h>
const int N=5;
void subprom(int s[],int c,int inf,int prom,int acum,int acum1){
    if(inf!=c){
        if(s[inf]>prom){
            acum+=1;
        }
        if(s[inf]==prom){
            acum1+=1;
        }
        subprom(s,c,inf+1,prom,acum,acum1);
    }
    else{
        printf("\n La cantidad que supera el promedio es: %d",acum);
        printf("\n La cantidad que iguala el promedio es: %d",acum1);
        return;
    }
}
void subcarga(int arre[],int inf,int sup,int &c,int prom,int s[]){
    if(inf!=sup){
        if(arre[inf]>=prom){
            s[c]=arre[inf];
            c++;
        }
        subcarga(arre,inf+1,sup,c,prom,s);	
    }
    else{
        return;
    }
}
void prome(int arre[],int inf,int sup,int &prom,int acum){
    if(inf!=sup){
        acum+=arre[inf];
        prome(arre,inf+1,sup,prom,acum);
    }
    else{
        printf("\n El promedio es: %d",acum);
        prom+=acum/N;
        return;
    }
}
void carga(int arre[],int inf,int sup) {
    if(inf!=sup){
        printf("\n Ingrese el numero: ");
        scanf("%d",arre+inf);
        carga(arre,inf+1,sup);
    }
    else{
        printf("\n Arreglo cargado");
        return;
    }
}
int main(){
    int arre[N],s[N],inf=0,sup=N,c=0,prom,acum=0,acum1=0;
    carga(arre, inf,sup);
    prome(arre,inf,sup,prom,acum);
    subcarga(arre,inf,sup,c,prom,s);
    c+=1;
    subprom(s,c,inf,prom,acum,acum1);
}