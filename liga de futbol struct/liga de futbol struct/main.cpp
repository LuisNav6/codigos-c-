//
//  main.cpp
//  liga de futbol struct
//
//  Created by Luis Navarrete on 24/03/21.
//

#include <iostream>
#include <string>
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

equipo llenar();
void imprimir (equipo);
void quiencuestamas(equipo eq);
float sumapreciosjug(equipo eq);

int main(){
    //declarar un vector del tipo del struct equipo
    equipo liga[TOTAL];//QUE LA LIGA DE FUTBOL TIENE 3 EQUIPOS
    //llenar la liga
    for(int i=0;i<TOTAL;i++){
        liga[i]=llenar();
    }
    for(int i=0;i<TOTAL;i++){
        imprimir( liga[i]);
    }
    //quien cuesta más en cadac equipo
    for(int i=0;i<TOTAL;i++){
        cout<<endl<<"Equipo# "<<i;
        quiencuestamas(liga[i]);
    }
    //sumar precios de jugadores
    for(int i=0;i<TOTAL;i++){
        cout<<endl<<"Equipo# "<<i<<"suma de precios de los jugadores: "<<sumapreciosjug(liga[i]);
    }
    return 0;
}//fin main
equipo llenar(){
    equipo aux;
    fflush(stdin);
    cout<<endl<<"Dame el nombre del equipo: ";
    cin.getline(aux.nomeq,30);
    cout<<"ciudad sede: ";
    cin.getline(aux.cdsed,30);
    for(int i=0;i<TAM;i++){
        cout<<"Dame el nombre del jugador # "<<i+1<<":";
        fflush(stdin);
        cin.getline(aux.jug[i].nomjug,30);
        cout<<"precio del jugador: ";
        cin>>aux.jug[i].precio;
    }
    return aux;
}
void imprimir (equipo eq){
    cout<<endl<<"Imprimiendo..."<<endl;
    cout<<endl<<"equipo: "<<eq.nomeq;
    cout<<endl<<"cd sede: "<<eq.cdsed;
    for(int i=0;i<TAM;i++){
        cout<<endl<<"jugador #"<<i+1<<":"<<eq.jug[i].nomjug;
        cout<<endl<<"precio: "<<eq.jug[i].precio<<endl;
    }
}
void quiencuestamas(equipo eq){
    float mayor=eq.jug[0].precio;//suponer que el más caro es el de la posición 0
    int posicion=0;//suponer que el más caro es el de la posición 0
    for(int i=1;i<TAM;i++){
        if(eq.jug[i].precio>mayor){
            mayor=eq.jug[i].precio;
        posicion=i;
        }//fin if
    }//fin for
    cout<<endl<<"El jugador más caro es: "<<eq.jug[posicion].nomjug;
    cout<<" que cuesta: "<<mayor<<endl;
    
}
float sumapreciosjug(equipo eq){
    float acum=0;
    for(int i=0;i<TAM;i++){
        acum=acum+eq.jug[i].precio;
    }
    return acum;
}
