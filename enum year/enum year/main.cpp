//
//  main.cpp
//  enum year
//
//  Created by Luis Navarrete on 31/03/21.
//

#include <iostream>

using namespace std;
//definiendo de enum year
enum year{
    JAN=1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AGO,
    SEP,
    OCT,
    NOV,
    DEC,
};
int main(){
    int i;
    for(i=JAN;i<=DEC;i++){
        cout<<i<<" ";
    }
    return 0;
}
