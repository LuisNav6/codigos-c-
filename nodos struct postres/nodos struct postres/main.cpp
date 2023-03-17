//
//  main.cpp
//  nodos struct postres
//
//  Created by Luis Navarrete on 03/10/21.
//

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

//struct de postres
struct postres{
    string nombre;
    postres *liga;
};
struct ingredientes{//struct que almacena los ingredientes
    postres *ingr;
};

//prototipos
postres* crea();
postres* inserta_inicio(struct postres *p,string nom);
postres* elimina_referencia(struct postres* p,string nom);
///void recorre(struct postres* p,string nom);

int main(int argc, const char * argv[]) {
    int op;
    string nom;
    postres *p=NULL;
    do{
        cout<<endl<<"Dar de alta un postre [1]"<<endl;
        cout<<endl<<"Dar de baja un postre [2]"<<endl;
        cout<<endl<<"mostrar ingredientes de un postre [3]"<<endl;
        cout<<endl<<"salir [10]"<<endl;
        cout<<endl<<"Que opción deseas: ";
        cin>>op;
        switch(op){
            case 1: cout<<"Dame el nombre del postre: ";
                cin>>nom;
                p=inserta_inicio(p,nom);
                cout<<endl<<"Dato insertado"<<endl;
                break;
            case 2:
                cout<<"Dame el nombre del postre: ";
                    cin>>nom;
                p=elimina_referencia(p,nom);
                break;
            case 3:cout<<endl<<"Dame el nombre del postre a mostrar: ";
                cin>>nom;
             //   recorre(p,nom);
                break;
        }
    }while(op!=10);
    return 0;
}

postres* elimina_referencia(struct postres* p,string nom){
    postres*q=p;
    postres*t=NULL;
    int band=1;
    while(q->nombre!=nom && band==1){
        if(q->liga!=NULL){
            t=q;
            q=q->liga;
        }else{
            band=0;
        }
    }
    if(band==0){
        cout<<endl<<"El postre "<<nom<<" no se ha encontrado!"<<endl;
    }
        if(p==q){
        p=q->liga;
    }else{
        t->liga=q->liga;
    delete(q);
        cout<<endl<<"Elemento eliminado!!"<<endl;
}
    return p;
}
postres* inserta_inicio(postres *p,string nom){
    postres *q=NULL;
   // int n;
    if(p==NULL){
        p=crea();
        p->nombre=nom;
       /* cout<<endl<<"Dame el número de ingredientes: ";
        cin>>n;
        for(int i=0;i<=n;i++){
            cout<<endl<<"Dame el ingrediente "<<i<<": ";
            cin>>p[i].ing;
        }*/
        p->liga=NULL;
    }else{
        q=crea();
        p->nombre=nom;
        /*cout<<endl<<"Dame el número de ingredientes: ";
        cin>>n;
        for(int i=0;i<=n;i++){
            cout<<endl<<"Dame el ingrediente "<<i<<": ";
            q->postres.ing[i];
        }*/
        q->liga=p;
        p=q;
    }
    return p;
}
postres* crea(){//crea el espacio en memoria
    postres *p;
    p=new postres;
    return p;
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
