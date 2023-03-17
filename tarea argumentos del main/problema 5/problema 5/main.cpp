//
//  main.cpp
//  problema 5
//
//  Created by Luis Navarrete on 18/02/21.
//

#include <stdio.h>
#include <stdlib.h>
void serie(int n);
int main(int argc,char **argv){
    int n=0;
    n=atoi(argv[1]);
    serie(n);
}
void serie(int n){
int cont=2;
int bandera=0;
while(cont<=n){
    printf("\t%d",cont);
    //system("pause");
    if(bandera==0){
        cont+=3;
        bandera=1;
    }
    else{
        cont+=2;
        bandera=0;
    }
}
}

