//
//  main.cpp
//  uso de constantes enum, define y const
//
//  Created by Luis Navarrete on 08/04/21.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
#define CENTIGRADOS 33.8//un grado centigrado pertenece a 33.8 grados farenheit
//prototipo de funciones
enum{LUZ=300000, DIA=24, HORA=60, MINUTO=60};
//la luz viaja a 300000 km/seg, el dia tiene 24 hrs, la hora 60 minutos, el minuto 60 seg
const double PI=3.1416;//enum no soporta variables de numeros reales
using namespace std;
float distancia(double tiempo);
float conversion(float grados);
void equivalencia(float horas);
void volumen();
void volcono();
int main(){
    double tiempo;
    double dist;
    float grados;
    float conver;
    float h;
    int resp = 0;
    cout<<endl;
    system("pause");
    do{
    cout<<"MENU DE OPCIONES!"<<endl;
    cout<<endl<<"Distancia recorrida...1";
    cout<<endl<<"Conversión de grados centígrados a Farenheit...2";
    cout<<endl<<"Equivalencia de horas en minutos,segundos y días...3";
    cout<<endl<<"Area y volumen de un cilindro...4";
    cout<<endl<<"Area y volumen de un cono...5";
    cout<<endl<<"Salir...6";
    cout<<endl<<"Dame la respuesta deseada: ";
    cin>>resp;
    switch(resp){
        case 1:cout<<endl<<"Dame el tiempo empleado en segundos: ";
        cin>>tiempo;
            dist=distancia(tiempo);
            cout<<endl<<"La distancia recorrida fue: "<<dist<<" km"<<endl;break;
        case 2:cout<<endl<<"Dame los grados a convertir: ";
            cin>>grados;
            conver=conversion(grados);
            cout<<endl<<"Los grados centígrados: "<<grados<<" en Farenheit son: "<<conver<<endl;break;
        case 3: cout<<endl<<"Dame la hora a trabajar: ";
            cin>>h;
            equivalencia(h);break;
        case 4:volumen();break;
        case 5:volcono();break;
        case 6: cout<<endl<<"¡ADIOS!"<<endl;break;
    }
    }while(resp!=6);
    return 0;
    
}
    // a partir de aqui se implementan las funciones
float distancia(double tiempo){
     double dist=0;
    dist=tiempo*LUZ;
    return dist;
}
float conversion(float grados){
    float conver;
    conver=grados*CENTIGRADOS;
    return conver;
}
void equivalencia(float horas){
    float minutos=0,segundos=0,dias=0;
    dias=horas/DIA;
    minutos=horas*HORA;
    segundos=minutos*MINUTO;
    cout<<endl<<"Tus horas son: "<<dias<<" en días"<<endl;
    cout<<endl<<"Tus horas son: "<<minutos<<" en minutos"<<endl;
    cout<<endl<<"Tus horas son: "<<segundos<<" en segundos"<<endl;
    
}
void volumen(){
    float altura, radio,v,a,x;
    cout<<endl<<"Dame la altura: ";
    cin>>altura;
    cout<<endl<<"Dame el radio: ";
    cin>>radio;
    x=altura*radio;
    v=PI*pow(radio,2)*altura;
    a=(2*PI)*(radio*x);
    cout<<endl<<"el volumen del cilindro dado es: "<<v<<endl;
    cout<<endl<<"el área del cilindro dado es: "<<a<<endl;
}
void volcono(){
    float altura, radio,v,a,x,g;
    cout<<endl<<"Dame la altura: ";
    cin>>altura;
    cout<<endl<<"Dame el radio: ";
    cin>>radio;
    cout<<endl<<"Dame la generatriz: ";
    cin>>g;
    x=radio+g;
    a=PI*(radio*x);
    v=(PI*pow(radio,2)*altura)/3;
    cout<<endl<<"el volumen del cilindro dado es: "<<v<<endl;
    cout<<endl<<"el área del cilindro dado es: "<<a<<endl;
}
