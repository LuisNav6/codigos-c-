//
//  main.cpp
//  struct con string y matriz de int
//
//  Created by Luis Navarrete on 29/03/21.
//

#include <iostream>
#include <string>
using namespace std;
struct varios{//se tienen 6 campos!!!
    string nombre;
    char dispositivo[30];
    int numeros[4];
    float temperaturas[3][3];
    char colores [3][20];
    
    struct masdatos{
        int punto[4];
        float num;
        int matriz[2][2];
        
    }aux;
};

int main(){
    varios dato1;
    cout<<endl<<"Nombre: ";
    getline(cin,dato1.nombre);
    cout<<endl<<"Dispositivo: ";
    cin.getline(dato1.dispositivo,30);
    
    for(int i=0;i<4;i++){
        cout<<endl<<"Dato# "<<i<<": ";
        cin>>dato1.aux.punto[i];
    }
    fflush(stdin);
    for(int i=0;i<3;i++){
        cout<<endl<<"Color# "<<i<<": ";
        cin.getline(dato1.colores[i],20);
    }
    cout<<"****************************";
    varios mat;
    for(int r=0;r<2;r++){
        for(int c=0;c<2;c++){
            cout<<endl<<"Dame el dato: ";
            cin>>mat.aux.matriz[r][c];
        }
    }
           
    cout<<"****************************";
    varios v[2];
    for(int i=0;i<2;i++){
        cout<<endl<<"posición #"<<i;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            cout<<endl<<"dato "<<r<<" "<<c<<": ";
            cin>>v[i].temperaturas[r][c];
        }
    }
    }//for i
    cout<<"****************************";
            varios datos;
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            cout<<endl<<"dato "<<r<<" "<<c<<": ";            cin>>datos.temperaturas[r][c];
        }
    }
    cout<<"****************************";
    varios var;
    for(int i=0;i<4;i++){
        cout<<endl<<"Dame un dato: ";
        cin>>var.numeros[i];
        
    }
    cout<<"****************************";
    varios vec[2];
    for(int j=0;j<2;j++){
        cout<<endl<<"posicion: "<<j;
        for(int i=0;i<4;i++){
            cout<<endl<<"Dame un dato: ";
            cin>>vec[j].numeros[i];
        }
    }
    return 0;
}

