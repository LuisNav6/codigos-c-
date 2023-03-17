//
//  main.cpp
//  arboles balanceados con nodos
//
//  Created by Luis Navarrete on 10/11/21.
//

#include <iostream>
struct nodo{
    int info;
    nodo *izq,*der;
    int FO;
};
//prototipos
nodo* crea();
nodo* insert(struct nodo *nodo,bool bo,int infor);//inserta en arboles balanceados
void inorden (struct nodo *apnodo);//recorrido del arbol
using namespace std;
int main(int argc, const char * argv[]) {
    nodo *nodo=NULL;
    int infor,op;
    bool bo=false;
    do{
    cout<<endl<<"A R B O L E S  A V L"<<endl;
    cout<<endl<<"Inserta...[1]"<<endl;
    cout<<endl<<"Mostrar...[2]"<<endl;
    cout<<endl<<"Salir...[3]"<<endl;
        cin>>op;
        switch(op){
            case 1:
                cout<<endl<<"Dame el dato a insertar:";
                cin>>infor;
                nodo=insert(nodo,bo,infor);
                break;
            case 2:
                inorden(nodo);
                break;
                
        }
    }while(op!=3);
    return 0;
}
nodo* insert(struct nodo *nodo,bool bo,int infor){
    nodo* otro;
    nodo* nodo1;
    nodo* nodo2;
    if(nodo!=NULL){//1
        if(infor<nodo->info){//1.1
            insert(nodo->izq,bo,infor);//recursive call;
            if(bo==true){//1.1.1
                if(nodo->FO){
                    
                }
            }
        }//1.1
    }//1
}
nodo* crea(){
    return new nodo;
}
