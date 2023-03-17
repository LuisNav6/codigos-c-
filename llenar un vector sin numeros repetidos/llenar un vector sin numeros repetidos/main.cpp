//
//  main.cpp
//  llenar un vector sin numeros repetidos
//
//  Created by Luis Navarrete on 26/05/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void llenar(int *v,int tam);
void imprimir(int *v,int tam);
bool revisar(int *v,int tam,int num);

int main(int argc, const char * argv[]) {
    srand(time_t(0));
    int *v=new int[6];
    llenar(v,6);//sin repetidos;
    imprimir(v,6);
    return 0;
}
void llenar(int *v,int tam){
    int i=0,num;
    bool bandera;
    while(i<tam){
        num=1+rand()%(6-1+1);
        bandera=revisar(v,i,num);
        if(bandera==false){
            //el numero no esta y lo podemos meter al vector
            v[i]=num;
            i++;
        }
    }//fin while
}
bool revisar(int *v,int tam,int num){
    bool band=false;
    for(int i=0;i<tam;i++){
        if(v[i]==num){
            band=true;break;
        }
    }//fin for
    return band;
}
void imprimir(int *v,int tam){
    cout<<endl<<"Imprimiendo sin vectores repetidos..."<<endl;
    for(int i=0;i<tam;i++)
        cout<<endl<<v[i]<<" ";
}
