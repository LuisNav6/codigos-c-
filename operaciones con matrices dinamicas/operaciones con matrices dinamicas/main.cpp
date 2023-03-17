//
//  main.cpp
//  operaciones con matrices dinamicas
//
//  Created by Luis Navarrete on 04/06/21.
//

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

int **crearEspacio(int ren, int col);
void llenar(int **mat, int ren, int col);
void imprimir(int **mat, int ren, int col);
int **sumar(int **m1, int **m2, int ren3, int col3);
int **multiplicar(int **m1, int **m2, int ren1, int col1, int ren2, int col2);


int main(){
    srand(time_t(NULL));
    int **m1, **m2, **m3, **m4;
    int ren1, col1, ren2, col2, ren3=0, col3=0, ren4=0, col4=0;
    cout<<endl<<"Dame el total de renglones de la matriz 1: ";
    cin>>ren1;
    cout<<endl<<"Dame el total de columnas de la matriz 1: ";
    cin>>col1;
    cout<<endl<<"Dame el total de renglones de la matriz 2: ";
    cin>>ren2;
    cout<<endl<<"Dame el total de columnas de la matriz 2: ";
    cin>>col2;
    m1=crearEspacio(ren1, col1);
    m2=crearEspacio(ren2, col2);
    llenar(m1, ren1, col1);
    llenar(m2, ren2, col2);
    cout<<endl;
    cout<<endl<<"Matriz 1"<<endl;
    imprimir(m1, ren1, col1);
    cout<<endl;
    cout<<endl<<"Matriz 2"<<endl;
    imprimir(m2, ren2, col2);
    if(ren1==ren2 && col1==col2){
        ren3=ren1;
        col3=col1;
        m3=sumar(m1, m2, ren3, col3);
        cout<<endl<<"Matriz sumada"<<endl;
        imprimir(m3, ren3, col3);
    }
    else{
        cout<<endl<<"No procede la suma de matrices";
    }
    if(col1==ren2){
        ren4=ren1;
        col4=col2;
        m4=multiplicar(m1, m2, ren1, col1, ren2, col2);
        cout<<endl<<"Matriz Multiplicada"<<endl;
        imprimir(m4, ren4, col4);
    }
    else{
        cout<<endl<<"No procede la multiplicacion";
    }
}

int **crearEspacio(int ren, int col){
    int **aux;
    aux=new int *[ren];
    for(int i=0; i<ren; i++){
        aux[i]=new int [col];
    }
    
    return aux;
}

void llenar(int **mat, int ren, int col){
    for(int i=0; i<ren; i++){
        for(int j=0; j<col; j++){
            mat[i][j]=1+rand()%(30-1+1);
        }
    }
}

void imprimir(int **mat, int ren, int col){
    for(int i=0; i<ren; i++){
        for(int j=0; j<col; j++){
            cout<<setw(5)<<*(mat[i]+j);
        }
        cout<<endl;
    }
}

int **sumar(int **m1, int **m2, int ren3, int col3){
    int **aux;
    aux=crearEspacio(ren3, col3);
    
    for(int i=0; i<ren3; i++){
        for(int j=0; j<col3; j++){
            aux[i][j]=m1[i][j] + m2[i][j];
        }
        
    }
    
    return aux;
}

int **multiplicar(int **m1, int **m2, int ren1, int col1, int ren2, int col2){
    int **aux1;
    aux1=crearEspacio(ren1, col2);
    for(int i=0; i<ren1; i++){
        for(int j=0; j<col2; j++){
            aux1[i][j]=0;
            for(int k=0; k<col1; k++){
                aux1[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    return aux1;
    
}
