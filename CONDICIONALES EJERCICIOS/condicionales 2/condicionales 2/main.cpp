//
//  main.cpp
//  condicionales 2
//
//  Created by Luis Navarrete on 12/08/21.
//
//aumento de suedo selectiva simple
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    float sue,sum,aum,nsue;
    cout<<endl<<"DAME TU SUELDO: ";
    cin>>sue;
    if(sue<1000){
        aum=sue*0.15;
    nsue=sue+aum;
    cout<<endl<<"TU NUEVO SUELDO ES:$"<<nsue<<endl;
    }else{
        cout<<endl<<"NO ERES ACREEDOR DE AUMENTO :("<<endl;
    }
    return 0;
}
