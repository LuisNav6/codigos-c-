//
//  main.cpp
//  puntero ejemplo 1
//
//  Created by Luis Navarrete on 12/05/21.
//
//un puntero es igual al & de una variable
//los punteros solo almacenan la dirección de memoria
#include <iostream>

using namespace std;

int main(){
    
    int z=7;
    cout<<endl<<"&z=  "<<&z;//la direccion de memoria que utiliza z en mi maquina
    cout<<endl<<"----------------------------------------------------------";
    
    int *p1;  //declaracion de  puntero
    p1=&z;  //uso de operador de referencia o direccion
    cout<<endl<<"p1=  "<<p1;
    cout<<endl<<"&p1= "<<&p1;//la direccion de memoria que utiliza p1 en mi maquina
    cout<<endl<<"*p1= "<<*p1;//7
    cout<<endl<<"----------------------------------------------------------";
    int *p2;
    p2=p1;
    cout<<endl<<"p2= "<<*p2;
    
    *p2=15; //uso de operador de desreferencia o indireccion
    cout<<endl<<"z= "<<z<<endl;//15
    
    
    return 0;
}
