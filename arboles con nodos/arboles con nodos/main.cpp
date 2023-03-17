//
//  main.cpp
//  arboles con nodos
//
//  Created by Luis Navarrete on 13/10/21.
//

#include <iostream>
using namespace std;
//estructura
struct nodo{
    char info;
    nodo *izq,*der;
};
//prototipos
nodo* reserva_memoria();//generamos memoria para la el nodo
nodo* crea_arbol(struct nodo *apnodo);//creamos el arbol
//recorridos
void preorden (struct nodo *apnodo);
void inorden (struct nodo *apnodo);
void postorden (struct nodo *apnodo);
int main(int argc, const char * argv[]){
    int op;
    nodo* apnodo=NULL;
    do{
        cout<<endl<<"Cargar el arbol en memoria [1]"<<endl;
        cout<<endl<<"Mostrar el recorrido en preorden[2]"<<endl;
        cout<<endl<<"Mostrar el recorrido en inorden [3]"<<endl;
        cout<<endl<<"Mostrar el recorrido en postorden[4]"<<endl;
        cout<<endl<<"salir [5] "<<endl;
        cout<<endl<<"Dame la opcion deseada:";
        cin>>op;
        switch (op) {
            case 1:
                apnodo=reserva_memoria();
                apnodo->izq=NULL;
                apnodo->der=NULL;
                apnodo=crea_arbol(apnodo);
                cout<<endl<<"Arbol cargado!!"<<endl;
                break;
            case 2: preorden(apnodo);
                break;
            case 3: inorden(apnodo);
                break;
            case 4: postorden(apnodo);
                break;
        }
    }while(op!=8);
    
    return 0;
}
void postorden (struct nodo *apnodo){
    //izq-der-raiz
    if(apnodo!=NULL){
        postorden(apnodo->izq);
        postorden(apnodo->der);
        cout<<endl<<"["<<apnodo->info<<"]";
    }
}
void inorden (struct nodo *apnodo){
    //izq-raiz-der
    if(apnodo!=NULL){
        inorden(apnodo->izq);
        cout<<endl<<"["<<apnodo->info<<"]";
        inorden(apnodo->der);
    }
}
void preorden (struct nodo *apnodo){
    //raiz-izq-der
    if(apnodo!=NULL){
        cout<<endl<<"["<<apnodo->info<<"]";
        preorden(apnodo->izq);
        preorden(apnodo->der);
    }
}
nodo* crea_arbol(struct nodo *apnodo){//crear arbol
    int resp;
    nodo* otro=NULL;
    cout<<endl<<"Dame el caracter que quieres almacenar: ";
    cin>>apnodo->info;
    cout<<endl<<"Existe nodo por izquierda?"<<endl<<"(1)SI,(2)NO:";
    cin>>resp;
    if(resp==1){
    otro=reserva_memoria();//se crea nuevo nodo
        apnodo->izq=otro;
        crea_arbol(apnodo->izq);//llamada recursiva
    }else{
        apnodo->izq=NULL;
    }
    cout<<endl<<"Existe nodo por derecha?"<<endl<<"(1)SI,(2)NO:";
    cin>>resp;
    if(resp==1){
        otro=reserva_memoria();//se crea nuevo nodo
        apnodo->der=otro;
        crea_arbol(apnodo->der);//llamada recursiva
    }else{
        apnodo->der=NULL;
    }
    return apnodo;
}
nodo* reserva_memoria(){//crear memoria
  //crea el espacio en memoria
        nodo *apnodo;
        apnodo=new nodo;
        return apnodo;
       
        /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
    }
