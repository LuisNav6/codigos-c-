//
//  main.cpp
//  eleva1
//
//  Created by Luis Navarrete on 24/02/21.
//

#include <stdio.h>
//programa que eleva una base a una potencia utilizando una formula de procesamiento recursiva
//version 1
int eleva(int,int);
int main(){
    int base, exponente, resultado;
    printf("\nDame una base:");
    scanf("%d",&base);
    printf("\nDame una exponente:");
    scanf("%d",&exponente);
    resultado=eleva(base,exponente);
    printf("\nEl resultado de elevar %d a la %d es %d\n",base,exponente,resultado);
    return 0;
}
int eleva(int base ,int exponente){
    int aux;
    if(exponente>1){
        aux=base*eleva(base,exponente-1);
    }else{
        aux=base;
    }
    return aux;
}

