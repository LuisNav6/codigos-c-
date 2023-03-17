//
//  main.cpp
//  listas simples divididas
//
//  Created by Luis Navarrete on 04/10/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *liga;
};
nodo* crea();
nodo* inserta_inicio(struct nodo *p,int dato);//añadir datos a la lista
void recorre(struct nodo* p);//mostrar la lista
int main(int argc, const char * argv[]) {
    int op,dato;
    nodo* p=NULL;
    nodo* s=NULL;
    bool band = false;
    do{
        cout<<endl<<"Insertar....[1]"<<endl;
        cout<<endl<<"mostrar...[2]"<<endl;
        cout<<endl<<"Salir...[3]"<<endl;
        cout<<endl<<"Dame la opcion deseada:";
        cin>>op;
        switch(op){
            case 1: cout<<"Dame el dato: ";
                cin>>dato;
                if(dato>0){
                s=inserta_inicio(s,dato);
                    band=true;
                }else{
                p=inserta_inicio(p,dato);
                    band=false;
                }
                cout<<endl<<"Dato insertado al inicio!!"<<endl;
                break;
            case 2: cout<<endl<<"LISTA POSITIVOS:"<<endl;
                    recorre(s);
                    cout<<endl<<"LISTA NEGATIVOS:"<<endl;
                    recorre(p);
            break;
        }
    }while(op!=3);
    return 0;
}
void recorre(nodo* p){
    nodo *q=p;
    if(q==NULL){
        cout<<"Lista Vacia!!!"<<endl;
    }else{
        while(q!=NULL){
          //  if(p->info>0){
                   cout<<"["<<q->info<<"]"<<"      ";
                   q=q->liga;
    }
}
    cout<<endl;
}
nodo* inserta_inicio(nodo *p,int dato){
    nodo *q=NULL;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->liga=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->liga=p;
        p=q;
    }
    return p;
}
nodo* crea(){//crea el espacio en memoria
    nodo *p;
    p=new nodo;
    return p;
   
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
