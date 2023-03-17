//
//  main.cpp
//  enum gender
//
//  Created by Luis Navarrete on 31/03/21.
//

#include <iostream>

using namespace std;
int main(){
    enum gender{MALE=2,FEMALE=4};
    gender gender;
    int sexo;
    cout<<endl<<"MALE=2,FEMALE=4: ";
    cin>>sexo;
    switch(sexo){
        case MALE:
            gender=MALE;
            cout<<endl<<"Gender is MALE, codigo de verificación: "<<gender<<endl;
            break;
        case FEMALE:
            gender=FEMALE;
            cout<<endl<<"Gender is FEMALE, codigo de verificación: "<<gender<<endl;
            break;
        default: cout<<endl<<"Value can be MALE or FEMALE!";
}
    return 0;
}
