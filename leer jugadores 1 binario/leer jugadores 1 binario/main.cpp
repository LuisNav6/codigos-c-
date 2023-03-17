//
//  main.cpp
//  leer jugadores 1 binario
//
//  Created by Luis Navarrete on 14/05/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#define TAM 8 //juadores por equipo
#define TOTAL 6 //equipos de futbol

using namespace std;

struct equipo{
    char nomeq[30];
    char cdsede[30];
    struct jugadores{
        char nomjug[30];
        float precio;
        int edad;
    }jug[TAM];
};

int main(){
    fstream archivo;
    equipo eq[TOTAL];
    archivo.open("equipo.dat",ios::binary|ios::in);
    
    if(!archivo){
        cerr << "No se pudo abrir el archivo " << endl;
        cin.get();
        return 1;
    }
    equipo aux;
    int c=0;
    cout << endl << endl << "La informaci\242n es rescatada desde el archivo ";
    for(int i=0; i < TAM; i++){
        archivo.read((char *)(& aux), sizeof (equipo));
        cout << endl << "Ciudad sede: " << aux.cdsede;
        cout << endl << "Nombre equipo: "<< aux.nomeq;
        for(int j=0; j < TOTAL; j++){
            cout << endl << "Nombre jugadores " << aux.jug[j].nomjug;
            cout << endl << "Edad: " << aux.jug[j].edad;
            cout << endl << "Precio: " << aux.jug[j].precio;
        }
    }
    archivo.close();
}
