//
//  main.cpp
//  LEER RENGLONES Y CUANTAS PALABRAS
//
//  Created by Luis Navarrete on 06/05/21.
//
#include <iostream>
#include <fstream> //necesaria para el manejo de archivos
//#include <windows.h>
using namespace std;

int renglones();
int palabras();
fstream leerArch; //declaracion local
/*****************************************************************************************************/
int main(){
    
    
    renglones();
    palabras();
    system("pause");
    return 0;
}

int renglones(){
    fstream leerArch; //declaracion local
    char linea[100]; //variable para guardar ahi lo que sacamos del archivo
    leerArch.open("renglones.txt",ios::in); //ABRE EL ARCHIVO DE TEXTO DE ESCRITURA
    if ( !leerArch )  // verifica que el archivo se abrio con exito
       cout << " No se pudo abrir el archivo " << endl ;
    else{
        int cont;
        while ( leerArch.getline(linea,100) ){ //recupera una linea de codigo y la almacena en la cadena linea
        cont++;
            cout<<linea<<endl; //imprime la linea a pantalla.
            //Sleep(1000);
        }//fin de while
        cout<<endl<<"Total de renglones: "<<cont;
     }//fin del else

cout<<endl;
    return 0;
}//fin de la funcion()

int palabras(){
    leerArch.open("renglones.txt",ios::in);
    char linea[100];
    string palabra;
    int cont;
    
    while ( leerArch.getline(linea,100) ){ //recupera una linea de codigo y la almacena en la cadena linea
        for(int i=0; i<100; i++){
            if(linea[i] == ' ')
            cont++;
        }
        }//fin de while
    cout<<endl<<"Total de palabras: "<<cont;
    cout<<endl;
    return 0;
}
