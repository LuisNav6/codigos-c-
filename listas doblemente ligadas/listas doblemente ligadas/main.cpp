//
//  main.cpp
//  listas doblemente ligadas
//
//  Created by Luis Navarrete on 21/09/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *izq,*der;
};
//prototipos
nodo* crea();
nodo* inserta_inicio(struct nodo *p,int dato);
nodo* inserta_final(struct nodo* p,int dato);
nodo* inserta_antes(struct nodo* p,int dato,int x);
nodo* inserta_despues(struct nodo* p,int dato,int x);
nodo* Elimina_inicio(struct nodo *p);
nodo* elimina_final(struct nodo*p);
nodo*elimina_antes(struct nodo* p,int x);
nodo*elimina_despues(struct nodo* p,int x);
nodo* elimina_referencia(struct nodo* p,int x);
nodo* busqueda_referencia(struct nodo *p,int x);
//nodo* inserta_inicioCirculares(struct nodo *p,int dato);
void recorre(struct nodo* p);
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
        cout<<endl<<"Elimina al final [7]"<<endl;
        cout<<endl<<"Elimina despues de una referencia [8]"<<endl;
        cout<<endl<<"Elimina antes de una referencia [9]"<<endl;
        cout<<endl<<"Elimina nodo con referencia x [10]"<<endl;
        cout<<endl<<"Busqueda de nodo con información x [11]"<<endl;
      // cout<<endl<<"inserta al inicio-circulares[19]"<<endl;
        cout<<endl<<"salir [12]"<<endl;
        cout<<endl<<"Que opción deseas: ";
        cin>>op;
        switch(op){
            case 1: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicio(p,dato);
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
            case 7: p=elimina_final(p);
                  cout<<endl<<"Dato del final eliminado!!"<<endl;
                break;
            case 8:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_despues(p,x);
                cout<<endl<<"el dato fue eliminado"<<endl;
                break;
            case 9:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_antes(p,x);
                cout<<endl<<"el dato fue eliminado"<<endl;
                break;
            case 10:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_referencia(p,x);
                break;
            case 11:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=busqueda_referencia(p,x);
                break;
          /* case 19: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicioCirculares(p,dato);
                cout<<endl<<"Dato insertado al inicio-circulares!!"<<endl;
                break;*/
        }
    }while(op!=12);
    return 0;
}
/* nodo* inserta_inicioCirculares(struct nodo *p,int dato){
    nodo *q=NULL,*t=NULL;
    if(p==NULL){
        p=crea();
        p->info=dato;
        p->izq=p;
        p->der=p;
    }else{
        q=crea();
        q->info=dato;
    while(t->der!=p){
        t=t->der;
        q->der=p;
        p->izq=q;
        q->izq=t;
        t->der=q;
        p=q;
    }
    }
    return p;
}*/
nodo* elimina_referencia(struct nodo* p,int x){
    nodo*q=p;
    nodo*t=NULL;
    int band=1;
    while(q->info!=x && band==1){
        if(q->der!=NULL){
            t=q;
            q=q->der;
        }else{
            band=0;
        }
    }
    if(band==0){
        cout<<endl<<"El elemento con referencia "<<x<<" no se ha encontrado!"<<endl;
    }
        if(p==q){//se encontro en la referencia
        p=q->der;
    }else{
        p->der=NULL;
        t->der=q->der;
    delete(q);
        cout<<endl<<"Elemento eliminado!!"<<endl;
}
    return p;
}
nodo* busqueda_referencia(struct nodo *p,int x){
    if(p!=NULL){
        if(p->info==x){
            cout<<endl<<"El elemento SI se encuentra en la lista!!"<<endl;
        }else{
        busqueda_referencia(p->der,x);
        }
    }else{
        cout<<endl<<"El elemento NO se encuentra en la lista!!"<<endl;
    }
    return p;
}
nodo*elimina_antes(struct nodo* p,int x){
    nodo*q=p,*t=NULL,*r=NULL;
    while(q->der!=NULL&&q->info!=x)
        q=q->der;
    if(q->info==x){
        if(p==q){
            cout<<endl<<"No existe el nodo anterior al primero!!"<<endl;
        }else{
            t=q->izq;
            if(p==t){//es el primer nodo de la lista
                p=q;
                p->izq=NULL;
            }else{
                r=t->izq;
                q->izq=r;
                r->der=q;
            }
            delete(t);
        }
    }else{
        cout<<endl<<"El elemento con información:"<<x<<" no esta en la lista!!"<<endl;
    }
    return p;
}
nodo*elimina_despues(struct nodo*p,int x){
    bool band=true;
    nodo*q=p,*t=NULL,*r=NULL;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        while(q->info!=x&&band==true){
            if(q->der!=NULL){
                q=q->der;
            }else{
                band=false;
            }
        }
        if(band==true){
            if(q->der==NULL){
                cout<<endl<<"No hay nodos posterior a la referencia!!"<<endl;
    }else{
        t=q->der;//nodo a eliminar
        r=t->der;
        if(r!=NULL){
            q->der=r;
            r->izq=q;
        }else{
            q->der=NULL;
        }
    }
    delete(t);
    }else{
        cout<<endl<<"Referencia no encontrada,nodo no eliminado!!"<<endl;
    }
    }
    return p;
}
nodo* elimina_final(struct nodo*p){
    nodo*q=p;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        p=p->izq;
        if(p!=NULL)
        p->der=NULL;
        delete(q);
    }
    return p;
}
nodo* Elimina_inicio(struct nodo *p){
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
 
nodo* inserta_despues(struct nodo* p,int dato,int x){
    nodo *q=p;
    nodo *t=NULL;
    nodo *r=NULL;
    bool band = true;
    while(q->info!=x&&q->izq!=NULL&&band==true)
            q=q->izq;
    if(q->info==x&&band==true){
        t=crea();
        t->info=dato;
        t->izq=q;
        r=q->der;
        q->der=t;
        if(p==q){
            p=t;
            t->der=NULL;
        } else{
            if(band==false){
            r->izq=t;
            t->der=r;
            cout<<"El nodo dado como referencia no fue encontrado,dato no insertado!!"<<endl;
            }
        }
    }
    return q;
}
nodo* inserta_antes(struct nodo* p,int dato,int x){
    nodo *q=p;
    nodo *t=NULL;
    nodo *r=NULL;
   // bool band = true;
    while(q->info!=x&&q->der!=NULL)
        q=q->der;
        if(q->info==x){
            t=crea();
            t->info=dato;
            t->der=q;
            r=q->izq;
            q->izq=t;
    if(p==q){
        p=t;
        t->izq=NULL;
    }else{
        r->der=t;
        t->izq=r;
        cout<<"Referencia no encontrada,dato no insertado!!"<<endl;
    }
        }
    return p;
}

nodo* inserta_final(struct nodo* p,int dato){
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
void recorre(nodo* p){
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
nodo* inserta_inicio(nodo *p,int dato){
    nodo *q=NULL;
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
nodo* crea(){//crea el espacio en memoria
    nodo *p;
    p=new nodo;
    return p;
   
    /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
}
