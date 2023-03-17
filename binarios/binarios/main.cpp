//
//  main.cpp
//  binarios
//
//  Created by Luis Navarrete on 08/09/21.
//

#include <iostream>
#include <fstream>

using namespace std;

struct cliente
{
    int cuenta;
    char nombre[30];
    float monto;
};

int cascaBin();
int llenarBin();

int main()
{
    int op;
    do
    {
        system("cls");
        cout << "[1] --> Crear archivo binario" << endl;
        cout << "[2] --> Llenar el archivo binario" << endl;
        cout << "[3] --> Cuenta" << endl;
        cout << "[4] --> Salir" << endl;
        cout << "Inserte la opcion deseada: " << endl;
        cin >> op;
        switch(op)
        {
            case 1 :
                cascaBin();
                break;
            case 2 :
                llenarBin();
                break;
        }
        
    }while(op != 4);
    return 0;
}

int cascaBin()
{
    fstream archivo;
    
    archivo.open("clientes.dat",ios::binary|ios::out);
    
    if(!archivo)
    {
        cerr << "No se pudo abrir el archivo " << endl;
        return 1;
    }
    cliente blanco = {0,"",0};
    
    for(int i = 0; i < 10; i++)
    {
        archivo.write(reinterpret_cast<char *> (&blanco), sizeof(cliente));
    }
    archivo.close();
    
    cout << "archivo creado exitosamente!!\n";
    system("pause");
}

int llenarBin()
{
    fstream archivo;
    
    archivo.open("clientes.dat",ios::binary|ios::in|ios::out);
    
    if(!archivo)
    {
        cerr << "No se pudo abrir el archivo " << endl;
        system("pause");
        return 1;
    }
    
    cliente registro;
    
    cout << "Ingresa la cuenta: ";
    cin >> registro.cuenta;
    
    while(registro.cuenta > 0 && registro.cuenta <= 10)
    {
        cout << "Inserte su nombre: " << endl;
        cin >> registro.nombre;
        cout << "Inserte el monto: " << endl;
        cin >> registro.monto;
        
        archivo.seekp((registro.cuenta - 1) * sizeof(cliente), ios::beg);
        
        archivo.write(reinterpret_cast < char *> (&registro), sizeof(cliente));
        
        cout << "Datos grabados ... \n";
        cout << "Ingrese la cuenta: ";
        cin >> registro.cuenta;
    }
    archivo.close();
}
