//
//  main.cpp
//  creacion de matriz dinamica
//
//  Created by Luis Navarrete on 24/05/21.
//

#include <iostream>
#include <iomanip>//para el setw()
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
   //matrices dinamicas
    srand(time_t(0));
    int **m1;//para trabajar matrices se declara una apuntador de indireccion multiple
    int r,c,j,i;
    cout<<endl;
    cout<<endl<<"De cuantos renglones: ";
    cin>>r;
    cout<<endl<<"De cuantas columnas: ";
    cin>>c;
    //formando el cascaron de la matriz, solo los espacios
    m1=new int *[r];//creacion del vector de apuntadores
    //creando las columnas de las matrices
    for(i=0;i<r;i++){
        m1[i]=new int [c];//se crean vectores dinamicos por cada renglon , que seran las columnas
    }
    //captura de datos de matriz
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            m1[i][j]=10+rand()%(90-10+1);
            
        }
    }
    //imprimir la matriz dinamica
    (cout<<endl<<"Imprimiendo la matriz...")<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<setw(4)<<m1[i][j];
        }
        cout<<endl;
    }
        //liberando la memoria dinamica
        //primer paso: eliminar las columnas de la matriz;
        for(i=0;i<r;i++){
            delete [] m1[i];//eliminando las columanas del renglon i
        }
        //segundo paso: eliminar el vector de apuntadores
        delete [] m1;
    return 0;
}
