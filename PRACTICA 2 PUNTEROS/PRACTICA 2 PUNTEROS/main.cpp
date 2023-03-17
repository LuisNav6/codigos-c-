//
//  main.cpp
//  PRACTICA 2 PUNTEROS
//
//  Created by Luis Navarrete on 18/05/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    //formas de inicializar un apuntador
    //opcion 1, inicilizarlo apuntnado a nada
    int *ap1;
    ap1=NULL;
    int *ap2=NULL;
    //opcion 2, inicializarlo con la direccion de alguna variable
    int n=8;
    int *ap3;
    ap3=&n;
    int *ap4=&n;
    //opcion 3 inicalizarlo utilizando memoria dinamica
    //la memoria dinamica es aquella que esta disponible mientras el programa esta en ejecucion, los operadores asociados a esta son new y delete
    //new operador que obtiene una direccion de la memoria dinamica
    //delete operador que regresa el espacio de la memoria dinamica presto
    int *ap5;
    ap5=new int;
    *ap5=9;
    cout<<endl<<*ap5;
    char *ap6=new char;
    *ap6='@';
    cout<<endl<<*ap6;
    delete ap5;
    delete ap6;
    cout<<endl;
    system("PAUSE");
    
    return EXIT_SUCCESS;
    
    
}

