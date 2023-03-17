//
//  main.cpp
//  matriz recursividad
//
//  Created by Luis Navarrete on 26/02/21.
//
#include <stdio.h>
#define REN  5
#define COL  4

//prototipo

void imprimir(int mat[REN][COL],int i, int j); //analiza que parametros necesitas

int main(){

     int m[REN][COL]={ {45,67,12,68}, {89,63,25,47}, {69,29,73,16}, {83,71,29,86}, {36,54,48,60} };

    imprimir(m,0,0);//manda llamar  a la función recursiva

     return 0;

}//fin del main
void imprimir(int mat[REN][COL],int i, int j){
    if(i<REN){
        if(j<COL){
            printf("%d\t",mat[i][j]);
            imprimir(mat,i,j+1);
        }else{
            printf("\n");
            imprimir(mat,i+1,0);
            
        }
    }
}
