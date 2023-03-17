//
//  main.cpp
//  intro programacion orientada a objetos
//
//  Created by Luis Navarrete on 15/09/21.
//

#include <iostream>
using namespace std;
/*tipo horario definido por el usuario mediante una estructura simple*/
struct Horario{
    int hora,minuto,segundo;
};
//prototipos
void Militar(Horario &);//recibe una referencia por "alias"
void standar(Horario &);

int main(int argc, const char * argv[]) {
    Horario Mexico;//variable del tipo horario
    Mexico.hora=14;//se le asigna valores a los miembros
    Mexico.minuto=57;
    Mexico.segundo=0;
    cout<<"La hora en Mexico es:";
    Militar(Mexico);//envia como parametro la variable Mexico
    cout<<" en formato Militar \n es decir las ";
    standar(Mexico);
    cout<<endl;
    return 0;
}
//definicion de funciones prototipo

//recibe como argumento la referencia a la variable del tipo Horario;

void Militar(Horario &t){
    
    //imprime los miembros de la estructura t.
    
    cout<<(t.hora<10?"0":"")<<t.hora<<(t.minuto<10?"0":"")<<t.minuto;
    
    /* Recuerde que el operador condicional es (condicion ? valor-cierto:valor falso)*/
    
}
//recibe como argumento la referencia a la variable del tipo Horario;

void standar(Horario &t){
    cout<<((t.hora==0||t.hora==12)?12:t.hora%12)<<":"<<(t.minuto<10?"0":"")<<t.minuto<<":"<<(t.segundo<10?"0":"")<<t.segundo<<(t.hora<12?"AM":"PM");
}
