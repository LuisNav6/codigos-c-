//
//  main.cpp
//  N consolas N videojuegos struct
//
//  Created by Luis Navarrete on 26/03/21.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#define TAM 2
#define TOTAL 2
//tema struct aninados
struct consolas{
    char nomconsola[30];
    float precioconsola;
    struct videojuegos{
        char nomjuego[30];
        float preciojuego;
    }juegos[TAM];
};

void llenar(consolas tienda[TOTAL]);
void imprimir(consolas tienda[TOTAL]);
void consmascara(consolas tienda[TOTAL]);
void buscar(char juego[30],consolas tienda[TOTAL]);
void buscaconsola(consolas tienda[TOTAL], char miconsola[30]);
using namespace std;
int main(){
    char miconsola[30];
    char aux[30];
    //declarar un vector del tipo del struct
    consolas tienda[TOTAL];
    llenar(tienda);//mandar completo el vector
    imprimir(tienda);
    cout<<endl<<"----------------------------------";
    consmascara(tienda);
    cout<<endl<<"----------------------------------";
    cout<<endl<<"Dame el nombre del juego: ";
    fflush(stdin);
    cin.getline(aux,30);
    buscar(aux,tienda);
    cout<<endl<<"----------------------------------";
    cout<<endl<<"Dame la consola a buscar: ";
    cin.getline(miconsola,30);
    buscaconsola(tienda,miconsola);
    return 0;
}//fin main
void llenar(consolas tienda[TOTAL]){
    cout<<endl<<"Llenando vector..."<<endl;
    for(int i=0;i<TOTAL;i++){//for de equipos
        fflush(stdin);
        cout<<endl<<"Nombre de la consola# "<<i<<": ";
        cin.getline(tienda[i].nomconsola,30);
        cout<<endl<<"precio: ";
        cin>>tienda[i].precioconsola;
        cout<<endl<<"Datos de los videojuegos de la consola# "<<i;
        for(int j=0;j<TAM;j++){//for de los jugadorees
            fflush(stdin);
            cout<<endl<<"Nombre del videojuego#"<<j<<": ";
            cin.getline(tienda[i].juegos[j].nomjuego,30);
            cout<<endl<<"precio:";
           cin>>tienda[i].juegos[j].preciojuego;
        }
    }
}
void imprimir (consolas tienda[TOTAL]){
    cout<<endl<<"Imprimiendo..."<<endl;
    cout<<endl<<"Consolas en existencia!"<<endl;
    for(int i=0;i<TOTAL;i++){
        cout<<endl<<"consola: "<<tienda[i].nomconsola;
        cout<<endl<<"precio: "<<tienda[i].precioconsola;
    cout<<endl<<"Lista de videojuegos!"<<endl;
    for(int j=0;j<TAM;j++){
        cout<<endl<<setw(20)<<tienda[i].juegos[j].nomjuego<<setw(8)<<tienda[i].juegos[j].preciojuego;
    }
        cout<<endl;
}
}
void consmascara(consolas tienda[TOTAL]){
    char consola[30];
    float mayor=0;
    for(int i=0;i<TOTAL;i++){
            if(tienda[i].precioconsola>mayor){
                strcpy(consola,tienda[i].nomconsola);
                mayor=tienda[i].precioconsola;
            }//fin if
    }//fin i
    cout<<endl<<"La consola más cara es: "<<consola;
    cout<<endl<<"Con el precio de: "<<mayor;
}
void buscar(char juego[30],consolas tienda[TOTAL]){//busca la consola donde esta el juego solicitado
    int band=0;
   // char x[30];
    for(int i=0;i<TOTAL;i++){
    for(int j=0;j<TAM;j++){
            if(strcmp(tienda[i].juegos[j].nomjuego,juego)==0){
                //strcpy(x,tienda->juegos[j].nomjuego);
                band=1;
                cout<<endl<<"juego encontrado"<<endl;
                cout<<endl<<"El juego: "<<juego<<" lo tenemos en existencia en: "<<tienda[i].nomconsola;
            }
    }
    }
        if(band==0)
        cout<<endl<<"El juego no lo tenemos en existencia!"<<endl;
    }
void buscaconsola(consolas tienda[TOTAL], char miconsola[30]){ /*busca la consola solicitada e imprime los juegos que tienen y la sumatoria de sus precios, si no esta imprime consola no encontrada*/
    int band=0;
    float acum=0;
    for(int i=0;i<TOTAL;i++){
    for(int j=0;j<TAM;j++){
        if(strcmp(tienda[i].nomconsola,miconsola)==0){
            band=1;
            cout<<endl<<"consola encontrada"<<endl;
            cout<<endl<<"la consola:\t"<<miconsola<<" tiene como juegos: "<<tienda[i].juegos[j].nomjuego<<endl;
                acum=acum+tienda[i].juegos[j].preciojuego;
        }
    }
    }
    cout<<endl<<"La sumatoria de los precios de los videojuegos en la consola  \t"<<miconsola<<" son:\t"<<acum;
    if(band==0)
        cout<<endl<<"consola no encontrada"<<endl;
}
                                                
