//
//  main.cpp
//  listas simples y pilas
//
//  Created by Luis Navarrete on 27/09/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *liga;
    nodo *izq,*der;
};

//prototipos
nodo* crea();
nodo* inserta_inicio(struct nodo *p,int dato);//pilas
nodo* Elimina_inicio(struct nodo *p);//pilas
nodo* inserta_final(struct nodo* p,int dato);//colas
nodo* Elimina_iniciocolas(struct nodo *p);//colas
void recorre(struct nodo* p);//pilas
void recorre_colas(struct nodo* p);//colas
int main(int argc, const char * argv[]) {
    int dato,op;
    nodo *p=NULL;
    do{
        cout<<endl<<"Push....[1]"<<endl;
        cout<<endl<<"Pop....[2]"<<endl;
        cout<<endl<<"mostrar pilas....[3]"<<endl;
        cout<<endl<<"INSERTA ELEMENTO COLA....[4]"<<endl;
        cout<<endl<<"ELIMINA ELEMENTO COLA....[5]"<<endl;
        cout<<endl<<"MOSTRAR COLAS....[6]"<<endl;
        cout<<endl<<"salir....[7]"<<endl;
        cout<<endl<<"Dame la opción deseada:";
        cin>>op;
        switch(op){
            case 1: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicio(p,dato);
                cout<<endl<<"Dato insertado al inicio!!"<<endl;
                break;
            case 2: p=Elimina_inicio(p);
                cout<<endl<<"Dato del inicio eliminado!!"<<endl;
                break;
            case 3: recorre(p);
                break;
            case 4:
                cout<<"Dame el dato: ";
                   cin>>dato;
                   p=inserta_final(p,dato);
                   cout<<endl<<"Dato insertado!!"<<endl;
                break;
            case 5:
                p=Elimina_iniciocolas(p);
                      cout<<endl<<"Dato eliminado!!"<<endl;
                break;
            case 6: recorre_colas(p);
                break;
        }
    }while(op!=7);
    return 0;
}
//colas
nodo* Elimina_iniciocolas(struct nodo *p){//elimina
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
void recorre_colas(nodo* p){//mostrar
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
//pilas
nodo* Elimina_inicio(struct nodo *p){//pop
    nodo*q=p;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        p=p->liga;
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
            q=q->liga;
        }
    }
    cout<<endl;
}
nodo* inserta_inicio(nodo *p,int dato){//push
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

