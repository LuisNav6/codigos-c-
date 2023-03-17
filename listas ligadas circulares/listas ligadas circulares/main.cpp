//
//  main.cpp
//  listas ligadas circulares
//
//  Created by Luis Navarrete on 20/09/21.
//

#include <iostream>

using namespace std;

    struct nodo{
        int info;
        nodo *liga;
    };
nodo *crea();
nodo *inserta_inicio_circulares(nodo *p,int dato);

int main(int argc, const char * argv[]) {
    int op,dato,x;
    nodo *p=NULL;
    do{
        cout<<endl<<"Inserta al inicio [1]"<<endl;
        cout<<endl<<"Recorre [2]"<<endl;
        cout<<endl<<"Inserta al final [3]"<<endl;
        cout<<endl<<"Inserta antes de la referencia [4]"<<endl;
        cout<<endl<<"Inserta después de la referencia [5]"<<endl;
        cout<<endl<<"Elimina al inicio [6]"<<endl;
        cout<<endl<<"salir [9]"<<endl;
        cout<<endl<<"Que opción deseas: ";
        cin>>op;
        switch(op){
            case 1: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicio_circulares(p,dato);
                cout<<endl<<"Dato insertado al inicio!!"<<endl;
                break;
            case 2: recorre(p);
                break;
            case 3: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_final(p,dato);
                cout<<endl<<"Dato insertado al final!!"<<endl;
                break;
            case 4: cout<<"Dame el dato: ";
                cin>>dato;
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=inserta_antes(p,dato,x);
                cout<<endl<<"El dato "<<dato<<" fue insertado antes de la referencia:"<<x<<endl;
                break;
            case 5: cout<<"Dame el dato: ";
                cin>>dato;
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=inserta_despues(p,dato,x);
                cout<<endl<<"El dato "<<dato<<" fue insertado después de la referencia:"<<x<<endl;
                break;
            case 6: p=Elimina_inicio(p);
                cout<<endl<<"Dato del inicio eliminado!!"<<endl;
                break;
        }
    }while(op!=9);
    return 0;
}
nodo* Elimina_inicio(struct nodo *p){
    nodo*q=p;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        p=p->liga;
        delete(q);
    }
    return p;
}
nodo* inserta_despues(struct nodo* p,int dato,int x){
    nodo *q=p;
    nodo *t=NULL;
    //nodo *r=NULL;
    bool band = true;
    while(q->info!=x&&band==true){
        if(q->liga!=NULL){
            q=q->liga;
        }else{
            band=false;
        }
    }
    if(band==true){
        t=crea();
        t->info=dato;
        t->liga=q->liga;
        q->liga=t;
    }else{
        cout<<"El nodo dado como referencia no fue encontrado,dato no insertado!!"<<endl;
    }
    return q;
}
nodo* inserta_antes(struct nodo* p,int dato,int x){
    nodo *q=p;
    nodo *t=NULL;
    nodo *r=NULL;
    bool band = true;
    while(q->info!=x&&band==true){
        if(q->liga!=NULL){
            t=q;
            q=q->liga;
        }else{
            band=false;
        }
    }
    if(band==true){
        r=crea();
        r->info=dato;
        if(p==q){
            r->liga=p;
            p=r;
        }else{
            t->liga=r;
            r->liga=q;
        }
    }else{
        cout<<"Referencia no encontrada,dato no insertado!!"<<endl;
    }
    return p;
}
nodo* inserta_final(struct nodo* p,int dato){
    nodo *q=NULL;
    nodo *t=p;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->liga=NULL;
    }else{
    q=crea();
    q->info=dato;
    q->liga=NULL;
        while(t->liga!=NULL)
            t=t->liga;
            t->liga=q;
    }
    return p;
}
void recorre(nodo* p){
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
nodo* inserta_inicio(nodo *p,int dato){
    nodo *q=NULL,*t=NULL;;
    if(p==NULL){
        p=crea();
        p->liga=p;
    }else
        t=p;
        while(t->liga!=p){
            t=t->liga;
        q=crea();
        q->info=dato;
        q->liga=p;
        t->liga=q;
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

    return 0;
}
