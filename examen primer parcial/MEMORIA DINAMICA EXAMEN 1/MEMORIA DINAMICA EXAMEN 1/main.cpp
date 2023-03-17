//
//  main.cpp
//  MEMORIA DINAMICA EXAMEN 1
//
//  Created by Luis Navarrete on 14/09/21.
//
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;
void memoria(int** m,int r,int c);
void imprimirLlenar(int **m,int r,int c);
int main(){
    srand(time_t(0));
    int **m;
    int r,c;
    cout<<"Dame los renglones:";
    cin>>r;
    cout<<"Dame las columnas:";
    cin>>c;
    memoria(m,r,c);
    return 0;
}
void imprimirLlenar(int **m,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){//llenamos la matriz
            m[i][j]=10+rand()%(90-10+1);//damos los random
        }
    }
    int may=0;
    may=m[0][0];
    cout<<endl<<"...Imprimiendo matriz dinámica..."<<endl<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout << setw(4) <<"["<<m[i][j]<<"]";
        }
        cout<<endl;
    }
    int prenglon=0,pcolumna=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(may<m[i][j]){
                may=m[i][j];
                prenglon=i+1;
                pcolumna=j+1;
            }
        }
    }
    cout<<endl<<"El valor mayor en la matriz es: "<<may<<" El cual esta en el renglón:"<<prenglon<<" y en la columna:"<<pcolumna<<endl;
    //Limpiando memoria del buffer
    for(int i=0; i<r;i++){
        delete [] m[i];
    }
    delete [] m;
}
void memoria(int** m,int r,int c){
    m =new int*[r];//le damos memoria a la matriz dinámica
    for(int i=0;i<r;i++){
        m[i]=new int[c];
    }
    cout<<endl<<"Espacio creado exitosamente :)"<<endl;
    imprimirLlenar(m,r,c);
}
