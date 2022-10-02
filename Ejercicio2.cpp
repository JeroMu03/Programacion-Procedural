#include <stdio.h>
#include <malloc.h>
struct box{
    int dni;
    char cat;
    float pe;
};
int N;
int M;
const int O=43;
void mostrarpe(int *&y){
    int i;
    for(i=0; i<O; i++){
    printf("\n para pe: %d cnt: %d",i+47,y[i]);
    }
    return;
}
void list(box *&p,int i, int *&y,int x){
    if(i<N){
        if(x<91){
            if(p[i].pe==x){
                printf("\n peso if %f",p[i].pe);
                y[x-47]+=1;
                printf("\n conta %d",y[x-47]);
            }
            list(p,i,y,x+1);
        }
        list(p,i+1,y,x);
    }
}
void cero(int *&y){
    int i;
    for(i=0;i<O;i++){
        y[i]=0;
    }
    return;
}
void mostrarc(int *&q){
    int i;
    for(i=0; i<M; i++){
    printf("\n dni: %d",q[i]);
    }
    return;
}
void dnimax(box *&p,int *&q,int i, int j, int ma){
    if(i<N){
        if(p[i].pe==ma){
            printf("\n pe: %f",p[i].pe);
            q[j]=p[i].dni;
            j++;
        }
    dnimax(p,q,i+1,j,ma);
    }
}
void max(box *&p, int i,char a,float &ma,int &cnt){
    if(i<N){
        if(p[i].cat==a){
            if(p[i].pe>ma){
                ma=p[i].pe;
            }
        }
        max(p,i+1,a,ma,cnt);
        if(p[i].pe==ma){
            cnt++;
        }
    }
}
void mostrar(box *&p){
    for(int i=0; i<N; i++){
        printf("\n boxeador %d ", i+1);
        printf("\n dni nashe %d ", p[i].dni);
        printf("\n categoria nashe %c ", p[i].cat);
        printf("\n plata nashe %f ", p[i].pe);
    }
    return;
}
void set(box *&p,int &N){
    printf("\n Ingrese la cantidad de boxeadores:");
    scanf("%d",&N);
    p=(box*)malloc(N*sizeof(box));
    return;
}
void carga(box *&p,int &N){
    int band=1,i=0;
    char q;
    set(p,N);
    while(band!=0 && i<N){
        printf("\n Ingrese categoria del boxeador %d:",i+1);
        fflush(stdin);
        scanf("%c",&q);
        if(q=='A'||q=='B'||q=='C'||q=='D'||q=='E'||q=='F'||q=='G'||q=='H'){
            p[i].cat=q;
            printf("\n Ingrese DNI:");
            scanf("%d",&p[i].dni);
            printf("\n Ingrese peso nashe: ");
            scanf("%f",&p[i].pe);
            i++;
        }
        else printf("\n No existe la categoria");
        printf("\n Ingrese 0 para terminar la carga u otro numero para continuar: ");
        scanf("%d",&band);
    }
    return ;
}
int main(){
    box *p;
    char a;
    int i=0,*q,cnt=0,j=0,*y,x=47;
    float ma=0;
    carga(p,N);
    mostrar(p);
    printf("\n Ingrese la categoria peso:");
    fflush(stdin);
    scanf("%c",&a);
    max(p,i,a,ma,cnt);
    M=cnt;
    printf("\n max: %f",ma);
    printf("\n cont: %d",M);
    q=(int*)malloc(M*sizeof(int));
    dnimax(p,q,i,j,ma);
    mostrarc(q);
    y=(int*)malloc(O*sizeof(int));
    cero(y);
    list(p,i,y,x);
    mostrarpe(y);
}