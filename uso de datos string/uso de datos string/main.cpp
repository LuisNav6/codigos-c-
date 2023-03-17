//
//  main.cpp
//  uso de datos string
//
//  Created by Luis Navarrete on 22/03/21.
//

#include <iostream>
#include <string>//no es lo mismo que <<string.h>>, string.h es para usar strcpy,strcmp,strlen
//string se usa pra utilizar variables del tipo string
using namespace std;
string captura();
int main(int argc, char** argv){
    string cad1,cad2;
    string cad3="isc 3";//inicializar un string en su declaracion
    //revisa si un string esta vacio
    if(cad3.empty()==true){//if(cad3=="")
        cout<<endl<<"1 string vacio";
    }else{
        cout<<endl<<"string con informacion";
    }
    //asingar un char a un string
    char op='s';
    string letras;
    letras=op;///<------
    cout<<endl<<"2 asignando un char a un string"<<letras<<endl;
    cad1=cad3;//asignacion directa entrev string;
    cout<<endl<<"3 cad3 "<<cad3;
    cad3="uaa";//cambiar el valor en cualquier momento
    cout<<endl<<"4  cad3 "<<cad3;
    cout<<endl<<"Dame una cadena: ";
    getline(cin,cad2);//captura cadenas con string
    cout<<endl<<"cadena capturada "<<cad2;
    if(cad3==cad2)//dos string se pueden comparar directamente
        cout<<endl<<cad3<<"7 es igual "<<cad2;
    else
        cout<<endl<<"7 no es igual "<<cad2;
    //concatenar cadenas y char
    cad3=cad3 + " " + cad2 + " " + letras + " " + '@';
    cout<<endl<<"8 concatenamos cadenas y char "<<cad3;
    //metodo swap de intercambio de cadenas
    string c1="lenguaje c";
    string c2="lenguaje java";
    c1.swap(c2);
    cout<<endl<<"9 el valor de c1 "<<c1;
    cout<<endl<<"10 el valor de c2 "<<c2;
    //limpia un string
    c1.clear();//equivalente a c1="";
    //se puede recorrer caracter por caracter
    cout<<endl<<"11 recorriendo la cadena caracter por caracter"<<endl;
    for(int i=0;i<cad3.size();i++){
        cout<<cad3[i]<<" ";
    }
    //captura desde una funcion que retorna un string
    string auxiliar;
    auxiliar=captura();
    cout<<"13 cadena que retorna la funcion cadena "<<auxiliar;
    return 0;
}
//funcion que retorna un string
string captura(){
string aux;
cout<<endl<<"Dame una cadena: ";
//limpiar el buffer antes de la captura de un string
    //cin.ignore(256,'\n');equivalente a fflush(stdin);
    fflush(stdin);
    getline(cin,aux);//captura cadenas en un string
    return aux;
}

