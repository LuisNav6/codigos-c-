//
//  main.cpp
//  liga de futbol 2 struct
//
//  Created by Luis Navarrete on 24/03/21.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#define TAM 3
#define TOTAL 3
//tema struct aninados
struct equipo{
    char nomeq[30];
    char cdsed[30];
    struct jugadores{//struct aninado
        char nomjug[30];
        float precio;
    }jug[TAM];//VECTOR DEL TIPO DEL STRUCT ANIDADO
    };
using namespace std;
void llenar(equipo liga [TOTAL]);
void imprimir(equipo liga [TOTAL]);
void buscar(equipo liga[TOTAL],char team[30]);//Dado el nombre de un equipo decide su ciudad sede, si el equipo no sta mandar error
void jugadormascaro(equipo liga[TOTAL]);
int main(){
    //declarar un vector del tipo del struct equipo
    equipo liga[TOTAL];//LA LIGA DE FUTBOL TIENE 3 EQUIPOS
   //llenar
    char aux[30];
    llenar(liga);//mandar completo el vector
    imprimir(liga);
    cout<<endl<<"Dame el nombre de un equipo: ";
    cin.getline(aux,30);
    buscar(liga,aux);
    jugadormascaro(liga);
    return 0;
}//fin main
void llenar(equipo liga[TOTAL]){
    cout<<endl<<"Llenando vector..."<<endl;
    for(int i=0;i<TOTAL;i++){//for de equipos
        fflush(stdin);
        cout<<endl<<"Nombre del equipo: ";
        cin.getline(liga[i].nomeq,30);
        cout<<endl<<"ciudad sede: ";
        cin.getline(liga[i].cdsed,30);
        cout<<endl<<"Datos de los jugadores del equipo# "<<i;
        for(int j=0;j<TAM;j++){//for de los jugadorees
            fflush(stdin);
            cout<<endl<<"Nombre del jugador #"<<j<<": ";
            cin.getline(liga[i].jug[j].nomjug,30);
            cout<<endl<<"precio del jugador:";
           cin>>liga[i].jug[j].precio;
        }
    }
}
void imprimir (equipo liga[TOTAL]){
    cout<<endl<<"Imprimiendo..."<<endl;
    cout<<endl<<"Equipos de la liga!"<<endl;
    for(int i=0;i<TOTAL;i++){
        cout<<endl<<"equipo: "<<liga[i].nomeq;
        cout<<endl<<"cd sede: "<<liga[i].cdsed;
    cout<<endl<<"Lista de jugadores!"<<endl;
    for(int j=0;j<TAM;j++){
        cout<<endl<<setw(20)<<liga[i].jug[j].nomjug<<setw(8)<<liga[i].jug[j].precio;
    }
        cout<<endl;
}
}
void buscar(equipo liga[TOTAL],char team[30]){
    int band=0;//supongo que ese equipo no etsa en el vector
    for(int i=0;i<TOTAL;i++){
        if(strcmp(liga[i].nomeq,team)==0){
            band=1;
            cout<<endl<<"La ciudad sede de: "<<team<<"es: "<<liga[i].cdsed;
        }
    }
    if(band==0)
        cout<<endl<<"El equipo no está registrado en la liga!"<<endl;
}
void jugadormascaro(equipo liga[TOTAL]){
    char equipo[30];
    char jugador[30];
    float mayor=0;
    for(int i=0;i<TOTAL;i++){
        for(int j=0;j<TAM;j++){
            if(liga[i].jug[j].precio>mayor){
                strcpy(equipo,liga[i].nomeq);
                strcpy(jugador,liga[i].jug[j].nomjug);
                mayor=liga[i].jug[j].precio;
            }//fin if
        }//fin j
    }//fin i
    cout<<endl<<"El jugador más caro de toda la liga es: "<<jugador;
    cout<<endl<<"Perteneciente a: "<<equipo;
    cout<<endl<<"Con el precio de: "<<mayor;
}
