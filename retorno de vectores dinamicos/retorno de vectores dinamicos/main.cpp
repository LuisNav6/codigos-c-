//
//  main.cpp
//  retorno de vectores dinamicos
//
//  Created by Luis Navarrete on 17/05/21.
//

#include <iostream>
using namespace std;
int *f();
int main(){
 
    int *aux;
    /*int vec[4]={1,2,3,4};
    cout<<vec<<endl;//direccion de memoria de la seccion del main
    int *v;
    v = new int[4];
    cout<<v<<endl;//direccion de memoria dinamica
    */
    aux=f();
    for(int i=0;i<4;i++)
        cout<<endl<<aux[i]<<endl<<"--------";
    //funcion();
    return 0;
}
int *f(){//el asterisco dice que la funcion retorna una direccion de memoria
    int vec[4]={1,2,3,4};
    cout<<vec<<endl;//direccion de memoria de la seccion del main
    int *v;
    v = new int[4];
    v[0]=12;
    v[1]=13;
    v[2]=14;
    v[3]=15;
    cout<<v<<endl;//direccion de memoria dinamica
    
    return v;
}
