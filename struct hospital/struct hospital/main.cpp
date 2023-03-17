//
//  main.cpp
//  struct hospital
//
//  Created by Luis Navarrete on 19/03/21.
//

#include <iostream>
#include <string.h>
#include <climits>
 
#define TAM 3

using namespace std;

struct hospital{
    char nomdoctor[30];
    char especialidad[30];
    struct paciente{
        char nompaciente[30];
        char padecimiento[30];
    }paci;
};

void llenar2(hospital hospi[TAM]);
void imprimir2(hospital hospi[TAM]);
hospital llenar1();
void imprimir1(hospital miclinica);

int main(){
    cout<<endl<<"------------------------------------------------"<<endl;
    hospital clinica;
    
    clinica = llenar1();
    imprimir1(clinica);
    
    cout<<endl<<"------------------------------------------------"<<endl;
    hospital hospitales[TAM];
    llenar2(hospitales);
    imprimir2(hospitales);
     
    return 0;
}

void llenar2(hospital  hospi[TAM]){
    for(int i=0;i<TAM;i++){
        cout<<endl<< "Nombre del paciente: ";
        fflush(stdin);
        cin.getline(hospi[i].paci.nompaciente,30);
        cout<<endl<<"Padecimiento: ";
        cin.getline(hospi[i].paci.padecimiento,30);
    }
}

void imprimir2(hospital hospi[TAM]){
    for(int i=0;i<TAM;i++){
        cout<<endl<<"El paciente "<<hospi[i].paci.nompaciente;
        cout<<endl<<"Padece de "<<hospi[i].paci.padecimiento<<endl;
    }
}

hospital llenar1(){
    hospital aux;
    
    cout<<endl<<"Nombre del doctor: ";
    fflush(stdin);
    cin.getline(aux.nomdoctor,30);
    cout<<endl<<"Especialidad: ";
    fflush(stdin);
    cin.getline(aux.especialidad,30);
    
    return aux;
}

void imprimir1(hospital miclinica){
    cout<<endl<<"El nombre del doctor es: "<<miclinica.nomdoctor;
    cout<<endl<<"Su especialidad es: "<<miclinica.especialidad;
}
