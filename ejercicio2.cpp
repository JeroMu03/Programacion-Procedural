#include <stdio.h>
#include <string.h>
#include <malloc.h>
int N=0;
struct all{
    char nom[20];
    int nr;
    char re;
};
struct alp{
    char nom[20];
    int nr;
    char re;
};
void ap(FILE *al,int arre[]){
    all ala;
    int i=0;
    rewind(al);
    while(fread(&ala,sizeof(ala),1,al)!=0){
        if(ala.nr==arre[i]){
            printf("\n Nombre del alumno: %s,Registro del alumno: %d",ala.nom,ala.nr);
            i+=1;
        }
    }
    return;
}
void carga(FILE *pp,int arre[]){
    alp apa;
    int i=0;
    rewind(pp);
    while(fread(&apa,sizeof(apa),1,pp)!=0){
        if(apa.re=='A'){
            arre[i]=apa.nr;
            i+=1;
        }
    }
    return;
}
void aprob(FILE *pp,int *&arre){
    alp apa;
    while(fread(&apa,sizeof(apa),1,pp)!=0){
        if(apa.re=='A'){
            N+=1;
        }
    }
    arre=(int*)malloc(N*sizeof(int));
    return;
}
int main(){
    FILE *al,*pp;
    int *arre;
    if((pp=fopen("alumnosPP.dat","r"))==NULL){
        printf("error \n");
    }
    else{
        aprob(pp,arre);
        carga(pp,arre);
        fclose(pp);
        if((al=fopen("alumnosAL.dat","r"))==NULL){
            printf("\n error");
        }
        else{
            ap(al,arre);
        }
    }
}