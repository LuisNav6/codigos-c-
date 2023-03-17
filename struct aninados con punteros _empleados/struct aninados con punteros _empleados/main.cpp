//
//  main.cpp
//  struct aninados con punteros _empleados
//
//  Created by Luis Navarrete on 03/06/21.
//

#include <iostream>
#include <string>//para utilizar el tipo de dato string
/*muy importante colocar el using namespace
antes de cualquier linea que utilice el tipo
de dato string*/

using namespace std;

struct hijos
{
    string nomH;
    int edad;
    char sexo;
};

struct empleado
{
    string nomE;
    double sueldo;
    int n; //total de hijos
    hijos *datos; //vector dinamico de tamano n que almacena
    //los datos de los hijos
};

//prototipos
void llenar(empleado *, int);

void imprimir(empleado *, int);
int main(int argc, char** argv)
{
int n;
    cout<<endl<<"Cuantos empleados tiene la empresa: ";
    cin>>n;
    empleado *emp=new empleado[n];
    llenar(emp,n);
    imprimir(emp,n);
    delete []emp ;
return 0;
}
void llenar(empleado *emp, int n)
{
    cout << endl << "Llenando vector...";
    for(int i=0; i< n; i++)
    {
        cout << endl << "Nombre empleado: ";
        fflush(stdin);
        getline(cin,emp[i].nomE);
        cout << endl << "Sueldo: ";
        cin >> emp[i].sueldo;
        cout << endl << "Total de hijos: ";
        cin >> emp[i].n;
        emp[i].datos = new hijos[emp[i].n];
        for(int j=0; j < emp[i].n; j++)
        {
            cout << endl << "Nombre del hijo "<< j +1 << ": ";
            fflush(stdin);
            getline(cin,emp[i].datos[j].nomH);
            cout << endl << "Edad del hijo: ";
            cin >> emp[i].datos[j].edad;
            cout << endl << "Sexo del hijo: ";
            cin >> emp[i].datos[j].sexo;
        }
    }
}

void imprimir(empleado *emp, int n)
{
    cout << endl << "Imprimiendo vector ...";
    for(int i=0; i < n; i++)
    {
        cout << endl << "Nombre del empleado: " << emp[i].nomE;
        cout << endl << "Sueldo: " << emp[i].sueldo;
        cout << endl << "Total de hijos: " << emp[i].n;
        for(int j=0; j < emp[i].n; j++)
        {
            cout << endl << "Nombre del hijo " << j +1 << ": " << emp[i].datos[j].nomH;
            cout << endl << "Edad del hijo: " << emp[i].datos[j].edad;
            cout << endl << "Sexo del hijo: " << emp[i].datos[j].sexo;
        }
    }
    
}
