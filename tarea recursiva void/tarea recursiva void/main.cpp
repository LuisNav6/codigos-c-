//
//  main.cpp
//  tarea recursiva void
//
//  Created by Luis Navarrete on 22/02/21.
//

#include <stdio.h>
void tabla(int n,int i);
void serie(int s,int t);
int main(){
    int i=1;
    int n;
    int s=2;
    int t;
    printf("\nDame el valor a multiplicar:");
    scanf("%d",&n);
tabla(n,i);//llamada a la funcion
    printf("\n");
    printf("\nDame el termino de la serie:");
    scanf("%d",&t);
    serie(s,t);
    printf("\n");
    return 0;
}//fin main
void tabla(int n,int i){
    if(i<=10){
        printf("\n%d x %d = %d",n,i,n*i);
        tabla(n,i+1);//recursividad
    }
}
void serie(int s,int t){
    if(t>=1){
        printf("\t%d",s);
        serie(s*2,t-1);
    }
}
