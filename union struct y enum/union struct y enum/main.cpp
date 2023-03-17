//
//  main.cpp
//  union struct y enum
//
//  Created by Luis Navarrete on 07/04/21.
//

#include <iostream>
#include <string>
#define TAM 4

using namespace std;

enum tipo{ ALUMNOS = 1, MAESTROS, SECRETARIAS
    
};

union extra{
    float promedio;
    float salario;
    float comp;
};

struct escuela{
    string nombre;
    string dom;
    string tel;
    tipo tp;
    extra dato;
};

void llenar(escuela morelos [TAM]);
void imprimir(escuela morelos[TAM]);
void consulta(escuela morelos[TAM], int);

int main(){
    int validar;
    escuela morelos[TAM];
    llenar(morelos);
    imprimir(morelos);
    do{
        cout << endl << "Tipo de dato que desea consultar - Alumno (1) - Maestro (2) - Secretaria (3) -" << endl;
        cin >> validar;
    }while(validar < 1 || validar > 3);
    consulta(morelos,validar);
}

void consulta(escuela morelos[TAM], int validar){
    if(validar == ALUMNOS)
        cout << endl << "Reporte de Alumnos";
    else if(validar == MAESTROS)
        cout << endl << "Reporte de Maestros";
        else
            cout << endl << "Reporte de Secretarias";
    
    for(int i=0; i < TAM; i++){
        if(morelos[i].tp == validar){
            cout << endl << "Nombre: " << morelos[i].nombre;
            cout << endl << "Domicilio: " << morelos[i].dom;
            cout << endl << "Telefono: " << morelos[i].tel;
            switch(morelos[i].tp){
                case ALUMNOS: cout << endl << "Promedio: " << morelos[i].dato.promedio; break;
                case MAESTROS: cout << endl << "Salario: " << morelos[i].dato.salario; break;
                case SECRETARIAS: cout << endl << "Compesacion: " << morelos[i].dato.comp; break;
            }
        }
    }
}

void imprimir(escuela morelos[TAM]){
    cout << endl << "Imprimiendo datos";
    cout << endl << "-------------------------------------------";
    for(int i=0; i < TAM; i++){
        cout << endl << "Tipo de persona " << morelos[i].tp;
        cout << endl << "Nombre: " << morelos[i].nombre;
        cout << endl << "Domicilio: " << morelos[i].dom;
        cout << endl << "Telefono: " << morelos[i].tel;
        switch(morelos[i].tp){
            case ALUMNOS: cout << endl << "Promedio: " << morelos[i].dato.promedio; break;
            case MAESTROS: cout << endl << "Salario: " << morelos[i].dato.salario; break;
            case SECRETARIAS: cout << endl << "Compesacion: " << morelos[i].dato.comp; break;
        }
        cout << endl << "********************************";
    }
}

void llenar(escuela morelos [TAM]){
    cout << endl << "Llenando datos";
    int validar;
    for(int i=0; i < TAM; i ++){
        do{
            cout << endl << "Alumno (1) - Maestro (2) - Secretaria (3)" << endl;
            cin >> validar;
        }while(validar < 1 || validar > 3);
        
        switch(validar){
            case ALUMNOS:
                cout << endl << "Dame el nombre del alumno: ";
                fflush(stdin);
                getline(cin,morelos[i].nombre);
                cout << endl << "Dame el domicilo del alumno: ";
                fflush(stdin);
                getline(cin,morelos[i].dom);
                cout << endl << "Dame el telefono del alumno: ";
                fflush(stdin);
                getline(cin,morelos[i].tel);
                cout << endl << "Dame tu promedio: ";
                cin >> morelos[i].dato.promedio;
                morelos[i].tp = ALUMNOS;
                break;
            case MAESTROS:
                cout << endl << "Deme el nombre del maestro: ";
                fflush(stdin);
                getline(cin,morelos[i].nombre);
                cout << endl << "Deme el domicilio del maestro: ";
                fflush(stdin);
                getline(cin,morelos[i].dom);
                cout << endl << "Dame el telefono del maestro: ";
                fflush(stdin);
                getline(cin,morelos[i].tel);
                cout << endl << "Salario del maestro: ";
                cin >> morelos[i].dato.salario;
                morelos[i].tp = MAESTROS;
                break;
            case SECRETARIAS:
                cout << endl << "Deme el nombre de la secretaria: ";
                fflush(stdin);
                getline(cin,morelos[i].nombre);
                cout << endl << "Deme el domicilio de la secretaria: ";
                fflush(stdin);
                getline(cin,morelos[i].dom);
                cout << endl << "Dame el telefono de la secretaria: ";
                fflush(stdin);
                getline(cin,morelos[i].tel);
                cout << endl << "Deme su compensacion: ";
                cin >> morelos[i].dato.comp;
                morelos[i].tp = SECRETARIAS;
                break;
        }
    }
}
