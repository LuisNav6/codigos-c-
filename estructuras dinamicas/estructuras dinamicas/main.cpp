//
//  main.cpp
//  estructuras dinamicas
//
//  Created by Luis Navarrete on 01/06/21.
//

#include <iostream>
using namespace std;
struct punto{
    int x;
    int y;
};
punto llenar();
punto *llenar2();
void imprimir(punto *);
void imprimir1(punto);
int main(int argc, const char * argv[]){
  
    punto punto1;
    punto1=llenar();
    
    
    punto *punto2;
   
    punto2=llenar2();
    imprimir(punto2);
    imprimir1(punto1);
    punto *v;
    int n=5;
    v=new punto[n];//vector dinamico de estructuras
    cout<<endl<<"Llenando vector..."<<endl;
    for(int i=0;i<5;i++){
        v[i].x=i+2;
        v[i].y=i*i;
    }
    cout<<endl<<"Imprimiendo vector..."<<endl;
    for(int i=0;i<5;i++){
        cout<<endl<<"x: "<<v[i].x<<" "<<"y: "<<v[i].y;
    }
    punto **v1;//vector superdinamico
    //construir un vector de estructuras superdinamico
    v1=new punto*[n];
    for(int i=0;i<n;i++){
        v1[i]=new punto;
    }
    cout<<endl<<"Llenando vector superdinamico..."<<endl;
    for(int i=0;i<n;i++){
        v1[i]->x=i+3;
        v1[i]->y=i*2;
    }
    cout<<endl<<"Imprimiendo vector superdinamico..."<<endl;
    for(int i=0;i<n;i++){
        cout<<endl<<"x: "<<v1[i]->x<<" "<<"y: "<<v1[i]->y;
    }
    return 0;
}
punto llenar(){
    punto punto1;
    cout<<endl<<"Dame x: ";
    cin>>punto1.x;
    cout<<endl<<"Dame y: ";
    cin>>punto1.y;
    return punto1;
    
}
punto *llenar2(){
    punto *punto2;
    punto2=new punto;
    cout<<endl<<"Dame x: ";
    cin>>punto2->x;
    cout<<endl<<"Dame y: ";
    cin>>punto2->y;
    return punto2;
}
void imprimir(punto *punto2){
    cout<<endl<<"x vale: "<<punto2->x;
    cout<<endl<<"y vale: "<<punto2->y;
}
void imprimir1(punto punto1){
    cout<<endl<<"x vale: "<<punto1.x;
    cout<<endl<<"y vale: "<<punto1.y;
}
