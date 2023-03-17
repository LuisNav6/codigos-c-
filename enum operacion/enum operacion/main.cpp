//
//  main.cpp
//  enum operacion
//
//  Created by Luis Navarrete on 31/03/21.
//

#include <iostream>
#include<conio.h>
#include <cstdlib>
using namespace std;
enum operacion{SUMAR,RESTAR,MULTIPLICAR,DIVIDIR};
int operar(int v1,int v2,operacion op){
    switch(op){
            
        case SUMAR:
            return v1+v2;
            break;
        case RESTAR:
            return v1-v2;
            break;
        case MULTIPLICAR:
            return v1*v2;
            break;
        case DIVIDIR:
            return v1/v2;
            break;
        default: cout<<endl<<"El programa se detiene por operacion no valida";
            exit(1);
    }
}
int main(){
    int valor1;
    int valor2;
    cout<<endl<<"Dame el valor 1: ";
    cin>>valor1;
    cout<<endl<<"Dame el valor 2: ";
    cin>>valor2;
    cout<<endl<<"La suma de: "<<valor1<<" y "<<valor2<<" es: "<<operar(valor1,valor2,SUMAR)<<endl;
    cout<<endl<<"La resta de: "<<valor1<<" y "<<valor2<<" es: "<<operar(valor1,valor2,RESTAR)<<endl;
    cout<<endl<<"La multiplicación de: "<<valor1<<" y "<<valor2<<" es: "<<operar(valor1,valor2,MULTIPLICAR)<<endl;
    cout<<endl<<"La división  de: "<<valor1<<" y "<<valor2<<" es: "<<operar(valor1,valor2,DIVIDIR)<<endl;
    return 0;
}

