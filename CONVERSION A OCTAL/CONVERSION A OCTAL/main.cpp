//
//  main.cpp
//  CONVERSION A OCTAL
//
//  Created by Luis Navarrete on 26/02/21.
//

#include<stdio.h>
#include <math.h>
int octal(int n, int i);
int main(){
    int k=octal(114,0);//114 es base 10
    printf("\nEn octal es %d\t",k);
    //prueba 4 veces más la función
    return 0;
}
int octal(int n, int i){
    int coc,residuo,res;
    coc=n/8;
    residuo=n%8;
    if(coc!=0)
        res=residuo*pow(10,1)+octal(coc,i+1);
    else
        res=residuo*pow(10,i);
    return res;
}
