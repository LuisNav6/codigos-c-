//
//  main.cpp
//  arboles con nodos
//
//  Created by Luis Navarrete on 13/10/21.
//

#include <iostream>
using namespace std;
//structure
struct nodo{
    int info;
    nodo *izq,*der;
};
//prototypes
nodo* reserva_memoria();//creat memory for the tree
nodo* crea_arbol(struct nodo *apnodo);//creat the tree
//reading
void preorden (struct nodo *apnodo);
void inorden (struct nodo *apnodo);
void postorden (struct nodo *apnodo);
//insert
nodo* insertion_ABB(struct nodo *apnodo,int infor);
//search
void search_tree (struct nodo *apnodo,int infor);
//delete
nodo* delete_ABB (struct nodo *apnodo,int infor);
int main(int argc, const char * argv[]){
    int infor;
    int op;
    nodo* apnodo=NULL;
    do{
        cout<<endl<<"Cargar el arbol en memoria [1]"<<endl;
        cout<<endl<<"Mostrar el recorrido en preorden[2]"<<endl;
        cout<<endl<<"Mostrar el recorrido en inorden [3]"<<endl;
        cout<<endl<<"Mostrar el recorrido en postorden[4]"<<endl;
        cout<<endl<<"Insertar árboles binarios balanceados[5]"<<endl;
        cout<<endl<<"Buscar con referencia con árboles binarios balanceados[6]"<<endl;
        cout<<endl<<"Eliminar árboles binarios balanceados[7]"<<endl;
        cout<<endl<<"salir [8] "<<endl;
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
            case 5: cout<<endl<<"Dame el dato a insertar: ";
                cin>>infor;
                apnodo=insertion_ABB(apnodo,infor);
                cout<<endl<<"Dato insertado!!"<<endl;
                break;
           case 6: cout<<endl<<"Dame el dato a buscar: ";
                cin>>infor;
                search_tree(apnodo,infor);
                break;
            case 7: cout<<endl<<"Dame el dato a eliminar: ";
                cin>>infor;
                delete_ABB(apnodo,infor);
                cout<<endl<<"Dato eliminado!!!"<<endl;
                break;
            default: cout<<endl<<"opcion incorrecta!!"<<endl;
                break;
        }
    }while(op!=8);
    
    return 0;
}
nodo *delete_ABB(struct nodo *apnodo, int infor)
{
    nodo *otro,*aux,*aux1;
    bool bo;
    if(apnodo!=NULL)
    {
        if(infor<apnodo->info)
        {
            delete_ABB(apnodo->izq,infor);
        }
        else
        {
            if(infor>apnodo->info)
            {
                delete_ABB(apnodo->der,infor);
            }
            else
            {
                otro=apnodo;
                if(otro->der==NULL)
                {
                    apnodo=otro->izq;
                }
                else
                {
                    if(otro->izq==NULL)
                    {
                        apnodo = otro->der;
                    }
                    else
                    {
                        aux=apnodo->izq;
                        bo=false;
                        while(aux->der!=NULL)
                        {
                            aux1 = aux;
                            aux = aux->der;
                            bo = true;
                        }
                        apnodo->info = aux->info;
                        otro = aux;
                        
                        if(bo==true)
                        {
                            aux1->der = aux->izq;
                        }
                        else
                        {
                            apnodo->izq=aux->izq;
                        }
                    }
                }
                delete otro;
            }
        }
    }
    else
    {
        cout<<endl<<"Dato a eliminar no esta en el arbol";
    }
    return apnodo;
}
void search_tree (struct nodo *apnodo,int infor){
    if(apnodo==NULL){
        apnodo=reserva_memoria();
        apnodo->info=infor;
        apnodo->izq=NULL;
        apnodo->der=NULL;
    }else{
        if(infor<apnodo->info){
            if(apnodo->izq==NULL){
                cout<<endl<<"El dato no se encuentra en el árbol!!"<<endl;
            }else{
                search_tree(apnodo->izq,infor);//recursive call
            }
        }else{
            if(infor>apnodo->info){
                if(apnodo->der==NULL){
                    cout<<endl<<"El dato no se encuentra en el árbol!!"<<endl;
                }else{
                    search_tree(apnodo->der,infor);//recursive call
                }
            }else{
                cout<<endl<<"El dato no se encuentra en el árbol!!"<<endl;
            }
        }
    }
}
nodo* insertion_ABB(struct nodo *apnodo,int infor){
    nodo* otro;
    if(apnodo==NULL){
        apnodo=reserva_memoria();
        apnodo->info=infor;
        apnodo->izq=NULL;
        apnodo->der=NULL;
    }else{
    if(infor<apnodo->info){//node is less than root
        if(apnodo->izq==NULL){
            otro=reserva_memoria();//crear a new node
            otro->izq=NULL;
            otro->der=NULL;
            otro->info=infor;
            apnodo->izq=otro;
        }else{
            insertion_ABB(apnodo->izq,infor);//recursive call
        }//end of apnodo->izq==NULL
    }else{
        if(infor>apnodo->info){//node is greater than root
            if(apnodo->der==NULL){
                otro=reserva_memoria();//crear a new node
                otro->izq=NULL;
                otro->der=NULL;
                otro->info=infor;
                apnodo->der=otro;
            }else{
                insertion_ABB(apnodo->der,infor);//recursive call
            }//end of apnodo->der==NULL
        }else{
            cout<<endl<<"El nodo ya se encuentra en el árbol,no se insertó!!"<<endl;
        }
    }
    }
    return apnodo;
}
void postorden (struct nodo *apnodo){
    //left-right-root
    if(apnodo!=NULL){
        postorden(apnodo->izq);
        postorden(apnodo->der);
        cout<<endl<<"["<<apnodo->info<<"]";
    }
}
void inorden (struct nodo *apnodo){
    //left-root-right
    if(apnodo!=NULL){
        inorden(apnodo->izq);
        cout<<endl<<"["<<apnodo->info<<"]";
        inorden(apnodo->der);
    }
}
void preorden (struct nodo *apnodo){
    //root-left-right
    if(apnodo!=NULL){
        cout<<endl<<"["<<apnodo->info<<"]";
        preorden(apnodo->izq);
        preorden(apnodo->der);
    }
}
nodo* crea_arbol(struct nodo *apnodo){//creat the tree
    int resp;
    nodo* otro=NULL;
    cout<<endl<<"Dame el caracter que quieres almacenar: ";
    cin>>apnodo->info;
    cout<<endl<<"Existe nodo por izquierda?"<<endl<<"(1)SI,(2)NO:";
    cin>>resp;
    if(resp==1){
    otro=reserva_memoria();//creat a new node
        apnodo->izq=otro;
        crea_arbol(apnodo->izq);//recursive call
    }else{
        apnodo->izq=NULL;
    }
    cout<<endl<<"Existe nodo por derecha?"<<endl<<"(1)SI,(2)NO:";
    cin>>resp;
    if(resp==1){
        otro=reserva_memoria();//creat a new node
        apnodo->der=otro;
        crea_arbol(apnodo->der);//recursive call
    }else{
        apnodo->der=NULL;
    }
    return apnodo;
}
nodo* reserva_memoria(){//creat memory
  //creat a space of memory
        nodo *apnodo;
        apnodo=new nodo;
        return apnodo;
       
        /*return new nodo;--seria otra opción más simple de hacer lo de las lineas de arriba*/
    }
