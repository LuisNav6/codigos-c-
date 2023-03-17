//
//  main.cpp
//  clase horario
//
//  Created by Luis Navarrete on 20/09/21.
//

#include <iostream>
#include "Chorario.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Chorario mihora;//instancia u objeto de la clase Chorario
    Chorario masTarde(15,10,55);
    cout<<endl<<"Datos del objeto más tarde"<<endl;
    masTarde.militar();
    cout<<endl;
    masTarde.estandar();
    cout<<endl<<"Datos del objeto mi hora"<<endl;
    mihora.ajuste(18,25,10);
    mihora.militar();
    mihora.estandar();
    return 0;
}
class Chorario{
private:
    int hora,minuto,segundo;
public:
    Chorario();//metodo constructor por defecto
    Chorario(int,int,int);//metodo constructor con argumentos
    void ajuste(int,int,int);
    void militar();
    void estandar();
};
Chorario::Chorario(int h,int m,int s){
    ajuste(h,m,s);
    
}
Chorario::Chorario(){
    hora=minuto=segundo=0;
}
void Chorario::ajuste(int h,int m,int s){
    hora=(h>=0&&h<=24)?h:0;//if resumido
    minuto=(m>=0&&m<=60)?m:0;
    segundo=(s>=0&&s<=24)?s:0;
}
void Chorario::militar(){
    cout<<(hora<10?"0":"")<<hora<<":"
    <<(minuto<10?"0":"")<<minuto<<":"
    <<(segundo<10?"0":"")<<segundo;
}
void Chorario::estandar(){
    cout<<((hora==0||hora==12)?12:hora%12)
    <<":"<<(minuto<10?"0":"")<<minuto
    <<":"<<(segundo<10?"0":"")<<segundo
    <<(hora<12?"AM":"PM");
}
