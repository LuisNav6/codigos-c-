//
//  main.cpp
//  indireccion multiple
//
//  Created by Luis Navarrete on 24/05/21.
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
   //la indireccion multiple es cuando un puntero apunta a otro puntero
    //este tipo de punteros son utilizados para programar diversas estruturas de datos, una de ellas son las matrices dinamicas
    int **p;
    int *k;
    k=new int;
    *k=13;
    cout<<endl<<*k;//vemos 13
    p=&k;//asignamos a p la direccion de memoria donde esta k
    cout<<endl<<**p;//vemos 13
    cout<<endl;
    system("pause");
    
    
    return 0;
}
