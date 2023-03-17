//
//  main.cpp
//  help exponencial
//
//  Created by Luis Navarrete on 14/10/21.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int x, n, i, j;
    float exp=0;
    double fac;
    cout<<endl<<"DAME EL NUMERO DE REPETICIONES: ";
    cin>>n;
    cout<<endl<<"DAME EL VALOR DE X: ";
    cin>>x;
    
    while(i<=n){
        j=1;
        fac=1;
        while(j<=i){
            fac=fac*j;
            j=j+1;
        }
        exp=exp+pow(x,i)/fac;
        i=i+1;
    }
    
    cout<<endl<<"El valor es: "<<exp<<endl;
    return 0;
}
