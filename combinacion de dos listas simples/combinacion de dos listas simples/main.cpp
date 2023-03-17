//
//  main.cpp
//  combinacion de dos listas simples
//
//  Created by Luis Navarrete on 05/10/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *liga;
};
//prototipos
nodo* inserta_inicio(struct nodo *p,int dato);//llenar lista 1
nodo* inserta_inicio2(struct nodo *t,int dato);//llenar lista 2
nodo* crea();//crear espacio
void recorre(struct nodo* p,struct nodo* t);//mostrar lista 1 y 2
void recorre3(struct nodo* p);//mostrar lista 3
nodo* Unirlistas(struct nodo* p,struct nodo* t);//unir la lista 1 y 2
int main(int argc, const char * argv[]) {
    nodo *p=NULL;
    nodo *t=NULL;
    int op,dato;
    do{
        cout<<endl<<"Inserta al inicio lista 1 [1]"<<endl;
        cout<<endl<<"Inserta al inicio lista 2 [2]"<<endl;
        cout<<endl<<"Mostrar contenido de listas 1 y 2 [3]"<<endl;
        cout<<endl<<"Unir lista 1 y 2 [4]"<<endl;
        cout<<endl<<"Mostrar lista 3 [5]"<<endl;
        cout<<endl<<"Salir [6]"<<endl;
        cout<<endl<<"Dame la opcion deseada:";
        cin>>op;
        switch(op){
            case 1:cout<<endl<<"LISTA 1"<<endl;
                cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicio(p,dato);
                cout<<endl<<"Dato insertado al inicio!!"<<endl;
                break;
            case 2:cout<<endl<<"LISTA 2"<<endl;
                cout<<"Dame el dato: ";
                cin>>dato;
                t=inserta_inicio(t,dato);
                cout<<endl<<"Dato insertado al inicio!!"<<endl;
                break;
            case 3: recorre(p,t);
                break;
            case 4: p=Unirlistas(p,t);
                cout<<endl<<"LISTAS MEZCLADAS CON EXITO!!"<<endl;
                break;
            case 5:cout<<endl<<"LISTA 3:"<<endl;
                recorre3(p);
                break;
        }
    }while(op!=6);
    return 0;
}
void recorre3(struct nodo* p){
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
nodo* Unirlistas(struct nodo* p,struct nodo* t){
    nodo* r;
    if(p==NULL){//lista 1 vacia
        cout<<endl<<"LISTA VACIA!!"<<endl;
        p=t;
    }else{
        if(t!=NULL){// lista 2 no esta vacia
            r=p;//buscar ultimo nodo de lista 1
            while(r->liga!=NULL)
                r=r->liga;
            r->liga=t;//enlaza lista 2 después del ultimo nodo y p apunta a lista 2
        }
    }
    return p;//retornamos lista 1
}
void recorre(struct nodo* p,struct nodo *t){
    nodo *q=p;
    cout<<endl<<"lista 1:"<<endl;
    if(q==NULL){
        cout<<"Lista Vacia!!!"<<endl;
    }else{
        while(q!=NULL){
            cout<<"["<<q->info<<"]"<<"      ";
            q=q->liga;
        }
    }
nodo *r=t;
    cout<<endl<<"lista 2:"<<endl;
if(r==NULL){
    cout<<"Lista Vacia!!!"<<endl;
}else{
    while(r!=NULL){
        cout<<"["<<r->info<<"]"<<"      ";
        r=r->liga;
    }
}
cout<<endl;
}
nodo* inserta_inicio2(nodo *t,int dato){
    nodo *q=NULL;
    if(t==NULL){
        t=crea();
        t->info=dato;
        t->liga=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->liga=t;
        t=q;
    }
    return t;
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
