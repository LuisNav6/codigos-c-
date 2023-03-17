//
//  main.cpp
//  struct anidados persona-direccion
//
//  Created by Luis Navarrete on 17/03/21.
//

#include <iostream>
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

int main(){
//declarar una variable del tipo del struct producto
    producto prod;
    prod = llenar();
    imprimir(prod);
    return 0;
}//fin main
producto llenar(){
    producto prod;
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
    cout<<endl<<"Imprimiendo datos..."<<endl;
    cout<<endl<<prod.nomproducto<<endl;
    cout<<endl<<prod.existencias<<endl;
    cout<<endl<<prod.precio<<endl;
    cout<<endl<<prod.prov.nomproveedor<<endl;
    cout<<endl<<prod.prov.idProveedor<<endl;
}
