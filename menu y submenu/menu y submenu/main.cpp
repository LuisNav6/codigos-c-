//
//  main.cpp
//  menu y submenu
//
//  Created by Luis Navarrete on 13/05/21.
//

#include <iostream>

using namespace std;
void menu();
void submenu();
int main(){
    int op;
    int opc;
    do{
        do{
        menu();
        cin>>op;
        }while(op<1||op>5);
        switch(op){
            case 1: cout<<endl<<"elegiste 1-Modo horizontal";break;
            case 2: cout<<endl<<"elegiste 2-carta completa";break;;
            case 3: cout<<endl<<"elegiste 3-modo vertical";break;
            case 4:
                do{
                    do{
                submenu();
                cin>>opc;
            }while(opc<1||opc>5);
                switch(opc){
                    case 1:cout<<endl<<"Seleccionaste la primer estadistica";break;
                    case 2:cout<<endl<<"Seleccionaste la segunda estadistica";break;
                    case 3:cout<<endl<<"Seleccionaste la tercer estadistica";break;
                    case 4:cout<<endl<<"Seleccionaste la cuarta estadistica";break;
                }
                }while(opc!=5);
            case 5: cout<<endl<<"fin del  programa"<<endl;break;
                }
    }while(op!=5);
    return 0;
}
void menu(){
    cout<<endl<<"Bingo"<<endl;
    cout<<endl<<"Modo 1-Horizontal"<<endl;
    cout<<endl<<"Modo 2-Carta completa"<<endl;
    cout<<endl<<"Modo 3-Vertical"<<endl;
    cout<<endl<<"4-Estadisticas"<<endl;
    cout<<endl<<"5-salir"<<endl;
    cout<<endl<<"Cual opción deseas: ";
    
}
void submenu(){
    cout<<endl<<"Estadisticas"<<endl;
    cout<<endl<<"Modo 1-Estadisticas 1"<<endl;
    cout<<endl<<"Modo 2-Estadisticas 2"<<endl;
    cout<<endl<<"Modo 3-Estadisticas 3"<<endl;
    cout<<endl<<"4-Estadisticas"<<endl;
    cout<<endl<<"5-Regresar a menu principal"<<endl;
    cout<<endl<<"Cual opción deseas: ";
}
