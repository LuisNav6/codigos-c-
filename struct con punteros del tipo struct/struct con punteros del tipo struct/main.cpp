//
//  main.cpp
//  struct con punteros del tipo struct
//
//  Created by Luis Navarrete on 03/06/21.
//


#include <iostream>
#include <string>

using namespace std;

struct medicamento{
       string nomM;//nombre del medicamento
       double precio;//precio del medicamento
};

struct paciente{
   string nomP;//nombre del paciente
   string enfermedad;
   int n;//total de medicamentos que toma
   medicamento **medi;//es para un arreglo de estructuras dinamico de tamaño n
};

//prototipos
void llenar(paciente *p,int tam);
void imprimir(paciente *p,int tam);
int main(int argc, char** argv) {
   int n;

   paciente *p;
   cout<<endl<<"Dame el total de pacientes: ";
   cin>>n; //total de pacientes
   //crea el vector dinamico de pacientes
    p=new paciente[n];
    
   //implementa y llama la funcion de llenar
    llenar(p,n);
   //implementa y llama la funcion de imprimir*/
    imprimir(p,n);
   return 0;
}
void llenar(paciente *p,int tam){
    cout<<endl<<"Llenando..."<<endl;
    for(int i=0;i<tam;i++){
        cout<<endl<<"Dame el nombre del paciente: ";
        fflush(stdin);
        getline(cin,p[i].nomP);
        cout<<endl<<"Dame la enfermedad que padece: ";
        getline(cin,p[i].enfermedad);
        cout<<endl<<"Cuantas medicinas toma: ";
        cin>>p[i].n;
        p[i].medi=new medicamento*[p[i].n];
        for(int j=0;j<p[i].n;j++){
            p[i].medi[j]=new medicamento;
            cout<<endl<<"Dame el nombre del medicamento: ";
            fflush(stdin);
            getline(cin,p[i].medi[j]->nomM);
            cout<<endl<<"Dame el precio del medicamento: ";
            cin>>p[i].medi[j]->precio;
            
            
    }
    
}
}
void imprimir(paciente *p,int tam){
    cout<<endl<<"Imprimiendo..."<<endl;
    for(int i=0;i<tam;i++){
        cout<<endl<<"Nombre del paciente "<<i+1<<": "<<p[i].nomP;
        cout<<endl<<"Enfermedad que padece: "<<p[i].enfermedad;
        cout<<endl<<"Medicinas  que toma: "<<p[i].n;
        cout<<endl;
        for(int j=0;j<p[i].n;j++){
            cout<<endl<<"Nombre del medicamento "<<j+1<<": "<<p[i].medi[j]->nomM;
            cout<<endl<<"Precio del medicamento: "<<j+1<<": "<<p[i].medi[j]->precio;
            cout<<endl;
    }
    
}
    
}

