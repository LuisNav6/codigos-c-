//
//  main.cpp
//  struct persona-direccion 3
//
//  Created by Luis Navarrete on 18/03/21.
//

#include <iostream>
#define TAM 2
using namespace std;

struct producto{
    char nomproducto[40];
    int existencias;
    float precio;
    
    struct proveedor{
        char nomproveedor[40];
        int idProveedor;
    }prov;
   
};
//prototipos
producto llenar();
void imprimir(producto prod);
void llenar2(producto v[TAM]);
void imprimir2(producto v[TAM]);

int main(){
//declarar una variable del tipo del struct producto
    //producto prod;
   // prod = llenar();
   //imprimir(prod);
    //opcion 1 trabajando con vectores
   /* producto vector[TAM];
    cout<<endl<<"llenando vector..";
    for(int i=0;i<TAM;i++){
        vector[i]=llenar();
    }
    cout<<endl<<"imprimiendo vector..";
    for(int i=0;i<TAM;i++){
        imprimir(vector[i]);
    }*/
    //opcion 2 trabajando con vectores
    producto v[TAM];
    llenar2(v);//mandar completo el vector con todos sus renglones
    imprimir2(v);//mandar completo el vector con todos sus renglones
    return 0;
}//fin main
producto llenar(){
    producto prod;
    fflush(stdin);
    cout<<endl<<"Nombre del producto: ";
    cin.getline(prod.nomproducto,40);
    cout<<endl<<"Existencias: ";
    cin>>prod.existencias;
    cout<<endl<<"Precio: ";
    cin>>prod.precio;
    
    cout<<endl<<"Nombre del proveedor: ";
    fflush(stdin);
    cin.getline(prod.prov.nomproveedor,40);
    cout<<endl<<"id proveedor: ";
    cin>>prod.prov.idProveedor;
    return prod;
}
void imprimir(producto prod){
   // cout<<endl<<"Imprimiendo datos..."<<endl;
    cout<<endl<<prod.nomproducto<<endl;
    cout<<endl<<prod.existencias<<endl;
    cout<<endl<<prod.precio<<endl;
    cout<<endl<<prod.prov.nomproveedor<<endl;
    cout<<endl<<prod.prov.idProveedor<<endl;
}
void llenar2(producto v[TAM]){
    cout<<endl<<"Llenando vector...";
    for(int i=0;i<TAM;i++){
        fflush(stdin);
        cout<<endl<<"Nombre del producto: ";
        cin.getline(v[i].nomproducto,40);
        cout<<endl<<"Existencias: ";
        cin>>v[i].existencias;
        cout<<endl<<"Precio: ";
        cin>>v[i].precio;
        
        cout<<endl<<"Nombre del proveedor: ";
        fflush(stdin);
        cin.getline(v[i].prov.nomproveedor,40);
        cout<<endl<<"id proveedor: ";
        cin>>v[i].prov.idProveedor;
    }//fin for
}
void imprimir2(producto v[TAM]){
    cout<<endl<<"Imprimiendo vector...";
    for(int i=0;i<TAM;i++){
    cout<<endl<<v[i].nomproducto<<endl;
    cout<<endl<<v[i].existencias<<endl;
    cout<<endl<<v[i].precio<<endl;
    cout<<endl<<v[i].prov.nomproveedor<<endl;
    cout<<endl<<v[i].prov.idProveedor<<endl;
    }
}
