//
//  main.cpp
//  shuffle de vector dinámico
//
//  Created by Luis Navarrete on 19/05/21.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void imprimir(int *vec,int tam);
void shuffle(int *array,int n);

int main(int argc, const char * argv[]) {
    srand(time_t(0));
    int *vec;
    int tam;
    cout<<endl<<"Dame el tamaño del vector: ";
    cin>>tam;
    vec=new int[tam];//vector dinamico
    //llenamos el vector dinamico
    for(int i=0;i<tam;i++){
        vec[i]=i+1;
    }
    cout<<endl<<"Vector original! "<<endl;
    imprimir(vec,tam);
    cout<<endl;
    char resp;
    cout<<endl<<"Quieres revolver el vector s/n: ";
    fflush(stdin);
    cin>>resp;
    while(resp=='s'){
        shuffle(vec,tam);
        imprimir(vec,tam);
        cout<<endl<<"Quieres revolver el vector otra vez s/n: ";
        fflush(stdin);
        cin>>resp;
        if(resp=='n')
            cout<<endl<<"Adios!"<<endl;
    }
}
void imprimir(int *vec,int tam){
    cout<<endl;
    for(int i=0;i<tam;i++){
        cout<<vec[i]<<" ";
    }
}
void shuffle(int *array,int n){
    if(n>1){
        int i;
        for(i=0;i<n-1;i++){
            int j=i+rand()/(RAND_MAX/(n-i)+1);
            int t=array[j];
            array[j]=array[i];
            array[i]=t;
        }
    }
}

