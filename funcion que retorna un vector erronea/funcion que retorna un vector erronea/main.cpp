//
//  main.cpp
//  funcion que retorna un vector erronea
//
//  Created by Luis Navarrete on 20/05/21.
//

#include <iostream>

char *llenar();

using namespace std;

int main(int argc, const char * argv[]) {
    char *nombre;
    nombre=llenar();
    cout<<endl<<"El nombre capturado es:"<<nombre<<endl;
    return 0;
}
char *llenar(){
    char aux[30];
    cout<<endl<<"Dame un nombre: ";
    fflush(stdin);
    cin.getline(aux,30);
    return aux;
    
}

