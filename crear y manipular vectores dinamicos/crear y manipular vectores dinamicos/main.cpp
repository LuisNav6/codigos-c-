//
//  main.cpp
//  crear y manipular vectores dinamicos
//
//  Created by Luis Navarrete on 18/05/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, const char * argv[]) {
    srand(time_t(0));
    int *v;//puntero para el vector dinamico
    int n;
    cout<<endl<<"De que tamaño quieres el vector dinamico: ";
    cin>>n;
    v=new int[n]; //creacion del vector dinamico
   // llenando el vector
    for(int i=0;i<n;i++){
        v[i]=10+rand()%(50-10+1);
        //con aritmetica de punteros es asi: *(v+i)=10+rand()%(50-10+1);
    }
    //imprimiendo el vector
    cout<<endl<<"Imprimiendo el vector!"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        //con aritmetica de punteros es: cout<<*(v+i)<<" ";
        
    }
    //eliminando el espacio asignado al vector dinamico
    delete []v;
    
    return 0;
}
