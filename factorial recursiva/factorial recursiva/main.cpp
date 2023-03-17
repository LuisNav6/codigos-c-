//
//  main.cpp
//  factorial recursiva
//
//  Created by Luis Navarrete on 25/02/21.
//

#include <stdio.h>
int factorial(int num);
int main(){
    int f;
    f=factorial(4);
    printf("\n%d\n",f);
    return 0;
}
int factorial(int num){
    int aux;
    
    if(num>0)
        
        aux=num*factorial(num-1);
    
    else
        
            aux=1;
    
    return aux;
}
