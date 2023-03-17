//
//  main.cpp
//  nodos y listas simples y ligadas
//
//  Created by Luis Navarrete on 06/09/21.
//

#include <iostream>

using namespace std;

struct nodo{
    int info;
    nodo *liga;
};
//prototipos
nodo* crea();
nodo* inserta_inicio(struct nodo *p,int dato);
nodo* inserta_final(struct nodo* p,int dato);
nodo* inserta_antes(struct nodo* p,int dato,int x);
nodo* inserta_despues(struct nodo* p,int dato,int x);
nodo* Elimina_inicio(struct nodo *p);
nodo* Elimina_final(struct nodo *p);
nodo* elimina_referencia(struct nodo* p,int x);
nodo* elimina_antes(struct nodo* p,int x);
nodo* elimina_despues(struct nodo* p,int x);
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
        cout<<endl<<"Elimina dato con la Referencia dada[8]"<<endl;
        cout<<endl<<"Elimina dato antes de la  Referencia dada[9]"<<endl;
        cout<<endl<<"Elimina dato después de la  Referencia dada[10]"<<endl;
        cout<<endl<<"Busqueda de un dato[11]"<<endl;
      //  cout<<endl<<"inserta al inicio-circulares[19]"<<endl;
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
                break;
            case 5: cout<<"Dame el dato: ";
                cin>>dato;
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=inserta_despues(p,dato,x);
                break;
            case 6: p=Elimina_inicio(p);
                cout<<endl<<"Dato del inicio eliminado!!"<<endl;
                break;
            case 7: p=Elimina_final(p);
                cout<<endl<<"Dato del final eliminado!!"<<endl;
                break;
            case 8:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_referencia(p,x);
                break;
            case 9:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_antes(p,x);
                break;
            case 10:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=elimina_despues(p,x);
                cout<<endl<<"Dato eliminado!!"<<endl;
                break;
            case 11:
                cout<<"Dame la referencia: ";
                    cin>>x;
                p=busqueda_referencia(p,x);
                break;
          /*  case 19: cout<<"Dame el dato: ";
                cin>>dato;
                p=inserta_inicioCirculares(p,dato);
                cout<<endl<<"Dato insertado al inicio-circulares!!"<<endl;
                break;*/
        }
    }while(op!=12);
    return 0;
}
/*nodo* inserta_inicioCirculares(struct nodo *p,int dato){
    nodo *q=NULL,*t=NULL;
    if(p==NULL){
        p=crea();
        p->liga=p;
    }else{
        t=p;
    while(t->liga!=p){
        t=t->liga;
        q=crea();
        q->info=dato;
        q->liga=p;
        t->liga=q;
        p=q;
    }
    }
    return p;
}*/
nodo* busqueda_referencia(struct nodo *p,int x){
    if(p!=NULL){
        if(p->info==x){
            cout<<endl<<"El elemento SI se encuentra en la lista!!"<<endl;
        }else{
        busqueda_referencia(p->liga,x);
        }
    }else{
        cout<<endl<<"El elemento NO se encuentra en la lista!!"<<endl;
    }
    return p;
}
nodo* elimina_despues(struct nodo* p,int x){
    nodo*q=p,*t=NULL,*r=NULL;
    int band=1;
    if(p==NULL){
        cout<<endl<<"Lista vacia no hay nodos a eliminar!!"<<endl;
    }else{
        while(q->info!=x&&band==1){
            if(q->liga!=NULL){
                q=q->liga;
            }else{
                band=0;
            }
        }
        if(band==1){
            if(q->liga==NULL){
            cout<<endl<<"no hay nodos posterior a la referencia: "<<x<<endl;
        }else{
            t=q->liga;//nodo a eliminar
            r=t->liga;
            if(r!=NULL){
                q->liga=r;
                r->liga=q;
            }else{
                q->liga=NULL;
        }
    }
            delete(t);
        }else{
            cout<<endl<<"Referencia no encontrada,nodo no elimiando!!"<<endl;
        }
    }
    return p;
}
nodo* elimina_antes(struct nodo* p,int x){
    nodo*q=NULL,*t=NULL,*r=NULL;
    int band;
    if(p->info==x){
        cout<<endl<<"No existe un nodo que preceda al que contiene: "<<x<<endl;
    }else{
        q=p;
        t=p;
        band=1;
        while(q->info!=x&&band==1){
            if(q->liga!=NULL){
                r=t;
                t=q;
                q=q->liga;
            }else{
                band=0;
            }
        }
        if(band==0){
            cout<<endl<<"El elemento no se encuentra en la lista!!"<<endl;
        }else{
            if(p->liga==q){//el elemento a eliminar es el primero
                p=q;
            }else{
                r->liga=q;
            }
            delete(t);
            cout<<endl<<"Elemento eliminado!!"<<endl;
        }
    }
    return p;
}
nodo* elimina_referencia(struct nodo* p,int x){
    nodo*q=p;
    nodo*t=NULL;
    int band=1;
    while(q->info!=x && band==1){
        if(q->liga!=NULL){
            t=q;
            q=q->liga;
        }else{
            band=0;
        }
    }
    if(band==0){
        cout<<endl<<"El elemento con referencia "<<x<<" no se ha encontrado!"<<endl;
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
nodo* Elimina_final(struct nodo *p){
    nodo*q=p;
    nodo*t=NULL;
    if(p->liga==NULL){
        p=NULL;
    }else{
        while(q->liga!=NULL){
            t=q;
        q=q->liga;
    }
        t->liga=NULL;
        delete(q);
    }
    return p;
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
