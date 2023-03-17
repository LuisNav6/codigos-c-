//
//  main.cpp
//  colas
//
//  Created by Luis Navarrete on 23/08/21.
//

#include <iostream>
using namespace std;
struct cola{
    char nombre[25];
    int prioridad;
};
bool cola_llena(int fi,int max);
bool cola_vacia(int fr);
void inserta(int &fr,int &fi,int cola[],int max,int dato);
int elimina(int &fr,int &fi,int cola[],int max);
void mostrar(int cola[],int &fr,int &fi);
int main(int argc, const char * argv[]) {
    int max=5, dato;
    cola cola[max],fr=-1,fi=-1;
    int resp;
    bool band=false;
    do{
        cout<<"COLA LLENA..1"<<endl;
        cout<<"COLA VACIA..2"<<endl;
        cout<<"INSERTA..3"<<endl;
        cout<<"ELIMINA..4"<<endl;
        cout<<"MOSTRAR..5"<<endl;
        cout<<"SALIR..6"<<endl;
        cin>>resp;
    switch(resp){
        case 1:band=cola_llena(fi,max);
            if(band)
                cout<<endl<<"Cola llena!!"<<endl;
            else
                cout<<endl<<"Tu cola no llena!!"<<endl;
            system("pause");
            break;
        case 2:band=cola_vacia(fr);
            if(band)
                cout<<endl<<"Cola vacia!!"<<endl;
            else
                cout<<endl<<"Tu cola no esta vacia!!"<<endl;
            system("pause");
            break;
        case 3: cout<<endl<<"Ingresa un dato: ";
            cin>>dato;
            inserta(fr,fi,cola,max,dato);
            break;
        case 4: int el;
            el=elimina(fr,fi,cola,max);
            break;
        case 5:mostrar(cola,fr,fi);
            break;
    }
    }while(resp!=6);
}
void mostrar(int cola[],int &fr,int &fi){
    for(int i=fr;i<=fi;i++){
        cout<<"["<<cola[i]<<"]"<<endl;
    }
}
int elimina(int &fr,int &fi,int cola[],int max){
    int dato=-1;
    if(!cola_vacia(fr)){
        dato=cola[fr];
        if(fr==fi){
            fr=-1;
            fi=-1;
        }else{
            fr++;
        }
    }else{
        cout<<endl<<"SUBDESBORDAMIENTO-COLA VACIA!"<<endl;
    }
    return dato;
}
void inserta(int &fr,int &fi,int cola[],int max,int dato){
    if(!cola_llena(fi,max)){
        fi++;
        cola[fi]=dato;
     if(fi==0)
        fr=0;
    }else{
        cout<<endl<<"DESBORDAMIENTO-COLA LLENA!"<<endl;
    }
}
bool cola_llena(int fi,int max){
    if(fi==(max-1)){
        return true;
    }else{
        return false;
    }
}
bool cola_vacia(int fr){
    if(fr==(-1)){
        return true;
}else
    return false;
}
