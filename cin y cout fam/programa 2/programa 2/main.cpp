//
//  main.cpp
//  programa 2
//
//  Created by Luis Navarrete on 17/03/21.
//
//programa que lee un año y dice si es bisiesto o no

#include <iostream>
using namespace std;
int bisiesto(int);//prototipo de la funcion que valida si un año es bisiesto o no
int main(){
    int anio,op,respuesta;
    do{
        cout<<endl<<"introduce año:";//164 es codigo ASCII de control para la ñ
        cin>>anio;//captura anio
        respuesta=bisiesto(anio);//llamada a la funcion
        if(respuesta==1)//verifica que regreso la funcion
            cout<<"bisiesto"<<endl;
            else
                cout<<"no es bisiesto"<<endl;
        cout<<"Deseas probar otro año: 1.SI 2.NO";
        cin>>op;//lee la respuesta
    }while(op==1);//mientras que op sea 1 quiere hacer otra consulta
    return 0;
}
/*un año es bisiesto cuando es multiplo de 4 pero no de 100, o bien cuando es multiplo de 400*/
int bisiesto(int a){//definicion de la funcion
    if((a%4==0&&a%100!=0)||a%400==0)
        return 1;//si es bisiesto retorna 1
    else
        return 0;
}


