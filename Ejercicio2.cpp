#include <stdio.h>
int mult(int &a,int b,int &c);
int main(){
    int a,b=1,c;
    printf("\n Ingrese un numero del 1 al 9: ");
    scanf("%d",&a);
    mult(a,b,c);
    printf("\n %d",c);
}
int mult(int &a,int b,int &c){
    if(b==11){
        return c;
    }
    else{
        c=a*b;
        printf("\n %d",a*b);
        return(mult(a,b+1,c));
    }
}