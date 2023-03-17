//
//  main.cpp
//  funcion recursiva
//
//  Created by Luis Navarrete on 17/02/21.
//

#include <stdio.h>//funcion recursiva es aquella que se manda a llamar a si misma
#define TAM 6
void imprimir1(int i);
void imprimir2(int j);
void imprimir3(int vec[TAM],int k);
void imprimircad(char v[],int l);
int main(){
    //lamada a la funcion recursiva
    imprimir1(10);//quiero imprimir del 10 al 1
    printf("\n");
    imprimir2(1);//imprimir del 1 al 10
    printf("\n");
    int vec[TAM]={10,11,12,13,14,15};
    imprimir3(vec,0);
    printf("\n");
    char cadena[]="hola mundo";//imprimir caracter por caracter
    imprimircad(cadena,0);
    return 0;
}
void imprimir1(int i){//implementacion
    if(i>=1){
        printf("\t%d",i);
        imprimir1(i-1);
    }

}
void imprimir2(int j){
    if(j<=10){
        printf("\t%d",j);
        imprimir2(j+1);
    }
}
void imprimir3(int vec[TAM],int k){
    if(k<TAM){
        printf("\t%d",vec[k]);
        imprimir3(vec,k+1);
    }
}
void imprimircad(char v[],int l){
    if(v[l]!='\0'){//if(l<strlen(cad))
        printf("\t%c",v[l]);
        imprimircad(v,l+1);
    }
}
