//
//  main.cpp
//  uso de cin y cout
//
//  Created by Luis Navarrete on 16/03/21.
//
//cin.getline(variable,tamaño);
//endl es \n
#include <iostream>
using namespace std;//si no se debe poner std:: en cada cin, cout, endl¡MAS TRABAJO!
int main(){
    int i;
    char nom[30];
    cout<<endl<<"hola\t"<<"mundo";
    cout<<endl<<"i=";
    cin>>i;
    cout<<endl<<"Dame un nombre:";
    //cin>>nom;//solo agarra lo escrito antes del espacio
    fflush(stdin);
    cin.getline(nom,30);
    cout<<endl<<i;
    cout<<endl<<nom<<endl;
    int tabla=5;
    for(int i=1;i<=10;i++){
        cout<<endl<<i<<"x"<<tabla<<"="<<tabla*i<<endl;
    }
    
    return 0;
}

