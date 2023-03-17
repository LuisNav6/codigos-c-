//
//  main.cpp
//  exf
//
//  Created by Luis Navarrete on 08/06/21.
//

#include <iostream>
#include <iomanip>
using namespace std;
void imprimir(int **m,int n);
int main(int argc, const char * argv[]) {
    int **m;
    int n=5;
    m=new int *[n];
    imprimir(m,n);
    return 0;
}
void imprimir(int **m,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<setw(4)<<*(m[i]+j);
        }
        cout<<endl;
        
    }
}
