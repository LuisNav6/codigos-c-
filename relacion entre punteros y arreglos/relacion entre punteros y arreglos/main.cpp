//
//  main.cpp
//  relacion entre punteros y arreglos
//
//  Created by Luis Navarrete on 23/08/21.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(int argc, const char * argv[]) {
    int *vec,i,*ptr=NULL;
    vec=new int[10];
    srand(time_t(0));
    for(i=0;i<10;i++){
        vec[i]=(rand()%100+1);
        cout<<"["<<vec[i]<<"]\t";
    }
    cout<<endl<<"-------------------------------"<<endl;
    ptr=vec;
    for(i=0;i<10;i++){
        //cout<<"["<<ptr[i]<<"]\t";
        cout<<"["<<*(ptr+i)<<"]\t";
    }
    cout<<endl;
    system("pause");
}
