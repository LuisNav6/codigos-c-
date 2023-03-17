//
//  main.cpp
//  programa 1
//
//  Created by Luis Navarrete on 16/03/21.
//

#include <iostream>
#include <iomanip>//para us ode fixed y setprecision para indicarv dcimales
#include <cmath>//para uso de pow
using namespace std;
//prototipos
void formulas();
int main(){
    /*programa que leea el valor del radio y calcule a longitud de la circunferencia, el area del circulo y el volumen de la esfera correspondiente a ese radio
     
     longitud de la circunferencia=2*PI*radio
     area de la circunferencia=PIU*radio^2
     volumen de la esfera=(4/3)*PI*radio^3*/
    formulas();
    system("pause");
    return 0;
}
void formulas(){
    const float PI=3.1416;/*const se utiliza para declarar constantes es una forma opcional al #define,hacerlo de esta esta manera hace que la constante sea local*/
    float radio;
    cout<<"introduce el valor del radio:";
    cin>>radio;
    cout<<fixed<<setprecision(2);/*de aqui en adelante cualquier numero real que se imprima tendra 2 decimales*/
    cout<<endl<<"longitud de la circunferencia:"<<2*PI*radio;
    cout<<endl<<"area del circulo:"<<PI*pow(radio,2);
    cout<<endl<<"volumen de la esfera:"<<(4.0/3)*PI*pow(radio,3)<<endl;
}
  
