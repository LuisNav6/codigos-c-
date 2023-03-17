//
//  main.cpp
//  archivos secuenciales
//
//  Created by Luis Navarrete on 03/09/21.
//

#include <iostream>
#include <fstream>

using namespace std;

int alta();
int consulta();
int cuenta(char*);
int main(int argc, char** argv)
{
    int op;
    do
    {
        system("cls");
        cout << "[1] --> Altas" << endl;
        cout << "[2] --> Consultas" << endl;
        cout << "[3] --> Imprime archivo" << endl;
        cout << "[4] --> Salir" << endl;
        cout << "Inserte la opcion deseada: " << endl;
        cin >> op;
        switch(op)
        {
            case 1 :
                alta();
                break;
            case 2 :
                consulta();
                break;
            case 3:
               cout<<"El numero de caracteres del archivo es:"<< cuenta("ejemplo.txt")<<endl;
                break;
        }
        
    }while(op != 4);
    return 0;
}

int alta()
{
    fstream archivo;
    
    archivo.open("clientes.txt",ios::out|ios::app);
    
    // verificar que el archivo este chido
    if( !archivo )
    {
        cerr << "No se pudo abrir el archivo " << endl;
        cin.get();
        return 1;
    }
    cout << "--> ALTA <--" << endl;
    cout << "Dame la cuenta, nombre y monto" << endl;
    cout << "Para terminar de dar de alta coloque un '0' en consulta " << endl << endl;
    
    bool respta = true;
    int cuenta;
    char nombre[30];
    float monto;
    
    while(respta)
    {
        cout << "Cuenta(ID): ";
        cin >> cuenta;
        if(cuenta == 0) break;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Monto: $";
        cin >> monto;
        
        archivo << cuenta << " " << nombre << " " << monto << endl;
        cout << endl;
    }
    archivo.close();
    system("pause");
}
int cuenta(char*nombre){
    int cont=0;
    int c;
    fstream archivo;
    archivo.open(nombre,ios::in);
    if(!archivo){
        cout<<"error de apertura apertura";
        return -1;
    }
    c=archivo.get();
    while(!archivo.eof()){
        cont++;
        archivo.get(c);
    }
    archivo.close();
    system("pause");
}
int consulta()
{
    fstream archivo;
    
    archivo.open("clientes.txt",ios::in);
    
    if(!archivo)
    {
        cerr << "No se pudo abrir el archivo" << endl;
        cin.get();
        return 1;
    }
    
    int cuenta;
    char nombre[30];
    float monto;
    
    int x =0;
    while(archivo >> cuenta >> nombre >> monto)
    {
        x++;
    }
    
    cout << "--> CONSULTA <--" << endl;
    cout << "Existen " << x << " registros en el archivo\n" << endl;
    archivo.clear();
    archivo.seekg(0);
    
    archivo >> cuenta >> nombre >> monto;
    while( !archivo.eof() )
    {
        cout << "Cuenta(ID): " << cuenta << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Monto: $" << monto << endl;
        cout << endl;
        archivo >> cuenta >> nombre >> monto;
    }
    archivo.close();
    cout << endl;
    system("pause");
}
