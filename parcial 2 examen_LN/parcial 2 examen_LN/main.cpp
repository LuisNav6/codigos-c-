//
//  main.cpp
//  parcial 2 examen_LN
//
//  Created by Luis Navarrete on 26/10/21.
//

#include <iostream>
using namespace std;

//for divided list
struct nodo2{
    int info;
    nodo2 *izq,*der;
};

//for mixed lists
struct nodo{
    int info;
    nodo *liga;
};
//PROTOTYPES

//for divided list
nodo2* crea();//memory space
nodo2* inserta_inicio(struct nodo2 *p,int dato);//insert dato
void recorre(struct nodo2* p);//show

//for mixed lists
nodo* inserta_final(struct nodo *r,int dato);//fill list 1
nodo* inserta_final2(struct nodo *w,int dato);//fill list 2
nodo* crea2();//creat a memory space
void recorre_mezcla(struct nodo* r,struct nodo* w);//show list 1 and 2
void recorre3(struct nodo* r);//show list 3
nodo* Unirlistas(struct nodo* r,struct nodo* w);//link the list 1 and 2

int main(int argc, const char * argv[]) {
    int resp;//for do and switch principal
    //for divided list
    int op,dato;
    nodo2* p=NULL,*s=NULL;
    //for mixed lists
    nodo *r=NULL;
    nodo *w=NULL;
    int o,d;
    do{
        cout<<endl<<" E X A M E N   P A R C I A L    2"<<endl;
        cout<<endl<<"Dividir una lista en positivos y negativos [1]"<<endl;
        cout<<endl<<"Mezclar 2 listas ordenadas y crear una tercera [2]"<<endl;
        cout<<endl<<"Salir [3]"<<endl;
        cout<<endl<<"Cual opción deseas: ";
        cin>>resp;
        switch(resp){
            case 1:
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
                            }else{
                            p=inserta_inicio(p,dato);
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
                break;
             case 2:
                do{
                    cout<<endl<<"Inserta al inicio lista 1 [1]"<<endl;
                    cout<<endl<<"Inserta al inicio lista 2 [2]"<<endl;
                    cout<<endl<<"Mostrar contenido de listas 1 y 2 [3]"<<endl;
                    cout<<endl<<"Unir lista 1 y 2 [4]"<<endl;
                    cout<<endl<<"Mostrar lista 3 [5]"<<endl;
                    cout<<endl<<"Salir [6]"<<endl;
                    cout<<endl<<"Dame la opcion deseada:";
                    cin>>o;
                    switch(o){
                        case 1:cout<<endl<<"LISTA 1"<<endl;
                            cout<<"Dame el dato: ";
                            cin>>d;
                            r=inserta_final(r,d);
                            cout<<endl<<"Dato insertado al inicio!!"<<endl;
                            break;
                        case 2:cout<<endl<<"LISTA 2"<<endl;
                            cout<<"Dame el dato: ";
                            cin>>d;
                            w=inserta_final2(w,d);
                            cout<<endl<<"Dato insertado al inicio!!"<<endl;
                            break;
                        case 3: recorre_mezcla(r,w);
                            break;
                        case 4: r=Unirlistas(r,w);
                            cout<<endl<<"LISTAS MEZCLADAS CON EXITO!!"<<endl;
                            break;
                        case 5:cout<<endl<<"LISTA 3:"<<endl;
                            recorre3(r);
                            break;
                    }
                }while(o!=6);
                break;
        }
    }while(resp!=3);
    return 0;
}
//divided list
nodo2* crea(){//crea el espacio en memoria
    nodo2 *p;
    p=new nodo2;
    return p;
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
nodo2* inserta_inicio(nodo2 *p,int dato){//insert dato
    nodo2 *q=NULL;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->izq=NULL;
        p->der=NULL;
    }else{
        q=crea();
        q->info=dato;
        q->der=p;
        p->izq=q;
        q->izq=NULL;
        p=q;
    }
    return p;
}
void recorre(nodo2* p){
    nodo2*q=p;
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

//--------------------------------------------------------------------------

//mixed lists
nodo* inserta_final(struct nodo* r,int dato){
    nodo *q=NULL;
    nodo *t=r;
    if(r==NULL){
        r=crea2();
        r->info=dato;
        r->liga=NULL;
    }else{
    q=crea2();
    q->info=dato;
    q->liga=NULL;
        while(t->liga!=NULL)
            t=t->liga;
            t->liga=q;
    }
    return r;
}
nodo* inserta_final2(struct nodo* w,int dato){
    nodo *q=NULL;
    nodo *t=w;
    if(w==NULL){
        w=crea2();
        w->info=dato;
        w->liga=NULL;
    }else{
    q=crea2();
    q->info=dato;
    q->liga=NULL;
        while(t->liga!=NULL)
            t=t->liga;
            t->liga=q;
    }
    return w;
}
nodo* crea2(){//crea el espacio en memoria
    nodo *p;
    p=new nodo;
    return p;
   
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
void recorre3(struct nodo* r){
    nodo *q=r;
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
nodo* Unirlistas(struct nodo* r,struct nodo* w){
    nodo* z;
    if(r==NULL){//lista 1 vacia
        cout<<endl<<"LISTA VACIA!!"<<endl;
        r=w;
    }else{
        if(w!=NULL){// lista 2 no esta vacia
            z=r;//buscar ultimo nodo de lista 1
            while(z->liga!=NULL)
                z=z->liga;
            z->liga=w;//enlaza lista 2 después del ultimo nodo y p apunta a lista 2
        }
    }
    return r;//retornamos lista 1
}
void recorre_mezcla(struct nodo* r,struct nodo *w){
    nodo *q=r;
    cout<<endl<<"lista 1:"<<endl;
    if(q==NULL){
        cout<<"Lista Vacia!!!"<<endl;
    }else{
        while(q!=NULL){
            cout<<"["<<q->info<<"]"<<"      ";
            q=q->liga;
        }
    }
nodo *z=w;
    cout<<endl<<"lista 2:"<<endl;
if(z==NULL){
    cout<<"Lista Vacia!!!"<<endl;
}else{
    while(z!=NULL){
        cout<<"["<<z->info<<"]"<<"      ";
        z=z->liga;
    }
}
cout<<endl;
}
