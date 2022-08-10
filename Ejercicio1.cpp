#include <stdio.h>
const int N=5;
void numpares(int num[N]) {
    int i, cont=0;
    for (i=0; i<N; i++){
        if(num[i]%2==0){
            cont+=1;
        }
    }
    printf("\n La cantidad de numeros pares: %d", cont);
    return;
}
void pares(int num[N]) {
    int i;
    for (i=0; i<N; i=i+2) {
        printf("\n %d", num[i]);
    }
    return;
}
void cero(int num[N]){
    int i=0;
    bool a = false;
    while(a==false && i<N){
        if(num[i]==0){
            a=true;
        }
        else{
            i+=1;
        }
    }
    if(a==true){
        printf("\n Hay un cero registrado");
    }
    else{
        printf("\n No hay un cero registrado");
    }
    return;
}
void carga(int num[N]) {
    int i;
    for (i=0; i<N; i++){
        printf("Cargue el numero: ");
        scanf("%d",&num[i]);
    }
    return;
}
main()
{
    int num[N];
    carga(num);
    cero(num);
    pares(num);
    numpares(num);
}