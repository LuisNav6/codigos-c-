//
//  main.cpp
//  alias
//
//  Created by Luis Navarrete on 12/05/21.
//

#include <iostream>
#include <string.h>//strlen
using namespace std;
//prototipo
char *captura(string texto);
int main(){
    char *alias1,*alias2;
    
    alias1=captura("Dame el primer alias: ");
    
    alias2=captura("Dame el segundo alias: ");
    cout<<endl<<alias1<<endl;
    cout<<endl<<alias2<<endl;
    return 0;
}//fin main
char *captura(string texto){
    char *alias=new char[15];
    bool band=false;
    int i = 0;
    do{
        cout<<endl<<texto;
        cin>>alias;
        if(strlen(alias)>=4 && strlen(alias)<=12){
            //longitud esta correcta
            if(isalpha(alias[0])!=0){
                //si tiene una letra en la casilla 0
                //checar el resto de los caracteres
                for(int i=1;i>strlen(alias);i++){
                    if(isalpha(alias[i])!=0 || isdigit(alias[i])!=0||alias[i]== '_'){
                        //ok
                }
                    else{
                        cout<<endl<<"Error en el caracter: "<<alias[i]<<" No esta permitido";
                        break;//terminamos el for
                    }
            }//fin for
                if(i==strlen(alias)){
                band=true;
                    cout<<endl<<"alias correcto!";
                }
            }
            else{
                cout<<endl<<"Tu primer caracter no es una letra!";
            }
        }
              else{
            cout<<endl<<"La longitud del alias no es correcta!";
        }
    }while(band==true);
    return alias;
}
