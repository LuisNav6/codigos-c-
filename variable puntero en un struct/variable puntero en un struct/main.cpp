//
//  main.cpp
//  variable puntero en un struct
//
//  Created by Luis Navarrete on 27/05/21.
//

#include <iostream>
#include <cstdlib>

#define TAMNOMBRE 30
#define TAMTEL 15

using namespace std;
//programa que ejemplifica el uso de punteros del tipo de un struct y su uso de funciones
//importante, notar que en este ejemplo no hay arreglos de estructuras los datos se almacenan 1 vez
struct datos{
    char nombre [TAMNOMBRE];
    char numtel [TAMTEL];
    int edad;
};
void imprime1(datos aux);
void imprime2(datos *aux);
datos captura1();
datos *captura2();

int main(int argc, const char * argv[]) {
    datos misdatos;
    misdatos=captura1();
    imprime1(misdatos);
    //imprime2(&misdatos); //probar si esta llamada funciona
    datos *tusdatos;//puntero del tipo struct
    tusdatos=captura2();
    imprime2(tusdatos);
    delete tusdatos;//regresamos espacio a memoria dinamica
    
    
    return 0;
}
datos captura1(){
    datos aux;
    cout<<endl<<"dame el nombre: ";
    cin.getline(aux.nombre,TAMNOMBRE);
    cout<<endl<<"dame el tel: ";
    cin.getline(aux.numtel,TAMTEL);
    cout<<endl<<"Dame edad: ";
    cin>>aux.edad;
    return aux;
}
void imprime1(datos aux){
    cout<<endl<<"IMPRIMIENDO..."<<endl;
    cout<<endl<<aux.nombre;
    cout<<endl<<aux.numtel;
    cout<<endl<<aux.edad;
    cout<<endl;
}
void imprime2(datos *aux){
    cout<<endl<<"IMPRIMIENDO..."<<endl;
    cout<<endl<<aux->nombre;
    cout<<endl<<aux->numtel;
    cout<<endl<<aux->edad;
    cout<<endl;
}
datos *captura2(){
    datos *aux;
    aux=new datos; //pedimos espacio a mem din
    fflush(stdin);//para evitar que se brinque la sig preg
    cout<<endl<<"dame el nombre: ";
    cin.getline(aux->nombre,TAMNOMBRE);
    cout<<endl<<"dame el tel: ";
    cin.getline(aux->numtel,TAMTEL);
    cout<<endl<<"Dame edad: ";
    cin>>aux->edad;
    return aux;
}
