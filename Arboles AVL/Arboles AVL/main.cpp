//
//  main.cpp
//  Arboles AVL
//
//  Created by Luis Navarrete on 11/11/21.
//

#include <iostream>

using namespace std;
struct nodo{
    int info;
    nodo *izq,*der;
    int FE;
};
//prototypes
nodo* crea();//reserve memory
nodo* insert(struct nodo*p,bool bo, int infor);//insert and order
void inorden(struct nodo* apnodo);
int main(int argc, const char * argv[]) {
    int infor, op;
    bool bo=false;
    nodo *p=NULL;
    do{
        cout<<endl<<"A R B O L E S   A V L"<<endl;
        cout<<endl<<"Insertar...[1]"<<endl;
        cout<<endl<<"Mostrar...[2]"<<endl;
        cout<<endl<<"Salir...[3]"<<endl;
        cin>>op;
        switch(op){
            case 1: cout<<endl<<"Dame el dato a insertar:";
                cin>>infor;
                p=insert(p,bo,infor);
                break;
            case 2: inorden(p);
                break;
        }
    }while(op!=3);
    return 0;
}
nodo* insert(struct nodo*p,bool bo, int infor){
    nodo *aux1,*aux2;
    int factEq;
    if(p != NULL){//1
        if(infor < p->info){//1.1
            insert(p->izq,bo,infor);//recursive call
            if(bo == true){//1.1.1
                cout<<endl<<"Dame el factor de equilibrio:";
                cin>>factEq;
                switch(factEq){//1.1.1.1
                    case 1: p->FE=0; bo=false;
                        break;
                    case 0: p->FE=-1;
                        break;
                    case -1: aux1=p->izq;
                        break;
                        if(aux1->FE <= 0){//1.1.1.1.1
                            p->izq=aux1->der;
                            aux1->der=p;
                            p->FE=0;
                            p=aux1;
                        }else{
                            aux2=aux1->der;
                            p->izq=aux2->der;
                            aux2->der=p;
                            aux1->der=aux2->izq;
                            aux2->der=aux1;
                            if(aux2->FE == -1){//1.1.1.1.1 A
                                p->FE=1;
                            }else{
                                p->FE=0;
                            }//fin 1.1.1.1.1 A
                            if(aux2->FE == 1){//1.1.1.1.1 B
                                aux1->FE=-1;
                            }else{
                                aux1->FE=0;
                            }//fin 1.1.1.1.1 B
                            p=aux2;
                        }//fin 1.1.1.1.1
                        p->FE=0;
                        bo=false;
                }//fin 1.1.1.1
            }//fin 1.1.1
            else{
                if(infor > p->info){//1.1.3
                    insert(p->der,bo,infor);//recursive call
                    if(bo == true){//1.1.3.1
                        cout<<endl<<"Dame el factor de equilibrio:";
                        cin>>factEq;
                        switch(factEq){//1.1.3.1.1
                            case -1: p->FE=0; bo=false;
                                break;
                            case 0: aux1->FE=1;
                                break;
                            case 1: aux1=p->der;
                                break;
                                if(aux1->FE <= 0){//1.1.3.1.1 A
                                    p->der=aux1->izq;
                                    aux1->izq=p;
                                    p->FE=0;
                                    p=aux1;
                                }else{
                                    aux2=aux1->izq;
                                    p->der=aux2->izq;
                                    aux2->izq=p;
                                    aux1->izq=aux2->der;
                                    aux2->der=aux1;
                                    if(aux2->FE == 1){
                                        p->FE=-1;
                                    }else{
                                        p->FE=0;
                                    }
                                    p=aux2;
                                }//fin 1.1.3.1.1 A
                                p->FE=0;
                                bo=false;
                        }//fin 1.1.3.1.1
                    }//fin 1.1.3.1
                    else{
                        cout<<endl<<"LA INFORMACION YA SE ENCUENTRA EN EL ARBOL!!"<<endl;
                    }
                }//fin 1.1.3
            }
        }//fin 1.1
        else{
            p=crea();
            p->info=infor;
            p->izq=NULL;
            p->der=NULL;
            p->FE=0;
            bo=true;
        }
    }//fin 1
    return p;
}
nodo* crea(){
    return new nodo;
}
void inorden(struct nodo* apnodo){
        //izq-raiz-der
        if(apnodo!=NULL){
            inorden(apnodo->izq);
            cout<<endl<<"["<<apnodo->info<<"]";
            inorden(apnodo->der);
        }
}
