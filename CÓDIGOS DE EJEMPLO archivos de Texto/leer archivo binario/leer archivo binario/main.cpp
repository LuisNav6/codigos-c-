//
//  main.cpp
//  leer archivo binario
//
//  Created by Luis Navarrete on 05/05/21.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
/*programa que escribe archivos secuencialmente en un archivo binario*/
struct cliente{
    int cuenta;
    char nombre[50];//aviso, si su intencion es mandar a grabar los datos de un struct a un binario, no se usen el tipo string en el campo,utilice vector de char
    float monto;
};
int main(){
    string resp;
    fstream archivo;
    //apertura de archivo en modo binario para escritura y agregar
    archivo.open("clientes.dat",ios::binary|ios::out);
    if(!archivo){
        cerr<<"No se puede abrir el archivo!"<<endl;
        cin.get();
        return 1;//termina el programa
    }
    cliente registro;
    int c=0;
    cout<<endl<<endl<<"La información es rescatada desde el archivo!";
    int cuenta;
    cout<<endl<<"Dame la cuenta: ";//puede cambiarse el nombre del cliente o monto sin problemas
    cin>>cuenta;//67
    bool existe=false;
    while(archivo.read((char*)(&registro),sizeof(cliente))){
        if(registro.cuenta==cuenta){//solo se cambia el if
            existe=true;
        cout<<endl;
        cout<<endl<<"cuenta: "<<registro.cuenta;
        cout<<endl<<"Nombre: "<<registro.nombre;
        cout<<endl<<"Monto: "<<registro.monto;
        }
        c++;
    }
    if(existe==false)
        cout<<endl<<"Cuenta inexistente!";
    cout<<endl<<endl<<"Total de registros: "<<c;
    archivo.close();
    return 0;
    
}
