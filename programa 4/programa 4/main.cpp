//
//  main.cpp
//  programa 4
//
//  Created by Luis Navarrete on 17/03/21.
//

#include <iostream>//---necesario para uso de cin y cout
#include <iomanip>//---pero uso de setw,left,right,setfix
#include <ctime>//---notar qye tiene c al principio y no .h al final
#include <cstdlib>
#define TAM 5
using namespace std;//---necesario para uso abreviado de cin y cout
//prototipos
void llenar(float[TAM][TAM]);
void imprimir1(float[TAM][TAM]);
void imprimir2(float[TAM][TAM]);
int main(int argc,char** argv) {
    srand(time_t(NULL));//se puede usar null o 0
    float matriz[TAM][TAM];
    llenar(matriz);
    //notar la diferencia entre estas dos funciones de imprimir
    imprimir1(matriz);
    imprimir2(matriz);
    
    return 0;
}
void llenar(float matriz[TAM][TAM]){
    cout<<endl<<"LLENANDO MATRIZ"<<endl;
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            matriz[i][j]=(1+rand()%(1000-1+1))*3.1416;//la multiplicacion es solo para obtener decimales
        }
    }
}
void imprimir1(float matriz[TAM][TAM]){
    cout<<endl<<"IMPRIMIENDO MATRIZ"<<endl;
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;//equivale a "\n" en printf
    }
}
void imprimir2(float matriz[TAM][TAM]){
    cout<<endl<<"IMPRIMIENDO MATRIZ"<<endl;
    for(int i=0;i<TAM;i++){
        for(int j=0;j<TAM;j++){
            cout<<right<<setw(10)<<fixed<<setprecision(2)<<matriz[i][j]<<" ";
            //right justifica a la derecha
            //fixed y setprecision(2) indica que se desean 2 decimales
            //setw(10) indica el ancho de imprimir el dato, tipo %10f en el printf
        }
        cout<<endl;//equivale a "\n" en printf
    }
}



