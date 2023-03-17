//
//  main.cpp
//  cadena hexadecimal
//
//  Created by Luis Navarrete on 26/02/21.
//

#include <math.h>
#include <string.h>
#include <stdio.h>
int hexadec(char cad[],int indice, int i);
int main(){
    char cad[]="8f3";
    int k=hexadec(cad,strlen(cad)-1,0);
    printf("\n%s-%d",cad,k);
    //prueba el ejercicio 4 veces más
    
    
    return 0;
    
}//fin main
int hexadec(char cad[],int indice, int i){
    char hex[]="123456789abcdef";
    int res,num;
    if(indice>=0){
        for(int j=0;j<strlen(hex);j++){
            if(cad[indice]==hex[j]){
                num=j;break;
            }//fin if
        }//fin for
        res=num*pow(16,i)+hexadec(cad,indice-1,i+1);
    }else{
        res=0;
    }
    return res;
}
