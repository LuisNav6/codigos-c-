//
//  main.cpp
//  eleva2
//
//  Created by Luis Navarrete on 24/02/21.
//

#include <stdio.h>
//programa que eleva una base a un potencia utilizando una formula con procesamiento recursivo
//version 2
int eleva(int,int);
int main(){
    int base,exponente,resultado;
    printf("\nDame una base:");
    scanf("%d",&base);
    printf("\nDame una exponente:");
    scanf("%d",&exponente);
    resultado=eleva(base,exponente);
    printf("\nEl resultado de elevar %d a la %d es %d\n",base,exponente,resultado);
    return 0;
}
int eleva(int base,int exponente){
if(exponente>1){
    return base*eleva(base,exponente-1);
}else{
    return base;
}
}
