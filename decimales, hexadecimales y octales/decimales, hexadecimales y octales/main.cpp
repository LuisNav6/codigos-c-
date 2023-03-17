//
//  main.cpp
//  decimales, hexadecimales y octales
//
//  Created by Luis Navarrete on 17/08/21.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int x=15;
    float y=0.00234;
    float pi=3.1415;
    cout<<dec<<"El valor en decimal de x: "<<x<<endl;
    cout<<oct<<"El valor en octal de x: "<<x<<endl;
    cout<<hex<<"El valor en hexadecimal de x: "<<x<<endl;
    cout<<uppercase<<"El valor en uppercase de x: "<<x<<endl;
    cout<<scientific<<"El valor en notacion cientifica de y: "<<y<<endl;
    cout<<"el valor de pi es: "<<pi<<endl;
    cout.precision(2);
    cout<<fixed<<"el valor de pi es: "<<pi<<endl;
    cout<<showpoint<<"el valor de pi es: "<<pi<<endl;
    cout.width(50);
    cout.fill('/');
    cout<<"el valor de pi es: "<<pi<<endl;

    return 0;
}
