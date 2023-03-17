//
//  main.cpp
//  sumatoria numeros
//
//  Created by Luis Navarrete on 22/02/21.
//

#include <stdio.h>
#include <stdlib.h>
int sumanumeros(int);
int main(){
    int n,suma;
    printf("\nCuantos numeros quieres sumar:");
    scanf("%d",&n);
    suma=sumanumeros(n);
    printf("\nLa suma de los numeros es:%d\n",suma);
    system("pause");
    return 0;
}
int sumanumeros(int n){
    int suma,num;
    if(n>=1){
        printf("\nDame un numero:");
        scanf("%d",&num);
        suma=num+sumanumeros(n-1);
    }else{
        suma=0;
    }
    return suma;
}
