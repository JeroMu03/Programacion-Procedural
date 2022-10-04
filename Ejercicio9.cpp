#include <stdio.h>
#include <malloc.h>
//nasheeeeeeeeeeeeeeeeeeeeeeeeeeee
struct co{
    char nom[20];
    char carr[20];
    struct co *asig;
};
struct libro{
    int cod;
    co col;
    struct libro *sig;
};
typedef struct libro *libropuntero;
typedef struct co *alumpuntero;
void busq(alumpuntero &cba,alumpuntero &ante,alumpuntero &na,alumpuntero &p){
    if(cba!=NULL){
        ante=p;
        p=p->asig;
    }
    else{
        ante->asig=na;
        printf("Ingrese nombre del alumno:");
        fflush(stdin);
        gets(na->nom);
        printf("Ingrese carrera del alumno:");
        fflush(stdin);
        gets(na->carr);
    }
    return;
}
void alum(libropuntero cbl,alumpuntero &cba, int cd,alumpuntero &ante,alumpuntero &na, alumpuntero &p){
    if(cbl!=NULL){
        if(cbl->cod==cd){
            na=(alumpuntero)malloc(sizeof(struct co));
            ante=cbl->col;
            p=cba;
            busq(cba,ante,na,p);
        }
        else{
            alum(cbl->sig,cba,cd,ante,na,p);
        }
    }
    else{
        printf("\n No se encontro el codigo");
        return;
    }

}
void set(libropuntero &cbl){
    int band=1;
    libropuntero nl;
    while(band!=0){
        nl=(libropuntero)malloc(sizeof(struct libro));
        printf("\n Ingrese codigo del libro:");
        scanf("%d",&nl->cod);
        printf("\n Ingrese 0 para terminar la carga o cq numero");
        scanf("%d",&band);
        nl->sig=cbl;
        cbl=nl;
    }
    return;
}
int menu(){
    int d;
    printf("\n Elija una opcion: \n");
    printf("1-Ingresar libro \n");
    printf("2-Insertar alumno \n");
    printf("3-Ingresar libro en prestamo \n");
    printf("4-Devolver libro \n");
    printf("5-Buscar libros por carrera \n");
    scanf("%d",&d);
    return d;
}
void crear(alumpuntero &cba, libropuntero &cbl){
    cba=NULL;
    cbl=NULL;
    return;
}
int main(){
    alumpuntero cba, ante,na,p;
    libropuntero cbl;
    int op,cd;
    crear(cba,cbl);
    do{
        op=menu();
        switch(op){
            case 0:break;
            case 1:{
                set(cbl);
            }
            case 2:{
                printf("\n Ingrese codigo de libro:");
                scanf("%d",&cd);
                alum(cbl,cba,cd,ante,na,p);
            }
        }
    }
}
