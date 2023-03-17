#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

struct nodo{
    string info;
    int id;
    nodo *liga;
};
nodo* crea();
nodo* inserta_final(struct nodo* p,string inf,int id);
nodo* Elimina_inicio(struct nodo *p);
void recorre(struct nodo* p);
int main(){
	 int op,id;
	 string inf;
	nodo *p=NULL;
	   do{
	   	cout<<endl<<"------QUEJAS Y SUGERENCIAS------"<<endl;
	   	cout<<endl<<"Añadir una queja o sugerencia [1]"<<endl;
	   	cout<<endl<<"Mostrar las quejas o sugerencias ingresadas [2]"<<endl;
	   	cout<<endl<<"Eliminar una queja o sugerencia [3]"<<endl;
	   	cout<<endl<<"Salir [4]"<<endl;
	   	cout<<endl<<"Dame la opcion deseada:";
	   	cin>>op;
	   	switch(op){
	   		case 1: cout<<"Dame tu queja o sugerencia:";
	   		fflush(stdin);
                getline(cin,inf);
                cout<<endl<<"Dame tu id:";
                cin>>id;
                p=inserta_final(p,inf,id);
                cout<<endl<<"Añadid@!!"<<endl;
                 break;
            case 2: recorre(p);
                 break;
            case 3: p=Elimina_inicio(p);
                cout<<endl<<"Eliminado!!"<<endl;
                 break;
		   }
	   }while(op!=4);
}
nodo* crea(){
	nodo *p;
    p=new nodo;
    return p;
}
nodo* inserta_final(struct nodo* p,string inf,int id){
	 nodo *q=NULL;
    nodo *t=p;
    if(p==NULL){
        p=crea();
        p->info=inf;
        p->id=id;
        p->liga=NULL;
    }else{
    q=crea();
    q->info=inf;
    q->id=id;
    q->liga=NULL;
        while(t->liga!=NULL)
            t=t->liga;
            t->liga=q;
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
void recorre(struct nodo* p){
    nodo *q=p;
    if(q==NULL){
        cout<<"Lista Vacia!!!"<<endl;
    }else{
        while(q!=NULL){
            cout<<"[id:"<<q->id<<"/"<<q->info<<"]"<<endl;
            q=q->liga;
        }
    }
    cout<<endl;
}
