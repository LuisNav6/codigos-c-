//
//  main.cpp
//  examen recursividad
//
//  Created by Luis Navarrete on 09/09/21.
//

#include <iostream>
using namespace std;
int suma_sucesiva(int a,int b);
int suma_naturales(int n);

int main(int argc, const char * argv[]) {
    int op;
    int ss;
    //int r;
    do{
        cout<<"SUMAS SUCESIVAS....1"<<endl;
        cout<<"SUMA DE NUMEROS NATURALES....2"<<endl;
        cout<<"SALIR....3"<<endl;
        cout<<"QUE OPCION DESEAS:";
        cin>>op;
   
    switch(op){
        case 1: int a,b;
            cout<<endl<<"Dame el valor a sumar: ";
            cin>>a;
            cout<<endl<<"Dame las veces a sumar: ";
            cin>>b;
            ss=suma_sucesiva(a,b);
            cout<<"El resultado es: "<<ss<<endl;
            break;
        case 2: int n;
            cout<<endl<<"Dame el valor final:";
            cin>>n;
            cout<<endl<<"La suma de los primeros numeros naturales hasta "<<n<<" es:"<<suma_naturales(n)<<endl;
            break;
    }
    }while(op!=3);
}
int suma_naturales(int n){
    if(n==0||n==1)
        return n;
    else
        return suma_naturales(n-1)+n;
}
int suma_sucesiva(int a,int b){
    if(b==1)//caso base
        return a;
else
    return a+suma_sucesiva(a,b-1);//recursividad
    
}
