#include <stdio.h>
#include <string.h>
const int N=10;
const int M=20;
struct alu{
    char nom[M];
    char ap[M];
    int dni;
};
void mayor(alu a[N]){
    int i, cont=0;
    for(i=0; i<N; i++){
        if(a[i].dni>40000000){
            cont++;
        }
    }
    printf("\n Hay: %d alumnos con dni superior a 40 millones", cont);
    return;
}
void mostrar(alu a[N]){
    int i;
    for(i=0; i<N; i++){
        printf("\n Alumno:%s %s DNI: %d", a[i].nom,a[i].ap, a[i].dni);
    }
    return;
}
void carga(alu a[N]){
    int i;
    for(i=0; i<N; i++){
        printf("\n Ingrese el nombre del alumno: ");
        fflush(stdin);
        gets(a[i].nom);
        printf("\n Ingrese el apellido del alumno: ");
        fflush(stdin);
        gets(a[i].ap);
        printf("\n Ingrese el DNI del alumno: ");
        scanf("%d",&a[i].dni);
    }
    return;
}
main(){
    alu a[N];
    carga(a);
    mostrar(a);
    mayor(a);
}