//
//  main.cpp
//  tarea practica struct empleado
//
//  Created by Luis Navarrete on 17/03/21.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#define TAM 3
using namespace std;

struct empleado{
    char nom[40];
    char sexo;
    float sueldo;
};

void llenar(empleado emp[TAM]);//llena el arreglo de estructuras
void imprimir(empleado emp[TAM]);//imprime el arreglo
float nomina(empleado emo[TAM]);//retorna el total a pagar de nomina
void ganaMas(empleado emp[TAM]);//imprime el nombre y sueldo de cada empleado
void contarFemMas(empleado emp[TAM]);//imprime el total de hombres y mujeres
void quienes(empleado emp[TAM],float,float);//rango de empleados con cierto sueldo

int main(){
    float sueldoInicial;
    float sueldoFinal;
    empleado emp[TAM];
    llenar(emp);
    cout<<endl<<"Imprimiendo ..."<<endl;
    imprimir(emp);
    float paga=nomina(emp);
    cout<<endl<<"El total a pagar por la nomina es: "<<paga<<endl;
    ganaMas(emp);
    contarFemMas(emp);
    cout<<endl<<"Dame el sueldo inicial:";
    cin>>sueldoInicial;
    cout<<endl<<"Dame el sueldo final:";
    cin>>sueldoFinal;
    quienes(emp,sueldoInicial,sueldoFinal);
    system ("pause");
}//fin main

void quienes(empleado emp[TAM],float sueldoInicial, float sueldoFinal){
    cout<<endl<<"Los empleados que entran en el rango entre: "<<sueldoInicial<<"\t"<<"y "<<sueldoFinal<<"\t"<<"son:"<<endl;
    for(int i=0;i<TAM;i++){
    if(emp[i].sueldo >= sueldoInicial && emp[i].sueldo <= sueldoFinal){
    cout<<endl<<"Empleado: "<<emp[i].nom<<" Sueldo : "<<emp[i].sueldo<<endl;
        }
    }
}

void contarFemMas(empleado emp[TAM]){
    int m=0,h=0;
    for(int i=0;i<TAM;i++){
        if(emp[i].sexo=='M'||emp[i].sexo=='m'){
            m++;
        }
        if(emp[i].sexo=='H'||emp[i].sexo=='h'){
            h++;
        }
    }
    cout<<endl<<"El total de hombres en la emperesa son: "<<h;
    cout<<endl<<"El total de mujeres en la empresa son: "<<m;
}

void ganaMas(empleado emp[TAM]){
    float aux;
    char nom[40];
    aux=emp[0].sueldo;
    strcpy(nom,emp[0].nom);
    for(int i=1;i<TAM;i++){
        if(aux<emp[i].sueldo){
            aux=emp[i].sueldo;
            strcpy(nom,emp[i].nom);
        }
    }
    cout<<"El emplead@ "<<nom<<" fue el que mas gano con la cantidad de: "<<aux;
}

void llenar(empleado emp[TAM]){
    for(int i=0;i<TAM;i++){
        cout<<endl<<"Cual es tu nombre?: ";
        fflush(stdin);
        cin.getline(emp[i].nom,40);
        cout<<endl<<"Cual es tu sexo? M / H: ";
        cin>>emp[i].sexo;
        cout<<endl<<"Cual es tu sueldo?: ";
        cin>>emp[i].sueldo;
    }
}

void imprimir(empleado emp[TAM]){
    cout<<right<<setw(10)<<"Nombre"<<right<<setw(10)<<"Sexo"<<right<<setw(10)<<" Sueldo"<<endl;
    for(int i=0;i<TAM;i++){
        cout<<right<<setw(10)<<fixed<<setprecision(2)<<emp[i].nom<< " " << right<<setw(10)<<fixed<<setprecision(2)<<emp[i].sexo<< " " << right<<setw(10)<<fixed<<setprecision(2)<<emp[i].sueldo<< " " <<endl;
    }
}

float nomina(empleado emp[TAM]){
    float suma;
    for(int i=0;i<TAM;i++){
    suma+=emp[i].sueldo;
    }
    return suma;
}
