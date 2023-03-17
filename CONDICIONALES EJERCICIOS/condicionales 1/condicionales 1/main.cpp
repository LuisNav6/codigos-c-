//
//  main.cpp
//  condicionales 1
//
//  Created by Luis Navarrete on 12/08/21.
//
//examen selectiva simple
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    float cal;
    cout<<endl<<"Dame tu califiación: "<<endl;
    cin>>cal;
    if(cal>8)
        cout<<endl<<"APROBADO!!!"<<endl;
    else
        cout<<endl<<"REPROBADO!!!"<<endl;
    return 0;
}
