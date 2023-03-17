//
//  main.cpp
//  struct consolas-videojuegos
//
//  Created by Luis Navarrete on 24/03/21.
//




#include <iostream>
#include <cstring>
#define TAM 3


struct consolas{
    char nomconsola[30];
    float precioconsola;
    struct videojuegos{
        char nomjuego[30];
        float preciojuego;
    }juegos[TAM];
};

consolas llenar(consolas tienda);
void imprimir(consolas tienda);
void buscar(consolas tienda, char nomjueg[]);
void listar(float inicio,float final, consolas tienda);

using namespace std;

int main(){
    consolas tienda;
    float inicio;
    float final;
    char nomjueg[30];
    cout << endl <<"----------------------------------------------------";
    tienda = llenar(tienda);
    cout << endl <<"----------------------------------------------------";
    imprimir(tienda);
    cout << endl <<"----------------------------------------------------";
    cout << endl << "Dame el juego que deseas buscar: ";
    fflush(stdin);
    cin.getline(nomjueg,30);
    buscar(tienda,nomjueg);
    cout << endl << "----------------------------------------------------";
    cout<<endl<<"Dame el inicio: ";
    cin>>inicio;
    cout<<endl<<"Dame el final: ";
    cin>>final;
    listar(inicio,final,tienda);
}

void listar(float inicio,float final, consolas tienda){
    for(int i=0; i < TAM; i++){
        if(tienda.juegos[i].preciojuego > inicio && tienda.juegos[i].preciojuego < final){
            cout << endl << "El juego " << tienda.juegos[i].nomjuego << " esta dentro de su rango de precios!"<<endl;
        }
    }
}

void buscar(consolas tienda, char nomjueg[]){
    int posicion=0;
    
    for(int i=0; i < TAM; i++){
        if(strcmp(tienda.juegos[i].nomjuego,nomjueg) == 0){
            posicion = i;
        }
    }
    if(strcmp(tienda.juegos[posicion].nomjuego,nomjueg) == 0){
        cout << endl << "Encotramos su juego " << tienda.juegos[posicion].nomjuego;
    }else{
        cout << endl << "No encontramos su juego";
    }
    
}


consolas llenar(consolas tienda){
    cout << endl << "Nombre de la consola: ";
    fflush(stdin);
    cin.getline(tienda.nomconsola,30);
    cout << endl << "Precio de la consola: ";
    cin >> tienda.precioconsola;
    for(int i=0; i < TAM; i++){
        cout << endl << "Nombre del juego: ";
        fflush(stdin);
        cin.getline(tienda.juegos[i].nomjuego,30);
        cout << endl << "Precio del juego: ";
        cin >> tienda.juegos[i].preciojuego;
    }
    return tienda;
}

void imprimir(consolas tienda){
    cout << endl << "La consola " << tienda.nomconsola << " tiene el precio de: "<< tienda.precioconsola;
    for(int i=0; i < TAM; i++){
        cout << endl << "El juego numero #"<< i + 1 <<" con el nombre " << tienda.juegos[i].nomjuego;
        cout << endl << "Con el precio de: " << tienda.juegos[i].preciojuego;
    }
}
