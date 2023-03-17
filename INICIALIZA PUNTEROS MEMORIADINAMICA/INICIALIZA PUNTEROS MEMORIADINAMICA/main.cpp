//
//  main.cpp
//  INICIALIZA PUNTEROS MEMORIADINAMICA
//
//  Created by Luis Navarrete on 18/05/21.
//

#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, const char * argv[]) {
    //ejemplifica la asignacion dinamica de memoria a varibles int, char y float
    //declaracion de apuntadores
    int *ipuntero;
    float *fpuntero;
    char *Minombre;
    //asignacion dinamica para que los apuntadores obtengan una direccion de memoria
    ipuntero=new int;
    fpuntero= new float;
    Minombre=new char[20];//inicializar un vector con 20 caracteres
    
    //asignacion de valores
    *ipuntero=25;
    *fpuntero=60.4;
    strcpy(Minombre,"Rocio");
    //impresion de valores usando los apuntadores
    cout<<"\nEdad: "<<*ipuntero<<" peso: "<<*fpuntero<<" nombre: "<<Minombre<<endl;
    //liberacion de espacio
    delete ipuntero;
    delete fpuntero;
    delete [] Minombre;
    return 0;
    
}
