#include <stdio.h>
#include <string.h>
const int N=28;
const int M=12;
void vocales(char frase[N]){
    int i,cont = 0;
    for(i=0; i<N; i++){
        if(frase[i]=='a'||frase[i]=='e'||frase[i]=='i'||frase[i]=='o'||frase[i]=='u'){
            cont++;
        }
    }
    printf("\n La cantidad de vocales es de: %d", cont);
    return;
}
void copiar(char frase[N]){
    char prom[M];
    strncpy(prom,frase,12);
    printf("\n %s",prom);
    return;
}
void dos(char frase[N]){
    int i, cont=0;
    for(i=0; i<N; i++){
        if(frase[i]=='2'){
            cont+=1;
        }
        if(cont==3){
            frase[i]='0';
        }
    }
    printf("%s",frase);
    fflush(stdout);
    return;
}
void carga(char frase[N]){
    printf("Ingrese la frase: ");
    fflush(stdin);
    gets(frase);
    return;
}
main()
{
    char frase[N];
    carga(frase);
    dos(frase);
    copiar(frase);
    vocales(frase);
}