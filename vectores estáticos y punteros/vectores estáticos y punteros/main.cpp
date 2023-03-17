//
//  main.cpp
//  vectores estáticos y punteros
//
//  Created by Luis Navarrete on 18/05/21.
//
//cualquier vector es en realidad un puntero
//por los tanto los vectores pueden sere recibidos en un parametro declarado como una variable tipo apuntador
//por lo tanto los vectores pueden ser manipualados con aritmetica de punteros
//por eso un vector cuando se envia como argumento todos los cambios realizados en la funcion se mantienen, esto debido al que los vectores son en realidad punteros

#include <iostream>
#define TAM 5
void llenar1(int *);
void imprimir1(int *);
void llenar2(int *);
void imprimir2(int *);
using namespace std;

int main(int argc, const char * argv[]) {
    int v[TAM];
    llenar1(v);//llenando con sintaxis de corchetes
    imprimir1(v);//imprimiendo con sintaxis de corchetes
    llenar2(v);//llenando con sintaxis de punteros
    imprimir2(v);//imprimiendo con sintaxis de punteros
    
    return 0;
}
void imprimir1(int *v){
    cout<<endl<<"funcion imprimir1 usando sintaxis de corchetes"<<endl;
    for(int i=0;i<TAM;i++){
        cout<<v[i]<<" ";
        
        
    }
}
void imprimir2(int *v){
    cout<<endl<<"funcion imprimir2 usando aritmetica de de punteros"<<endl;
    for(int i=0;i<TAM;i++){
        cout<<*(v+i)<<" ";
    }
}
void llenar1(int *v){
    cout<<endl<<"funcion llenar1 usando sintaxis de corchetes"<<endl;
    for(int i=0;i<TAM;i++){
        cout<<endl<<"Dame un valor: ";
        cin>>v[i];
    }
}
void llenar2(int *v){
    cout<<endl<<"funcion llenar2 usando aritmetica de punteros "<<endl;
    for(int i=0;i<TAM;i++){
        cout<<endl<<"Dame un valor: ";
        cin>>*(v+i);
}
}

