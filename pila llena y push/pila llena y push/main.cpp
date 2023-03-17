//
//  main.cpp
//  pila llena y push
//
//  Created by Luis Navarrete on 10/08/21.
//

#include <iostream>
bool pilallena(int &max,int &tope);
void push(int pila[5],int &max,int &tope,int dato);
bool pilavacia(int &tope);
int pop(int pila[5],int &tope);
void mostrar(int pila[5],int &tope);
using namespace std;
int main(){
    int resp;
    int max=5;
    int tope=-1;
    int pila[max];
    int dato;
    do{
        cout<<"PILA LLENA..1"<<endl;
        cout<<"PILA VACIA..2"<<endl;
        cout<<"PUSH..3"<<endl;
        cout<<"POP..4"<<endl;
        cout<<"MOSTRAR..5"<<endl;
        cout<<"SALIR..6"<<endl;
        cin>>resp;
    switch(resp){
        case 3: cout<<endl<<"Ingresa un dato: ";
            cin>>dato;
            push(pila,max,tope,dato);
            break;
        case 4: int quita;
            quita=pop(pila,tope);
            break;
        case 5:mostrar(pila,tope);
            break;
    }
    }while(resp!=6);
        
}

bool pilallena(int &max,int &tope){
    if(tope==(max-1)){
        cout<<endl<<"PILA LLENA"<<endl;
        return  true;
    }
    else{
        return false;
    }
}
void push(int pila[5],int &max,int &tope,int dato){
    bool band;
    band=pilallena(max,tope);
             if(band)
                 cout<<"DESBORDAMIENTO"<<endl;
             else
                 tope++;
    pila[tope]=dato;
    //mostrar(pila,tope);
}
bool pilavacia(int &tope){
    if(tope==(-1)){
        cout<<endl<<"PILA VACIA"<<endl;
        return true;
        
    }else{
        return false;
    }
}
int pop(int pila[5],int &tope){
    bool band;
    int dato=-1;
    band=pilavacia(tope);
    if(band){
        cout<<"SUBDESBORDAMIENTO"<<endl;
    }
    else{
        dato=pila[tope];
        tope--;
       // mostrar(pila,tope);
    }
    return (dato);
}
void mostrar(int pila[5],int &tope){
    for(int i=tope;i>=0;i--)
    cout<<endl<<"["<<pila[i]<<"]"<<endl;
}
