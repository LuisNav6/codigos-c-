//
//  main.cpp
//  matrices dinamicas 24 ago
//
//  Created by Luis Navarrete on 24/08/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int **reserva_memoria(int **,int f,int c);
void llenar_matriz(int **,int f,int c);
void muestra_matriz(int **,int f,int c);

int main(int argc, const char * argv[]) {
    int **mat = nullptr;
    int fi = 0,col = 0,op;
    srand(time_t(0));
    do{
        system("cls");
        cout<<"RESERVA DE MEMORIA...1"<<endl;
        cout<<"LLENA LA MATRIZ DE DATOS...2"<<endl;
        cout<<"MUESTRA LA MATRIZ...3"<<endl;
        cout<<"...4"<<endl;
        cout<<"SALIR...5"<<endl;
        cout<<endl<<"DAME LA OPCION DESEADA:";
        cin>>op;
        switch(op){
            case 1: int **res;
                res=reserva_memoria(mat,fi,col);
                break;
            case 2:
                llenar_matriz(mat,fi,col);
                break;
            case 3: muestra_matriz(mat,fi,col);
                break;
            case 4: break;
        }
    }while(op!=5);
    return 0;
}
int **reserva_memoria(int **mat,int f,int c){
    mat=new int* [f];
    for(int i=0;i<f;i++){
        mat[i]=new int [c];
    }
    return mat;
}
void llenar_matriz(int **mat,int f,int c){
    int i,j;
    for( i=0;i<f;i++){
        for( j=0;i<c;i++){
          // mat[i][j]=(rand()%100)+1;
            (*(mat[i]+j))=(rand()%100)+1;
        }
    }
}
void muestra_matriz(int **mat,int f,int c){
    int i,j;
    for( i=0;i<f;i++){
        for( j=0;i<c;i++){
            cout<<"["<<mat[i][j]<<"]";
        }
    }
    cout<<endl;
}
