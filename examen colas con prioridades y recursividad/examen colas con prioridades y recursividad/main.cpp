//
//  main.cpp
//  examen colas con prioridades y recursividad
//
//  Created by Luis Navarrete on 09/09/21.
//
#include<iostream>
#include <string.h>
using namespace std;
struct cola{
    string nombre;
    int prioridad;
};
bool cola_vacia(int fr);
bool cola_llena(int fi, int fr,int max);
void inserta(struct cola cola[],int *fr,int *fi,struct cola dato,int max);
void elimina(struct cola cola[],int *fr,int *fi,struct cola *dato,int max);
void mostrar(struct cola cola[], int fr, int fi,int max);
int main(){
    int resp,max=5,fr=-1,fi=-1,prioridad;
    struct cola cola[max],dato;
    for(int i=0;i<max;i++){
        cola[i].nombre="\0";
        cola[i].prioridad=NULL;
    }
    do{
        cout<<"************************************************"<<endl;
        cout<<endl<<"COLA LLENA....[1]";
        cout<<endl<<"COLA VACIA....[2]";
        cout<<endl<<"INSERTAR....[3]";
        cout<<endl<<"ELIMINAR....[4]";
        cout<<endl<<"MOSTRAR....[5]";
        cout<<endl<<"SALIR....[6]"<<endl;
        cin>>resp;
        switch(resp){
            case 1:
                if(cola_vacia(fr)){
                    cout<<"cola vacía!!"<<endl;
                }
                else{
                    cout<<"Tu cola no está vacía!!"<<endl;
                }
                break;
            case 2:
                if(cola_llena(fi,fr,max)){
                    cout<<"Cola llena"<<endl;
                }
                else{
                    cout<<"Tu cola no está llena!!"<<endl;
                }
            break;
            case 3:
                cout<<"Ingresa un trabajo: ";
                cin>>dato.nombre;
                cout<<endl<<"Ingresa tu prioridad([1]-INMEDIATO,[2]-URGENTE,[3]-NORMAL):";
                cin>>dato.prioridad;
                inserta(cola,&fr,&fi,dato,max);
            break;
            case 4:
                elimina(cola,&fr,&fi,&dato,max);
            break;
            case 5:
                mostrar(cola, fr, fi,max);
            break;
        }
    }while(resp!=6);
}

void mostrar(struct cola cola[],int fr,int fi,int max){
    cout << "Trabajos a realizar"<<endl;
    for(int i=0;i<max;i++)
    {
        if(cola[i].nombre == "\0"){
            cout<<"[ ]";
        }
        else{
            cout<<"["<<cola[i].nombre<<"]";
        }
    }
    cout << endl;
    cout << "Prioridad a tomar:"<<endl;
    for(int j=0;j<max;j++)
    {
        if(cola[j].prioridad==NULL){
            cout<<"[ ]";
        }else{
            cout<<"["<<cola[j].prioridad<<"]";
        }
    }
    cout<<endl;
}
void elimina(struct cola cola[],int *fr,int *fi,struct cola *dato,int max){
    if(cola_vacia(*fr)==false){
        *dato=cola[*fr];
        cola[*fr].nombre="\0";
        cola[*fr].prioridad=NULL;
        cout<<endl<<"Dato eliminado!!"<< endl;
        if(*fr==*fi){
            *fr=-1;
            *fi=-1;
        }else{
            if(*fr==max-1){
                *fr=0;
            }else{
                *fr=*fr+1;
            }
        }
    }else{
        cout<<endl<<"SUBDESBORDAMIENTO-COLA VACIA!"<<endl;
    }
}
void inserta(struct cola cola[],int *fr,int *fi,struct cola dato,int max){
    if(cola_llena(*fi,*fr,max)==false){
            struct cola aux;
            if(*fi==max-1){
                *fi=0;
            }else{
                *fi = *fi+1;
            }
            cola[*fi]=dato;
        cout<<"trabajo agregado!"<<endl;
            if(*fr==-1){
                *fr=0;
            }
            for (int i=0;i<=*fi;i++) {
                for (int j=i;j<=*fi;j++) {
                       if (cola[i].prioridad>cola[j].prioridad) {
                           aux=cola[i];
                        cola[i]=cola[j];
                        cola[j]=aux;
                    }
                }
            }
    }else{
        cout<<endl<<"DESBORDAMIENTO-COLA LLENA!"<<endl;
    }
}
bool cola_vacia(int fr){
    if(fr==-1){
        return true;
    }else{
        return false;
    }
}
bool cola_llena(int fi,int fr,int max){
    if((fi==max-1)&&(fr==0))
    {
        return true;
    }
    else if(fi==fr-1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

