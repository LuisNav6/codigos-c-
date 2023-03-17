//
//  main.cpp
//  jugadores 1 binarios
//
//  Created by Luis Navarrete on 11/05/21.
//

#include <iostream>
#define TAM 8 //juadores por equipo
#define TOTAL 6 //equipos de futbol
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>

struct equipo{
    char nomeq[30];
    char cdsede[30];
    struct jugadores{
        char nomjug[30];
        float precio;
        int edad;
    }jug[TAM];
};

void llenar(equipo eq[TOTAL]);

using namespace std;

int main(){
    srand(time_t(0));
    fstream archivo;
    equipo eq[TOTAL];
    llenar(eq);
    equipo aux;
    
    archivo.open("equipo.dat", ios::binary|ios::out|ios::app);
    
    if(!archivo){
        cerr << "No se puede abrir el archivo " << endl;
        cin.get();
        return 1;
    }
    for(int i=0; i < TOTAL; i++){
        aux = eq[i];
    }
    archivo.write((char *)(& aux), sizeof(equipo));
    
    archivo.close();
}

void llenar(equipo eq[TOTAL]){
    char nombresequipos[16][30]={"America","Chivas","Rayados","Cruz Azul","Santos Laguna","Tigres","Atlas","Xolos","Toluca","Puebla","Leon","Monarcas","Necaxa","Veracruz","San Luis","Pachuca"};
    char ciudadessede[16][30]={"mexico","Guadalajara","Mty","Mexico","Torreon","Mty","Gdl","Tijuana","Toluca","Puebla","Leon","Morelia","AGS","Veracruz","San luis Potosi", "Pachuca"};
    char nomjug[20][20]={"Alejandro ","Carlos ","Victor ","Luis enrique ","Pablo ","Guillermo ","Patricio ","Roberto ","Cristobal ","Hector ","Mario ","Javier ","Daniel ","Oscar ","Angel ","Antonio ","Esteban ","Ivan ","Alberto ","Cesar "};
    char apellido[20][20]={"Barba","Delgado","Diaz","Jimenez","Avila","Alva","Hernandez","Garcia","Martinez","Lopez","Gonzalez","Perez","Rodriguez","Sanchez","Cruz","Ramirez","Flores","Gomez","salazar","comte"};
    
    for (int i=0; i<TOTAL; i++){
        int n=0+rand()%(15-0+1);
        strcpy(  eq[i].nomeq, nombresequipos[ n ] );
        strcpy(  eq[i].cdsede, ciudadessede[ n ] );
        cout<<endl<<endl<<eq[i].nomeq<<" "<<eq[i].cdsede;
        //inicia ciclo para jugadores
        for (int j=0; j<TAM; j++){
            strcpy( eq[i].jug[j].nomjug, nomjug[  0+rand()%(19-0+1)  ] );
            strcat( eq[i].jug[j].nomjug, apellido[ 0+rand()%(19-0+1) ]);
            eq[i].jug[j].precio=  1000+rand()%(8000-1000+1);
            eq[i].jug[j].edad= 19 + rand()%(35-19+1);
            cout<<endl<<eq[i].jug[j].nomjug<<" "<<eq[i].jug[j].precio<<" "<<eq[i].jug[j].edad;
        }//fin for jugadores
    }
}
