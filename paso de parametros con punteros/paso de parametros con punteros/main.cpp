//
//  main.cpp
//  paso de parametros con punteros
//
//  Created by Luis Navarrete on 18/05/21.
//
//se tiene dos tipos de paso de parametros, paso de parametros por valor y por referencia
//el paso de parametros por valor como su nombre lo dice, lo que envia a una funcion es una copia del valor
//el paso de parametros por  referencia lo que envia una funcion es una direccion de memoria. con el paso de parametros por referencias es posible alterar el contenido de una variable declarada en otra funcion

//programa que intercambia los valores de dos variables enteras

#include <iostream>
#include <cstdlib>
void intento1(int, int);
void intento2(int *a, int *b);
using namespace std;

int main(int argc, const char * argv[]) {
    int a=9;
    int b=18;

//paso de parametros por valor
    intento1(a, b);
    cout<<endl<<"a: "<<a<<" "<<"b: "<<b;
    cout<<endl<<"NO LOS INTERCAMBIO PORQUE SE HIZO PASO DE PARAMETROS POR VALOR\n";
    //paso de parametros por referencia
    intento2(&a,&b);//se usa el operador de referencia para obtener la direccion de las variables
    cout<<endl<<"a: "<<a<<" "<<"b: "<<b;
    cout<<endl<<"SI LOS INTERCAMBIO PORQUE SE HIZO PASO DE PARAMETROS POR REFERENCIA\n";
    cout<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
void intento1(int a, int b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}
void intento2(int *a, int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
