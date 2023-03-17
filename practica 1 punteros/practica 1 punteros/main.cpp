//
//  main.cpp
//  practica 1 punteros
//
//  Created by Luis Navarrete on 17/05/21.
//

#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    //un apuntador es una variable que almacena una dirección de memoria, puede ser de cualquier tipo de dato en su declaración
    //existen dos operadores asociados al uso de apuntadores:
     //1.- operadores de referencia o de dirección (&)
    //2.- operadores de desreferencia o de indirección (*)
    
    //usos del *:
    //para declarar un apuntador
    //para obtener el valor almacenado en la direccion en la cual apunta el apuntador(operador de desreferencia)
    int *ptr;
    int num=7;
    int *ptr2;
    cout<<endl<<&num;//imprime la direccion de la variable donde esta num
    ptr=&num;//imprime la direccion donde esta la variable num;
    cout<<endl<<ptr;//imprime la direccion de memoria que tiene guardado el apuntador ptr
    cout<<endl<<&ptr;//imprime la memoria donde esta la variable ptr
    cout<<endl<<*ptr;//imprime el valor almacenado en la direccion a donde apunta el ptr, se le debe de asignar una direccion de memoria, no un entero
    *ptr=15;//permite cambiar el valor de la direccion a la que apunta
    cout<<endl<<num;
    ptr2=ptr;//la asignacion entre apuntadores esta permitida!!!!
    *ptr2=30;
    cout<<endl<<num<<endl<<*ptr<<endl<<*ptr2;
    int *ptr3=NULL;//un apuntador puede ser localizado o a NULL o 0, con lo que indica que por lo pronto no apunta a ningun lugar
    system("PAUSE");
    return EXIT_SUCCESS;
}
