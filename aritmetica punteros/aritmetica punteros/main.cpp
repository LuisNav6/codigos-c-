//
//  main.cpp
//  aritmetica punteros
//
//  Created by Luis Navarrete on 20/05/21.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int k=7;
    int *ptr=&k;
    int *ptr2=new int;
    *ptr2=3;
    (*ptr)++;
    cout<<endl<<(*ptr)++;
    cout<<endl<<--(*ptr2);
    *ptr2+=2;
    k=(*ptr)--+2* *ptr2;
    cout<<endl<<k;
    cout<<endl<<*ptr2;
    delete ptr2;
    return 0;
}
