//
//  main.cpp
//  problema 4
//
//  Created by Luis Navarrete on 18/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void r(int tam,char c);
void t(int tam,char c);

int main(int argc, char **argv){
    char c;
    int tam=0;
    printf("\nQue caracter deseas para tu figura? ");
    scanf("%c",&c);
    printf("\nDe que tamano deseas tu figura? ");
    scanf("%d",&tam);
    
    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"C") == 0){
            r(tam,c);
        }
        if(strcmp(argv[i],"T") == 0){
            t(tam,c);
        }
    }
}

void r(int tam, char c){
    int ren,col;
    ren=1;
    do{
        col=1;
        while(col<=tam){
            printf("%c ",c);
            col++;
        }
        printf("\n");
        ren++;
    }while(ren!=tam);
}

void t(int tam, char c){
    for(int i=1;i<=tam;i++){
        for(int j=0;j<i;j++){
            printf("%c",c);
        }
        printf("\n");
    }
}
