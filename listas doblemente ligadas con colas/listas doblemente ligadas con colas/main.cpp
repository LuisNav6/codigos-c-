//
//  main.cpp
//  listas doblemente ligadas con colas
//
//  Created by Luis Navarrete on 27/09/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *izq,*der;
};
//prototipos
nodo* crea();
nodo* inserta_final(struct nodo* p,int dato);
nodo* Elimina_inicio(struct nodo *p);
void recorre(struct nodo* p);

int main(int argc, const char * argv[]) {
    int op,dato;
    nodo *p=NULL;
    do{
        cout<<endl<<"INSERTA...[1]"<<endl;
        cout<<endl<<"ELIMINA...[2]"<<endl;
        cout<<endl<<"MOSTRAR...[3]"<<endl;
        cout<<endl<<"SALIR...[4]"<<endl;
        cout<<endl<<"Dame la opción deseada:";
        cin>>op;
        switch(op){
            case 1:
                cout<<"Dame el dato: ";
                   cin>>dato;
                   p=inserta_final(p,dato);
                   cout<<endl<<"Dato insertado!!"<<endl;
                break;
            case 2:
                p=Elimina_inicio(p);
                      cout<<endl<<"Dato eliminado!!"<<endl;
                break;
            case 3: recorre(p);
                break;
        }
    }while(op!=4);
    return 0;
}
nodo* Elimina_inicio(struct nodo *p){//elimina
    nodo*q=p;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        p=p->der;
        if(p!=NULL)
        p->izq=NULL;
        delete(q);
    }
    return p;
}
void recorre(nodo* p){//mostrar
    nodo *q=p;
    if(q==NULL){
        cout<<"Lista Vacia!!!"<<endl;
    }else{
        while(q!=NULL){
            cout<<"["<<q->info<<"]"<<"      ";
            q=q->der;
        }
    }
    cout<<endl;
}
nodo* inserta_final(struct nodo* p,int dato){//inserta
    nodo *q=NULL;
    nodo *t=p;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->der=NULL;
        p->izq=NULL;
    }else{
    q=crea();
    q->info=dato;
    q->der=NULL;
        while(t->der!=NULL)
            t=t->der;
            t->der=q;
            q->izq=t;
    }
    return p;
}
nodo* crea(){//crea el espacio en memoria
    nodo *p;
    p=new nodo;
    return p;
   
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
